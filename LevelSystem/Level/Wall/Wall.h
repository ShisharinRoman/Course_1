/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Wall.h                                                */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление структуры structWall                    */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\..\\System\\GraphicSystem.h"
#include"..\\..\\..\\System\\Point.h"

/* structWall                                   */
/************************************************/
/* structWall - структура, которая является     */
/* объектом стена.                              */
/************************************************/
struct structWall {

	structPoint Point1, Point2; // Координаты левого верхнего и нижнего правого угла

	bool door = false;
	bool breakable = false;

	sf::Sprite Sprite; 

	/* structWall() - конструктор структуры */
	structWall();

	/* setSpriteInformation() - Устанавлиает, где на      */
	/* плоскости игры будет отрисован спрайт. Также       */
	/* усанавливает область на текстуре, откуда будет     */
	/* считываться спрайт.                                */
	void setSpriteInformation(structPoint Point1,structPoint Point2);

	/* CreateSprite() - Определение файла текстуры */
	void CreateSprite(sf::Texture* Texture);

};