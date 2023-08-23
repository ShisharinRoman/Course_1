/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: MainMenu.h                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: ќбъ€вление класса classMainMenu                    */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\System\\SystemMenu.h"

/* classMainMenu                                 */
/*************************************************/
/* classMainMenu - класс который €вл€етьс€       */
/* объектом главного меню.                       */
/*************************************************/
class classMainMenu : public classSystemMenu {
private:

	structPoint Coordinate; //  оординаты меню

	const char* State[2]{ // ћассив возможных состо€ний
	"Start",
	"Exit"
	};

	int SelectState; // ¬ыбранное состо€ние
	int SizeState; //  олличество состо€ний
	void* vIdList; // ”казатель на classIdList

public:

	/* classMainMenu() - конструктор класса который  */
	/* принимает значени€: указатель на classIdList. */
	classMainMenu(void* _IdList);

	/* ChangeState() - метод класса который измен€ет */
	/* выбранное состо€ние.                          */
	void ChangeState(int Key);

	/* EnterState() - метод класса который запускает */
	/* выбранное состо€ние.                          */
	void EnterState();

};