/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: StaticObject.cpp                                      */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classStaticObject                */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\Object.h"

class classStaticObject : public classObject {
private:

	const char* PhysicState; // ���������� ��������� ������� (�� �����������)

	bool CanMove; // ����� �� ������ ���������

	int vspeed, hspeed; // ������������ � �������������� ��������

protected:

	/* classStaticObject() - ����������� ������, ������� ��������� */
	/* ��������: ���������� �������, ����� � ������� �������, ���� */
	/* � �������� �������, ��������� ��������� �������, ����� �    */
	/* ������ ������� �������, ��������� �� classIdList,           */
	/* ���������� ��������� �������, ������� ������ ���������.     */
	classStaticObject(structPoint _Coordinate, int _Length, int _Height, const char* _TextureName, int _Priority, int _LengthSprite, int _HeightSprite, void* _IdList, const char* _PhysicState, bool _CanMove);

	/* Move() - ����� ������, ������� ����������� */
	/* ������.                                    */
	void Move();

};
