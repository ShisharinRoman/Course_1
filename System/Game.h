/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: Game.h                                                */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classGame                        */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include<SFML/Graphics.hpp>

/* classGame                          */
/**************************************/
/* classGame - класс который является */
/* главным в управлении всей игрой.   */
/**************************************/
class classGame {
private:

	char* State;
	int Phase;
	int timer;
public:

	/* classGame() - конструктор класса */
	classGame();

	/* GameStart() - метод класса, который */
	/* запускает игру.                     */
	void GameStart();

	/* ChangeState() - метод класса, который */
	/* изменяет */
	void ChangeState(const char* _State);
};