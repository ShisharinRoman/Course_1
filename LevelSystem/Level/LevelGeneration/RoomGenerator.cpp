/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: RoomGenerator.cpp                                     */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classRoomGenerator       */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"LevelGeneration.h"
#include<cmath>

structPoint classRoomGenerator::FindRoomCoordinate(int Id) {
	structPoint Coordinate;
	bool AllBreak = false;
	for (int i = 0; i < SizeVer; i++) {
		for (int j = 0; j < SizeHor; j++) {
			if (LevelMapId[i][j] - 1 == Id) { // Поиск комнаты по номеру
				Coordinate.X = j; // Запись координат комнаты
				Coordinate.Y = i;
				AllBreak = true;
				break;
			}
		}
		if (AllBreak) {
			break;
		}
	}
	return Coordinate;
}

classRoomGenerator::classRoomGenerator(int** _LevelMap, int** _LevelMapId, structWall*** _RoomWallList, int** _RoomTypeList, int** _NumberWallOfRoom,
	float** _EnemyCounter, structObjInformation*** _ObjList, int** _ObjNumber,int _SizeHor, int _SizeVer, structPoint* _StartPos, int _RoomNumber, int _NumberLevel, structPoint** _RoomCoordinateList) {
	LevelMap = _LevelMap;
	LevelMapId = _LevelMapId;
	RoomWallList = _RoomWallList;
	RoomTypeList = _RoomTypeList;
	NumberWallOfRoom = _NumberWallOfRoom;
	EnemyCounter = _EnemyCounter;
	SizeHor = _SizeHor;
	SizeVer = _SizeVer;
	StartPos = _StartPos;
	RoomNumber = _RoomNumber;
	NumberLevel = _NumberLevel;
	RoomCoordinateList = _RoomCoordinateList;
	ObjList = _ObjList;
	ObjNumber = _ObjNumber;
	return;
}

void classRoomGenerator::Start() {
	RoomStartSettings();
	GenerateRoomStructure();
}

void classRoomGenerator::CreateWall(structPoint Point1, structPoint Point2, structWall* RoomWallSystem, bool door, bool breakable,
	structPoint SpritePoint) {
	if (!RoomWallSystem) {
		throw "classRoomGenerator::CreateWall() : Invalid Adress";
	}
	(*RoomWallSystem).Point1 = Point1;
	(*RoomWallSystem).Point2 = Point2;
	(*RoomWallSystem).door = door; // Определение является ли стена проходом
	(*RoomWallSystem).breakable = breakable; // Определение можно ли сломать стену взрывом (Не реализовано)
	(*RoomWallSystem).setSpriteInformation(SpritePoint, structPoint(abs(Point2.X - Point1.X), abs(Point2.Y - Point1.Y)));
	return;
}

void classRoomGenerator::GenerateRoomStructure() {

	for (int i = 0; i < RoomNumber; i++) { // Генерация стен для каждой комнаты

		/* Чтобы сгенерировать стены, сначала определяется тип комнаты */
		/* Затем рассматриваються соседние "квадраты", в которых могут */
		/* быть гипотетические соседние комнаты, если соседняя комната */
		/* существует, то создаються две стены и проход, если нет      */
		/* комнаты, то создаеться одна стена.                          */
		if ((*RoomTypeList)[i] != 0) {
			if (LevelMapId[(*RoomCoordinateList)[i].Y][(*RoomCoordinateList)[i].X - 1] > 0) {
				CreateWall(structPoint(0, 0), structPoint(60, 180), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 1));
				(*NumberWallOfRoom)[i]++;
				CreateWall(structPoint(0, 300), structPoint(60, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 301));
				(*NumberWallOfRoom)[i]++;
				CreateWall(structPoint(0, 180), structPoint(60, 300), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(1, 181));
			}
			else {
				CreateWall(structPoint(0, 0), structPoint(60, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 1));
			}

			(*NumberWallOfRoom)[i]++;

			if (LevelMapId[(*RoomCoordinateList)[i].Y - 1][(*RoomCoordinateList)[i].X] > 0) {
				CreateWall(structPoint(0, 0), structPoint(260, 60), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 1));
				(*NumberWallOfRoom)[i]++;
				CreateWall(structPoint(380, 0), structPoint(640, 60), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(381, 1));
				(*NumberWallOfRoom)[i]++;
				CreateWall(structPoint(260, 0), structPoint(380, 60), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(261, 1));
			}
			else {
				CreateWall(structPoint(0, 0), structPoint(640, 60), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 1));
			}
			(*NumberWallOfRoom)[i]++;

			if (((*RoomTypeList)[i] != 8) && ((*RoomTypeList)[i] != 12) && ((*RoomTypeList)[i] != 7) && ((*RoomTypeList)[i] != 10)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y][(*RoomCoordinateList)[i].X + 1] > 0) {
					CreateWall(structPoint(580, 0), structPoint(640, 180), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(581, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(580, 300), structPoint(640, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(581, 301));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(580, 180), structPoint(640, 300), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(581, 181));
				}
				else {
					CreateWall(structPoint(580, 0), structPoint(640, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1225, 1));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if (((*RoomTypeList)[i] <= 5) || ((*RoomTypeList)[i] == 7) || ((*RoomTypeList)[i] == 10)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y + 1][(*RoomCoordinateList)[i].X] > 0) {
					CreateWall(structPoint(0, 420), structPoint(260, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(380, 420), structPoint(640, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(381, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(260, 420), structPoint(380, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(261, 421));
				}
				else {
					CreateWall(structPoint(0, 420), structPoint(640, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 421));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if (((*RoomTypeList)[i] >= 6) && ((*RoomTypeList)[i] != 7) && ((*RoomTypeList)[i] != 10)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y + 2][(*RoomCoordinateList)[i].X] > 0) {
					CreateWall(structPoint(0, 900), structPoint(260, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(380, 900), structPoint(640, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(381, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(260, 900), structPoint(380, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(261, 421));
				}
				else {
					CreateWall(structPoint(0, 900), structPoint(640, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 421));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if (((*RoomTypeList)[i] >= 6) && ((*RoomTypeList)[i] != 7) && ((*RoomTypeList)[i] != 10) && ((*RoomTypeList)[i] != 11)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y + 1][(*RoomCoordinateList)[i].X - 1] > 0) {
					CreateWall(structPoint(0, 480), structPoint(60, 660), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(0, 780), structPoint(60, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 301));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(0, 660), structPoint(60, 780), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(1, 181));
				}
				else {
					CreateWall(structPoint(0, 480), structPoint(60, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 1));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if (((*RoomTypeList)[i] == 6) || ((*RoomTypeList)[i] == 8) || ((*RoomTypeList)[i] == 11)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y + 1][(*RoomCoordinateList)[i].X + 1] > 0) {
					CreateWall(structPoint(580, 480), structPoint(640, 660), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(581, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(580, 780), structPoint(640, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(581, 301));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(580, 660), structPoint(640, 780), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(581, 181));
				}
				else {
					CreateWall(structPoint(580, 480), structPoint(640, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1225, 1));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if (((*RoomTypeList)[i] >= 7) && ((*RoomTypeList)[i] != 9) && ((*RoomTypeList)[i] != 11)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y - 1][(*RoomCoordinateList)[i].X + 1] > 0) {
					CreateWall(structPoint(640, 0), structPoint(900, 60), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(1020, 0), structPoint(1280, 60), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(381, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(900, 0), structPoint(1020, 60), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(261, 1));
				}
				else {
					CreateWall(structPoint(640, 0), structPoint(1280, 60), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 1));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if (((*RoomTypeList)[i] >= 7) && ((*RoomTypeList)[i] != 9) && ((*RoomTypeList)[i] != 11)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y][(*RoomCoordinateList)[i].X + 2] > 0) {
					CreateWall(structPoint(1220, 0), structPoint(1280, 180), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(581, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(1220, 300), structPoint(1280, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(581, 301));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(1220, 180), structPoint(1280, 300), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(581, 181));
				}
				else {
					CreateWall(structPoint(1220, 0), structPoint(1280, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1225, 1));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if (((*RoomTypeList)[i] == 7) || ((*RoomTypeList)[i] == 8)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y + 1][(*RoomCoordinateList)[i].X + 1] > 0) {
					CreateWall(structPoint(640, 420), structPoint(900, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(1020, 420), structPoint(1280, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(381, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(900, 420), structPoint(1020, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(261, 421));
				}
				else {
					CreateWall(structPoint(640, 420), structPoint(1280, 480), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 421));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if (((*RoomTypeList)[i] == 9) || ((*RoomTypeList)[i] == 10) || ((*RoomTypeList)[i] == 12)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y + 1][(*RoomCoordinateList)[i].X + 2] > 0) {
					CreateWall(structPoint(1220, 480), structPoint(1280, 660), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(581, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(1220, 780), structPoint(1280, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(581, 301));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(1220, 660), structPoint(1280, 780), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(581, 181));
				}
				else {
					CreateWall(structPoint(1220, 480), structPoint(1280, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1225, 1));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if (((*RoomTypeList)[i] == 9) || ((*RoomTypeList)[i] == 10) || ((*RoomTypeList)[i] == 12)) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y + 2][(*RoomCoordinateList)[i].X + 1] > 0) {
					CreateWall(structPoint(640, 900), structPoint(900, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(1020, 900), structPoint(1280, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(381, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(900, 900), structPoint(1020, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(261, 421));
				}
				else {
					CreateWall(structPoint(640, 900), structPoint(1280, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 421));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if ((*RoomTypeList)[i] == 9) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y][(*RoomCoordinateList)[i].X + 1] > 0) {
					CreateWall(structPoint(640, 480), structPoint(900, 540), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(1020, 480), structPoint(1280, 540), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(381, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(900, 480), structPoint(1020, 540), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(261, 1));
				}
				else {
					CreateWall(structPoint(640, 480), structPoint(1280, 540), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 1));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if ((*RoomTypeList)[i] == 10) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y + 1][(*RoomCoordinateList)[i].X] > 0) {
					CreateWall(structPoint(640, 480), structPoint(700, 660), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(640, 780), structPoint(700, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 301));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(640, 660), structPoint(700, 780), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(1, 181));
				}
				else {
					CreateWall(structPoint(640, 480), structPoint(700, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 1));
				}
				(*NumberWallOfRoom)[i]++;
			}

			if ((*RoomTypeList)[i] == 11) {
				if (LevelMapId[(*RoomCoordinateList)[i].Y][(*RoomCoordinateList)[i].X - 1] > 0) {
					CreateWall(structPoint(-640, 480), structPoint(-380, 540), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(-260, 480), structPoint(0, 540), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(381, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(-380, 480), structPoint(-260, 540), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(261, 1));
				}
				else {
					CreateWall(structPoint(-640, 480), structPoint(0, 540), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 1));
				}
				(*NumberWallOfRoom)[i]++;

				if (LevelMapId[(*RoomCoordinateList)[i].Y + 2][(*RoomCoordinateList)[i].X - 1] > 0) {
					CreateWall(structPoint(-640, 900), structPoint(-380, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(-260, 900), structPoint(0, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(381, 421));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(-380, 900), structPoint(-260, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(261, 421));
				}
				else {
					CreateWall(structPoint(-640, 900), structPoint(0, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 421));
				}
				(*NumberWallOfRoom)[i]++;

				if (LevelMapId[(*RoomCoordinateList)[i].Y + 1][(*RoomCoordinateList)[i].X - 2] > 0) {
					CreateWall(structPoint(-640, 480), structPoint(-580, 660), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 1));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(-640, 780), structPoint(-580, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(1, 301));
					(*NumberWallOfRoom)[i]++;
					CreateWall(structPoint(-640, 660), structPoint(-580, 780), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], true, false, structPoint(1, 181));
				}
				else {
					CreateWall(structPoint(-640, 480), structPoint(-580, 960), &(*RoomWallList)[i][(*NumberWallOfRoom)[i]], false, false, structPoint(645, 1));
				}
				(*NumberWallOfRoom)[i]++;
			}
		}
	}

	return;
}

int classRoomGenerator::getRoomType(int Id) {
	int RoomType = 0;
	bool AllBreak = false;
	for (int i = 0; i < SizeVer; i++) {
		for (int j = 0; j < SizeHor; j++) {
			if (LevelMapId[i][j] - 1 == Id) { // Поиск комнаты по номеру
				RoomType = LevelMap[i][j]; // Запись типа комнаты
				AllBreak = true;
				break;
			}
		}
		if (AllBreak) {
			break;
		}
	}
	return RoomType;
}

void classRoomGenerator::RoomStartSettings() {

	for (int i = 0; i < RoomNumber; i++) {

		(*RoomTypeList)[i] = getRoomType(i);
		(*RoomCoordinateList)[i] = FindRoomCoordinate(i);

		if ((*RoomTypeList)[i] == 5) {
			(*ObjNumber)[i] = 1;
			(*ObjList)[i][0].PointSpawn = structPoint(320,160);
			(*ObjList)[i][0].Type = "PassNextLevel";
		} 
		else {
			(*ObjNumber)[i] = 0;
		}

		/* Генерация показателя "враждебности". "Враждебность" зависит */
		/* от номера уровня и размера комнаты. (Размер комнаты         */
		/* определяется её типом)                                      */
		if (((*RoomTypeList)[i] > 1) && ((*RoomTypeList)[i] != 5)) {
			if ((*RoomTypeList)[i] < 5) {
				(*EnemyCounter)[i] = ((float(5) + float(rand() % 6)) * NumberLevel) + float(rand() % 7);
			}
			if (((*RoomTypeList)[i] > 5) && ((*RoomTypeList)[i] < 8)) {
				(*EnemyCounter)[i] = ((float(10) + float(rand() % 6)) * NumberLevel) + float(rand() % 12);
			}
			if (((*RoomTypeList)[i] > 7) && ((*RoomTypeList)[i] < 12)) {
				(*EnemyCounter)[i] = ((float(15) + float(rand() % 6)) * NumberLevel) + float(rand() % 17);
			}
			if ((*RoomTypeList)[i] == 12) {
				(*EnemyCounter)[i] = ((float(20) + float(rand() % 6)) * NumberLevel) + float(rand() % 22);
			}
		}
		else {
			(*EnemyCounter)[i] = 0;
		}

	}
	return;
}
