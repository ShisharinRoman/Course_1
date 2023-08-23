/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: Camera.cpp                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: –евлизаци€ методов класса classCamera              */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include<cmath>
#include"Camera.h"
#include"..\\..\\System\\IdList.h"
#include"..\\..\\Objects\\GameObjects\\MortalObjects\\Player\\Player.h"
#include"..\\..\\LevelSystem\\Location.h"

classCamera::classCamera(void* IdList) {
	vIdList = IdList;
	return;
}

void classCamera::setCoordinate(structPoint _CameraCoordinate) {
	CameraCoordinate = _CameraCoordinate;

	/* ќбнуление скоростей */
	/***********************/
	vspeed = 0;
	hspeed = 0;
	/***********************/

	return;
}

void classCamera::CameraSetMove() {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classPlayer* IdPlayer = static_cast<classPlayer*>((*IdList).getIdPlayer());

	if (IdPlayer) { // »грок существует
		hspeed = 0;
		vspeed = 0;

		/* Ќахождение рассто€ни€ от игрока до центра камеры (ѕо горизонтали */
		/* и вертикали).                                                    */
		/********************************************************************/
		int DirectX = CameraCoordinate.X + 320 - (*IdPlayer).Coordinate.X;
		int DirectY = CameraCoordinate.Y + 240 - (*IdPlayer).Coordinate.Y;
		/********************************************************************/

		if ((abs(DirectX) > 65) || (abs(DirectY) > 65)) { // ≈сли игрок удалилс€ от центра камеры 

			classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());
			int RoomType = (*IdLocation).getRoomType();
			int PlayerHspeed = (*IdPlayer).getHspeed();
			int PlayerVspeed = (*IdPlayer).getVspeed();

			/* ”становка скоростей камеры в зависимости от направлени€ */
			/* движени€ игрока, типы комнаты и рассто€ни€ игрока до    */
			/* центра карты.                                           */
			/***********************************************************/
			if ((DirectX < 0) && (RoomType > 6) && (PlayerHspeed > 0)) {
				hspeed = PlayerHspeed;
			}
			if ((DirectX > 0) && (RoomType > 6) && (PlayerHspeed < 0)) {
				hspeed = PlayerHspeed;
			}
			if ((DirectY < 0) && ((RoomType == 6) || (RoomType > 7)) && (PlayerVspeed > 0)) {
				vspeed = PlayerVspeed;
			}
			if ((DirectY > 0) && ((RoomType == 6) || (RoomType > 7)) && (PlayerVspeed < 0)) {
				vspeed = PlayerVspeed;
			}
			/***********************************************************/
		}
		CameraMove();
	}

	return;
}

void classCamera::CameraMove() {
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classLocation* IdLocation = static_cast<classLocation*>((*IdList).getIdLocation());
	int RoomType = (*IdLocation).getRoomType();

	if (RoomType > 5) {

		/* ѕроверка на то, что камера не выйдет за */
		/* гроницы допстимой площади (ƒопустима€   */
		/* площадь зависит от типа комнаты).       */
		/*******************************************/
		if (RoomType != 11) { // Ћева€ граница допустимой площади
			if (CameraCoordinate.X + hspeed < 0) {
				hspeed = 0;
				CameraCoordinate.X = 0;
			}
		}
		else {
			if (CameraCoordinate.X + hspeed < -640) {
				hspeed = 0;
				CameraCoordinate.X = -640;
			}
		}

		if ((RoomType != 6) && (RoomType != 11)) { // ѕрава€ граница допустимой площади
			if (CameraCoordinate.X + 640 + hspeed > 1280) {
				hspeed = 0;
				CameraCoordinate.X = 640;
			}
		}
		else {
			if (CameraCoordinate.X + 640 + hspeed > 640) {
				hspeed = 0;
				CameraCoordinate.X = 0;
			}
		}

		if (CameraCoordinate.Y + vspeed < 0) { // ¬ерхн€€ граница допустимой площади
			vspeed = 0;
			CameraCoordinate.Y = 0;
		}

		if (RoomType != 7) { // Ќижн€€ граница допустимой площади
			if (CameraCoordinate.Y + 480 + vspeed > 960) {
				vspeed = 0;
				CameraCoordinate.Y = 480;
			}
		}
		else {
			if (CameraCoordinate.Y + 480 + vspeed > 480) {
				vspeed = 0;
				CameraCoordinate.Y = 0;
			}
		}
		/*****************************************/

	}

	/* »зменение координат камеры в зависимости от */
	/* от скоростей.                               */
	/***********************************************/
	CameraCoordinate.X = CameraCoordinate.X + hspeed;
	CameraCoordinate.Y = CameraCoordinate.Y + vspeed;
	/***********************************************/

	return;
}

