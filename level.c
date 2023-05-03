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

#include "level.h"
#include "environment.h"
#include "text.h"
#include "gui.h"
#include "engine.h"
#include "enemy.h"

#include "daten/txt/shields/shieldtxt.h"
#include "daten/txt/other/othertxt.h"

#include "daten/lvl/lvldat.h"

void p_lvlcontrol_init (void) __nonbanked
{
	v_lvl = 1; v_visit_2 = 0; v_visit_3 = 0; v_visit_4 = 0; 
}

void p_lvlcontrol_whichLVL (void) __nonbanked
{
	if (v_lvl == 1) p_lvl_1 ();
	else if (v_lvl == 2) p_lvl_2 ();
	else if (v_lvl == 3) p_lvl_3 ();
	else if (v_lvl == 4) p_lvl_4 ();
}

void p_lvlcontrol_changeLVL1 (void) __nonbanked
{
	HIDE_SPRITES;
	HIDE_BKG;
	p_engine_saveMap (v_lvl);
	p_engine_loadMap (mainmap);
	p_enemy_uninitOwner ();
	p_enemy_uninitDrone ();
	set_bkg_tiles (1, 1, 18, 14, v_lvldat);
	p_enemy_init ();
}

void p_lvl_1 (void) __nonbanked
{
	p_environment_shild (93, schild1);
	p_environment_shild (118, schild2);
	p_environment_shild (122, schild3);

	p_environment_dietrich (74, 0);
	p_environment_dietrich (53, 1);
	p_environment_dietrich (84, 2);

	p_environment_geld (72, 3);

	if (v_pmk == 56) {
		if ((v_tuer [0] == 0) && (v_pdietrich == 0)){
			p_text_showTXT (tuerzu);
			p_text_hideTXT ();
		}
		else if (((v_tuer [0] == 0) && (v_pdietrich > 0)) ||
			  (v_tuer [0] == 1)) {

			if (v_tuer [0] == 0) --v_pdietrich;

			v_tuer [0] = 1;

			p_gui_showDietrich ();
			p_engine_uninitDog ();
			p_enemy_uninitCars ();

			if (v_visit_2 == 0) {
				p_engine_loadMap (house1);
				v_visit_2 = 1;
			}
			else if (v_visit_2 == 1) {

				p_engine_loadSavedMap (2);

			}

			set_bkg_tiles (1, 1, 18, 14, v_lvldat);
			p_engine_changeLvl (2, 80, 128); 
			p_enemy_initOwner ();
			p_enemy_initDrone ();
		}
	}
	else if (v_pmk == 80) {
		if ((v_tuer [1] == 0) && (v_pdietrich == 0)){
			p_text_showTXT (tuerzu);
			p_text_hideTXT ();
		}
		else if (((v_tuer [1] == 0) && (v_pdietrich > 0)) ||
			  (v_tuer [1] == 1)) {

			if (v_tuer [1] == 0) --v_pdietrich;

			v_tuer [1] = 1; 
			
			p_gui_showDietrich ();
			p_engine_uninitDog ();
			p_enemy_uninitCars ();

			if (v_visit_3 == 0) {
				p_engine_loadMap (house2);
				v_visit_3 = 1;
			}
			else if (v_visit_3 == 1) {

				p_engine_loadSavedMap (3);
			}
			set_bkg_tiles (1, 1, 18, 14, v_lvldat);
			p_engine_changeLvl (3, 80, 128); 
			p_enemy_initOwner ();
			p_enemy_initDrone ();
		}
	}
	else if (v_pmk == 87) {
		if ((v_tuer [2] == 0) && (v_pdietrich == 0)){
			p_text_showTXT (tuerzu);
			p_text_hideTXT ();
		}
		else if (((v_tuer [2] == 0) && (v_pdietrich > 0)) ||
		          (v_tuer [2] == 1)) {

			if (v_tuer [2] == 0) --v_pdietrich;

			v_tuer [2] = 1;
			p_gui_showDietrich ();
			p_engine_uninitDog ();
			p_enemy_uninitCars ();

			if (v_visit_4 == 0) {
				p_engine_loadMap (house3);
				v_visit_4 = 1;
			}
			else if (v_visit_4 == 1) {
				p_engine_loadSavedMap (4);
			}
			set_bkg_tiles (1, 1, 18, 14, v_lvldat);
			p_engine_changeLvl (4, 80, 128); 
			p_enemy_initDrone ();
			p_enemy_initOwner ();
		}
	}
}

//Ablauf Haus 1
void p_lvl_2 (void) __nonbanked
{
	p_environment_truheGeld (58, 0, 5);
	p_environment_truheDietrich (87, 1);

	if (v_pmk == 242) {
		p_lvlcontrol_changeLVL1 ();
		p_engine_changeLvl (1, 32, 48);
	}
}

//Ablauf Haus 2
void p_lvl_3 (void) __nonbanked
{
	p_environment_schalter (183, 1);
	p_environment_schalter (149, 2);
	p_environment_truheGeld (187, 2, 5);
	p_environment_truheGeld (74, 3, 10);

	if (v_pmk == 242) {
		p_lvlcontrol_changeLVL1 ();
		p_engine_changeLvl (1, 80, 56);
	}
}

//Ablauf Haus 3
void p_lvl_4 (void) __nonbanked
{
	p_environment_schalter (185, 3);
	p_environment_truheGeld (33, 4, 10);

	if (v_pmk == 242) {
		p_lvlcontrol_changeLVL1 ();
		p_engine_changeLvl (1, 136, 56);
	}
}
