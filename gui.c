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

#include "gui.h"

#include "daten/gui/guidata.h"

//wandelt char in Tile um
void p_gui_umwandlung (uint8_t l_w, uint8_t l_xk, uint8_t l_yk) __nonbanked
{
	unsigned char l_tile [1];

	uint8_t l_i;

	if (l_w == 0) l_tile [0] = 91;

	for (l_i = 0x01; l_i != 0x0A; ++l_i) {
		if (l_w == l_i) l_tile [0] = 0x65 - l_i;
	}

	set_bkg_tiles (l_xk, l_yk, 1, 1, l_tile);
}

//zeigt Ausdauer an
void p_gui_showAus (void) __nonbanked
{
	p_gui_umwandlung (v_paus, 3, 16);
}

//zeigt Geld an
void p_gui_showGeld (void) __nonbanked
{
	p_gui_umwandlung (v_pgeld % 10, 12, 16);
        p_gui_umwandlung ((v_pgeld / 10) % 10, 11, 16);
}

//zeigt Anzahl Dietriche an
void p_gui_showDietrich (void) __nonbanked
{
	p_gui_umwandlung (v_pdietrich, 7, 16);
}

//zeigt Spielerposition an
void p_gui_showMapKoords (void) __nonbanked
{
	p_gui_umwandlung (v_pmk % 10, 10, 17);
        p_gui_umwandlung ((v_pmk / 10) % 10, 9, 17);
        p_gui_umwandlung (((v_pmk / 10) / 10) % 10, 8, 17);	
}

//zeigt Restzeit an
void p_gui_showTime (void) __nonbanked
{
	p_gui_umwandlung (v_time % 10, 18, 16);
        p_gui_umwandlung ((v_time / 10) % 10, 17, 16);
        p_gui_umwandlung (((v_time / 10) / 10) % 10, 16, 16);	
}

void p_gui_showALL (void) __nonbanked
{
	p_gui_showAus ();
	p_gui_showGeld ();
	p_gui_showDietrich ();
	p_gui_showTime ();
}

void p_gui_init (void) __nonbanked
{
	set_bkg_tiles (0, 0, 20, 18, statscreen);
	p_gui_showALL ();
} 

