/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Location.h                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classLocation                    */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once
#include"Level\\Wall\\Wall.h"
#include"ObjInformation.h"

/* classLocation                               */
/***********************************************/
/* classLocation - класс, который работает с   */
/* комнатой из объекта classLevel.             */
/***********************************************/
class classLocation {

private:

	const char* TextureName; // Путь к текущей текстуры уровня

	structPoint PlayerLevelCoordinate; // Координаты игрока на карте уровня

	void* vIdList; // Указатель на структуру хранящую адресса

	void** ActiveObjectList;
	int NumberActiveObject;

	sf::Texture Texture; // Текстура

	/*       Информация об комнате        */
	/**************************************/
	structWall* WallList; // Список стен
	int NumberWall; // Кол-во стен
	float* EnemyCounter; // Показатель "враждебности"
	structPoint RoomCoordinate; // Координаты комнаты
	int RoomType; // Тип комнаты
	structObjInformation* ObjList;
	int ObjNumber;
	/**************************************/

	/* UpdateLocation() - метод класса, который получает */
	/* информацию об комнате по координатам.             */
	void UpdateLocation(structPoint Coordinate);

	/* CreateObjects() - метод класса, который создает   */
	/* объекты находящиеся в комнате.                    */
	void CreateObjects();

	/* DeleteObjects() - метод класса, который удаляет   */
	/* объекты находящиеся в комнате.                    */
	void DeleteObjects();

public:

	/* classLocation() - конструктор класса, который     */
	/* принимает значения: указатель на класс, хранящий  */
	/* адресса объектов, и путь к текстуре.              */
	classLocation(void* _IdList, const char* TextureName);

	/* CanObjectMoveToPoint() - метод класса, который    */
	/* проверяет может объект переместиться в заданную   */
	/*  точку.                                           */
	/* ObjPoint1 - левый верхний угол объекта.           */
	/* ObjPoint2 - правый нижний угол объекта.           */
	int CanObjectMoveToPoint(structPoint ObjPoint1,structPoint ObjPoint2);

	/* MovingToAnotherRoom() - метод класса, который     */
	/* перемещает игрока в другую комнату по направлению */
	/* Direction.                                        */
	void MovingToAnotherRoom(char Direction);

	/* LiveObjects() - метод класса, который запускает   */
	/* объекты находящиеся в комнате.                    */
	void LiveObjects();

	/* SpawnPlayer() - метод класса, который создает     */
	/* игрока в заданных координатах.                    */
	void SpawnPlayer(structPoint SpawnPoint);

	/* getRoomType() - метод класса, который возвращает  */
	/* тип комнаты.                                      */
	int getRoomType();

	/* UpdatePlayerCoordinate() - метод класса, который */
	/* обновляет координаты игрока на карте уровня.     */
	void UpdatePlayerCoordinate();

	/* DrawRoom() - метод класса, который передает      */
	/* информацию, что нужно нарисовать, объекту        */
	/* classGraphicalSystem.                            */
	void DrawRoom();

	/* ~classLocation() - деструктор класса.            */
	~classLocation();
};