/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Location.h                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classLocation                    */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"Level\\Wall\\Wall.h"
#include"ObjInformation.h"

/* classLocation                               */
/***********************************************/
/* classLocation - �����, ������� �������� �   */
/* �������� �� ������� classLevel.             */
/***********************************************/
class classLocation {

private:

	const char* TextureName; // ���� � ������� �������� ������

	structPoint PlayerLevelCoordinate; // ���������� ������ �� ����� ������

	void* vIdList; // ��������� �� ��������� �������� �������

	void** ActiveObjectList;
	int NumberActiveObject;

	sf::Texture Texture; // ��������

	/*       ���������� �� �������        */
	/**************************************/
	structWall* WallList; // ������ ����
	int NumberWall; // ���-�� ����
	float* EnemyCounter; // ���������� "������������"
	structPoint RoomCoordinate; // ���������� �������
	int RoomType; // ��� �������
	structObjInformation* ObjList;
	int ObjNumber;
	/**************************************/

	/* UpdateLocation() - ����� ������, ������� �������� */
	/* ���������� �� ������� �� �����������.             */
	void UpdateLocation(structPoint Coordinate);

	/* CreateObjects() - ����� ������, ������� �������   */
	/* ������� ����������� � �������.                    */
	void CreateObjects();

	/* DeleteObjects() - ����� ������, ������� �������   */
	/* ������� ����������� � �������.                    */
	void DeleteObjects();

public:

	/* classLocation() - ����������� ������, �������     */
	/* ��������� ��������: ��������� �� �����, ��������  */
	/* ������� ��������, � ���� � ��������.              */
	classLocation(void* _IdList, const char* TextureName);

	/* CanObjectMoveToPoint() - ����� ������, �������    */
	/* ��������� ����� ������ ������������� � ��������   */
	/*  �����.                                           */
	/* ObjPoint1 - ����� ������� ���� �������.           */
	/* ObjPoint2 - ������ ������ ���� �������.           */
	int CanObjectMoveToPoint(structPoint ObjPoint1,structPoint ObjPoint2);

	/* MovingToAnotherRoom() - ����� ������, �������     */
	/* ���������� ������ � ������ ������� �� ����������� */
	/* Direction.                                        */
	void MovingToAnotherRoom(char Direction);

	/* LiveObjects() - ����� ������, ������� ���������   */
	/* ������� ����������� � �������.                    */
	void LiveObjects();

	/* SpawnPlayer() - ����� ������, ������� �������     */
	/* ������ � �������� �����������.                    */
	void SpawnPlayer(structPoint SpawnPoint);

	/* getRoomType() - ����� ������, ������� ����������  */
	/* ��� �������.                                      */
	int getRoomType();

	/* UpdatePlayerCoordinate() - ����� ������, ������� */
	/* ��������� ���������� ������ �� ����� ������.     */
	void UpdatePlayerCoordinate();

	/* DrawRoom() - ����� ������, ������� ��������      */
	/* ����������, ��� ����� ����������, �������        */
	/* classGraphicalSystem.                            */
	void DrawRoom();

	/* ~classLocation() - ���������� ������.            */
	~classLocation();
};