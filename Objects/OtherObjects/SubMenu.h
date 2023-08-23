/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: SubMenu.h                                             */
/* Abstract: This is a simple C++ program                          */
/* Description: ќбъ€вление класса classMainMenu                    */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\System\\SystemMenu.h"

/* classSubMenu                           */
/******************************************/
/* classSubMenu - класс который €вл€етьс€ */
/* подменю во врем€ паузы игры.           */
/******************************************/
class classSubMenu : protected classSystemMenu {
private:

	void* vIdList; // ”казатель на classIdList

	const char* State[2]{ // ћассив возможных состо€ний
		"Continue",
		"Exit"
	};

	int SelectState; // ¬ыбранное состо€ние
	int SizeState; //  олличество состо€ний
	
	structPoint Coordinate; //  оординаты меню

public:

	/* classSubMenu() - конструктор класса который   */
	/* принимает значени€: указатель на classIdList. */
	classSubMenu(void* _IdList);

	/* ChangeState() - метод класса который измен€ет */
	/* выбранное состо€ние.                          */
	void ChangeState(int KeyCode);

	/* EnterState() - метод класса который запускает */
	/* выбранное состо€ние.                          */
	void EnterState();

	/* Exit() - метод класса, который запускает      */
	/* выход игры в главное меню.                    */
	void Exit();

};
