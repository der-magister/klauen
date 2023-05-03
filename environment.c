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

#include "environment.h"
#include "text.h"
#include "gui.h"
#include "player.h"

#include "daten/txt/other/othertxt.h"
#include "daten/txt/chest/chesttxt.h"

void p_environment_init (void) __nonbanked
{
	uint8_t l_i;

	for (l_i = 0; l_i < 4; ++l_i) v_tuer [l_i] = 0;
	for (l_i = 0; l_i < 11; ++l_i) v_truhen [l_i] = 0;
	for (l_i = 0; l_i < 11; ++l_i) v_schalter [l_i] = 0;
	for (l_i = 0; l_i < 3; ++l_i) v_dietrich [l_i] = 0;
}

void p_environment_shild (uint8_t l_mk, unsigned char l_txt [81]) __nonbanked
{
	if (l_mk == v_pmk) {
		p_text_showTXT (l_txt);
	}
}

void p_environment_dietrich (uint8_t l_mk, uint8_t l_nr) __nonbanked
{
	if ((l_mk == v_pmk) && (v_dietrich [l_nr] == 0)) {
		p_text_showTXT (dietrich);
		++v_pdietrich;
		p_gui_showDietrich ();
		v_dietrich [l_nr] = 1;
	}
}

void p_environment_geld (uint8_t l_mk, uint8_t l_nr) __nonbanked
{
	if ((l_mk == v_pmk) && (v_dietrich [l_nr] == 0)) {
		v_pgeld += 5;
		p_text_showTXT (geld);
		p_gui_showGeld ();
		v_dietrich [l_nr] = 1;
	}
}

void p_environment_collectGeld (void) __nonbanked
{
	v_tile [0] = 127;
	++v_pgeld;
	p_gui_showGeld ();
	set_bkg_tiles (v_pxk / 8 - 1, v_pyk / 8 - 2, 1, 1, v_tile);
	v_lvldat [v_pmk] = 0;
}

void p_environment_collectClock (void) __nonbanked
{
	v_tile [0] = 127;
	v_time += 5;
	p_gui_showTime ();
	set_bkg_tiles (v_pxk / 8 - 1, v_pyk / 8 - 2, 1, 1, v_tile);
	v_lvldat [v_pmk] = 0;	
}

void p_environment_truheDietrich (uint8_t l_mk, uint8_t l_nr) __nonbanked
{
	if ((l_mk == v_pmk) && (v_truhen [l_nr] == 0)) {
		p_text_showTXT (dietrich);
		++v_pdietrich;
		p_gui_showDietrich ();
		v_truhen [l_nr] = 1;
	}
	else if ((l_mk == v_pmk) && (v_truhen [l_nr] == 1)) {
		p_text_showTXT (leer);
	}
}

void p_environment_truheGeld (uint8_t l_mk, uint8_t l_nr, uint8_t l_anzahl) __nonbanked
{
	if ((l_mk == v_pmk) && (v_truhen [l_nr] == 0)) {

		if (l_anzahl == 5) {
			p_text_showTXT (geld);
			v_pgeld += 5;
		}
		else if (l_anzahl == 10) {
			p_text_showTXT (geld10);
			v_pgeld += 10;
		}
		p_gui_showGeld ();
		v_truhen [l_nr] = 1;
	}
	else if ((l_mk == v_pmk) && (v_truhen [l_nr] == 1)) {
		p_text_showTXT (leer);
	}	
}

void p_environment_schalter (uint8_t l_mk, uint8_t l_nr) __nonbanked
{
	unsigned char l_tile [1] = { 127 };
	unsigned char l_tile_2 [1] = { 61 };

	if (l_mk == v_pmk) {
		if (l_nr == 1) {
			if (v_schalter [0] == 0) {
				set_bkg_tiles (5, 11, 1, 1, l_tile);
				set_bkg_tiles (4, 10, 1, 1, l_tile_2);
				v_schalter [0] == 1;
				v_lvldat [v_pmk + 1] = l_tile [0];
				v_lvldat [v_pmk - 18] = l_tile_2 [0];
			} 	
		}
		else if (l_nr == 2) {
			if (v_schalter [1] == 0) {
				set_bkg_tiles (5, 9, 1, 1, l_tile);
				set_bkg_tiles (6, 8, 1, 1, l_tile_2);
				v_schalter [1] == 1;
				v_lvldat [v_pmk - 1] = l_tile [0];
				v_lvldat [v_pmk - 18] = l_tile_2 [0]; 		
			}
		}
		else if (l_nr == 3) {
			if (v_schalter [2] == 0) {
				set_bkg_tiles (5, 11, 1, 1, l_tile);
				set_bkg_tiles (6, 10, 1, 1, l_tile_2);
				v_schalter [3] == 1;
				v_lvldat [v_pmk - 1] = l_tile [0];
				v_lvldat [v_pmk - 18] = l_tile_2 [0]; 		
			}
		}
	} 
}
