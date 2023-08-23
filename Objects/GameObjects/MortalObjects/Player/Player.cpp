/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Player.cpp                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classPlayer              */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"Player.h"
#include"..\\..\\..\\..\\System\\KeyCodes.h"
#include"..\\..\\..\\..\\LevelSystem\\Location.h"
#define MaxSpeed 13

classPlayer::classPlayer(structPoint _Coordinate, void* _IdList) :
	classLiveObject(true, 3, 30, 30, _Coordinate, "images\\Player\\Player.png", 2, 30, 30, _IdList) {
	return;
}

void classPlayer::SetSpeed(int Action, float* Speed) {
	switch (Action) {
	case 0: // Замедление
		if (abs(*Speed) > 0.5) {
			*Speed -= (*Speed / abs(*Speed));
		}
		break;
	case 1: // Ускорение по направлениям вниз или вправо
		if (*Speed < 0) { // Если движение было не в ту сторону
			*Speed += 4;
		}
		else {
			if (*Speed < MaxSpeed) { // Ограничение скорости
				*Speed += 3;
			}
			else {
				*Speed = MaxSpeed;
			}
		}
		break;
	case 2: // Ускорение по направлениям вверх и влево
		if (*Speed > 0) { // Если движение было не в ту сторону
			*Speed -= 4;
		}
		else {
			if (*Speed > -MaxSpeed) { // Ограничение скорости
				*Speed -= 2;
			}
			else {
				*Speed = -MaxSpeed;
			}
		}
		break;
	}
	return;
}

void classPlayer::MoveSystem(int KeyCode) {
	switch (KeyCode) {
	case 0: // Остановка движения
		SetSpeed(0, &hspeed);
		SetSpeed(0, &vspeed);
		break;
	case VK_UP: // Движение вверх (Горизонтальная скорость обнуляется)
		hspeed = 0;
		SetSpeed(2, &vspeed);
		break;
	case VK_DOWN: // Движение вниз (Горизонтальная скорость обнуляется)
		hspeed = 0;
		SetSpeed(1, &vspeed);
		break;
	case VK_LEFT: // Движение влево (Вертикальная скорость обнуляется)
		SetSpeed(2, &hspeed);
		vspeed = 0;
		break;
	case VK_RIGHT: // Движение вправо (Вертикальная скорость обнуляеться)
		SetSpeed(1, &hspeed);
		vspeed = 0;
		break;
	}
	Move(); // Запуск движения
	system("cls");
	return;
}

classPlayer::~classPlayer() {
	return;
}