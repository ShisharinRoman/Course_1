/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: Game.h                                                */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classGame                        */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include<SFML/Graphics.hpp>

/* classGame                          */
/**************************************/
/* classGame - ����� ������� �������� */
/* ������� � ���������� ���� �����.   */
/**************************************/
class classGame {
private:

	char* State;
	int Phase;
	int timer;
public:

	/* classGame() - ����������� ������ */
	classGame();

	/* GameStart() - ����� ������, ������� */
	/* ��������� ����.                     */
	void GameStart();

	/* ChangeState() - ����� ������, ������� */
	/* �������� */
	void ChangeState(const char* _State);
};