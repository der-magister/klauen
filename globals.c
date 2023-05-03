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

#include "globals.h"

uint8_t v_lvl;						//aktuelles Level
uint8_t v_time;						//Spielzeit
unsigned char v_lvldat [252];				//beinhaltet die Leveldaten
unsigned char v_lvldat_2 [252];				//beinhaltet modifizierte Leveldaten
unsigned char v_lvldat_3 [252];
unsigned char v_lvldat_4 [252];
uint8_t v_visit_2;
uint8_t v_visit_3;
uint8_t v_visit_4;

//Spielerwerte
uint8_t v_paus;						//Spieler Ausdauer

//Inventar Spieler
uint8_t v_pgeld;					//Spieler Geld
uint8_t v_pdietrich;					//Spieler Anzahl Dietriche

//andere Werte Spieler
uint8_t v_pxk;						//Spieler X-Koordinate
uint8_t v_pyk;						//Spieler Y-Koordinate
uint8_t v_pmk;						//Spieler Kartekoordinate
uint8_t v_pschleich;		

uint8_t v_movetimer;					//Timer für Spielerbewegung
uint8_t v_enemytimer;		
uint8_t v_schleichtimer;
uint8_t v_ausdauertimer;
uint8_t v_timetimer;
uint8_t v_gameover;
uint8_t v_walk;
unsigned char v_tile [1];

//Umgebungswerte
uint8_t v_tuer [3];
uint8_t v_truhen [6];
uint8_t v_dietrich [4];
uint8_t v_schalter [4];

uint8_t v_e1;
uint8_t v_r1;
uint8_t v_r2;
uint8_t v_r3;

uint8_t v_dogXK;
uint8_t v_dogYK;
uint8_t v_carX1;
uint8_t v_carX2;
uint8_t v_carY1;
uint8_t v_carY2;
uint8_t v_ownerX1;
uint8_t v_ownerY1;
uint8_t v_droneX1;
uint8_t v_droneY1;
uint8_t v_droneX2;
uint8_t v_droneY2;