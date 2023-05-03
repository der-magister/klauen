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

#include "others.h"
#include "init.h"
#include "gui.h"
#include "enemy.h"
#include "engine.h"

#include "daten/txt/other/othertxt.h"

void p_others_gameOver (void) __nonbanked
{
	p_engine_saveMap (v_lvl);
	set_bkg_tiles (0, 0, 20, 20, gameover);
	HIDE_SPRITES;
	v_movetimer = 255; v_enemytimer = 255; v_ausdauertimer = 255; v_timetimer = 255; v_walk = FALSE;
	delay (160);
	waitpad (J_START);
	p_enemy_uninitOwner ();
	p_enemy_uninitDrone ();
	p_gui_init ();
	p_init_initGame2 ();
}

void p_others_intro (void) __nonbanked
{
	set_bkg_tiles (0, 0, 20, 20, credits);
	delay (2800);
	set_bkg_tiles (0, 0, 20, 20, action);
	delay (2800);
	set_bkg_tiles (0, 0, 20, 20, title);
	delay (160);
	waitpad (J_START);
}

void p_others_timeout (void) __nonbanked
{
	HIDE_SPRITES;
	v_movetimer = 255; v_enemytimer = 255; v_ausdauertimer = 255; v_timetimer = 255; v_walk = FALSE;
	set_bkg_tiles (0, 0, 20, 20, timeout);
	p_enemy_uninitOwner ();
	p_enemy_uninitDrone ();
	delay (160);
	waitpad (J_START);
	p_init_initGame1 ();
	p_init_initGame2 ();
}

void p_others_win (void) __nonbanked
{
	HIDE_SPRITES;
	v_movetimer = 255; v_enemytimer = 255; v_ausdauertimer = 255; v_timetimer = 255; v_walk = FALSE;
	set_bkg_tiles (0, 0, 20, 20, win);
	p_enemy_uninitOwner ();
	p_enemy_uninitDrone ();
	delay (160);
	waitpad (J_START);
	p_init_initGame1 ();
	p_init_initGame2 ();
}
