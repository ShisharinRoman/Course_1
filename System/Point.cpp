/* figure CourceWork.cpp                                           */
/*******************************************************************/
/* Filename: Point.cpp                                             */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов стуруктуры structPoint          */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"Point.h"

structPoint::structPoint(int _X, int _Y) {
	X = _X;
	Y = _Y;
	return;
}

bool operator!=(const structPoint& Point1, const structPoint& Point2) {
	return ((Point1.X != Point2.X) && (Point1.Y != Point2.Y));
}

bool operator==(const structPoint& Point1, const structPoint& Point2) {
	return ((Point1.X == Point2.X) && (Point1.Y == Point2.Y));
}