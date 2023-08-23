/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: LevelSystem.cpp                                       */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classLevelSystem         */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"LevelSystem.h"
#include"..\\System\\IdList.h"
#include"Location.h"
#include"Level\\Level.h"


void classLevelSystem::CreateNewLevel() {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLevel* IdLevel = new classLevel(); // Создание нового уровня
	(*IdList).setIdLevel(IdLevel); 
	(*IdLevel).StartStructureGeneration(); // Запуск генерации структуры уровня
	(*IdLevel).StartRoomGeneration(); // Запуск генерации комнат уровня

	classLocation* IdLocation = new classLocation(vIdList, "images\\Wall\\Wall.png"); // Создание локации
	(*IdList).setIdLocation(IdLocation);
	(*IdLocation).SpawnPlayer(structPoint(320,120)); // Создание игрока в стартовой комнате

	return;
}

void classLevelSystem::DeleteLevel() {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());
	classLevel* IdLevel = static_cast<classLevel*>((*IdList).getIdLevel());

	
	delete IdLocation; // Удаление объекта просматривоаемого текущий уровень
	delete IdLevel; // Удаление текущего уровня

	NumberLevel++; // Увеличения номера уровня

	return;
}

classLevelSystem::classLevelSystem(void* _IdList) {

	vIdList = _IdList;
	NumberLevel = 1;

	return;
}

void classLevelSystem::Start() {
	CreateNewLevel();
	return;
}

void classLevelSystem::NextLevel() {
	DeleteLevel(); // Удаление текущего уровня
	CreateNewLevel(); // Создание нового уровня
	return;
}

classLevelSystem::~classLevelSystem() {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());
	classLevel* IdLevel = static_cast<classLevel*>((*IdList).getIdLevel());

	delete IdLocation; // Удаление объекта просматривоаемого текущий уровень
	delete IdLevel; // Удаление текущего уровня

	return;
}
