/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: classLiveObject.h                                     */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classParentDynamicObject         */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once

#include"..\\..\\..\\..\\System\\GraphicSystem.h"
#include"..\\..\\Object.h"

/* classLiveObject                                    */
/******************************************************/
/* classLiveObject - ����� �������, ��������          */
/* ������������ ������� ��� "�����" �������.          */
/******************************************************/
class classLiveObject : public classObject {
private:

	int HP = 0; // �������� �������

	bool Player = false; // ������ �������� �������

	int Rotation; // ���������� ��� ��������� �������� �������

	/* RotationSprite() - ����� ������, �������  */
	/* �������� �� ������� ������� � ����������� */
	/* ����������� ��������.                     */
	void RotationSprite();

	/* CheckMove() = ����� ������, �������  */
	/* ��������� ����� �� ������������� �   */
	/* ��������� ����������.                */
	void CheckMove();

protected:

	float vspeed, hspeed; // ������������ � �������������� ��������



	/* Move() - ����� ������, ������� ���������� */
	/* �������� �������.                         */
	void Move();

public:

	/* classParentDynamicObject() - ����������� ������, ����������� ��������: */
	/* ��������� �� �������, ���-�� ��������, ����� HitMash, ������ HitMask,  */
	/* ���������� �������, ���� � �������, ��������� �� ��������� ��������    */
	/* ������� ������ ��������.                                               */
	classLiveObject(bool _Player, int _HP, int _Length, int _Height, structPoint _Coordinate,
		const char* _NameImage, int _Priority,int _SpriteLength,int _SpriteHeight, void* _IdList);

	/* getVspeed() - ����� ������, ������� ���������� */
	/* ������������ ��������.                         */
	int getVspeed();

	/* getHspeed() - ����� ������, ������� ���������� */
	/* ������������� ��������.                        */
	int getHspeed();

};
