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

#include "enemy.h"

//laufpunkte Hund
const uint8_t v_dogXKdat [39] =	{
					152, 152, 152, 144, 136, 128, 120, 120, 120, 112, 104, 104, 96, 88, 80, 
					72, 64, 56, 56, 56, 56, 56, 56, 64, 72, 80, 88, 96, 104, 104, 104, 112, 120,
					120, 120, 128, 136, 144, 144 
};

const uint8_t v_dogYKdat [39] =	{ 	40,  32,  24,  24,  24,  24,  24,  32,  40,  40,  40,  32, 32, 32, 32, 32, 32, 
					32, 40, 48, 56, 64, 72, 72, 72, 72, 72,  72,   72, 64,  56,  56,  56, 64,  72, 72, 72, 72, 64 
};

void p_enemy_init (void) __nonbanked
{
	v_e1 = 0; v_r1 = 0; v_r2 = 0; v_r3 = 0;
	p_enemy_initDog (); 
	p_enemy_initCars ();
}


void p_enemy_initDog (void) __nonbanked
{	
	v_dogXK = v_dogXKdat [v_e1]; v_dogYK = v_dogYKdat [v_e1];
	set_sprite_tile (1, 8);
	move_sprite (1, v_dogXK, v_dogYK);
}

void p_engine_uninitDog (void) __nonbanked
{
	move_sprite (1, 0, 0);
}

void p_enemy_initCars (void) __nonbanked
{
	set_sprite_tile (2, 6);
	set_sprite_tile (3, 9);

	v_carX1 = 152; v_carX2 = 8; v_carY1 = 104; v_carY2 = 112;
}

void p_enemy_initOwner (void) __nonbanked
{
	set_sprite_tile (4, 3);
	
	if (v_lvl == 2) { 
		v_ownerX1 = 136; v_ownerY1 = 56;
	}
	else if (v_lvl == 3) {
		v_ownerX1 = 32; v_ownerY1 = 56;
	}
	else if (v_lvl == 4) {
		v_ownerX1 = 136; v_ownerY1 = 32;
	}

	move_sprite (4, v_ownerX1, v_ownerY1);	
	v_r1 = 1;
}

void p_enemy_uninitOwner (void) __nonbanked
{
	v_ownerX1 = 0; v_ownerY1 = 0;

	move_sprite (4, 0, 0);
}

void p_enemy_initDrone (void) __nonbanked
{
	set_sprite_tile (5, 4);
	set_sprite_tile (6, 4);

	if (v_lvl == 2) {
		v_droneX1 = 120; v_droneY1 = 120;
		v_droneX2 = 48, v_droneY2 = 96; 
	}
	else if (v_lvl == 3) {
		v_droneX1 = 40, v_droneY1 = 120;
		v_droneX2 = 80; v_droneY2 = 72;
	}
	else if (v_lvl == 4) {
		v_droneX1 = 144; v_droneY1 = 120;
		v_droneX2 =  88; v_droneY2 = 88;
	}
	move_sprite (5, v_droneX1, v_droneY1);
	move_sprite (6, v_droneX2, v_droneY2);
	v_r2 = 1; v_r3 = 1;
	
}

void p_enemy_uninitDrone (void) __nonbanked
{
	v_droneX1 = 0; v_droneY1 = 0;
	v_droneX2 = 0; v_droneY2 = 0;

	move_sprite (5, 0, 0);
	move_sprite (6, 0, 0);
}

void p_enemy_uninitCars (void) __nonbanked
{
	move_sprite (2, 0, 0);
	move_sprite (3, 0, 0);
}

void p_enemy_dog (void) __nonbanked
{
	if (v_lvl == 1) {
		v_dogXK = v_dogXKdat [v_e1]; v_dogYK = v_dogYKdat [v_e1];
		move_sprite (1, v_dogXK, v_dogYK);
	
		if (v_e1 == sizeof (v_dogXKdat)) {
			v_r1 = 1;
			--v_e1;
		}
		else if (v_e1 == 0) {
			v_r1 = 0;
		}

		if (v_r1 == 0) { 
			++v_e1;
		}
		else if (v_r1 == 1) { 
			--v_e1;
		}
	}
}

void p_enemy_cars (void) __nonbanked
{
	if (v_lvl == 1) {
		v_carX1 -= 8;
		v_carX2 += 8;
		if (v_carX1 > 8) move_sprite (2, v_carX1, v_carY1);
		else v_carX1 = 152;
		if (v_carX2 < 160) move_sprite (3, v_carX2, v_carY2);
		else v_carX2 = 8;
	}
}

void p_enemy_owner (void) __nonbanked
{
	if (v_lvl == 2) {
		if (v_r1 == 1) {
			v_ownerX1 -= 8;
			if (v_ownerX1 == 104) v_r1 = 0;
		}
		else {
			v_ownerX1 += 8;
			if (v_ownerX1 == 136) v_r1 = 1;
		}
	}
	else if (v_lvl == 3) {
		if (v_r1 == 1) {
			if (v_ownerX1 == 32) v_r1 = 0;
			else v_ownerX1 -= 8;
			
		}
		else {
			if (v_ownerX1 == 64) v_r1 = 1;
			else v_ownerX1 += 8;
		}
	}
	else if (v_lvl == 4) {
		if (v_r1 == 1) {
			if (v_ownerX1 == 120) v_r1 = 0;
			else v_ownerX1 -= 8;
			
		}
		else {
			if (v_ownerX1 == 136) v_r1 = 1;
			else v_ownerX1 += 8;
		}
	}

	if (v_lvl > 1) move_sprite (4, v_ownerX1, v_ownerY1);
}

void p_enemy_drone (void) __nonbanked
{
	if (v_lvl == 2) {
		if ((v_r2 == 1) || (v_r3 == 1)) {

			if (v_droneX1 == 120) v_r2 = 0;
			if (v_droneX2 == 104) v_r3 = 0;
			if (v_r2 == 1) v_droneX1 += 8; 
			if (v_r3 == 1) v_droneX2 += 8;
			
		}
		if ((v_r2 == 0) || (v_r3 == 0)) {
			if (v_r2 == 0) v_droneX1 -= 8; 
			if (v_r3 == 0) v_droneX2 -= 8;
			if (v_droneX1 == 40) v_r2 = 1;
			if (v_droneX2 == 48) v_r3 = 1;
		}

	}
	else if (v_lvl == 3) {
		if ((v_r2 == 1) || (v_r3 == 1)) {
			if (v_r2 == 1) v_droneX1 += 8; 
			if (v_r3 == 1) v_droneX2 -= 8;
			if (v_droneX1 == 128) v_r2 = 0;
			if (v_droneX2 == 16) v_r3 = 0;
		}
		if ((v_r2 == 0) || (v_r3 == 0)) {
			if (v_r2 == 0) v_droneX1 -= 8; 
			if (v_r3 == 0) v_droneX2 += 8;
			if (v_droneX1 == 40) v_r2 = 1;
			if (v_droneX2 == 80) v_r3 = 1;
		}		
	}
	else if (v_lvl == 4) {
		if ((v_r2 == 1) || (v_r3 == 1)) {
			if (v_r2 == 1) v_droneX1 -= 8; 
			if (v_r3 == 1) v_droneX2 += 8;
			if (v_droneX1 == 80) v_r2 = 0;
			if (v_droneX2 == 136) v_r3 = 0;
		}
		if ((v_r2 == 0) || (v_r3 == 0)) {
			if (v_r2 == 0) v_droneX1 += 8; 
			if (v_r3 == 0) v_droneX2 -= 8;
			if (v_droneX1 == 144) v_r2 = 1;
			if (v_droneX2 == 88) v_r3 = 1;
		}			
	}
	if (v_lvl > 1) {
		move_sprite (5, v_droneX1, v_droneY1);
		move_sprite (6, v_droneX2, v_droneY2);
	}
}
