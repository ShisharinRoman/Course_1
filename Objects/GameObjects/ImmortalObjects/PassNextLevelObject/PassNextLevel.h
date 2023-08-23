/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: PassNextLevel.h                                       */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classPassNextLevel               */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\Parent\\StaticObject.h"

/* classPassNextLevel                            */
/*************************************************/
/* classPassNextLevel - �����, ������� ��������� */
/* �������� �������� �� ����� �������.           */
/*************************************************/
class classPassNextLevel : protected classStaticObject {
public:

	/* classPassNextLevel - ����������� ������, ������� */
	/* ��������� ��������: ��������� �� classIdList  �  */
	/* ���������� ������ ����������.                    */
	classPassNextLevel(void* _IdList, structPoint _Coordinate);

	/* ObjectBehavior() - ����� ������, ���������� */
	/* �� "���������" �������.                     */
	virtual void ObjectBehavior();

};