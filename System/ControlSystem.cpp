/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: ControlSystem.cpp                                     */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classControlSystem       */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"Conio.h"
#include"ControlSystem.h"
#include"..\\Objects\\OtherObjects\\MainMenu.h"
#include"..\\Objects\\GameObjects\\MortalObjects\\Player\\Player.h"
#include"IdList.h"
#include"KeyCodes.h"
#include"..\\Objects\\OtherObjects\\SubMenu.h"
#include"Game.h"

classControlSystem::classControlSystem(void* _IdList) {
	vIdList = _IdList;
}

void classControlSystem::setPhase(const char* _Phase) {
	Phase = _Phase;
	return;
}

void classControlSystem::KeyboardInput() {
	KeyCode = 0; // Обнудение кода клавиши
	ArrowPressed = false;
	if (_kbhit()) {
		KeyCode = _getch();
		if (KeyCode == 224) { // Если были нажаты стрелки
			ArrowPressed = true;
			KeyCode = _getch();
		}
	}
	ObjectControl();
	return;
}


void classControlSystem::ObjectControl() {
	classIdList* IdList = static_cast<classIdList*>(vIdList);

	if (!strcmp(Phase, "Main Menu")) { // Если управляемый объект "Главное меню"
		classMainMenu* IdMainMenu = static_cast<classMainMenu*>((*IdList).getIdMainMenu());
		/* Запуск определенных событий в завсимости от кода клавиши */
		/************************************************************/
		if (ArrowPressed == true) {
			(*IdMainMenu).ChangeState(KeyCode);
		}
		if (KeyCode == VK_ENTER) {
			(*IdMainMenu).EnterState();
		}
		/************************************************************/
	}

	if (!strcmp(Phase, "Player")) { // Если управляемый объект "Игрок"

		classPlayer* IdPlayer = static_cast<classPlayer*>((*IdList).getIdPlayer());
		(*IdPlayer).MoveSystem(KeyCode); // Передача кода клавиши

		if (KeyCode == VK_ESCAPE) {
			classGame* IdGame = static_cast<classGame*>((*IdList).getIdGame());
			(*IdGame).ChangeState("Pause");
		}
	}

	if (!strcmp(Phase, "Pause")) { // Если управляемый объект меню паузы
		classSubMenu* IdSubMenu = static_cast<classSubMenu*>((*IdList).getIdSubMenu());

		if (ArrowPressed) {
			(*IdSubMenu).ChangeState(KeyCode);
		}
		if (KeyCode == VK_ENTER) {
			(*IdSubMenu).EnterState();
		}
		if (KeyCode == VK_ESCAPE) {
			(*IdSubMenu).Exit();
		}
	}
	return;
}

