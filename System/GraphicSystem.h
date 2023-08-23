/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: GraphicSystem.h                                       */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classGraphicSystem               */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include<SFML/Graphics.hpp>
#include"Point.h"

/* classGraphicSystem                              */
/***************************************************/
/* classGraphicSystem - класс который отвечаеть за */
/* отрисовку спрайтов на экране.                   */
/***************************************************/
class classGraphicSystem {
private:

	/* structSpriteInformation                        */
	/**************************************************/
	/* structSpriteInformation - структура в которой  */
	/* храниться информация о спрайте.                */
	/**************************************************/
	struct structSpriteInformation {
		structPoint* Coordinate; // Указатель на координаты спрайта
		sf::Sprite* Sprite;
		int Priority; // Приоритет отрисовки спрайта
		bool CameraDependent; // Зависит ли отрисовка спрайта от положения камеры

		/* structSpriteInformaation() - конструктор структуры. */
		structSpriteInformation();

	} *SpriteInformation; // Массив информации о спайтах

	int Size;

	void* vIdList; // Указатель на classIdList

	bool Sort; // Отсортирован ли массив спрайтов по приоритету отрисовки

	/* SortArray() - метод класса, который сортирует */
	/* спрайты по приоритету отриовки.               */
	void SortArray();

public:

	/* classGraphicSystem() - конструктор класса, который */
	/* принимает значения: указатель на classIdList.      */
	classGraphicSystem(void* _IdList);

	/* putSprite() - метод класса который добавляет спрайт в массив */
	void putSprite(sf::Sprite* _IdSprite, structPoint* _CoordinateSprite, int _Priority = 0, bool _CameraDependent = true);

	/* putSpriteArray() - метод класса которы добавляет массив */
	/* спрайтов в массив.                                      */
	void putSpriteArray(sf::Sprite** _IdSpriteArray, structPoint** _CoordinateSpriteArray, int _Size, int _Prioryte = 0, bool _CameraDependent = true);

	/* deleteSprite() - метод класса который удаляет спрайт */
	/* из массива.                                          */
	void deleteSprite(sf::Sprite* _IdSprite);

	/* deleteSpriteArray() - метод класса, который удаляет */
	/* массив спрайтов из массива.                         */
	void deleteSpriteArray(sf::Sprite* _IdSprite, int Size);

	/* DrawTextures() - метод класса, который рисует       */
	/* спрайты.                                            */
	void DrawTextures();

};