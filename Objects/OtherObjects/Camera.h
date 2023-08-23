/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: Camera.h                                              */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classCamera                      */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\System\\Point.h"

/* classCamera                                */
/**********************************************/
/* classCamera - класс который являеться      */
/* камерой в игре.                            */
/**********************************************/
class classCamera {
private:

	int vspeed, hspeed; // Вертикальная и горизонтальная скорость

	void* vIdList; // Указатель на объект IdList

	/* CameraMove() - метод класса, который     */
	/* отвечает за движение камеры.             */
	void CameraMove();

public:
	/* classCamera() - конструктор класса, принимает значения: */
	/* указатель на объект IdList.                             */
	classCamera(void* IdList);

	structPoint CameraCoordinate; // Координаты камеры

	void setCoordinate(structPoint _CameraCoordinate);

	/* CameraSetMove() - метод класса, который  */
	/* устаавливает горизонтальную и            */
	/* вертикальнуюскорость камеры.             */
	void CameraSetMove();

};