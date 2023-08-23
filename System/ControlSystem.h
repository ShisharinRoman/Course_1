/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: classControlSystem.h                                  */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classControlSystem               */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once

/* classControlSystem                           */
/************************************************/
/* classControlSystem - �����, ������� �������� */
/* �������� ���������� ����� � ����������.      */
/********************************************** */
class classControlSystem {
private:

	void* vIdList; // ��������� �� ����� IdList 
	int KeyCode; // ���������� ����������� ��� �������
	const char* Phase; //
	bool ArrowPressed; // ���������� ���������� �� ������� �������

	/* ObjectControl() - ����� ������, ������� */
	/* �������� ���������� ��������.           */
	void ObjectControl();

public:
	/* classControlSystem() - ����������� ������, ������� */
	/* ��������� ��������: ��������� �� ����� IdList      */
	classControlSystem(void* _IdList);

	/* KeyboardInput() - ����� ������, ������� */
	/* ��������� ���� � ����������.            */
	void KeyboardInput();

	void setPhase(const char* _Phase);
};