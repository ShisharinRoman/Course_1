/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: LevelGeneration.h                                     */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление классов classLevelStructureGenerator и  */
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
/* classLevelStructureGenerator - класс в котором генерируется */
/* основа уровня (Строение и типы комнат)              */
/*******************************************************/
class classLevelStructureGenerator {
private:

	/* CheckCanPlacedRoom() - метод класса, который проверяет может ли     */
	/*  быть размещена комната по координатам X и Y. Если комната состоит  */ 
	/*  из нескольких "квадратов", также проверяются всевозможные          */
	/*  варианты расположения комнаты.                                     */
	bool CheckCanPlacedRoom(int Room, int* Pos);

	/* RoomCreate() - метод класса, который создаёт комнату случайного типа */ 
	/*по координатам.                                                       */
	bool RoomCreate();

	/* NextPosition() - метод класса, который  определяет следущую позицию, */
	/* где будет поставленна комната. Выбор следующего места работает по    */
	/* принципу ромба, который постепенно расширяется. Центр ромба -        */
	/* стартовая координата.                                                */
	void NextPosition();

	/* GenerateTypeRoom() - метод класса, который управляет методами        */ 
	/* RoomCreate() и NextPosition(), создает структуру уровня.             */
	void GenerateTypeRoom();



	/********** Методы для сжатия карты **********/
	/*Убирают лишние "нулевые" строки и столбцы  */
	/*********************************************/
	void IndentifySizeVer(); // Вычисляет новый размер по вертикали
	void IndentifySizeHor(); // Вычисляет новый размер по горизонтали
	void CompressionMap(); // "Сжимает" карту под новые размеры
	/**********************************************/

	/* FindStartRoom() - метод класса, который нахождит координаты стартовой */
	/* комнаты уровня.                                                       */
	void FindStartRoom();

public:

	int** LevelMap; // Карта уровня, отображающая типы комнат
	int** LevelMapId; // Карта уровня, отображающая номера комнат 
	int* SizeVer; // Размер "сжатой" карты уровня по вертикали
	int* SizeHor; // Размер "сжатой" карты уровня по горизонтали
	structPoint* StartPos; // Координаты стартовой комнаты
	int SizeMap; // Размер сжатой комнаты
	int LevelNumber; // Номер уровня
	int RandomRangeCreateBossRoom; // Диапазон случайности генерации комнаты с боссом
	/******* Переменные для создания разных типов комнат ********/
	/************************************************************/
	int Center; // Переменная для хранения центра карты ( Стартовой комнаты )
	int LimitArtifactRoom;
	int RoomNumberNeed; // Сколько нужно поставить комнат (Исключение: комната с артефактом, магазин, комната с боссом) 
	int LimitShopRoom;
	int LimitBossRoom;
	int NowIdRoom; // Переменная для создания индефикатора комнат 
	/************************************************************/

	/* Переменные для помощи находения позиции следующей комнаты */
	/*************************************************************/
	structPoint NextCoordinate; // Координаты возможной следующей комнаты 
	int Diagonal;
	int DirCenterNext; // Переменная определяющая расстояние от центра карты до угла ромба
	char Dir; // Переменная отвечающая за направление поиска места для комнаты
	bool RoomPlaced;  // Определяет поставлена, ли комната в текущем ромбе (Позволяет увеличить ромб)
	bool BossRoomCreate;
	/*************************************************************/

	/* Переменные для сжатия карты */
	/*************************************************************/
	int StartVer, StartHor;
	int FinishVer, FinishHor;
	/*************************************************************/

	/* classLevelGeneralStructure - конструктор принимающий значения: */
	/* размер не "сжатой" карты уровня, номер уровня, ссылки на       */
	/* будущие размеры "сжатой" карты уровня и ссылку на координаты   */
	/* будущей стартовой комнаты.                                     */
	classLevelStructureGenerator(int Size, int LvlNumber, int* _SizeVer, int* _SizeHor, structPoint* _StartPos);

	/* GenerateStructure() - метод класса, который начинает генерацию */
	/* карты уровня в зависимости от парраметра RandomTypeGeneration  */
	void GenerateStructure(int RandomTypeGeneration);

	/*          Методы возвращающие значения        */
	/************************************************/
	int getNumberRoom(); // Вовращает кол-во созданных комнат
	int** getLevelMap(); // Возвращает карту уровня, где отображены типы комнат
	int** getLevelMapId(); // Возвращает карту уровня, ггде отображены номера комнат
	/************************************************/

};


/* classRoomGenerator                                     */
/***********************************************************/
/* classRoomGenerator - класс в котором генерируются      */
/* комнаты, т.е. генерация стен, генерация "враждебности", */
/* создание основной информации по комнате.                */
/***********************************************************/
class classRoomGenerator {
private:


	int** LevelMap; // Карта уровня, отображающая типы комнат
	int** LevelMapId; // Карта уровня, отображающая номера комнат 
	structWall*** RoomWallList; // Информация по стенам в каждой комнате уровня
	int** RoomTypeList; // Массив хранящий
	int** NumberWallOfRoom; // Кол-во стен в каждой комнате
	float** EnemyCounter; // Показатель "враждебности" в каждой комнате
	int SizeHor, SizeVer; // Размеры карты
	structPoint* StartPos; // Координаты стартовой комнаты
	int RoomNumber; // Кол-во комнат
	int NumberLevel; // Номер уровня
	structPoint** RoomCoordinateList; // Координаты каждой комнаты в уровне. Если комната состоит из нескольких "квадратов", то указывает на верхний-левый квадрат.
	structObjInformation*** ObjList;
	int** ObjNumber;

	/* CreateWall() - метод класса, который записывает общую информацию о стене, */
	/* т.е "создает" стену.                                                      */
	void CreateWall(structPoint Point1, structPoint Point2, structWall* RoomWallSystem, bool door, bool breakable,
		structPoint Point);

	/* RoomStartSettings() - метод класса, который записывыет общую информацию об */
	/* комнате.                                                                   */
	void RoomStartSettings();

	/* getRoomType() - метод класса, который возвращает тип комнаты по её */
	/* номеру.                                                            */
	int getRoomType(int Id);

	/* FindRoomCoordinate() - метод класса, который возвращает координаты */
	/* комнаты по ее номеру.                                              */
	structPoint FindRoomCoordinate(int Id);

	/* GenerateRoomStructure() - метод класса, который создает в каждой   */
	/* комнате стены.                                                     */
	void GenerateRoomStructure();


public:
	/* classRoomGenerator() - конструктор класса, который принимает      */
	/* значения: карта уровня по типу и номерам комнат, ссылку на массив, */
	/* который хранит информацию  про стены в каждой комнате, типы в      */
	/* каждой комнате, кол-во стен в каждой комнате,                      */
	/* показатель "враждебноси" для каждой комнаты, ссылку на координаты  */
	/* стартовой комнаты, кол-во комнат в уровне и номер уровня.          */
	classRoomGenerator(int** _LevelMap, int** _LevelMapId, structWall*** _RoomWallSystem, int** _RoomTypeList, int** _NumberWallOfRoom,
		float** _EnemyCounter, structObjInformation*** _ObjList, int** _ObjNumber,int _SizeHor, int _SizeVer, structPoint* _StartPos, int _RoomNumber, int _NumberLevel, structPoint** _RoomCoordinateList);

	/* Start() - метод класса, который начинает генерацию комнат          */
	void Start();
};

