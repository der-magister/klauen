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

#ifndef _environment_h_
#define _environment_h_

#include "globals.h"

extern void p_environment_init (void) __nonbanked;
extern void p_environment_shild (uint8_t l_mk, unsigned char l_txt [81]) __nonbanked;
extern void p_environment_dietrich (uint8_t l_mk, uint8_t l_nr) __nonbanked;
extern void p_environment_geld (uint8_t l_mk, uint8_t l_nr) __nonbanked;
extern void p_environment_collectGeld (void) __nonbanked;
extern void p_environment_collectClock (void) __nonbanked;
extern void p_environment_truheRiegel (uint8_t l_mk, uint8_t l_nr) __nonbanked;
extern void p_environment_truheDietrich (uint8_t l_mk, uint8_t l_nr) __nonbanked;
extern void p_environment_truheGeld (uint8_t l_mk, uint8_t l_nr, uint8_t l_anzahl) __nonbanked;
extern void p_environment_schalter (uint8_t l_mk, uint8_t l_nr) __nonbanked;

#endif
