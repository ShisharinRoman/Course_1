/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: MainMenu.cpp                                          */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������� ������ classMainMenu            */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"MainMenu.h"
#include"..\\..\\System\\Game.h"
#include"..\\..\\System\\IdList.h"

#define CLNSCR "\x1B[2J"

classMainMenu::classMainMenu(void* _IdList) : classSystemMenu(_IdList,296,87){
	SelectState = 0;
	SizeState = 2;
	vIdList = _IdList;
	Coordinate = structPoint(320 - 296 / 2, 240 - 87 / 2);
	DrawSprite(&Coordinate, "images\\MainMenu\\MainMenu.png");
	return;
}

void classMainMenu::ChangeState(int Key) {

	classSystemMenu::ChangeState(Key, SelectState);

	/* ���� ��������� ��������� ������� �� ������� */
	/***********************************************/
	if (SelectState + 1 > SizeState) {
		SelectState = 0;
	}
	if (SelectState < 0) {
		SelectState = SizeState - 1;
	}
	/***********************************************/

	Sprite.setTextureRect(sf::IntRect(2, 1 + SelectState * 96, 296, 87));
	return;
}

void classMainMenu::EnterState() {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classGame* GameId = static_cast<classGame*>((*IdList).getIdGame());

	if (!strcmp(State[SelectState], "Start")) {
		(*GameId).ChangeState("Game"); // ��������� ��������� ����
	}
	if (!strcmp(State[SelectState], "Exit")) {
		(*GameId).ChangeState("Exit"); // ��������� ��������� ����
	}
	
	return;
}

