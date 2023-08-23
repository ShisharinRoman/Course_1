/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: Game.cpp                                              */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classGame                */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

//#include<cstring>
#include"Game.h"
#include"..\\Objects\\OtherObjects\\MainMenu.h"
#include"ControlSystem.h"
#include"..\\LevelSystem\\LevelSystem.h"
#include"GraphicSystem.h"
#include"IdList.h"
#include"..\\Objects\\OtherObjects\\Camera.h"
#include"..\\Objects\\OtherObjects\\SubMenu.h"
#include"..\\LevelSystem\\Location.h"

#include<iostream>
#include<iomanip>
#include<time.h>


classGame::classGame() {
	State = new char[6];
	State = (char*)"Start";
	Phase = 1;
	timer = time(0);
	srand(time(0));
	rand();
	return;
}

void classGame::ChangeState(const char* _State) {
	Phase = 1;
	State = (char*)_State;
	return;
}

void classGame::GameStart() {

	classIdList IdList;
	IdList.setIdGame(this);

	classControlSystem ControlSystem(&IdList);

	sf::RenderWindow Window(sf::VideoMode(640, 480), "Lab General. Shisharin Roman");
	IdList.setIdWindow(&Window);

	classCamera Camera(&IdList);
	Camera.setCoordinate(structPoint(0, 0));
	IdList.setIdCamera(&Camera);

	classGraphicSystem GraphicSystem(&IdList);
	IdList.setIdGraphicSystem(&GraphicSystem);

	classMainMenu* IdMainMenu = nullptr;
	classLevelSystem* IdLevelSystem = nullptr;
	classSubMenu* IdSubMenu = nullptr;
	
	while ((Window.isOpen()) && (strcmp(State,"Exit"))) { // Основной цикл игры

		sf::Event event;

		if (Window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				Window.close();
		}

		if (Phase == 1) { // Если состояние только поменялось
			if (!strcmp(State, "Start")) {

				/* Удаление лишних объектов */
				/****************************/
				if (IdSubMenu) {
					delete IdSubMenu;
					IdSubMenu = nullptr;
				}
				if (IdLevelSystem) {
					delete IdLevelSystem;
					IdLevelSystem = nullptr;
				}
				/****************************/

				Camera.setCoordinate(structPoint(0, 0)); //Установка камеры на начальное положение

				/* Создание нужных объектов */
				/****************************/
				if (!IdMainMenu) {
					IdMainMenu = new classMainMenu(&IdList);
					IdList.setIdMainMenu(IdMainMenu);		
				}
				/****************************/

				ControlSystem.setPhase("Main Menu");
			}
			if (!strcmp(State, "Game")) {

				/* Удаление лишних объектов */
				/****************************/
				if (IdMainMenu) {
					delete IdMainMenu;
					IdMainMenu = nullptr;
				}
				if (IdSubMenu) {
					delete IdSubMenu;
					IdSubMenu = nullptr;
				}
				/****************************/
				
				/* Создание нужных объектов */
				/****************************/
				if (!IdLevelSystem) {
					IdLevelSystem = new classLevelSystem(&IdList);
					(*IdLevelSystem).Start();
					IdList.setIdLevelSystem(IdLevelSystem);		
				}
				/****************************/

				ControlSystem.setPhase("Player");
			}
			if (!strcmp(State, "Pause")) {

				/* Создание нужных объектов */
				/****************************/
				if (!IdSubMenu) {
					IdSubMenu = new classSubMenu(&IdList);
					IdList.setIdSubMenu(IdSubMenu);
				}
				/****************************/

				ControlSystem.setPhase("Pause");
			}
			Phase = 2;
		}

		if (!strcmp(State, "Game")) {
			classLocation* IdLocation = static_cast<classLocation*>(IdList.getIdLocation());
			(*IdLocation).LiveObjects(); // Запуск повеения объектов
		}

		ControlSystem.KeyboardInput();
		Camera.CameraSetMove();
		Window.clear();
		GraphicSystem.DrawTextures();
		Window.display();
	}
	Window.close();
	return;
}

