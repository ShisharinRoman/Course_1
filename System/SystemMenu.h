/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: SystemMenu.h                                          */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classSystemMenu                  */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"GraphicSystem.h"

/* classSystemMenu                                */
/**************************************************/
/* classSystemMenu - родительский класс который   */
/* отвечает за основные действия меню.            */
/**************************************************/
class classSystemMenu {
private:

	void* vIdList; // Указатель на classIdList

	sf::Texture Texture; 

	int HeightSprite, WightSprite; // Длина и высота спрайта

protected:

	sf::Sprite Sprite;

	/* classSystemMenu() - конструктор класса который */
	/* принимает значения: указатель на classIdList,  */
	/* длина и высота спрайта.                        */
	classSystemMenu(void* _IdList, int _HeightSprite, int _WightSprite);

	/* ChangeState() - метод класса который изменяет */
	/* выбранное состояние.                          */
	void ChangeState(int KeyCode, int& SelectState);

	/* DrawSprite() - метод класса отрисовывание     */
	/* спрайта.                                      */
	void DrawSprite(structPoint* Coordinate, const char* _TextureName);

	/* ~classSystemMenu() - деструктор класса. */
	~classSystemMenu();
};
