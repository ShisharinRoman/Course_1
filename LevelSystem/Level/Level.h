/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Level.h                                               */
/* Abstract: This is a simple C++ program                          */
/* Description: ќбъ€вление класса classLevel                       */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/
#pragma once
#include"Wall\\Wall.h"
#include"..\\ObjInformation.h"


/* classLevel                                        */
/*****************************************************/
/* classLevel - класс, который хранит всю информацию */
/* об уровне. “акже запускает генерацию уровн€       */
/*****************************************************/
class classLevel {
private:

	int NumberLevel; // Ќомер уровн€
	int RoomNumber; //  ол-во комнат
	int** LevelMap; //  арта уровн€, отображающа€ типы комнат
	int** LevelMapId; //  арта уровн€, отображающа€ номера комнат 
	int SizeHor, SizeVer; // –азмеры карты
	structPoint StartPos; //  оординаты начальной комнаты

	/* ѕеременные дл€ хранени€ общей информации по каждой комнате */
	/**************************************************************/
	structWall** RoomListStructure; // –асположение стен
	int* NumberWallRoom; //  ол-во стен
	float* EnemyCounter; // ѕоказатель "враждебности"
	structObjInformation** ObjList;
	int* ObjNumber;
	structPoint* RoomCoordinateList; //  оординаты комнаты или верхнего-левого "квадрата", если комната состоит из нескольких квадратов
	int* RoomTypeList; // “ип комнаты
	/******************************************************************/

public:
	/* classLevel() - конструктор класса.                      */
	classLevel();

	/* StartStructureGeneration() - метод класса, который      */
	/* начинает генерировать структуру уровн€.                 */
	void StartStructureGeneration();

	/* StartRoomGeneration() - метод класса, который начинает  */
	/* генерировать комнаты.                                   */
	void StartRoomGeneration();

	/* getRoomType() - метод класса, который возвращает тип    */
	/* комнаты по номеру комнаты                               */
	int getRoomType(int Id);
	
	/* getRoomWall() - метод класса, который возвращает        */
	/* информацию об стенах в комнате по номеру комнаты.       */
	structWall* getRoomWall(int Id);

	/* getRoomCoordinate() - метод класса, который возвращает  */
	/* координату комнаты по еЄ номеру.                        */
	structPoint getRoomCoordinate(int Id);

	/* getRoomEnemyCounter() - метод класса, который           */
	/* возвращает ссылку на показатель "враждебности" комнаты  */
	/* по еЄ номеру.                                           */
	float* getRoomEnemyCounter(int Id);

	/* getRoomNumberWall() - метод класса, который возвращает  */
	/* кол-во стен комнаты по номеру комнаты.                  */
	int getRoomNumberWall(int Id);

	/* getNumberRoom() - метод класса, который возвращает      */
	/* номер комнаты по еЄ координатам.                        */
	int getNumberRoom(structPoint Point);

	structObjInformation* getObjList(int Id);

	int getObjNumber(int Id);

	/* ~classLevel() - деструктор класса.                      */
	~classLevel();

};