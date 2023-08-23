/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Location.cpp                                          */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������� ������ classLocation            */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"Location.h"
#include"Level\\Level.h"
#include"..\\System\\IdList.h"
#include"..\\Objects\\GameObjects\\MortalObjects\\Player\\Player.h"
#include"..\\Objects\\OtherObjects\\Camera.h"
#include"..\\System\\GraphicSystem.h"
#include"..\\Objects\\GameObjects\\ImmortalObjects\\PassNextLevelObject\\PassNextLevel.h"

classLocation::classLocation(void* _IdList, const char* _TextureName) {

	vIdList = _IdList;
	TextureName = _TextureName;

	/* ��������� ���������� �� ��������� ������� */
	/*********************************************/
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLevel* IdLevel = static_cast<classLevel*>((*IdList).getIdLevel());
	UpdateLocation((*IdLevel).getRoomCoordinate(1));
	/*********************************************/

	ActiveObjectList = new void* [60];
	NumberActiveObject = 0;
	return;
}

int classLocation::CanObjectMoveToPoint(structPoint ObjPoint1, structPoint ObjPoint2) {
	int res = 0;
	for (int i = 0; i < NumberWall; i++) {
		if (!(((ObjPoint1.Y > WallList[i].Point2.Y) || (ObjPoint2.Y < WallList[i].Point1.Y)) ||
			((ObjPoint1.X > WallList[i].Point2.X) || (ObjPoint2.X < WallList[i].Point1.X)))) { // �������� ������� ������� � ����
			if ((WallList[i].door)/*&& ((*EnemyCounter) == 0)*/) { // ���� ����� �������� ��������
				res = 1; // ����� �������� ��������
				break;
			}
			else {
				res = 2; // ����� �������� ������
				break;
			}
		}
	}
	return res;
}

void classLocation::SpawnPlayer(structPoint SpawnPoint) {
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classPlayer* IdPlayer = new classPlayer(SpawnPoint, vIdList); // �������� ������
	(*IdList).setIdPlayer(IdPlayer);
	PlayerLevelCoordinate = RoomCoordinate; // ���������� ��������� ������ �� ����� ������
	return;
}

void classLocation::UpdateLocation(structPoint Coordinate) {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLevel* IdLevel = static_cast<classLevel*>((*IdList).getIdLevel());
	classGraphicSystem* IdGraphicSystem = static_cast<classGraphicSystem*>((*IdList).getIdGraphicSystem());

	(*IdGraphicSystem).deleteSpriteArray(&(WallList[0].Sprite), NumberWall); // �������� �������� ���� ������� �������

	DeleteObjects();

	/* ��������� ���������� �� ����� ������� */
	/********************************************************/
	int IdNewRoom = (*IdLevel).getNumberRoom(Coordinate); // ����� ������� 
	WallList = (*IdLevel).getRoomWall(IdNewRoom);  // ������ ���� �������
	NumberWall = (*IdLevel).getRoomNumberWall(IdNewRoom); // ���-�� ����
	EnemyCounter = (*IdLevel).getRoomEnemyCounter(IdNewRoom); // ���������� "������������"
	RoomCoordinate = (*IdLevel).getRoomCoordinate(IdNewRoom); // ���������� �������
	RoomType = (*IdLevel).getRoomType(IdNewRoom); // ��� �������
	ObjList = (*IdLevel).getObjList(IdNewRoom);
	ObjNumber = (*IdLevel).getObjNumber(IdNewRoom);
	/********************************************************/

	CreateObjects();
	
	DrawRoom(); // �������� �������� ���� ��������� �������

	return;
}

void classLocation::UpdatePlayerCoordinate() {

	if (RoomType > 5) { // ������ ��� ������, ������� ������� �� ����� 1 "��������"
		classIdList* IdList = static_cast<classIdList*>(vIdList);
		classPlayer* IdPlayer = static_cast<classPlayer*>((*IdList).getIdPlayer());
		/* ��������� ��������� ������ �� ����� ������ � ����������� */
		/* �� ��� ��������� � �������.                              */
		if (((*IdPlayer).Coordinate.Y > 490) && (PlayerLevelCoordinate.Y == RoomCoordinate.Y)) {
			PlayerLevelCoordinate.Y++;
		}
		if (((*IdPlayer).Coordinate.Y < 470) && (PlayerLevelCoordinate.Y == RoomCoordinate.Y + 1)) {
			PlayerLevelCoordinate.Y--;
		}
		if ((((*IdPlayer).Coordinate.X > 650) && (PlayerLevelCoordinate.X == RoomCoordinate.X)) ||
			(((*IdPlayer).Coordinate.X > 10) && (PlayerLevelCoordinate.X == RoomCoordinate.X - 1)))
		{
			PlayerLevelCoordinate.X++;
		}
		if ((((*IdPlayer).Coordinate.X < 630) && (PlayerLevelCoordinate.X == RoomCoordinate.X + 1)) ||
			(((*IdPlayer).Coordinate.X < -10) && (PlayerLevelCoordinate.X == RoomCoordinate.X))) {
			PlayerLevelCoordinate.X--;
		}
	}
	return;
}

void classLocation::MovingToAnotherRoom(char Direction) {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classPlayer* IdPlayer = static_cast<classPlayer*>((*IdList).getIdPlayer());
	classCamera* IdCamera = static_cast<classCamera*>((*IdList).getIdCamera());

	structPoint NewRoomCoordinate;
	int VerEnter = 0;
	int HorEnter = 0;

	if (Direction == 'd') {
		/* ��������� � ������ ��������� � ����������� */
		/* �����������.                               */
		/**********************************************/
		NewRoomCoordinate.Y = ++PlayerLevelCoordinate.Y;
		NewRoomCoordinate.X = PlayerLevelCoordinate.X;
		/**********************************************/

		UpdateLocation(NewRoomCoordinate);

		/* ���������� ������� ��������� ������ �� ����� */
		/* ������ � ��������� ������� ��� �����������   */
		/* ����������� ������ � ������ �������.         */
		/************************************************/
		VerEnter = NewRoomCoordinate.Y - RoomCoordinate.Y;
		HorEnter = NewRoomCoordinate.X - RoomCoordinate.X;
		/************************************************/

		/* ����������� ������ */
		/************************************************/
		(*IdPlayer).Coordinate.X = 320 + 640 * HorEnter;
		(*IdPlayer).Coordinate.Y = 80 + 480 * VerEnter;
		/************************************************/
	}
	if (Direction == 'u') {
		/* ��������� � ������ ��������� � ����������� */
		/* �����������.                               */
		/**********************************************/
		NewRoomCoordinate.Y = --PlayerLevelCoordinate.Y;
		NewRoomCoordinate.X = PlayerLevelCoordinate.X;
		/**********************************************/

		UpdateLocation(NewRoomCoordinate);

		/* ���������� ������� ��������� ������ �� ����� */
		/* ������ � ��������� ������� ��� �����������   */
		/* ����������� ������ � ������ �������.         */
		/************************************************/
		VerEnter = NewRoomCoordinate.Y - RoomCoordinate.Y;
		HorEnter = NewRoomCoordinate.X - RoomCoordinate.X;
		/************************************************/

		/* ����������� ������ */
		/************************************************/
		(*IdPlayer).Coordinate.X = 320 + 640 * HorEnter;
		(*IdPlayer).Coordinate.Y = 400 + 480 * VerEnter;
		/************************************************/
	}
	if (Direction == 'l') {
		/* ��������� � ������ ��������� � ����������� */
		/* �����������.                               */
		/**********************************************/
		NewRoomCoordinate.Y = PlayerLevelCoordinate.Y;
		NewRoomCoordinate.X = --PlayerLevelCoordinate.X;
		/**********************************************/

		UpdateLocation(NewRoomCoordinate);

		/* ���������� ������� ��������� ������ �� ����� */
		/* ������ � ��������� ������� ��� �����������   */
		/* ����������� ������ � ������ �������.         */
		/************************************************/
		VerEnter = NewRoomCoordinate.Y - RoomCoordinate.Y;
		HorEnter = NewRoomCoordinate.X - RoomCoordinate.X;
		/************************************************/

		/* ����������� ������ */
		/************************************************/
		(*IdPlayer).Coordinate.X = 560 + 640 * HorEnter;
		(*IdPlayer).Coordinate.Y = 240 + 480 * VerEnter;
		/************************************************/
	}
	if (Direction == 'r') {
		/* ��������� � ������ ��������� � ����������� */
		/* �����������.                               */
		/**********************************************/
		NewRoomCoordinate.Y = PlayerLevelCoordinate.Y;
		NewRoomCoordinate.X = ++PlayerLevelCoordinate.X;
		/**********************************************/

		UpdateLocation(NewRoomCoordinate);

		/* ���������� ������� ��������� ������ �� ����� */
		/* ������ � ��������� ������� ��� �����������   */
		/* ����������� ������ � ������ �������.         */
		/************************************************/
		VerEnter = NewRoomCoordinate.Y - RoomCoordinate.Y;
		HorEnter = NewRoomCoordinate.X - RoomCoordinate.X;
		/************************************************/

		/* ����������� ������ */
		/************************************************/
		(*IdPlayer).Coordinate.X = 80 + 640 * HorEnter;
		(*IdPlayer).Coordinate.Y = 240 + 480 * VerEnter;
		/************************************************/
	}

	(*IdCamera).setCoordinate(structPoint(0 + 680 * HorEnter, 0 + 480 * VerEnter)); // �������� ������

	return;
}

int classLocation::getRoomType() {
	return RoomType;
}

void classLocation::DrawRoom() {

	sf::Sprite** SpriteArray = new sf::Sprite * [NumberWall]; // �������� ������� ��� �������� ����
	structPoint** CoordinateArray = new structPoint * [NumberWall]; // �������� ������ ��������� ����

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classGraphicSystem* IdGraphicSystem = static_cast<classGraphicSystem*>((*IdList).getIdGraphicSystem());

	sf::Image Image;
	Image.loadFromFile(TextureName);
	Texture.loadFromImage(Image);

	for (int i = 0; i < NumberWall; i++) {
		WallList[i].CreateSprite(&Texture); // �������� �������� �����
		SpriteArray[i] = &(WallList[i].Sprite); // ���������� ������� � ������
		CoordinateArray[i] = &(WallList[i].Point1); // ���������� ��������� � ������
	}


	(*IdGraphicSystem).putSpriteArray(SpriteArray, CoordinateArray, NumberWall, 3, true); // �������� ������� � ����������� �������

	/*  �������� ��������  */
	/***********************/
	delete[] SpriteArray;
	delete[] CoordinateArray;
	/***********************/

	return;
}

void classLocation::CreateObjects() {

	for (int i = 0; i < ObjNumber; i++) {
		if (!strcmp(ObjList[i].Type,"PassNextLevel")) {
			classPassNextLevel* TempleId = new classPassNextLevel(vIdList,ObjList[i].PointSpawn);
			ActiveObjectList[NumberActiveObject] = TempleId; // ������ ��������� �� ������ � ������
			NumberActiveObject++;
		}
	}

	return;
}

void classLocation::DeleteObjects() {

	for (int i = 0; i < NumberActiveObject; i++) {
		if (!strcmp(ObjList[i].Type, "PassNextLevel")) {
			classPassNextLevel* IdObject = static_cast<classPassNextLevel*>(ActiveObjectList[i]);
			delete IdObject;
		}
		ActiveObjectList[i] = nullptr;
	}

	NumberActiveObject = 0;
	return;
}

void classLocation::LiveObjects() {

	for (int i = 0; i < NumberActiveObject; i++) {
		if (!strcmp(ObjList[i].Type, "PassNextLevel")) {
			classPassNextLevel* IdObject = static_cast<classPassNextLevel*>(ActiveObjectList[i]);
			(*IdObject).ObjectBehavior(); // ������ "���������" �������
		}
	}

	return;
}

classLocation::~classLocation() {

	DeleteObjects();

	delete[] ActiveObjectList;

	sf::Sprite** SpriteArray = new sf::Sprite * [NumberWall]; // �������� ������� ��� �������� ����

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classGraphicSystem* IdGraphicSystem = static_cast<classGraphicSystem*>((*IdList).getIdGraphicSystem());
	classPlayer* IdPlayer = static_cast<classPlayer*>((*IdList).getIdPlayer());

	for (int i = 0; i < NumberWall; i++) {
		SpriteArray[i] = &(WallList[i].Sprite); // ���������� ������� � ������
	}

	(*IdGraphicSystem).deleteSpriteArray(SpriteArray[0], NumberWall);

	delete[] SpriteArray;

	delete IdPlayer;

	return;
}