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

#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "globals.h"

extern void p_engine_loadTileset (uint8_t l_ftile, uint8_t l_ltile, unsigned char l_tileset [50]) __nonbanked;
extern void p_engine_loadSpriteset (uint8_t l_fsprite, uint8_t l_lsprite, unsigned char l_spriteset [25]) __nonbanked;
extern void p_engine_loadMap (unsigned char l_lvldat [252]) __nonbanked;
extern void p_engine_saveMap (uint8_t l_lvl) __nonbanked;
extern void p_engine_loadSavedMap (uint8_t l_lvl) __nonbanked;
extern uint8_t p_engine_calcCoord (uint8_t l_w1, uint8_t l_w2) __nonbanked;
extern void p_engine_changeLvl (uint8_t l_lvl, uint8_t l_pxk, uint8_t l_pyk) __nonbanked;

#endif
