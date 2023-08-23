/* figure CourceWork.cpp                                           */
/*******************************************************************/
/* Filename: Point.h                                               */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление структуры structPoint                   */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once

/* structPoint                    */
/**********************************/
/* structPoint - структура точки. */
/**********************************/
struct structPoint {

	/* Координаты точки */
	/********************/
	int X;
	int Y;
	/********************/

	/* structPoint() - конструктор принимающий */
	/* значения: координаты точки.             */
	structPoint(int _X = 0, int _Y = 0);

	/* Функиции сравнения точки с другими точками.                            */
	/**************************************************************************/
	friend bool operator!=(const structPoint& Point1,const structPoint& Point2);
	friend bool operator==(const structPoint& Point1, const structPoint& Point2);
	/**************************************************************************/

};