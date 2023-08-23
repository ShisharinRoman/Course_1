/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: StaticObject.cpp                                      */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classStaticObject                */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\Object.h"

class classStaticObject : public classObject {
private:

	const char* PhysicState; // Физическое состояние объекта (Не реализовано)

	bool CanMove; // Может ли объект двигаться

	int vspeed, hspeed; // Вертикальная и горизонтальная скорость

protected:

	/* classStaticObject() - конструктор класса, который принимает */
	/* значения: координаты объекта, длина и шириниа объекта, путь */
	/* к текстуре объекта, приоритет отрисовки спрайта, длина и    */
	/* ширина спрайта объекта, указатель на classIdList,           */
	/* физическое состояние объекта, можетли объект двигаться.     */
	classStaticObject(structPoint _Coordinate, int _Length, int _Height, const char* _TextureName, int _Priority, int _LengthSprite, int _HeightSprite, void* _IdList, const char* _PhysicState, bool _CanMove);

	/* Move() - метод класса, который передвигает */
	/* объект.                                    */
	void Move();

};
