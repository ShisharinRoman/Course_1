/* figure CourceWork.cpp                                           */
/*******************************************************************/
/* Filename: CourceWork.cpp                                        */
/* Abstract: This is a simple C++ program                          */
/* Description: Запускает игру                                     */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/


#include"System//Game.h"
#include<iostream>

int main() {
	classGame Game; // Создание игры
	Game.GameStart(); // Запуск игры
	return 0;
}