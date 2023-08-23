/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: Camera.cpp                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������� ������ classCamera              */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include<cmath>
#include"Camera.h"
#include"..\\..\\System\\IdList.h"
#include"..\\..\\Objects\\GameObjects\\MortalObjects\\Player\\Player.h"
#include"..\\..\\LevelSystem\\Location.h"

classCamera::classCamera(void* IdList) {
	vIdList = IdList;
	return;
}

void classCamera::setCoordinate(structPoint _CameraCoordinate) {
	CameraCoordinate = _CameraCoordinate;

	/* ��������� ��������� */
	/***********************/
	vspeed = 0;
	hspeed = 0;
	/***********************/

	return;
}

void classCamera::CameraSetMove() {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classPlayer* IdPlayer = static_cast<classPlayer*>((*IdList).getIdPlayer());

	if (IdPlayer) { // ����� ����������
		hspeed = 0;
		vspeed = 0;

		/* ���������� ���������� �� ������ �� ������ ������ (�� ����������� */
		/* � ���������).                                                    */
		/********************************************************************/
		int DirectX = CameraCoordinate.X + 320 - (*IdPlayer).Coordinate.X;
		int DirectY = CameraCoordinate.Y + 240 - (*IdPlayer).Coordinate.Y;
		/********************************************************************/

		if ((abs(DirectX) > 65) || (abs(DirectY) > 65)) { // ���� ����� �������� �� ������ ������ 

			classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());
			int RoomType = (*IdLocation).getRoomType();
			int PlayerHspeed = (*IdPlayer).getHspeed();
			int PlayerVspeed = (*IdPlayer).getVspeed();

			/* ��������� ��������� ������ � ����������� �� ����������� */
			/* �������� ������, ���� ������� � ���������� ������ ��    */
			/* ������ �����.                                           */
			/***********************************************************/
			if ((DirectX < 0) && (RoomType > 6) && (PlayerHspeed > 0)) {
				hspeed = PlayerHspeed;
			}
			if ((DirectX > 0) && (RoomType > 6) && (PlayerHspeed < 0)) {
				hspeed = PlayerHspeed;
			}
			if ((DirectY < 0) && ((RoomType == 6) || (RoomType > 7)) && (PlayerVspeed > 0)) {
				vspeed = PlayerVspeed;
			}
			if ((DirectY > 0) && ((RoomType == 6) || (RoomType > 7)) && (PlayerVspeed < 0)) {
				vspeed = PlayerVspeed;
			}
			/***********************************************************/
		}
		CameraMove();
	}

	return;
}

void classCamera::CameraMove() {
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());
	int RoomType = (*IdLocation).getRoomType();

	if (RoomType > 5) {

		/* �������� �� ��, ��� ������ �� ������ �� */
		/* ������� ��������� ������� (����������   */
		/* ������� ������� �� ���� �������).       */
		/*******************************************/
		if (RoomType != 11) { // ����� ������� ���������� �������
			if (CameraCoordinate.X + hspeed < 0) {
				hspeed = 0;
				CameraCoordinate.X = 0;
			}
		}
		else {
			if (CameraCoordinate.X + hspeed < -640) {
				hspeed = 0;
				CameraCoordinate.X = -640;
			}
		}

		if ((RoomType != 6) && (RoomType != 11)) { // ������ ������� ���������� �������
			if (CameraCoordinate.X + 640 + hspeed > 1280) {
				hspeed = 0;
				CameraCoordinate.X = 640;
			}
		}
		else {
			if (CameraCoordinate.X + 640 + hspeed > 640) {
				hspeed = 0;
				CameraCoordinate.X = 0;
			}
		}

		if (CameraCoordinate.Y + vspeed < 0) { // ������� ������� ���������� �������
			vspeed = 0;
			CameraCoordinate.Y = 0;
		}

		if (RoomType != 7) { // ������ ������� ���������� �������
			if (CameraCoordinate.Y + 480 + vspeed > 960) {
				vspeed = 0;
				CameraCoordinate.Y = 480;
			}
		}
		else {
			if (CameraCoordinate.Y + 480 + vspeed > 480) {
				vspeed = 0;
				CameraCoordinate.Y = 0;
			}
		}
		/*****************************************/

	}

	/* ��������� ��������� ������ � ����������� �� */
	/* �� ���������.                               */
	/***********************************************/
	CameraCoordinate.X = CameraCoordinate.X + hspeed;
	CameraCoordinate.Y = CameraCoordinate.Y + vspeed;
	/***********************************************/

	return;
}

