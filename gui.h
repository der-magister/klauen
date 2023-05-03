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

#ifndef _GUI_H_
#define _GUI_H_ 

#include "globals.h"

void p_gui_umwandlung (uint8_t l_w, uint8_t l_xk, uint8_t l_yk) __nonbanked;

extern void p_gui_showAus (void) __nonbanked;
extern void p_gui_showGeld (void) __nonbanked;
extern void p_gui_showDietrich (void) __nonbanked;
extern void p_gui_showMapKoords (void) __nonbanked;
extern void p_gui_showTime (void) __nonbanked;
extern void p_gui_init (void) __nonbanked;
extern void p_gui_showALL (void) __nonbanked;

#endif