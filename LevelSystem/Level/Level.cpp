/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Level.cpp                                             */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classLevel               */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include<cmath>
#include<cstring>
#include"Level.h"
#include"LevelGeneration\\LevelGeneration.h"

using namespace std;

classLevel::classLevel() {

	EnemyCounter = nullptr;
	LevelMap = nullptr;
	LevelMapId = nullptr;
	NumberWallRoom = nullptr;
	RoomCoordinateList = nullptr;
	RoomListStructure = nullptr;
	RoomNumber = 0;
	RoomTypeList = nullptr;
	SizeHor = 0;
	SizeVer = 0;
	StartPos = structPoint(0, 0);
	NumberLevel = 1;

	return;
}

void classLevel::StartStructureGeneration() {

	classLevelStructureGenerator LevelStructureGenerator(9, 1, &SizeVer, &SizeHor, &StartPos); // Создания генератора структуры уровня 
	LevelStructureGenerator.GenerateStructure(1); // Запуск генерации структуры уровня
	RoomNumber = LevelStructureGenerator.getNumberRoom();
	LevelMap = LevelStructureGenerator.getLevelMap();
	LevelMapId = LevelStructureGenerator.getLevelMapId();

	return;
}

void classLevel::StartRoomGeneration() {

	/* Создание массивов хранящих информацию по каждой комнате */
	/***********************************************************/
	RoomListStructure = new structWall * [RoomNumber];
	NumberWallRoom = new int[RoomNumber];
	RoomCoordinateList = new structPoint[RoomNumber];
	RoomTypeList = new int[RoomNumber];
	EnemyCounter = new float[RoomNumber];
	ObjList = new structObjInformation * [RoomNumber];
	ObjNumber = new int[RoomNumber];
	/***********************************************************/

	for (int i = 0; i < RoomNumber; i++) {
		NumberWallRoom[i] = 0;
		ObjNumber[i] = 0;
	}

	for (int i = 0; i < RoomNumber; i++) {
		RoomListStructure[i] = new structWall[20]; // 20 - Макс. возможное кол-во стен в комнате
		ObjList[i] = new structObjInformation[30];
	}

	classRoomGenerator RoomGenerator(LevelMap, LevelMapId, &RoomListStructure, &RoomTypeList, &NumberWallRoom,
		&EnemyCounter, &ObjList, &ObjNumber, SizeHor, SizeVer, &StartPos, RoomNumber, NumberLevel, &RoomCoordinateList); // Создание генератора комнат
	RoomGenerator.Start(); // Запуск генератора

	return;
}

int classLevel::getRoomType(int Id) {
	return RoomTypeList[Id - 1];
}

structPoint classLevel::getRoomCoordinate(int Id) {
	return RoomCoordinateList[Id - 1];
}

float* classLevel::getRoomEnemyCounter(int Id) {
	return &EnemyCounter[Id - 1];
}

structWall* classLevel::getRoomWall(int Id) {
	return RoomListStructure[Id - 1];
}

int classLevel::getRoomNumberWall(int Id) {
	return NumberWallRoom[Id - 1];
}

int classLevel::getNumberRoom(structPoint Point) {
	return LevelMapId[Point.Y][Point.X];
}

structObjInformation* classLevel::getObjList(int Id) {
	return ObjList[Id - 1];
}

int classLevel::getObjNumber(int Id) {
	return ObjNumber[Id - 1];
}

classLevel::~classLevel() {

	for (int i = 0; i < SizeVer; i++) {
		delete[] LevelMap[i];
		delete[] LevelMapId[i];

	}
	for (int i = 0; i < RoomNumber; i++) {
		delete[] RoomListStructure[i];
		delete[] ObjList[i];
	}
	delete[] LevelMap;
	delete[] LevelMapId;
	delete[] RoomListStructure;
	delete[] EnemyCounter;
	delete[] NumberWallRoom;
	delete[] RoomCoordinateList;
	delete[] RoomTypeList;
	delete[] ObjNumber;

	return;
}