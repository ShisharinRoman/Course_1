/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: SystemMenu.h                                          */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classSystemMenu                  */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"GraphicSystem.h"

/* classSystemMenu                                */
/**************************************************/
/* classSystemMenu - ������������ ����� �������   */
/* �������� �� �������� �������� ����.            */
/**************************************************/
class classSystemMenu {
private:

	void* vIdList; // ��������� �� classIdList

	sf::Texture Texture; 

	int HeightSprite, WightSprite; // ����� � ������ �������

protected:

	sf::Sprite Sprite;

	/* classSystemMenu() - ����������� ������ ������� */
	/* ��������� ��������: ��������� �� classIdList,  */
	/* ����� � ������ �������.                        */
	classSystemMenu(void* _IdList, int _HeightSprite, int _WightSprite);

	/* ChangeState() - ����� ������ ������� �������� */
	/* ��������� ���������.                          */
	void ChangeState(int KeyCode, int& SelectState);

	/* DrawSprite() - ����� ������ �������������     */
	/* �������.                                      */
	void DrawSprite(structPoint* Coordinate, const char* _TextureName);

	/* ~classSystemMenu() - ���������� ������. */
	~classSystemMenu();
};
