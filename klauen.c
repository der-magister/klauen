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


#include "klauen.h"
#include "init.h"
#include "player.h"
#include "level.h"
#include "enemy.h"
#include "gui.h"
#include "others.h"

void main (void) __nonbanked
{
	p_init_initGame1 ();
	p_init_initGame2 ();


	while (v_gameover == 0)
	{
		if ((v_movetimer == 6) && (v_walk == TRUE)) {
			if (joypad () & J_UP) p_player_move (1);
                	else if ((joypad () & J_DOWN)) p_player_move (2);
                	else if ((joypad () & J_LEFT)) p_player_move (3); 
                	else if ((joypad () & J_RIGHT)) p_player_move (4);

                	p_player_koliEnemy (); v_movetimer = 0; 
                }

                if (v_enemytimer == 25) {
                	p_enemy_dog ();
                	p_enemy_cars ();
                	p_enemy_owner ();
                	p_enemy_drone ();
                	p_player_koliEnemy ();
                	v_enemytimer = 0;
                }

                if ((joypad () & J_A) && (v_walk == TRUE)) p_lvlcontrol_whichLVL ();
                if ((joypad () & J_B) && (v_walk == TRUE)) p_player_schleichen ();

                if (v_schleichtimer == 50) {
                	--v_paus;
                	p_gui_showAus ();
                	v_schleichtimer = 0;
                	v_ausdauertimer = 0;

                	if (v_paus == 0) {
                		v_pschleich = 1; 
                		p_player_schleichen ();
                	}
                }

                if (v_ausdauertimer == 254) {
                	if (v_paus != 3) { 
                		++v_paus;
                		p_gui_showAus ();
                		v_ausdauertimer = 0;
                	}
                }

                if (v_timetimer == 100)  {
                	if (v_time > 0) {
                		--v_time;
                		p_gui_showTime ();
                		v_timetimer = 0;
                	}
                	else {
                		p_others_timeout ();

                	}

		}

                if (v_movetimer < 255) ++v_movetimer; 
                if (v_enemytimer < 255) ++v_enemytimer;
                if (v_ausdauertimer < 255) ++v_ausdauertimer;
                if (v_timetimer < 255) ++v_timetimer;

                if (v_pschleich == 1) ++v_schleichtimer;

                if ((v_pgeld > 83) && (v_lvl == 1)) {
                	p_others_win ();
                }

                wait_vbl_done ();
	}
	
}
