/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: Camera.h                                              */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classCamera                      */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\..\\System\\Point.h"

/* classCamera                                */
/**********************************************/
/* classCamera - ����� ������� ���������      */
/* ������� � ����.                            */
/**********************************************/
class classCamera {
private:

	int vspeed, hspeed; // ������������ � �������������� ��������

	void* vIdList; // ��������� �� ������ IdList

	/* CameraMove() - ����� ������, �������     */
	/* �������� �� �������� ������.             */
	void CameraMove();

public:
	/* classCamera() - ����������� ������, ��������� ��������: */
	/* ��������� �� ������ IdList.                             */
	classCamera(void* IdList);

	structPoint CameraCoordinate; // ���������� ������

	void setCoordinate(structPoint _CameraCoordinate);

	/* CameraSetMove() - ����� ������, �������  */
	/* ������������ �������������� �            */
	/* �������������������� ������.             */
	void CameraSetMove();

};