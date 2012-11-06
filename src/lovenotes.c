#include "lovenotes.h"
#include "m_random.h"

const char *s_INTROTEXT =
        "Warren's weird dream\n"\
        "A 'Doom' mod by Christiaan Janssen\n"\
        "\n"\
        "Warren has been playing too much 'Doom'.\n"\
        "After a particularly stressful day,\n"\
        "he falls asleep\n"\
        "and has the strangest dream:\n"\
        "trapped inside the world of 'Doom',\n"\
        "he can't shoot the monsters\n"\
        "and the monsters don't shoot back,\n"\
        "they talk to him when he touches them.\n"\
        "\n"\
        "Explore Warren's weird dream...\n";


// template            "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789ABCDEF"

const char *LN_EMPTY = "";
const char *LN_MSG00 = "   Give me another opportunity, please";
const char *LN_MSG01 = "     Why don't you return my calls?";
const char *LN_MSG02 = "        You're breaking my heart";
const char *LN_MSG03 = "           Who is that bitch?";
const char *LN_MSG04 = " She will never give you as much as I did";
const char *LN_MSG05 = "         Our baby misses her dad";
const char *LN_MSG06 = "    You know she's not as good in bed";
const char *LN_MSG07 = "  Sometimes I think I will kill myself";
const char *LN_MSG08 = "          Please come back to me";
const char *LN_MSG09 = " I am not ready to meet other people yet";
const char *LN_MSG10 = "    Why were you so nasty with Sylvia?";
const char *LN_MSG11 = "   I still keep the ugly shirt you were\n"\
                       "          wearing on our first date";
const char *LN_MSG12 = "       You will never find anyone \n"\
                       "            better than me";
const char *LN_MSG13 = "           I always loved you";
const char *LN_MSG14 = "     I can change.  I will show you";
const char *LN_MSG15 = " I will do anything to get you back. Anything";
const char *LN_MSG16 = "     'where is daddy?' 'where is daddy?'";
const char *LN_MSG17 = "      You are the father, I am sure";
const char *LN_MSG18 = " We will be a happy family once you return";
const char *LN_MSG19 = "        That bitch is a dead bitch";
const char *LN_MSG20 = " I can dye my hair blonde too, just like her";
const char *LN_MSG21 = "   My mother also wants you to come back";
const char *LN_MSG22 = " Your old stuff is still waiting at home";
const char *LN_MSG23 = "         Lucy has your eyes.";
const char *LN_MSG24 = " You started changing after the accident";
const char *LN_MSG25 = " It was not your fault, he jumped\n"\
                       "        in front of the car";
const char *LN_MSG26 = " Do you still wake up shouting in the \n"\
                       "       middle of the night?";
const char *LN_MSG27 = " It has been two years since the accident";
const char *LN_MSG28 = " I never understood why you drank so much";
const char *LN_MSG29 = " It's not too late, we can still fix this";
const char *LN_MSG30 = " The road was wet. Stop blaming yourself";
const char *LN_MSG31 = " Do you still have that jacket I bought you?";
const char *LN_MSG32 = "      You've always been a romantic";
const char *LN_MSG33 = "    You have to see her! She's so cute";
const char *LN_MSG34 = "      Did you erase me from facebook?";
const char *LN_MSG35 = " Remember that you introduced him to me";
const char *LN_MSG36 = " Mom is preparing a welcome party for you";
const char *LN_MSG37 = " David never meant anything to me. I'm sorry";
const char *LN_MSG38 = " I don't know why I did I it. I was angry at you";
const char *LN_MSG39 = "        I wanted to hurt you because\n"\
                       "             you were hurting me";
const char *LN_MSG40 = " I regret what I did, we should have talked";
const char *LN_MSG41 = " Now is the time to talk.  Say that you love me";
const char *LN_MSG42 = "   You know it's true.  We need each other";
const char *LN_MSG43 = " I haven't seen David ever again. I promise";
const char *LN_MSG44 = " You pushed me to him with your attitude";
const char *LN_MSG45 = "            David was your fault";
const char *LN_MSG46 = "               I need you";
const char *LN_MSG47 = "        I can't breathe without you";
const char *LN_MSG48 = "       You know that you still love me";
const char *LN_MSG49 = "       Don't be so quiet.  It hurts me";
const char *LN_MSG50 = " I don't mind if you play videogames all day";
const char *LN_MSG51 = " Other women won't understand you like me";
const char *LN_MSG52 = " No one has been spying you, that's ridiculous";
const char *LN_MSG53 = "   It was painful for me too, but I have\n"\
                       "              forgiven you";
const char *LN_MSG54 = "      You must accept that you've always\n"\
                       "            been a bit selfish";
const char *LN_MSG55 = "         Are you running away from me?";
const char *LN_MSG56 = " Sylvia asks for you every time we visit her";
const char *LN_MSG57 = " I know that you hated how controlling Mom is";
const char *LN_MSG58 = " Mom is sorry for shouting at you that day";
const char *LN_MSG59 = " She knew I was suffering. I'm her daughter";
const char *LN_MSG60 = "      Those days were very hard for both";
const char *LN_MSG61 = "            You didn't have to leave";
const char *LN_MSG62 = "                Do it for Lucy";
const char *LN_MSG63 = "        Stop pretending that you don't care";
const char *LN_MSG64 = "      You should start acting responsibly";
const char *LN_MSG65 = " You thought I would not find out about her?";
const char *LN_MSG66 = "     I want you to know that I'm not angry";
const char *LN_MSG67 = "      Everyone has a little secret I guess";
const char *LN_MSG68 = " Men never grow up, you are just big children";
const char *LN_MSG69 = " I saw you in a restaurant with her last week";
const char *LN_MSG70 = "     Don't try to hide it, I know it's true";
const char *LN_MSG71 = "       How long have you been seeing her?";
const char *LN_MSG72 = "  You're wasting your time with that bitch";
const char *LN_MSG73 = "  I thought that you knew about the affair";
const char *LN_MSG74 = " I thought that you left me because of that";
const char *LN_MSG75 = "        Yesterday the widow called home";
const char *LN_MSG76 = "      She already won the trial, I don't\n"\
                       "          know what does she want now";
const char *LN_MSG77 = " It's sad that Bruce didn't have children";
const char *LN_MSG78 = "    I didn't want to tell you about the call";
const char *LN_MSG79 = "   Don't worry, I told Fiona that you don't\n"\
                       "     live here any more. Just a little lie";
const char *LN_MSG80 = "        I told Rufus to call her back";
const char *LN_MSG81 = "         Rufus will take care of that,\n"\
                       "             he is a good lawyer";
const char *LN_MSG82 = " We have to see Rufus next week in his office";
const char *LN_MSG83 = "   Don't bring that whore with you next week";
const char *LN_MSG84 = " You should leave her, she's no good for you";
const char *LN_MSG85 = "   Don't lie to yourself, you don't love her";
const char *LN_MSG86 = "      You thought I would never find out?";
const char *LN_MSG87 = "        You can't hide anything to me";
const char *LN_MSG88 = "         Her name is Diane, am I right?";
const char *LN_MSG89 = "         Her first word was 'Martha'";
const char *LN_MSG90 = "    She didn't say 'mama' like other babies";
const char *LN_MSG91 = " I forgive you. She's only an adventure";
const char *LN_MSG92 = "         What will you do without me?";
const char *LN_MSG93 = " You went to college with David, didn't you?";
const char *LN_MSG94 = " It's hard to raise a baby without a father";
const char *LN_MSG95 = "      Mom is helping a lot with the baby";
const char *LN_MSG96 = "         Don't you dare ignoring me";
const char *LN_MSG97 = "           Of course the baby is real";
const char *LN_MSG98 = "      Call me tomorrow, when you wake up";
const char *LN_MSG99 = "     You still have my number, don't you?";

#define totalMessages 100
int remainingMessages = totalMessages;
int messageFlags[totalMessages];

void initLN()
{
    int i;
    remainingMessages = totalMessages;
    for (i=0; i<totalMessages; i++)
        messageFlags[i] = 0;
}

int getIndex()
{
    int i;
    int count = (M_Random() % remainingMessages) + 1;
    for (i=0; i<totalMessages; i++)
        if (!messageFlags[i]) {
            count--;
            if (!count) break;
        }
    return i;
}

int extractIndex()
{
    int ndx = getIndex();
    messageFlags[ndx] = 1;
    remainingMessages--;
    if (!remainingMessages)
        initLN();
    return ndx;
}

const char *getNextMessage()
{
    switch (extractIndex()) {
    case 0: return LN_MSG00;
    case 1: return LN_MSG01;
    case 2: return LN_MSG02;
    case 3: return LN_MSG03;
    case 4: return LN_MSG04;
    case 5: return LN_MSG05;
    case 6: return LN_MSG06;
    case 7: return LN_MSG07;
    case 8: return LN_MSG08;
    case 9: return LN_MSG09;
    case 10: return LN_MSG10;
    case 11: return LN_MSG11;
    case 12: return LN_MSG12;
    case 13: return LN_MSG13;
    case 14: return LN_MSG14;
    case 15: return LN_MSG15;
    case 16: return LN_MSG16;
    case 17: return LN_MSG17;
    case 18: return LN_MSG18;
    case 19: return LN_MSG19;
    case 20: return LN_MSG20;
    case 21: return LN_MSG21;
    case 22: return LN_MSG22;
    case 23: return LN_MSG23;
    case 24: return LN_MSG24;
    case 25: return LN_MSG25;
    case 26: return LN_MSG26;
    case 27: return LN_MSG27;
    case 28: return LN_MSG28;
    case 29: return LN_MSG29;
    case 30: return LN_MSG30;
    case 31: return LN_MSG31;
    case 32: return LN_MSG32;
    case 33: return LN_MSG33;
    case 34: return LN_MSG34;
    case 35: return LN_MSG35;
    case 36: return LN_MSG36;
    case 37: return LN_MSG37;
    case 38: return LN_MSG38;
    case 39: return LN_MSG39;
    case 40: return LN_MSG40;
    case 41: return LN_MSG41;
    case 42: return LN_MSG42;
    case 43: return LN_MSG43;
    case 44: return LN_MSG44;
    case 45: return LN_MSG45;
    case 46: return LN_MSG46;
    case 47: return LN_MSG47;
    case 48: return LN_MSG48;
    case 49: return LN_MSG49;
    case 50: return LN_MSG50;
    case 51: return LN_MSG51;
    case 52: return LN_MSG52;
    case 53: return LN_MSG53;
    case 54: return LN_MSG54;
    case 55: return LN_MSG55;
    case 56: return LN_MSG56;
    case 57: return LN_MSG57;
    case 58: return LN_MSG58;
    case 59: return LN_MSG59;
    case 60: return LN_MSG60;
    case 61: return LN_MSG61;
    case 62: return LN_MSG62;
    case 63: return LN_MSG63;
    case 64: return LN_MSG64;
    case 65: return LN_MSG65;
    case 66: return LN_MSG66;
    case 67: return LN_MSG67;
    case 68: return LN_MSG68;
    case 69: return LN_MSG69;
    case 70: return LN_MSG70;
    case 71: return LN_MSG71;
    case 72: return LN_MSG72;
    case 73: return LN_MSG73;
    case 74: return LN_MSG74;
    case 75: return LN_MSG75;
    case 76: return LN_MSG76;
    case 77: return LN_MSG77;
    case 78: return LN_MSG78;
    case 79: return LN_MSG79;
    case 80: return LN_MSG80;
    case 81: return LN_MSG81;
    case 82: return LN_MSG82;
    case 83: return LN_MSG83;
    case 84: return LN_MSG84;
    case 85: return LN_MSG85;
    case 86: return LN_MSG86;
    case 87: return LN_MSG87;
    case 88: return LN_MSG88;
    case 89: return LN_MSG89;
    case 90: return LN_MSG90;
    case 91: return LN_MSG91;
    case 92: return LN_MSG92;
    case 93: return LN_MSG93;
    case 94: return LN_MSG94;
    case 95: return LN_MSG95;
    case 96: return LN_MSG96;
    case 97: return LN_MSG97;
    case 98: return LN_MSG98;
    case 99: return LN_MSG99;
    }

    return LN_EMPTY;
}
