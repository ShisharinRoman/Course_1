/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: classControlSystem.h                                  */
/* Abstract: This is a simple C++ program                          */
/* Description: ќбъ€вление класса classControlSystem               */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once

/* classControlSystem                           */
/************************************************/
/* classControlSystem - класс, который €вл€етс€ */
/* системой управлени€ ввода с клавиатуры.      */
/********************************************** */
class classControlSystem {
private:

	void* vIdList; // ”казатель на класс IdList 
	int KeyCode; // ѕеременна€ принимающа€ код клавиши
	const char* Phase; //
	bool ArrowPressed; // ѕеременна€ отвечающа€ за нажатие стрелок

	/* ObjectControl() - метод класса, который */
	/* передает управление объектам.           */
	void ObjectControl();

public:
	/* classControlSystem() - конструктор класса, который */
	/* принимает значени€: указатель на класс IdList      */
	classControlSystem(void* _IdList);

	/* KeyboardInput() - метод класса, который */
	/* принимает ввод с клавиатуры.            */
	void KeyboardInput();

	void setPhase(const char* _Phase);
};