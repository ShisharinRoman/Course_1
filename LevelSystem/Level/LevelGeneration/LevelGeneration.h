/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: LevelGeneration.h                                     */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������� classLevelStructureGenerator �  */
/* classRoomGenerator.                                             */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"..\\Wall\\Wall.h"
#include"..\\..\\ObjInformation.h"

/* classLevelStructureGenerator                         */
/*******************************************************/
/* classLevelStructureGenerator - ����� � ������� ������������ */
/* ������ ������ (�������� � ���� ������)              */
/*******************************************************/
class classLevelStructureGenerator {
private:

	/* CheckCanPlacedRoom() - ����� ������, ������� ��������� ����� ��     */
	/*  ���� ��������� ������� �� ����������� X � Y. ���� ������� �������  */ 
	/*  �� ���������� "���������", ����� ����������� ������������          */
	/*  �������� ������������ �������.                                     */
	bool CheckCanPlacedRoom(int Room, int* Pos);

	/* RoomCreate() - ����� ������, ������� ������ ������� ���������� ���� */ 
	/*�� �����������.                                                       */
	bool RoomCreate();

	/* NextPosition() - ����� ������, �������  ���������� �������� �������, */
	/* ��� ����� ����������� �������. ����� ���������� ����� �������� ��    */
	/* �������� �����, ������� ���������� �����������. ����� ����� -        */
	/* ��������� ����������.                                                */
	void NextPosition();

	/* GenerateTypeRoom() - ����� ������, ������� ��������� ��������        */ 
	/* RoomCreate() � NextPosition(), ������� ��������� ������.             */
	void GenerateTypeRoom();



	/********** ������ ��� ������ ����� **********/
	/*������� ������ "�������" ������ � �������  */
	/*********************************************/
	void IndentifySizeVer(); // ��������� ����� ������ �� ���������
	void IndentifySizeHor(); // ��������� ����� ������ �� �����������
	void CompressionMap(); // "�������" ����� ��� ����� �������
	/**********************************************/

	/* FindStartRoom() - ����� ������, ������� �������� ���������� ��������� */
	/* ������� ������.                                                       */
	void FindStartRoom();

public:

	int** LevelMap; // ����� ������, ������������ ���� ������
	int** LevelMapId; // ����� ������, ������������ ������ ������ 
	int* SizeVer; // ������ "������" ����� ������ �� ���������
	int* SizeHor; // ������ "������" ����� ������ �� �����������
	structPoint* StartPos; // ���������� ��������� �������
	int SizeMap; // ������ ������ �������
	int LevelNumber; // ����� ������
	int RandomRangeCreateBossRoom; // �������� ����������� ��������� ������� � ������
	/******* ���������� ��� �������� ������ ����� ������ ********/
	/************************************************************/
	int Center; // ���������� ��� �������� ������ ����� ( ��������� ������� )
	int LimitArtifactRoom;
	int RoomNumberNeed; // ������� ����� ��������� ������ (����������: ������� � ����������, �������, ������� � ������) 
	int LimitShopRoom;
	int LimitBossRoom;
	int NowIdRoom; // ���������� ��� �������� ������������ ������ 
	/************************************************************/

	/* ���������� ��� ������ ��������� ������� ��������� ������� */
	/*************************************************************/
	structPoint NextCoordinate; // ���������� ��������� ��������� ������� 
	int Diagonal;
	int DirCenterNext; // ���������� ������������ ���������� �� ������ ����� �� ���� �����
	char Dir; // ���������� ���������� �� ����������� ������ ����� ��� �������
	bool RoomPlaced;  // ���������� ����������, �� ������� � ������� ����� (��������� ��������� ����)
	bool BossRoomCreate;
	/*************************************************************/

	/* ���������� ��� ������ ����� */
	/*************************************************************/
	int StartVer, StartHor;
	int FinishVer, FinishHor;
	/*************************************************************/

	/* classLevelGeneralStructure - ����������� ����������� ��������: */
	/* ������ �� "������" ����� ������, ����� ������, ������ ��       */
	/* ������� ������� "������" ����� ������ � ������ �� ����������   */
	/* ������� ��������� �������.                                     */
	classLevelStructureGenerator(int Size, int LvlNumber, int* _SizeVer, int* _SizeHor, structPoint* _StartPos);

	/* GenerateStructure() - ����� ������, ������� �������� ��������� */
	/* ����� ������ � ����������� �� ���������� RandomTypeGeneration  */
	void GenerateStructure(int RandomTypeGeneration);

	/*          ������ ������������ ��������        */
	/************************************************/
	int getNumberRoom(); // ��������� ���-�� ��������� ������
	int** getLevelMap(); // ���������� ����� ������, ��� ���������� ���� ������
	int** getLevelMapId(); // ���������� ����� ������, ���� ���������� ������ ������
	/************************************************/

};


/* classRoomGenerator                                     */
/***********************************************************/
/* classRoomGenerator - ����� � ������� ������������      */
/* �������, �.�. ��������� ����, ��������� "������������", */
/* �������� �������� ���������� �� �������.                */
/***********************************************************/
class classRoomGenerator {
private:


	int** LevelMap; // ����� ������, ������������ ���� ������
	int** LevelMapId; // ����� ������, ������������ ������ ������ 
	structWall*** RoomWallList; // ���������� �� ������ � ������ ������� ������
	int** RoomTypeList; // ������ ��������
	int** NumberWallOfRoom; // ���-�� ���� � ������ �������
	float** EnemyCounter; // ���������� "������������" � ������ �������
	int SizeHor, SizeVer; // ������� �����
	structPoint* StartPos; // ���������� ��������� �������
	int RoomNumber; // ���-�� ������
	int NumberLevel; // ����� ������
	structPoint** RoomCoordinateList; // ���������� ������ ������� � ������. ���� ������� ������� �� ���������� "���������", �� ��������� �� �������-����� �������.
	structObjInformation*** ObjList;
	int** ObjNumber;

	/* CreateWall() - ����� ������, ������� ���������� ����� ���������� � �����, */
	/* �.� "�������" �����.                                                      */
	void CreateWall(structPoint Point1, structPoint Point2, structWall* RoomWallSystem, bool door, bool breakable,
		structPoint Point);

	/* RoomStartSettings() - ����� ������, ������� ���������� ����� ���������� �� */
	/* �������.                                                                   */
	void RoomStartSettings();

	/* getRoomType() - ����� ������, ������� ���������� ��� ������� �� � */
	/* ������.                                                            */
	int getRoomType(int Id);

	/* FindRoomCoordinate() - ����� ������, ������� ���������� ���������� */
	/* ������� �� �� ������.                                              */
	structPoint FindRoomCoordinate(int Id);

	/* GenerateRoomStructure() - ����� ������, ������� ������� � ������   */
	/* ������� �����.                                                     */
	void GenerateRoomStructure();


public:
	/* classRoomGenerator() - ����������� ������, ������� ���������      */
	/* ��������: ����� ������ �� ���� � ������� ������, ������ �� ������, */
	/* ������� ������ ����������  ��� ����� � ������ �������, ���� �      */
	/* ������ �������, ���-�� ���� � ������ �������,                      */
	/* ���������� "�����������" ��� ������ �������, ������ �� ����������  */
	/* ��������� �������, ���-�� ������ � ������ � ����� ������.          */
	classRoomGenerator(int** _LevelMap, int** _LevelMapId, structWall*** _RoomWallSystem, int** _RoomTypeList, int** _NumberWallOfRoom,
		float** _EnemyCounter, structObjInformation*** _ObjList, int** _ObjNumber,int _SizeHor, int _SizeVer, structPoint* _StartPos, int _RoomNumber, int _NumberLevel, structPoint** _RoomCoordinateList);

	/* Start() - ����� ������, ������� �������� ��������� ������          */
	void Start();
};

