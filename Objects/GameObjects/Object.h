/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Object.h                                              */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classObject                      */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\System\\GraphicSystem.h"

/* classObject                                 */
/***********************************************/
/* classObject - родительский класс, который   */
/* отвечает за маску столкновений и отрисовки  */
/* спрайта объекта.                            */
/***********************************************/
class classObject {
private:

	/* CreateSprite() - создание спрайта. */
	void CreateSprite(const char* _NameImage, int _Priority);

protected:

	void* vIdList; // Указатель на структуру хранящую адресса объектов

	struct structHitMask { // Прямоугольная структура взаимодействия с другими объектами
		int Length;
		int Height;

	} HitMask;

	sf::Texture Texture;
	sf::Sprite Sprite;

	/* classObject() - конструктор класса, который принимает значения:   */
	/* длина,высота объекта, координаты объекта, путь к текстуре объекта */
	/* приоритет отрисовки спрайта, длина,высота спрайта у объекта и     */
	/* указатель на structIdList.                                        */
	classObject(int _Length, int _Height, structPoint _Coordinate, const char* _TextureName, int _Priority, int _LengthSprite, int _HeghtSprite, void* _IdList);

	/* PlayerTouchObject() - мето класса, который   */
	/* проверяет на столкновения игрока с объектом. */
	bool PlayerTouchObject();

public:

	structPoint Coordinate; // Координаты объекта

	structPoint CoordinateSprite; // Координаты, где будет отрисовываться спрайт объекта

	/* ~classObject() - деструктор класса. */
	~classObject();

};