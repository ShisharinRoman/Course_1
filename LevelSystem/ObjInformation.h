/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: ObjInformation.h                                      */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление структуры structObjInformation          */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/


#pragma once
#include"..\\System\\Point.h"

/* structObjInformation                  */
/*****************************************/
/* structObjInformation -  структура     */
/* хранящая информацию про объект,       */
/* который будет создан.                 */
/*****************************************/
struct structObjInformation {
	const char* Type; // Тип объекта
	structPoint PointSpawn; // Координаты создания
};
