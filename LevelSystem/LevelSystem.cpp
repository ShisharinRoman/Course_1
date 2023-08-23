/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: LevelSystem.cpp                                       */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������� ������ classLevelSystem         */
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
	classLevel* IdLevel = new classLevel(); // �������� ������ ������
	(*IdList).setIdLevel(IdLevel); 
	(*IdLevel).StartStructureGeneration(); // ������ ��������� ��������� ������
	(*IdLevel).StartRoomGeneration(); // ������ ��������� ������ ������

	classLocation* IdLocation = new classLocation(vIdList, "images\\Wall\\Wall.png"); // �������� �������
	(*IdList).setIdLocation(IdLocation);
	(*IdLocation).SpawnPlayer(structPoint(320,120)); // �������� ������ � ��������� �������

	return;
}

void classLevelSystem::DeleteLevel() {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());
	classLevel* IdLevel = static_cast<classLevel*>((*IdList).getIdLevel());

	
	delete IdLocation; // �������� ������� ����������������� ������� �������
	delete IdLevel; // �������� �������� ������

	NumberLevel++; // ���������� ������ ������

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
	DeleteLevel(); // �������� �������� ������
	CreateNewLevel(); // �������� ������ ������
	return;
}

classLevelSystem::~classLevelSystem() {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());
	classLevel* IdLevel = static_cast<classLevel*>((*IdList).getIdLevel());

	delete IdLocation; // �������� ������� ����������������� ������� �������
	delete IdLevel; // �������� �������� ������

	return;
}
