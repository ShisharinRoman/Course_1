/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Player.h                                              */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classPlayer                      */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/


#pragma once

#include"..\\Parent\\ParentDynamicObject.h"

/* classPlayer                            */
/******************************************/
/* classPlayer - �����, ������� ��������� */
/* �������.                               */
/******************************************/
class classPlayer : public classLiveObject {
private:

	/* SetSpeed() - ����� ������, ������� */
	/* �������� �� ��������� �������� �   */
	/* ����������� ���������� Action.     */
	void SetSpeed(int Action, float *Speed);

public:

	/* classPlayer() - ����������� ������, */
	/* ������� ��������� ��������:         */
	/* ���������� ��������� � ��������� �� */
	/* ����� �������� ������� ��������.    */
	classPlayer(structPoint _Coordinate, void* _IdList);

	/* MoveSystem() - ����� ������, ������� */
	/* ��������� ������������� ������.      */
	void MoveSystem(int KeyCode = 0);

};