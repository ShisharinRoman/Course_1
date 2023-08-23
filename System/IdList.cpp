/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: IdList.сpp                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classIdList              */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"IdList.h"

classIdList::classIdList() {
	IdGame = nullptr;
	IdLevelSystem = nullptr;
	IdLevel = nullptr;
	IdLocation = nullptr;
	IdPlayer = nullptr;
	IdCamera = nullptr;
	IdGraphicSystem = nullptr;
	IdMainMenu = nullptr;
	IdWindow = nullptr;
	IdLevel = nullptr;
}

void classIdList::setIdGame(void* Id) {
	IdGame = Id;
	return;
}

void classIdList::setIdLevelSystem(void* Id) {
	IdLevelSystem = Id;
	return;
}

void classIdList::setIdLocation(void* Id) {
	IdLocation = Id;
	return;
}

void classIdList::setIdPlayer(void* Id) {
	IdPlayer = Id;
	return;
}

void classIdList::setIdCamera(void* Id) {
	IdCamera = Id;
	return;
}

void classIdList::setIdMainMenu(void* Id) {
	IdMainMenu = Id;
	return;
}

void classIdList::setIdGraphicSystem(void* Id) {
	IdGraphicSystem = Id;
	return;
}

void classIdList::setIdWindow(void* Id) {
	IdWindow = Id;
	return;
}

void classIdList::setIdLevel(void* Id) {
	IdLevel = Id;
	return;
}

void classIdList::setIdSubMenu(void* Id) {
	IdSubMenu = Id;
	return;
}

void* classIdList::getIdGame() {
	return IdGame;
}

void* classIdList::getIdLevelSystem() {
	return IdLevelSystem;
}

void* classIdList::getIdLocation() {
	return IdLocation;
}

void* classIdList::getIdPlayer() {
	return IdPlayer;
}

void* classIdList::getIdCamera() {
	return IdCamera;
}

void* classIdList::getIdMainMenu() {
	return IdMainMenu;
}

void* classIdList::getGraphicSystem() {
	return IdGraphicSystem;
}

void* classIdList::getIdWindow() {
	return IdWindow;
}

void* classIdList::getIdGraphicSystem() {
	return IdGraphicSystem;
}

void* classIdList::getIdLevel() {
	return IdLevel;
}

void* classIdList::getIdSubMenu() {
	return IdSubMenu;
}