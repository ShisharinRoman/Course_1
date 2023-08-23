/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: MainMenu.h                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classMainMenu                    */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\System\\SystemMenu.h"

/* classMainMenu                                 */
/*************************************************/
/* classMainMenu - ����� ������� ���������       */
/* �������� �������� ����.                       */
/*************************************************/
class classMainMenu : public classSystemMenu {
private:

	structPoint Coordinate; // ���������� ����

	const char* State[2]{ // ������ ��������� ���������
	"Start",
	"Exit"
	};

	int SelectState; // ��������� ���������
	int SizeState; // ����������� ���������
	void* vIdList; // ��������� �� classIdList

public:

	/* classMainMenu() - ����������� ������ �������  */
	/* ��������� ��������: ��������� �� classIdList. */
	classMainMenu(void* _IdList);

	/* ChangeState() - ����� ������ ������� �������� */
	/* ��������� ���������.                          */
	void ChangeState(int Key);

	/* EnterState() - ����� ������ ������� ��������� */
	/* ��������� ���������.                          */
	void EnterState();

};