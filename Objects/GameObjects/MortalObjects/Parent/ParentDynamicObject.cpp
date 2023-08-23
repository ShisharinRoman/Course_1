/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: LiveObject.cpp                                        */
/* Abstract: This is a simple C++ program                          */
/* Description:  ���������� ������� ������                         */
/* classParentDynamicObject                                        */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include<cmath>
#include"ParentDynamicObject.h"
#include"..\\..\\..\\..\\LevelSystem\\Location.h"
#include"..\\..\\..\\..\\System\\IdList.h"

void classLiveObject::RotationSprite() {
	
	if (abs(int(vspeed)) >= abs(int(hspeed))) {
		if (int(vspeed) >= 0) {
			Rotation = 3; // ������� ������� ����
		}
		else {
			Rotation = 1; // ������� ������� �����
		}
	}
	else {
		if (int(hspeed) > 0) {
			Rotation = 0; // ������� ������� �������
		}
		else {
			Rotation = 2; // ������� ������� �����
		}
	}
	Sprite.setTextureRect(sf::IntRect(1, 1 + 37 * Rotation, HitMask.Length, HitMask.Height));

	return;
}

void classLiveObject::Move() {

	CheckMove();
	RotationSprite();

	/* ��������� ��������� � ����������� �� �������� */
	/*************************************************/
	Coordinate.X = Coordinate.X + int(hspeed);
	Coordinate.Y = Coordinate.Y + int(vspeed);
	CoordinateSprite.X = Coordinate.X - (HitMask.Length / 2);
	CoordinateSprite.Y = Coordinate.Y - (HitMask.Height / 2);
	/*************************************************/

	Sprite.setPosition(float(Coordinate.X), float(Coordinate.Y));

	if (Player) { // ������ ��� ������� ����������� �������
		classIdList* IdList = static_cast<classIdList*>(vIdList);
		classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());
		(*IdLocation).UpdatePlayerCoordinate(); // ���������� ���������� ������ �� ����� ������
	}

	return;
}

classLiveObject::classLiveObject(bool _Player, int _HP, int _Length, int _Height, structPoint _Coordinate, const char* _NameImage, int _Priority , int _LengthSprite, int _HeightSprite,void* _IdList) :
	classObject(_Length, _Height, _Coordinate, _NameImage,_Priority, _LengthSprite, _HeightSprite, _IdList) {
	HP = _HP;
	HitMask.Length = _Length;
	HitMask.Height = _Height;
	Player = _Player;
	hspeed = 0;
	vspeed = 0;
	Rotation = 0;
	return;
}

void classLiveObject::CheckMove() {
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());

	/* ���������� ��� �������� ������������� ������������ */
	/******************************************************/
	structPoint ObjPoint1;
	structPoint ObjPoint2;
	/******************************************************/

	int CanObjectMove = false; 
	bool Transition = false; // �������� ������� � ������ �������

	bool AllBreak = false;

	/* �������� �������� ��� �������������� �������� */
	/*************************************************/
	while (hspeed != 0) { 

		/* �������� ����� �������������� � ������� ���������� ������ */
		/* � ������� ����� ������������.                             */
		/*************************************************************/
		ObjPoint1.X = Coordinate.X - (HitMask.Length / 2) + ceil(hspeed);
		ObjPoint1.Y = Coordinate.Y - (HitMask.Height / 2);
		ObjPoint2.X = Coordinate.X + (HitMask.Length / 2) + ceil(hspeed);
		ObjPoint2.Y = Coordinate.Y + (HitMask.Height / 2);
		/*************************************************************/

		CanObjectMove = (*IdLocation).CanObjectMoveToPoint(ObjPoint1, ObjPoint2); // �������� �� ������������ �� ������
		if (CanObjectMove != 2) { // ���� ������ �� �����
			if (CanObjectMove == 1) { // ���� ����� ������������ �������� ������
				vspeed = 0;
				hspeed = 0;
				AllBreak = true;
				Transition = true;
			}
			break;
		}
		hspeed -= (hspeed / abs(hspeed)); // � ������ �������, �������������� �������� ����� ���������� �����������
	}
	/*************************************************/

	if (AllBreak == false) { // ���� ������� ��������, �� ������ ����� ����� ����������

		/* �������� �������� ��� ������������ �������� */
		/*************************************************/
		while (vspeed != 0) {

			/* �������� ����� �������������� � ������� ���������� ������ */
			/* � ������� ����� ������������.                             */
			/*************************************************************/
			ObjPoint1.X = Coordinate.X - (HitMask.Length / 2);
			ObjPoint1.Y = Coordinate.Y - (HitMask.Height / 2) + ceil(vspeed);
			ObjPoint2.X = Coordinate.X + (HitMask.Length / 2);
			ObjPoint2.Y = Coordinate.Y + (HitMask.Height / 2) + ceil(vspeed);
			/*************************************************************/

			CanObjectMove = (*IdLocation).CanObjectMoveToPoint(ObjPoint1, ObjPoint2); // �������� �� ������������ �� ������
			if (CanObjectMove != 2) { // ���� ������ �� �����
				if (CanObjectMove == 1) { // ���� ����� ������������ �������� ������
					vspeed = 0;
					hspeed = 0;
					Transition = true;
				}
				break;
			}
			vspeed -= (vspeed / abs(vspeed)); // � ������ �������, ������������ �������� ����� ���������� �����������
		}
	}

	/* ������� ������ � ������ ������        */
	/* ����������� ���� ����� �����          */
	/* ������������� �� ���� ��������        */
	/* ��������� ������ � "����������"       */
	/* ��������� ������� (������� ��������   */
	/* ���������� ������ � ����� ����������� */
	/* �������� �����).                      */
	/*****************************************/
	if ((Transition) && (Player)) {
		switch ((*IdLocation).getRoomType()) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			if (Coordinate.Y < 90) {
				(*IdLocation).MovingToAnotherRoom('u');
				break;
			}
			if (Coordinate.Y > 400) {
				(*IdLocation).MovingToAnotherRoom('d');
				break;
			}
			if (Coordinate.X < 80) {
				(*IdLocation).MovingToAnotherRoom('l');
				break;
			}
			if (Coordinate.X > 560) {
				(*IdLocation).MovingToAnotherRoom('r');
				break;
			}
			break;
		case 6:
			if (Coordinate.Y < 80) {
				(*IdLocation).MovingToAnotherRoom('u');
				break;
			}
			if (Coordinate.Y > 880) {
				(*IdLocation).MovingToAnotherRoom('d');
				break;
			}
			if (Coordinate.X < 80) {
				(*IdLocation).MovingToAnotherRoom('l');
				break;
			}
			if (Coordinate.X > 560) {
				(*IdLocation).MovingToAnotherRoom('r');
				break;
			}
			break;
		case 7:
			if (Coordinate.Y < 80) {
				(*IdLocation).MovingToAnotherRoom('u');
				break;
			}
			if (Coordinate.Y > 400) {
				(*IdLocation).MovingToAnotherRoom('d');
				break;
			}
			if (Coordinate.X < 80) {
				(*IdLocation).MovingToAnotherRoom('l');
				break;
			}
			if (Coordinate.X > 1200) {
				(*IdLocation).MovingToAnotherRoom('r');
				break;
			}
			break;
		case 8:
			if (Coordinate.Y < 80) {
				(*IdLocation).MovingToAnotherRoom('u');
				break;
			}
			if (((Coordinate.X < 640) && (Coordinate.Y > 880)) || ((Coordinate.X > 640) && (Coordinate.Y > 400))) {
				(*IdLocation).MovingToAnotherRoom('d');
				break;
			}
			if (Coordinate.X < 80) {
				(*IdLocation).MovingToAnotherRoom('l');
				break;
			}
			if (((Coordinate.Y < 480) && (Coordinate.X > 1200)) || ((Coordinate.Y > 480) && (Coordinate.X > 560))) {
				(*IdLocation).MovingToAnotherRoom('r');
				break;
			}
			break;
		case 9:
			if (((Coordinate.X < 640) && (Coordinate.Y < 80)) || ((Coordinate.X > 640) && (Coordinate.Y < 680))) {
				(*IdLocation).MovingToAnotherRoom('u');
				break;
			}
			if (Coordinate.Y > 880) {
				(*IdLocation).MovingToAnotherRoom('d');
				break;
			}
			if (Coordinate.X < 80) {
				(*IdLocation).MovingToAnotherRoom('l');
				break;
			}
			if (((Coordinate.Y < 480) && (Coordinate.X > 560)) || ((Coordinate.Y > 480) && (Coordinate.X > 1190))) {
				(*IdLocation).MovingToAnotherRoom('r');
				break;
			}
			break;
		case 10:
			if (Coordinate.Y < 90) {
				(*IdLocation).MovingToAnotherRoom('u');
				break;
			}
			if (((Coordinate.X < 640) && (Coordinate.Y > 400)) || ((Coordinate.X > 640) && (Coordinate.Y > 870))) {
				(*IdLocation).MovingToAnotherRoom('d');
				break;
			}
			if (((Coordinate.Y < 480) && (Coordinate.X < 80)) || ((Coordinate.Y > 480) && (Coordinate.X < 720))) {
				(*IdLocation).MovingToAnotherRoom('l');
				break;
			}
			if (Coordinate.X > 1200) {
				(*IdLocation).MovingToAnotherRoom('r');
				break;
			}
			break;
		case 11:
			if (((Coordinate.X > 0) && (Coordinate.Y < 80)) || ((Coordinate.X < 0) && (Coordinate.Y < 570))) {
				(*IdLocation).MovingToAnotherRoom('u');
				break;
			}
			if (Coordinate.Y > 880) {
				(*IdLocation).MovingToAnotherRoom('d');
				break;
			}
			if (((Coordinate.Y < 480) && (Coordinate.X < 80)) || ((Coordinate.Y > 480) && (Coordinate.X < -550))) {
				(*IdLocation).MovingToAnotherRoom('l');
				break;
			}
			if (Coordinate.X > 560) {
				(*IdLocation).MovingToAnotherRoom('r');
				break;
			}
			break;
		case 12:
			if (Coordinate.Y < 80) {
				(*IdLocation).MovingToAnotherRoom('u');
				break;
			}
			if (Coordinate.Y > 880) {
				(*IdLocation).MovingToAnotherRoom('d');
				break;
			}
			if (Coordinate.X < 80) {
				(*IdLocation).MovingToAnotherRoom('l');
				break;
			}
			if (Coordinate.X > 1200) {
				(*IdLocation).MovingToAnotherRoom('r');
				break;
			}
			break;
		}

	}
	/****************************************/
	return;
}

int classLiveObject::getHspeed() {
	return int(hspeed);
}

int classLiveObject::getVspeed() {
	return int(vspeed);
}