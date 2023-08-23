/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Player.cpp                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������� ������ classPlayer              */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"Player.h"
#include"..\\..\\..\\..\\System\\KeyCodes.h"
#include"..\\..\\..\\..\\LevelSystem\\Location.h"
#define MaxSpeed 13

classPlayer::classPlayer(structPoint _Coordinate, void* _IdList) :
	classLiveObject(true, 3, 30, 30, _Coordinate, "images\\Player\\Player.png", 2, 30, 30, _IdList) {
	return;
}

void classPlayer::SetSpeed(int Action, float* Speed) {
	switch (Action) {
	case 0: // ����������
		if (abs(*Speed) > 0.5) {
			*Speed -= (*Speed / abs(*Speed));
		}
		break;
	case 1: // ��������� �� ������������ ���� ��� ������
		if (*Speed < 0) { // ���� �������� ���� �� � �� �������
			*Speed += 4;
		}
		else {
			if (*Speed < MaxSpeed) { // ����������� ��������
				*Speed += 3;
			}
			else {
				*Speed = MaxSpeed;
			}
		}
		break;
	case 2: // ��������� �� ������������ ����� � �����
		if (*Speed > 0) { // ���� �������� ���� �� � �� �������
			*Speed -= 4;
		}
		else {
			if (*Speed > -MaxSpeed) { // ����������� ��������
				*Speed -= 2;
			}
			else {
				*Speed = -MaxSpeed;
			}
		}
		break;
	}
	return;
}

void classPlayer::MoveSystem(int KeyCode) {
	switch (KeyCode) {
	case 0: // ��������� ��������
		SetSpeed(0, &hspeed);
		SetSpeed(0, &vspeed);
		break;
	case VK_UP: // �������� ����� (�������������� �������� ����������)
		hspeed = 0;
		SetSpeed(2, &vspeed);
		break;
	case VK_DOWN: // �������� ���� (�������������� �������� ����������)
		hspeed = 0;
		SetSpeed(1, &vspeed);
		break;
	case VK_LEFT: // �������� ����� (������������ �������� ����������)
		SetSpeed(2, &hspeed);
		vspeed = 0;
		break;
	case VK_RIGHT: // �������� ������ (������������ �������� �����������)
		SetSpeed(1, &hspeed);
		vspeed = 0;
		break;
	}
	Move(); // ������ ��������
	system("cls");
	return;
}

classPlayer::~classPlayer() {
	return;
}