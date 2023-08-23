/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: StaticObject.cpp                                      */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classStaticObject        */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"..\\..\\..\\..\\System\\IdList.h"
#include"..\\..\\MortalObjects\\Player\\Player.h"
#include"StaticObject.h"


classStaticObject::classStaticObject(structPoint _Coordinate, int _Length, int _Height, const char* _TextureName, int _Priority,int _LengthSprite, int _HeightSprite, void* _IdList, const char* _PhysicState, bool _CanMove) :
	classObject(_Length, _Height, _Coordinate, _TextureName, _Priority, _LengthSprite, _HeightSprite, _IdList) {
	PhysicState = _PhysicState;
	CanMove = _CanMove;
	return;
}

void classStaticObject::Move() {
	Coordinate.X = Coordinate.X + hspeed;
	Coordinate.Y = Coordinate.Y + vspeed;
	return;
}


