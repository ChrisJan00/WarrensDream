/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *      Game completion, final screen animation.
 *
 *-----------------------------------------------------------------------------
 */

#include "doomstat.h"
#include "d_event.h"
#include "v_video.h"
#include "w_wad.h"
#include "s_sound.h"
#include "sounds.h"
#include "d_deh.h"  // Ty 03/22/98 - externalizations
#include "i_intro.h" // CPhipps - hmm...
#include "lovenotes.h"

// Stage of animation:
//  0 = text, 1 = art screen, 2 = character cast
static int introstage; // cph -
static int introcount; // made static
static const char*   introtext; // cph -
static const char*   introflat; // made static const

// defines for the end mission display text                     // phares

#define TEXTSPEED    3     // original value                    // phares
#define TEXTWAIT     250   // original value                    // phares
#define NEWTEXTSPEED 0.01f  // new value                         // phares
#define NEWTEXTWAIT  1000  // new value                         // phares

// CPhipps - removed the old finale screen text message strings;
// they were commented out for ages already
// Ty 03/22/98 - ... the new s_WHATEVER extern variables are used
// in the code below instead.

void WI_checkForAccelerate(void);    // killough 3/28/98: used to
extern int acceleratestage;          // accelerate intermission screens
static int midstage;                 // whether we're in "mid-stage"

//
// In_StartIntro
//
void In_StartIntro (void)
{
  gameaction = ga_nothing;
  gamestate = GS_INTRO;
  automapmode &= ~am_active;

  // killough 3/28/98: clear accelerative text flags
  acceleratestage = midstage = 0;


  introflat = bgflatE1;
  introtext = s_INTROTEXT;

  introstage = 0;
  introcount = 0;
}



boolean In_Responder (event_t *event)
{
//  if (introstage == 2)
//    return In_CastResponder (event);

  return false;
}

// Get_TextSpeed() returns the value of the text display speed  // phares
// Rewritten to allow user-directed acceleration -- killough 3/28/98

static float Get_TextSpeed(void)
{
  return midstage ? NEWTEXTSPEED : (midstage=acceleratestage) ?
    acceleratestage=0, NEWTEXTSPEED : TEXTSPEED;
}


//
// In_Ticker
//
// killough 3/28/98: almost totally rewritten, to use
// player-directed acceleration instead of constant delays.
// Now the player can accelerate the text display by using
// the fire/use keys while it is being printed. The delay
// automatically responds to the user, and gives enough
// time to read.
//
// killough 5/10/98: add back v1.9 demo compatibility
//

void In_Ticker(void)
{
  int i;
  if (!demo_compatibility)
    WI_checkForAccelerate();  // killough 3/28/98: check for acceleration
  else
    if (gamemode == commercial && introcount > 50) // check for skipping
      for (i=0; i<MAXPLAYERS; i++)
        if (players[i].cmd.buttons)
            gameaction = ga_newgame;
          //goto next_level;      // go on to the next level

  // advance animation
  introcount++;

//  if (introstage == 2)
//    In_CastTicker();

  if (!introstage)
    {
      float speed = demo_compatibility ? TEXTSPEED : Get_TextSpeed();
      /* killough 2/28/98: changed to allow acceleration */
      if (introcount > strlen(introtext)*speed +
          (midstage ? NEWTEXTWAIT : TEXTWAIT) ||
          (midstage && acceleratestage)) {
//        if (gamemode != commercial)       // Doom 1 / Ultimate Doom episode end
          {                               // with enough time, it's automatic
            introcount = 0;
            introstage = 1;
            wipegamestate = -1;         // force a wipe
            if (gameepisode == 3)
              S_StartMusic(mus_bunny);
            gameaction = ga_newgame;
          }
//        else   // you must press a button to continue in Doom 2
//          if (!demo_compatibility && midstage)
//            {
//            next_level:
//              if (gamemap == 30)
//                In_StartCast();              // cast of Doom 2 characters
//              else
//                gameaction = ga_newgame;  // next level, e.g. MAP07
//            }
      }
    }
}

//
// In_TextWrite
//
// This program displays the background and text at end-mission     // phares
// text time. It draws both repeatedly so that other displays,      //   |
// like the main menu, can be drawn over it dynamically and         //   V
// erased dynamically. The TEXTSPEED constant is changed into
// the Get_TextSpeed function so that the speed of writing the      //   ^
// text can be increased, and there's still time to read what's     //   |
// written.                                                         // phares
// CPhipps - reformatted

#include "hu_stuff.h"
extern patchnum_t hu_font[HU_FONTSIZE];


static void In_TextWrite (void)
{
  V_DrawBackground(introflat, 0);
  { // draw some of the text onto the screen
    int         cx = 10;
    int         cy = 10;
    const char* ch = introtext; // CPhipps - const
    int         count = (int)((float)(introcount - 10)/Get_TextSpeed()); // phares
    int         w;

    if (count < 0)
      count = 0;

    for ( ; count ; count-- ) {
      int       c = *ch++;

      if (!c)
  break;
      if (c == '\n') {
  cx = 10;
  cy += 11;
  continue;
      }

      c = toupper(c) - HU_FONTSTART;
      if (c < 0 || c> HU_FONTSIZE) {
  cx += 4;
  continue;
      }

      w = hu_font[c].width;
      if (cx+w > SCREENWIDTH)
  break;
      // CPhipps - patch drawing updated
      V_DrawNumPatch(cx, cy, 0, hu_font[c].lumpnum, CR_DEFAULT, VPT_STRETCH);
      cx+=w;
    }
  }
}

//
// In_BunnyScroll
//
static const char pfub2[] = { "PFUB2" };
static const char pfub1[] = { "PFUB1" };

static void In_BunnyScroll (void)
{
  char        name[10];
  int         stage;
  static int  laststage;

  {
    int scrolled = 320 - (introcount-230)/2;
    if (scrolled <= 0) {
      V_DrawNamePatch(0, 0, 0, pfub2, CR_DEFAULT, VPT_STRETCH);
    } else if (scrolled >= 320) {
      V_DrawNamePatch(0, 0, 0, pfub1, CR_DEFAULT, VPT_STRETCH);
    } else {
      V_DrawNamePatch(320-scrolled, 0, 0, pfub1, CR_DEFAULT, VPT_STRETCH);
      V_DrawNamePatch(-scrolled, 0, 0, pfub2, CR_DEFAULT, VPT_STRETCH);
    }
  }

  if (introcount < 1130)
    return;
  if (introcount < 1180)
  {
    // CPhipps - patch drawing updated
    V_DrawNamePatch((320-13*8)/2, (200-8*8)/2,0, "END0", CR_DEFAULT, VPT_STRETCH);
    laststage = 0;
    return;
  }

  stage = (introcount-1180) / 5;
  if (stage > 6)
    stage = 6;
  if (stage > laststage)
  {
    S_StartSound (NULL, sfx_pistol);
    laststage = stage;
  }

  sprintf (name,"END%i",stage);
  // CPhipps - patch drawing updated
  V_DrawNamePatch((320-13*8)/2, (200-8*8)/2, 0, name, CR_DEFAULT, VPT_STRETCH);
}


//
// In_Drawer
//
void In_Drawer (void)
{
//  if (introstage == 2)
//  {
//    In_CastDrawer ();
//    return;
//  }

  if (!introstage)
    In_TextWrite ();
  else
  {
    switch (gameepisode)
    {
      // CPhipps - patch drawing updated
      case 1:
           if ( gamemode == retail )
             V_DrawNamePatch(0, 0, 0, "CREDIT", CR_DEFAULT, VPT_STRETCH);
           else
             V_DrawNamePatch(0, 0, 0, "HELP2", CR_DEFAULT, VPT_STRETCH);
           break;
      case 2:
           V_DrawNamePatch(0, 0, 0, "VICTORY2", CR_DEFAULT, VPT_STRETCH);
           break;
      case 3:
           In_BunnyScroll ();
           break;
      case 4:
           V_DrawNamePatch(0, 0, 0, "ENDPIC", CR_DEFAULT, VPT_STRETCH);
           break;
    }
  }
}
