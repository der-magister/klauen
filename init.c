//   Klauen
//
//   Copyright (C) 2023 Heiko Wolf
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License As published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY Or FITNESS For A PARTICULAR PURPOSE.  See the
//   GNU General Public License For more details.
//
//   You should have received a copy of the GNU General Public License along
//   With this program; if not, write to the Free Software Foundation, Inc.,
//   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//   Kontakt: projekte@kabelmail.net

#include "init.h"
#include "engine.h"
#include "player.h"
#include "gui.h"
#include "level.h"
#include "environment.h"
#include "enemy.h"
#include "others.h"

#include "daten/tilesets/tilesets.h"
#include "daten/spritesets/sprites.h"

#include "daten/lvl/lvldat.h"

void p_init_initGame1 (void) __nonbanked
{
	SPRITES_8x8;
	
	//laden der Tilesets
	p_engine_loadTileset (46, 64, tiles);
	p_engine_loadTileset (65, 79, grundtiles);
	p_engine_loadTileset (80, 127, font);

	//laden der Spritesets
	p_engine_loadSpriteset (0, 10, sprites);

	SHOW_BKG;

	p_others_intro ();

	HIDE_BKG;

	p_player_init ();
	p_lvlcontrol_init ();
	p_environment_init ();
	p_gui_init ();
	v_gameover = 0; v_time = 120;
	
}

void p_init_initGame2 (void) __nonbanked
{
	v_movetimer = 0; v_walk = TRUE; v_enemytimer = 0; v_schleichtimer = 0; v_ausdauertimer = 0; v_timetimer = 0;
	p_gui_showALL ();
	p_engine_loadMap (mainmap);
	SHOW_BKG;
	SHOW_SPRITES;
	set_bkg_tiles (1, 1, 18, 14, v_lvldat);
	p_engine_changeLvl (1, 80, 128);
	p_enemy_init ();
}

