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

#include "text.h"

#include "daten/gui/guidata.h"

void p_text_hideTXT (void) __nonbanked
{
	HIDE_WIN;
	move_win (0, 0);
	delay (160);
	SHOW_SPRITES;
	v_walk = TRUE;

}

void p_text_showTXT (unsigned char l_txt [81]) __banked
{
	set_win_tiles (0, 0, 20, 6, rahmen);
	set_win_tiles (1, 1, 18, 4, l_txt);
	move_win (7, 96);
	v_walk = FALSE;
	SHOW_WIN;
	HIDE_SPRITES;
	delay (170);
	waitpad (J_A);
	p_text_hideTXT ();
}

