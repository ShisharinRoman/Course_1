/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Player.h                                              */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classPlayer                      */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/


#pragma once

#include"..\\Parent\\ParentDynamicObject.h"

/* classPlayer                            */
/******************************************/
/* classPlayer - класс, который являеться */
/* игроком.                               */
/******************************************/
class classPlayer : public classLiveObject {
private:

	/* SetSpeed() - метод класса, который */
	/* отвечает за изменение скорости в   */
	/* зависимости парраметра Action.     */
	void SetSpeed(int Action, float *Speed);

public:

	/* classPlayer() - конструктор класса, */
	/* который принимает значения:         */
	/* координаты появления и указатель на */
	/* класс хранящий адресса объектов.    */
	classPlayer(structPoint _Coordinate, void* _IdList);

	/* MoveSystem() - метод класса, который */
	/* управляет передвижением игрока.      */
	void MoveSystem(int KeyCode = 0);

};