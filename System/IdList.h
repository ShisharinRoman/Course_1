/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: IdList.h                                              */
/* Abstract: This is a simple C++ program                          */
/* Description: ќбъ€вление класса classIdList                      */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#pragma once

/* classIdList                         */
/***************************************/
/* classIdList - класс который хранит  */
/* указатели на различные важные       */
/* объекты.                            */
/***************************************/
struct classIdList {
private:

	/* ”казатели на важные объекты. */
	/********************************/
	void* IdGame;
	void* IdLevelSystem;
	void* IdLevel;
	void* IdLocation;
	void* IdPlayer;
	void* IdCamera;
	void* IdGraphicSystem;
	void* IdMainMenu;
	void* IdWindow;
	void* IdSubMenu;
	/********************************/

public:

	/* classIdList() - конструктор класса. */
	classIdList();

	/* ћетоды класса, которые принимают указатели */
	/* на объекты.                                */
	/**********************************************/
	void setIdGame(void* Id);
	void setIdLevelSystem(void* Id);
	void setIdLocation(void* Id);
	void setIdPlayer(void* Id);
	void setIdCamera(void* Id);
	void setIdMainMenu(void* Id);
	void setIdGraphicSystem(void* Id);
	void setIdWindow(void* Id);
	void setIdLevel(void* Id);
	void setIdSubMenu(void* Id);
	/**********************************************/

	/* ћетоды класса, класса которые возвращают   */
	/* указатели на объекты.                      */
	/**********************************************/
	void* getIdGame();
	void* getIdLevelSystem();
	void* getIdLocation();
	void* getIdPlayer();
	void* getIdCamera();
	void* getIdMainMenu();
	void* getGraphicSystem();
	void* getIdWindow();
	void* getIdGraphicSystem();
	void* getIdLevel();
	void* getIdSubMenu();
	/**********************************************/
};