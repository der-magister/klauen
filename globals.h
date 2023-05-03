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

#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include "asm/sm83/types.h"
#include "gb/gb.h"

#define LAYER_BKG 1
#define LAYER_WIN 2

#define FALSE 0
#define TRUE 1

extern uint8_t v_lvl;						//aktuelles Level
extern uint8_t v_time;						//Spielzeit
extern unsigned char v_lvldat [252];				//beinhaltet die Leveldaten
extern unsigned char v_lvldat_2 [252];				//beinhaltet modifizierte Leveldaten
extern unsigned char v_lvldat_3 [252];
extern unsigned char v_lvldat_4 [252];
extern uint8_t v_visit_2;
extern uint8_t v_visit_3;
extern uint8_t v_visit_4;

//Spielerwerte

extern uint8_t v_paus;						//Spieler Ausdauer

//Inventar Spieler
extern uint8_t v_pgeld;						//Spieler Geld
extern uint8_t v_pdietrich;					//Spieler Anzahl Dietriche

//andere Werte Spieler
extern uint8_t v_pxk;						//Spieler X-Koordinate
extern uint8_t v_pyk;						//Spieler Y-Koordinate
extern uint8_t v_pmk;						//Spieler Kartekoordinate
extern uint8_t v_pschleich;

extern uint8_t v_movetimer;					//Timer für Spielerbewegung
extern uint8_t v_enemytimer;
extern uint8_t v_schleichtimer;
extern uint8_t v_ausdauertimer;
extern uint8_t v_timetimer;

extern uint8_t v_gameover;
extern uint8_t v_walk;
extern unsigned char v_tile [1];

//Umgebungswerte
extern uint8_t v_tuer [3];
extern uint8_t v_truhen [6];
extern uint8_t v_dietrich [4];
extern uint8_t v_schalter [4];

extern uint8_t v_e1;
extern uint8_t v_r1;
extern uint8_t v_r2;
extern uint8_t v_r3;

extern uint8_t v_dogXK;
extern uint8_t v_dogYK;
extern uint8_t v_carX1;
extern uint8_t v_carX2;
extern uint8_t v_carY1;
extern uint8_t v_carY2;
extern uint8_t v_ownerX1;
extern uint8_t v_ownerY1;
extern uint8_t v_droneX1;
extern uint8_t v_droneY1;
extern uint8_t v_droneX2;
extern uint8_t v_droneY2;

#endif
