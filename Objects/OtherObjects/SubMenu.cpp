/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: SubMenu.cpp                                           */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classMainMenu            */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"SubMenu.h"
#include"..\\..\\System\\Game.h"
#include"..\\..\\System\\IdList.h"

void classSubMenu::ChangeState(int KeyCode) {

	classSystemMenu::ChangeState(KeyCode, SelectState);

	/* Если выбранное состояние выходит за границы */
	/***********************************************/
	if (SelectState < 0) {
		SelectState = SizeState - 1;
	}
	if (SelectState + 1 > SizeState) {
		SelectState = 0;
	}
	/***********************************************/

	Sprite.setTextureRect(sf::IntRect(2, 1 + SelectState * 166, 117, 159));
	return;
}
 
classSubMenu::classSubMenu(void* _IdList) : classSystemMenu(_IdList,117,159){
	vIdList = _IdList;
	SizeState = 2;
	SelectState = 0;
	Coordinate = structPoint(100, 100);
	DrawSprite(&Coordinate, "images\\SubMenu\\SubMenu.png");
	return;
}


void classSubMenu::EnterState() {
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classGame* IdGame = static_cast<classGame*>((*IdList).getIdGame());

	if (!strcmp(State[SelectState],"Continue")) {
		(*IdGame).ChangeState("Game"); // Изменение состояния игры
	}
	if (!strcmp(State[SelectState], "Exit")) {
		(*IdGame).ChangeState("Start"); // Изменение состояния игры
	}
	return;
}

void classSubMenu::Exit() {
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classGame* IdGame = static_cast<classGame*>((*IdList).getIdGame());
	(*IdGame).ChangeState("Game"); // Изменение состояния игры
}
