/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: SubMenu.h                                             */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classMainMenu                    */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\System\\SystemMenu.h"

/* classSubMenu                           */
/******************************************/
/* classSubMenu - ����� ������� ��������� */
/* ������� �� ����� ����� ����.           */
/******************************************/
class classSubMenu : protected classSystemMenu {
private:

	void* vIdList; // ��������� �� classIdList

	const char* State[2]{ // ������ ��������� ���������
		"Continue",
		"Exit"
	};

	int SelectState; // ��������� ���������
	int SizeState; // ����������� ���������
	
	structPoint Coordinate; // ���������� ����

public:

	/* classSubMenu() - ����������� ������ �������   */
	/* ��������� ��������: ��������� �� classIdList. */
	classSubMenu(void* _IdList);

	/* ChangeState() - ����� ������ ������� �������� */
	/* ��������� ���������.                          */
	void ChangeState(int KeyCode);

	/* EnterState() - ����� ������ ������� ��������� */
	/* ��������� ���������.                          */
	void EnterState();

	/* Exit() - ����� ������, ������� ���������      */
	/* ����� ���� � ������� ����.                    */
	void Exit();

};
