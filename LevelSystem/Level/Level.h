/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Level.h                                               */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classLevel                       */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/
#pragma once
#include"Wall\\Wall.h"
#include"..\\ObjInformation.h"


/* classLevel                                        */
/*****************************************************/
/* classLevel - �����, ������� ������ ��� ���������� */
/* �� ������. ����� ��������� ��������� ������       */
/*****************************************************/
class classLevel {
private:

	int NumberLevel; // ����� ������
	int RoomNumber; // ���-�� ������
	int** LevelMap; // ����� ������, ������������ ���� ������
	int** LevelMapId; // ����� ������, ������������ ������ ������ 
	int SizeHor, SizeVer; // ������� �����
	structPoint StartPos; // ���������� ��������� �������

	/* ���������� ��� �������� ����� ���������� �� ������ ������� */
	/**************************************************************/
	structWall** RoomListStructure; // ������������ ����
	int* NumberWallRoom; // ���-�� ����
	float* EnemyCounter; // ���������� "������������"
	structObjInformation** ObjList;
	int* ObjNumber;
	structPoint* RoomCoordinateList; // ���������� ������� ��� ��������-������ "��������", ���� ������� ������� �� ���������� ���������
	int* RoomTypeList; // ��� �������
	/******************************************************************/

public:
	/* classLevel() - ����������� ������.                      */
	classLevel();

	/* StartStructureGeneration() - ����� ������, �������      */
	/* �������� ������������ ��������� ������.                 */
	void StartStructureGeneration();

	/* StartRoomGeneration() - ����� ������, ������� ��������  */
	/* ������������ �������.                                   */
	void StartRoomGeneration();

	/* getRoomType() - ����� ������, ������� ���������� ���    */
	/* ������� �� ������ �������                               */
	int getRoomType(int Id);
	
	/* getRoomWall() - ����� ������, ������� ����������        */
	/* ���������� �� ������ � ������� �� ������ �������.       */
	structWall* getRoomWall(int Id);

	/* getRoomCoordinate() - ����� ������, ������� ����������  */
	/* ���������� ������� �� � ������.                        */
	structPoint getRoomCoordinate(int Id);

	/* getRoomEnemyCounter() - ����� ������, �������           */
	/* ���������� ������ �� ���������� "������������" �������  */
	/* �� � ������.                                           */
	float* getRoomEnemyCounter(int Id);

	/* getRoomNumberWall() - ����� ������, ������� ����������  */
	/* ���-�� ���� ������� �� ������ �������.                  */
	int getRoomNumberWall(int Id);

	/* getNumberRoom() - ����� ������, ������� ����������      */
	/* ����� ������� �� � �����������.                        */
	int getNumberRoom(structPoint Point);

	structObjInformation* getObjList(int Id);

	int getObjNumber(int Id);

	/* ~classLevel() - ���������� ������.                      */
	~classLevel();

};