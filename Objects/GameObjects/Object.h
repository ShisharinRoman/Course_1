/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Object.h                                              */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classObject                      */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\System\\GraphicSystem.h"

/* classObject                                 */
/***********************************************/
/* classObject - ������������ �����, �������   */
/* �������� �� ����� ������������ � ���������  */
/* ������� �������.                            */
/***********************************************/
class classObject {
private:

	/* CreateSprite() - �������� �������. */
	void CreateSprite(const char* _NameImage, int _Priority);

protected:

	void* vIdList; // ��������� �� ��������� �������� ������� ��������

	struct structHitMask { // ������������� ��������� �������������� � ������� ���������
		int Length;
		int Height;

	} HitMask;

	sf::Texture Texture;
	sf::Sprite Sprite;

	/* classObject() - ����������� ������, ������� ��������� ��������:   */
	/* �����,������ �������, ���������� �������, ���� � �������� ������� */
	/* ��������� ��������� �������, �����,������ ������� � ������� �     */
	/* ��������� �� structIdList.                                        */
	classObject(int _Length, int _Height, structPoint _Coordinate, const char* _TextureName, int _Priority, int _LengthSprite, int _HeghtSprite, void* _IdList);

	/* PlayerTouchObject() - ���� ������, �������   */
	/* ��������� �� ������������ ������ � ��������. */
	bool PlayerTouchObject();

public:

	structPoint Coordinate; // ���������� �������

	structPoint CoordinateSprite; // ����������, ��� ����� �������������� ������ �������

	/* ~classObject() - ���������� ������. */
	~classObject();

};