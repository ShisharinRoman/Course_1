/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: GraphicSystem.h                                       */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classGraphicSystem               */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include<SFML/Graphics.hpp>
#include"Point.h"

/* classGraphicSystem                              */
/***************************************************/
/* classGraphicSystem - ����� ������� ��������� �� */
/* ��������� �������� �� ������.                   */
/***************************************************/
class classGraphicSystem {
private:

	/* structSpriteInformation                        */
	/**************************************************/
	/* structSpriteInformation - ��������� � �������  */
	/* ��������� ���������� � �������.                */
	/**************************************************/
	struct structSpriteInformation {
		structPoint* Coordinate; // ��������� �� ���������� �������
		sf::Sprite* Sprite;
		int Priority; // ��������� ��������� �������
		bool CameraDependent; // ������� �� ��������� ������� �� ��������� ������

		/* structSpriteInformaation() - ����������� ���������. */
		structSpriteInformation();

	} *SpriteInformation; // ������ ���������� � �������

	int Size;

	void* vIdList; // ��������� �� classIdList

	bool Sort; // ������������ �� ������ �������� �� ���������� ���������

	/* SortArray() - ����� ������, ������� ��������� */
	/* ������� �� ���������� ��������.               */
	void SortArray();

public:

	/* classGraphicSystem() - ����������� ������, ������� */
	/* ��������� ��������: ��������� �� classIdList.      */
	classGraphicSystem(void* _IdList);

	/* putSprite() - ����� ������ ������� ��������� ������ � ������ */
	void putSprite(sf::Sprite* _IdSprite, structPoint* _CoordinateSprite, int _Priority = 0, bool _CameraDependent = true);

	/* putSpriteArray() - ����� ������ ������ ��������� ������ */
	/* �������� � ������.                                      */
	void putSpriteArray(sf::Sprite** _IdSpriteArray, structPoint** _CoordinateSpriteArray, int _Size, int _Prioryte = 0, bool _CameraDependent = true);

	/* deleteSprite() - ����� ������ ������� ������� ������ */
	/* �� �������.                                          */
	void deleteSprite(sf::Sprite* _IdSprite);

	/* deleteSpriteArray() - ����� ������, ������� ������� */
	/* ������ �������� �� �������.                         */
	void deleteSpriteArray(sf::Sprite* _IdSprite, int Size);

	/* DrawTextures() - ����� ������, ������� ������       */
	/* �������.                                            */
	void DrawTextures();

};