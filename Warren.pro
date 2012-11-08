TEMPLATE = app
CONFIG += console
CONFIG -= qt

LIBS += -L$$PWD/SDL
#LIBS += -lSDL -lSDL_ttf
#LIBS += -lmingw32 -lSDLmain -lSDL -mwindows
LIBS += -lmingw32 -lSDLmain -lSDL -mwindows
#LIBS += -lmingw32

INCLUDEPATH += $$PWD/src
SOURCES += \
    src/z_zone.c \
    src/z_bmalloc.c \
    src/wi_stuff.c \
    src/w_wad.c \
#    src/w_mmap.c \
    src/w_memcache.c \
    src/version.c \
    src/v_video.c \
    src/tables.c \
    src/st_stuff.c \
    src/st_lib.c \
    src/sounds.c \
    src/s_sound.c \
    src/r_things.c \
    src/r_sky.c \
    src/r_segs.c \
    src/r_plane.c \
    src/r_patch.c \
    src/r_main.c \
    src/r_fps.c \
    src/r_filter.c \
    src/r_drawspan.inl \
    src/r_drawflush.inl \
    src/r_drawcolumn.inl \
    src/r_drawcolpipeline.inl \
    src/r_draw.c \
    src/r_demo.c \
    src/r_data.c \
    src/r_bsp.c \
    src/p_user.c \
    src/p_tick.c \
    src/p_telept.c \
    src/p_switch.c \
    src/p_spec.c \
    src/p_sight.c \
    src/p_setup.c \
    src/p_saveg.c \
    src/p_pspr.c \
    src/p_plats.c \
    src/p_mobj.c \
    src/p_maputl.c \
    src/p_map.c \
    src/p_lights.c \
    src/p_inter.c \
    src/p_genlin.c \
    src/p_floor.c \
    src/p_enemy.c \
    src/p_doors.c \
    src/p_checksum.c \
    src/p_ceilng.c \
    src/md5.c \
    src/m_random.c \
    src/m_misc.c \
    src/m_menu.c \
    src/m_cheat.c \
    src/m_bbox.c \
    src/m_argv.c \
    src/lprintf.c \
    src/lovenotes.c \
    src/info.c \
    src/i_intro.c \
    src/hu_stuff.c \
    src/hu_lib.c \
    src/g_game.c \
    src/f_wipe.c \
    src/f_finale.c \
    src/dstrings.c \
    src/doomstat.c \
    src/doomdef.c \
    src/d_main.c \
    src/d_items.c \
    src/d_deh.c \
    src/am_map.c \
    src/d_client.c \
#    src/SDL/SDL_win32_main.c \
    src/SDL/i_video.c \
    src/SDL/i_system.c \
    src/SDL/i_sshot.c \
    src/SDL/i_sound.c \
    src/SDL/i_network.c \
    src/SDL/i_main.c \
    src/SDL/i_joy.c

HEADERS += \
    src/z_zone.h \
    src/z_bmalloc.h \
    src/wi_stuff.h \
    src/w_wad.h \
    src/version.h \
    src/v_video.h \
    src/tables.h \
    src/st_stuff.h \
    src/st_lib.h \
    src/sounds.h \
    src/s_sound.h \
    src/r_things.h \
    src/r_state.h \
    src/r_sky.h \
    src/r_segs.h \
    src/r_plane.h \
    src/r_patch.h \
    src/r_main.h \
    src/r_fps.h \
    src/r_filter.h \
    src/r_draw.h \
    src/r_demo.h \
    src/r_defs.h \
    src/r_data.h \
    src/r_bsp.h \
    src/protocol.h \
    src/p_user.h \
    src/p_tick.h \
    src/p_spec.h \
    src/p_setup.h \
    src/p_saveg.h \
    src/p_pspr.h \
    src/p_mobj.h \
    src/p_maputl.h \
    src/p_map.h \
    src/p_inter.h \
    src/p_enemy.h \
    src/p_checksum.h \
    src/mmus2mid.h \
    src/md5.h \
    src/m_swap.h \
    src/m_random.h \
    src/m_misc.h \
    src/m_menu.h \
    src/m_fixed.h \
    src/m_cheat.h \
    src/m_bbox.h \
    src/m_argv.h \
    src/lprintf.h \
    src/lovenotes.h \
    src/info.h \
    src/i_video.h \
    src/i_system.h \
    src/i_sound.h \
    src/i_network.h \
    src/i_main.h \
    src/i_joy.h \
    src/i_intro.h \
    src/hu_stuff.h \
    src/hu_lib.h \
    src/gl_struct.h \
    src/gl_intern.h \
    src/g_game.h \
    src/f_wipe.h \
    src/f_finale.h \
    src/dstrings.h \
    src/doomtype.h \
    src/doomstat.h \
    src/doomdef.h \
    src/doomdata.h \
    src/d_ticcmd.h \
    src/d_think.h \
    src/d_player.h \
    src/d_net.h \
    src/d_main.h \
    src/d_items.h \
    src/d_event.h \
    src/d_englsh.h \
    src/d_deh.h \
    src/am_map.h \
    config.h

