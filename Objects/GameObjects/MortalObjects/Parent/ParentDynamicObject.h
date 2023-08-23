/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: classLiveObject.h                                     */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classParentDynamicObject         */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once

#include"..\\..\\..\\..\\System\\GraphicSystem.h"
#include"..\\..\\Object.h"

/* classLiveObject                                    */
/******************************************************/
/* classLiveObject - класс который, является          */
/* родительским классом для "живых" объктов.          */
/******************************************************/
class classLiveObject : public classObject {
private:

	int HP = 0; // Здоровье объекта

	bool Player = false; // Объект является игроком

	int Rotation; // Переменная для изменения поворота спрайта

	/* RotationSprite() - метод класса, который  */
	/* отвечает за поворот спрайта в зависимости */
	/* направления движения.                     */
	void RotationSprite();

	/* CheckMove() = метод класса, который  */
	/* проверяет можно ли переместиться с   */
	/* имеющиеся скоростями.                */
	void CheckMove();

protected:

	float vspeed, hspeed; // Вертикальная и горизонтальная скорость



	/* Move() - метод класса, который производит */
	/* движение объекта.                         */
	void Move();

public:

	/* classParentDynamicObject() - конструктор класса, принимающий значения: */
	/* являеться ли игроком, кол-во здоровья, длина HitMash, высота HitMask,  */
	/* координаты объекта, путь к спрайту, указатель на структуру хранящую    */
	/* адресса других объектов.                                               */
	classLiveObject(bool _Player, int _HP, int _Length, int _Height, structPoint _Coordinate,
		const char* _NameImage, int _Priority,int _SpriteLength,int _SpriteHeight, void* _IdList);

	/* getVspeed() - метод класса, который возвращает */
	/* вертикальную скорость.                         */
	int getVspeed();

	/* getHspeed() - метод класса, который возвращает */
	/* горионтальную скорость.                        */
	int getHspeed();

};
