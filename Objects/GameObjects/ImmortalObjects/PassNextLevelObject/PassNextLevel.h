/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: PassNextLevel.h                                       */
/* Abstract: This is a simple C++ program                          */
/* Description: ќбъ€вление класса classPassNextLevel               */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\Parent\\StaticObject.h"

/* classPassNextLevel                            */
/*************************************************/
/* classPassNextLevel - класс, который €вл€етьс€ */
/* объектом перехода на новый уровень.           */
/*************************************************/
class classPassNextLevel : protected classStaticObject {
public:

	/* classPassNextLevel - конструктор класса, который */
	/* принимает значени€: указатель на classIdList  и  */
	/* координаты своего нахождени€.                    */
	classPassNextLevel(void* _IdList, structPoint _Coordinate);

	/* ObjectBehavior() - метод класса, отвечающий */
	/* за "поведение" объекта.                     */
	virtual void ObjectBehavior();

};