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

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "globals.h"

extern void p_enemy_init (void) __nonbanked;
extern void p_enemy_initDog (void) __nonbanked;
extern void p_engine_uninitDog (void) __nonbanked;
extern void p_enemy_initCars (void) __nonbanked;
extern void p_enemy_uninitCars (void) __nonbanked;
extern void p_enemy_initOwner (void)__nonbanked;
extern void p_enemy_initDrone (void) __nonbanked;
extern void p_enemy_uninitOwner (void) __nonbanked;
extern void p_enemy_uninitDrone (void) __nonbanked;
extern void p_enemy_dog (void) __nonbanked;
extern void p_enemy_cars (void) __nonbanked __nonbanked;
extern void p_enemy_owner (void) __nonbanked;
extern void p_enemy_drone (void) __nonbanked;

#endif
