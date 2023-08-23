/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Wall.h                                                */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ��������� structWall                    */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\..\\System\\GraphicSystem.h"
#include"..\\..\\..\\System\\Point.h"

/* structWall                                   */
/************************************************/
/* structWall - ���������, ������� ��������     */
/* �������� �����.                              */
/************************************************/
struct structWall {

	structPoint Point1, Point2; // ���������� ������ �������� � ������� ������� ����

	bool door = false;
	bool breakable = false;

	sf::Sprite Sprite; 

	/* structWall() - ����������� ��������� */
	structWall();

	/* setSpriteInformation() - ������������, ��� ��      */
	/* ��������� ���� ����� ��������� ������. �����       */
	/* ������������ ������� �� ��������, ������ �����     */
	/* ����������� ������.                                */
	void setSpriteInformation(structPoint Point1,structPoint Point2);

	/* CreateSprite() - ����������� ����� �������� */
	void CreateSprite(sf::Texture* Texture);

};