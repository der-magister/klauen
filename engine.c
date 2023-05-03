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

#include "engine.h"
#include "player.h"

/*
 Lädt angegebenes Tileset
 	l_tbank = Bank wo das Tileset liegt
	l_ftile = Nummer des ersten Tile
	l_ltile = Nummer des letzen Tile
	l_tileset = Name des Tileset
	l_rbank = Rückkehrbank (Bank voraus die Funktion aufgerufen wurde)
*/
void p_engine_loadTileset (uint8_t l_ftile, uint8_t l_ltile, unsigned char l_tileset [50]) __nonbanked
{
	set_bkg_data (l_ftile, l_ltile + 1, l_tileset);
}

/*
 Lädt angegebenes Spriteset
	l_fsprite = Nummer des ersten Sprites
	l_lsprite = Nummer des letzen Sprite
	l_spriteset = Name des Spriteset	
*/
void p_engine_loadSpriteset (uint8_t l_fsprite, uint8_t l_lsprite, unsigned char l_spriteset [25]) __nonbanked
{
	set_sprite_data (l_fsprite, l_lsprite + 1, l_spriteset);
}

//lädt angegebener Levelkarte
void p_engine_loadMap (unsigned char l_lvldat [252]) __nonbanked
{
	uint8_t l_i;

	for (l_i = 0; l_i != 253; ++l_i) v_lvldat [l_i] = l_lvldat [l_i];
}

//speichert aktuellen Levelzustand
void p_engine_saveMap (uint8_t l_lvl) __nonbanked
{
	uint8_t l_i;
	
	if (l_lvl == 2) for (l_i = 0; l_i != 253; ++l_i) v_lvldat_2 [l_i] = v_lvldat [l_i];
	else if (l_lvl == 3) for (l_i = 0; l_i != 253; ++l_i) v_lvldat_3 [l_i] = v_lvldat [l_i];
	else if (l_lvl == 4) for (l_i = 0; l_i != 253; ++l_i) v_lvldat_4 [l_i] = v_lvldat [l_i];
}

//Lädt gepseicherten Levelzustand
void p_engine_loadSavedMap (uint8_t l_lvl) __nonbanked
{
	uint8_t l_i;

	if (l_lvl == 2) for (l_i = 0; l_i != 253; ++l_i) v_lvldat [l_i] = v_lvldat_2 [l_i];
	else if (l_lvl == 3) for (l_i = 0; l_i != 253; ++l_i) v_lvldat [l_i] = v_lvldat_3 [l_i];
	else if (l_lvl == 4) for (l_i = 0; l_i != 253; ++l_i) v_lvldat [l_i] = v_lvldat_4 [l_i];
}

//berechnert Spielerkartenposition
uint8_t p_engine_calcCoord (uint8_t l_w1, uint8_t l_w2) __nonbanked
{
	return ((l_w1 - 16) / 8) + 18 * ((l_w2 - 24) / 8);
}

void p_engine_changeLvl (uint8_t l_lvl, uint8_t l_pxk, uint8_t l_pyk) __nonbanked
{
	v_lvl = l_lvl;
	v_pxk = l_pxk; v_pyk = l_pyk;
	p_player_setSprite ();
	v_movetimer = 0; v_enemytimer = 0; v_ausdauertimer = 0;
	delay (160);
	SHOW_SPRITES;
	SHOW_BKG;
}
