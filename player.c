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

#include "player.h"
#include "engine.h"
#include "gui.h"
#include "environment.h"
#include "others.h"

const unsigned char v_kdat [9] = { 47, 51, 54, 55, 57, 61, 62, 63, 64 };

void p_player_init (void) __nonbanked
{
	v_paus = 3; v_pgeld = 0; v_pdietrich = 0; v_pxk = 80; v_pyk = 128; v_pschleich = 0; 

	set_sprite_tile (0, 0);
	p_player_setSprite ();
}

void p_player_setSprite (void) __nonbanked
{
	move_sprite (0, v_pxk, v_pyk);
	v_pmk = p_engine_calcCoord (v_pxk, v_pyk);
	p_gui_showMapKoords ();
}

uint8_t v_player_kolision (unsigned char l_tile) __nonbanked
{
	uint8_t l_i;

	for (l_i = 0; l_i != sizeof (v_kdat) + 1; ++l_i) {
               if (l_tile == v_kdat [l_i]) return FALSE;
       	}
       	return TRUE;
}


void p_player_move (uint8_t l_ri) __nonbanked
{
	uint8_t l_walk = TRUE;

	//nach Norden
	if (l_ri == 1) {

		if (v_pyk > 24) {
			l_walk = v_player_kolision (v_lvldat [v_pmk - 18]);

			if (l_walk == TRUE) v_pyk -= 8;
		}
	}
	//nach Süden
	else if (l_ri == 2) {			
		if (v_pyk < 128) {
			l_walk = v_player_kolision (v_lvldat [v_pmk + 18]);

			if (l_walk == TRUE) v_pyk += 8;
		}
	}
	//nach Westen
	else if (l_ri ==  3) {
		if (v_pxk > 16) {
			l_walk = v_player_kolision (v_lvldat [v_pmk - 1]);
			if (l_walk == TRUE) v_pxk -= 8;
		}

		
	}
	else if (l_ri == 4) {
		if (v_pxk < 152) {
			l_walk = v_player_kolision (v_lvldat [v_pmk + 1]);

			if (l_walk == TRUE) v_pxk += 8;
		}		
	}


	if (l_walk == TRUE) {
		p_player_setSprite ();

		if ((v_lvldat [v_pmk] == 52) && (v_lvl > 1)) p_environment_collectGeld ();
		else if ((v_lvldat [v_pmk] == 46) && (v_lvl > 1)) p_environment_collectClock ();
	}
}

void p_player_koliEnemy (void) __nonbanked
{
	if (v_pschleich == 0) {
		if (v_lvl == 1) {
			if (((v_pxk == v_carX1) && (v_pyk == v_carY1)) ||
			    ((v_pxk == v_carX2) && (v_pyk == v_carY2)) ||
			    ((v_pxk == v_dogXK) && (v_pyk == v_dogYK)))

			{
				p_others_gameOver ();
			}
		}
		else if (v_lvl > 1) {
			if (((v_pxk == v_ownerX1) && (v_pyk == v_ownerY1)) || 
			    ((v_pxk == v_droneX1) && (v_pyk == v_droneY1)) ||
			    ((v_pxk == v_droneX2) && (v_pyk == v_droneY2)))
			{
				p_others_gameOver ();
			}
		}
	}
}

void p_player_schleichen (void) __nonbanked
{
	if ((v_pschleich == 0) && (v_paus > 0)) {
		set_sprite_tile (0, 2);
		v_pschleich = 1;
		v_schleichtimer = 0; --v_paus; v_ausdauertimer = 255;
		p_gui_showAus ();
		delay (150);

	}
	else if (v_pschleich == 1) {
		set_sprite_tile (0, 0);
		v_pschleich = 0; v_schleichtimer = 255; v_ausdauertimer = 0;
		delay (150);

	}

}
