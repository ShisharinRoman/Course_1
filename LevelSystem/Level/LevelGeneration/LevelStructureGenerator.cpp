/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: LevelStructure.cpp                                    */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������� ������ classLevelStructure      */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include <cmath>
#include"LevelGeneration.h"

classLevelStructureGenerator::classLevelStructureGenerator(int RoomNumber, int LvlNumber, int* _SizeVer, int* _SizeHor, structPoint* _StartPos) {
	SizeVer = _SizeVer;
	SizeHor = _SizeHor;
	StartPos = _StartPos;
	SizeMap = (RoomNumber - 4) * 2 + 1; // ���������� ������� �� "������" ����� ������
	Center = (RoomNumber - 4); // ���������� ������ ������
	LevelNumber = LvlNumber;

	/* ��������� ��������� �������� */
	/********************************/
	RandomRangeCreateBossRoom = 8;
	LimitArtifactRoom = 1;
	RoomNumberNeed = 0;
	LimitShopRoom = 1;
	LimitBossRoom = 1;
	NowIdRoom = 1;
	NextCoordinate = structPoint(0, 0);
	Diagonal = 0;
	DirCenterNext = 1;
	Dir = 'r';
	RoomPlaced = false;
	BossRoomCreate = false;
	StartVer = -1;
	StartHor = -1;
	FinishVer = -1;
	FinishHor = -1;
	/********************************/

	/* �������� ����� */
	/********************************/
	LevelMap = new int* [SizeMap];
	LevelMapId = new int* [SizeMap];

	for (int i = 0; i < SizeMap; i += 1) {
		LevelMap[i] = new int[SizeMap];
		LevelMapId[i] = new int[SizeMap];
		for (int j = 0; j < SizeMap; j += 1) {
			if ((i == 0) || (j == 0) || (i == SizeMap - 1) || (j == SizeMap - 1)) { // ����������� ���� �������
				LevelMap[i][j] = -1;
				LevelMapId[i][j] = -1;
			}
			else {
				LevelMap[i][j] = 0;
				LevelMapId[i][j] = 0;
			}

		}
	}
	/********************************/

	LevelMap[Center][Center] = 1; // ��������� ��������� ������� � ������ ������
	LevelMapId[Center][Center] = NowIdRoom++; // ������������ ���. ������� ������ "1" 
	RoomNumberNeed = RoomNumber;
}

bool classLevelStructureGenerator::CheckCanPlacedRoom(int Room, int* Pos) {
	bool res = false;
	int CanPosition = 0;
	switch (Room) {
	case 2:
		if (RoomNumberNeed >= 1) {
			*Pos = 1;
			res = true;
		}
		break;
	case 3:
		if ((RoomNumberNeed == 0) && (abs(NextCoordinate.Y - Center) + abs(NextCoordinate.X - Center) > LevelNumber) && (LimitArtifactRoom > 0)) {
			*Pos = 1;
			res = true;
		}
		break;
	case 4:
		if ((LimitShopRoom > 0) && (abs(NextCoordinate.Y - Center) + abs(NextCoordinate.X - Center) >= LevelNumber) && (RoomNumberNeed == 0)) {
			*Pos = 1;
			res = true;
		}
		break;
	case 5:
		if (rand() % RandomRangeCreateBossRoom == 0) {
			if ((LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] != 3) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] != 3) && (LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] != 3) && (LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] != 3) &&
				(LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] != 4) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] != 4) && (LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] != 4) && (LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] != 4)) {
				int CounterVoid = 0;
				if (LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] <= 0) CounterVoid++;
				if (LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] <= 0) CounterVoid++;
				if (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] <= 0) CounterVoid++;
				if (LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] <= 0) CounterVoid++;
				if ((RoomNumberNeed + LimitArtifactRoom + LimitShopRoom == 0) && (CounterVoid == 3)) {
					*Pos = 1;
					res = true;
				}
			}
		}
		else {
			RandomRangeCreateBossRoom--;
		}
		break;
	case 6:
		if (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] == 0) CanPosition = 1;
		if (LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] == 0) CanPosition = 2;
		if ((RoomNumberNeed >= 2) && (CanPosition != 0)) {
			*Pos = CanPosition;
			res = true;
		}
		break;
	case 7:
		if (LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] == 0) CanPosition = 1;
		if (LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] == 0) CanPosition = 2;
		if ((RoomNumberNeed >= 2) && (CanPosition != 0)) {
			*Pos = CanPosition;
			res = true;
		}
		break;
	case 8:
		if ((LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] == 0) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] == 0))     CanPosition = 1;
		if ((LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] == 0) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X - 1] == 0)) CanPosition = 2;
		if ((LevelMap[NextCoordinate.Y - 1][NextCoordinate.X + 1] == 0) && (LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] == 0)) CanPosition = 3;
		if ((RoomNumberNeed >= 3) && (CanPosition != 0)) {
			*Pos = CanPosition;
			res = true;
		}
		break;
	case 9:
		if ((LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] == 0) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X + 1] == 0)) CanPosition = 1;
		if ((LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] == 0) && (LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] == 0))     CanPosition = 3;
		if ((LevelMap[NextCoordinate.Y - 1][NextCoordinate.X - 1] == 0) && (LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] == 0)) CanPosition = 4;
		if ((RoomNumberNeed >= 3) && (CanPosition != 0)) {
			*Pos = CanPosition;
			res = true;
		}
		break;
	case 10:
		if ((LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] == 0) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X + 1] == 0)) CanPosition = 1;
		if ((LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] == 0) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] == 0))     CanPosition = 2;
		if ((LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] == 0) && (LevelMap[NextCoordinate.Y - 1][NextCoordinate.X - 1] == 0)) CanPosition = 4;
		if ((RoomNumberNeed >= 3) && (CanPosition != 0)) {
			*Pos = CanPosition;
			res = true;
		}
		break;
	case 11:
		if ((LevelMap[NextCoordinate.Y + 1][NextCoordinate.X - 1] == 0) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] == 0)) CanPosition = 2;
		if ((LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] == 0) && (LevelMap[NextCoordinate.Y - 1][NextCoordinate.X + 1] == 0))  CanPosition = 3;
		if ((LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] == 0) && (LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] == 0))     CanPosition = 4;
		if ((RoomNumberNeed >= 3) && (CanPosition != 0)) {
			*Pos = CanPosition;
			res = true;
		}
		break;
	case 12:
		if ((LevelMap[NextCoordinate.Y + 1][NextCoordinate.X + 1] == 0) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] == 0) && (LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] == 0)) CanPosition = 1;
		if ((LevelMap[NextCoordinate.Y + 1][NextCoordinate.X - 1] == 0) && (LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] == 0) && (LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] == 0)) CanPosition = 2;
		if ((LevelMap[NextCoordinate.Y - 1][NextCoordinate.X + 1] == 0) && (LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] == 0) && (LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] == 0)) CanPosition = 3;
		if ((LevelMap[NextCoordinate.Y - 1][NextCoordinate.X - 1] == 0) && (LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] == 0) && (LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] == 0)) CanPosition = 4;
		if ((RoomNumberNeed >= 4) && (CanPosition != 0)) {
			*Pos = CanPosition;
			res = true;
		}
		break;
	}
	return res;
}

bool classLevelStructureGenerator::RoomCreate() {
	bool res = true;
	int RoomCanList[15]; // ������ ����� �������, ������� ����� ���������
	int RoomCanPos[15]; // ������ �������, ��� ����� ��������� ��� �������
	int i = 0;
	if (RoomNumberNeed >= 1) {
		RoomCanList[0] = 1; // ���������� ����� ������� "����������"
		RoomCanList[1] = 1;
		RoomCanList[2] = 1;
	}

	if (RoomNumberNeed >= 1) {
		for (i = 3; i < 5; i++) {
			RoomCanList[i] = 2; // ���������� ������������ ���������� ��������� (��� ���������� ����� ������)
		}
	}

	for (int j = 2; j < 13; j++) {
		if (CheckCanPlacedRoom(j, &RoomCanPos[i])) { // ��������, ����� �� ������� ���� j ������������� � ���� �����.
			RoomCanList[i++] = j; // ���������� ������ ���� �������, � ������ ������
		}
	}

	int Length = i; // ������� ����� �������
	if (Length != 0) {

		int RandNumb = rand() % Length; // ����� ��������� �������

		if (RoomCanList[RandNumb] != 1) {
			RoomPlaced = true;
		}

		/* ���������� ������� �� ����� ������ */
		/**************************************************************/
		/* ���� ������� ������� �� ���������� "���������", ��         */
		/* ��������������� ������� �������, ������ ����������         */
		/* ���������� "���������" � ������� ����� ����������� ������� */
		/* � ����� �� ���� ������ � ����� �� ������� ������           */
		/* ���������������� �������. ����� ����������� ���-��         */
		/* ������, ������� ����� ���������.                           */
		/**************************************************************/
		switch (RoomCanList[RandNumb]) {
		case 1: // ������� "��������"
			res = false;
			break;
		case 2:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			RoomNumberNeed--;
			break;
		case 3:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			LimitArtifactRoom--; 
			break;
		case 4:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			LimitShopRoom--;
			break;
		case 5:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			LimitBossRoom--;
			break;
		case 6:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			if (RoomCanPos[RandNumb] == 1) {
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X] = NowIdRoom;
			}
			else {
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X] = NowIdRoom;
			}
			RoomNumberNeed -= 2;
			break;
		case 7:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			if (RoomCanPos[RandNumb] == 1) {
				LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y][NextCoordinate.X + 1] = NowIdRoom;
			}
			else {
				LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y][NextCoordinate.X - 1] = NowIdRoom;
			}
			RoomNumberNeed -= 2;
			break;
		case 8:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			if (RoomCanPos[RandNumb] == 1) {
				LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y][NextCoordinate.X + 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 2) {
				LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y][NextCoordinate.X - 1] = NowIdRoom;
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X - 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 3) {
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X + 1] = NowIdRoom;
			}
			RoomNumberNeed -= 3;
			break;
		case 9:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			if (RoomCanPos[RandNumb] == 1) {
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X + 1] = NowIdRoom;
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 3) {
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y][NextCoordinate.X + 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 4) {
				LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y][NextCoordinate.X - 1] = NowIdRoom;
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X - 1] = NowIdRoom;
			}
			RoomNumberNeed -= 3;
			break;
		case 10:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			if (RoomCanPos[RandNumb] == 1) {
				LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y][NextCoordinate.X + 1] = NowIdRoom;
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X + 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 2) {
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y][NextCoordinate.X - 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 4) {
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X - 1] = NowIdRoom;
			}
			RoomNumberNeed -= 3;
			break;
		case 11:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			if (RoomCanPos[RandNumb] == 2) {
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X - 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 3) {
				LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y][NextCoordinate.X + 1] = NowIdRoom;
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X + 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 4) {
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y][NextCoordinate.X - 1] = NowIdRoom;
			}
			RoomNumberNeed -= 3;
			break;
		case 12:
			LevelMapId[NextCoordinate.Y][NextCoordinate.X] = NowIdRoom;
			LevelMap[NextCoordinate.Y][NextCoordinate.X] = RoomCanList[RandNumb];
			if (RoomCanPos[RandNumb] == 1) {
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y][NextCoordinate.X + 1] = NowIdRoom;
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X + 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 2) {
				LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y + 1][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y][NextCoordinate.X - 1] = NowIdRoom;
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y + 1][NextCoordinate.X - 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 3) {
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X + 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y][NextCoordinate.X + 1] = NowIdRoom;
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X + 1] = NowIdRoom;
			}
			if (RoomCanPos[RandNumb] == 4) {
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMap[NextCoordinate.Y - 1][NextCoordinate.X - 1] = RoomCanList[RandNumb];
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X] = NowIdRoom;
				LevelMapId[NextCoordinate.Y][NextCoordinate.X - 1] = NowIdRoom;
				LevelMapId[NextCoordinate.Y - 1][NextCoordinate.X - 1] = NowIdRoom;
			}
			RoomNumberNeed -= 4;
			break;
		}
		if (res == true) {
			NowIdRoom++; 
		}
	}
	else {
		res = false;
	}
	return res;
}

void classLevelStructureGenerator::NextPosition() {
	do {
		/* ����� ��������� ��������� ����������   */
		/* ������� ���������� �� ���� �����.      */
		/* ����������� ����������� ���������,     */
		/* ����� ���� ��������� �� ����� ��       */
		/* ���������� �����, �� ����������        */
		/* ����������� � ������������ ����������� */
		/* ���������. ���� ���, �� �����������    */
		/* ��������� ����������.                  */
		switch (Dir) {
		case 'u': // ����������� ��������� - ����� � ������
			if (Diagonal < DirCenterNext - 1) {
				NextCoordinate.X++;
				NextCoordinate.Y--;
				Diagonal++;
			}
			else { 
				/* ��� ��� ��� ��������� ��������� � */
				/* �����, �� ����� ����������        */
				/* ������� ���������� �����.         */
				if (RoomPlaced || (BossRoomCreate)) { // ���� ������� �� ������� ����� ����������

					/* ���������� ���������������� ��� �������� �� ������ */
					/* �� ����� ����������.                               */
					/******************************************************/
					NextCoordinate.X = Center;
					NextCoordinate.Y = Center - DirCenterNext;
					/******************************************************/

					DirCenterNext++; // ���������� ������� �����
					RoomPlaced = false;
				}
				Diagonal = 1;
				Dir = 'r';
			}
			break;
		case 'r': // ����������� ��������� - ������ � ����
			if (Diagonal < DirCenterNext) {
				NextCoordinate.X++;
				NextCoordinate.Y++;
				Diagonal++;
			}
			else {
				Diagonal = 1;
				Dir = 'd';
			}
			break;
		case 'd': // ����������� ��������� - ���� � �����
			if (Diagonal < DirCenterNext) {
				NextCoordinate.X--;
				NextCoordinate.Y++;
				Diagonal++;
			}
			else {
				Diagonal = 1;
				Dir = 'l';
			}
			break;
		case 'l': // ����������� ��������� - ���� � �����
			if (Diagonal < DirCenterNext) {
				NextCoordinate.X--;
				NextCoordinate.Y--;
				Diagonal++;
			}
			else {
				Diagonal = 1;
				Dir = 'u';
			}
			break;
		}

		/* ��� ����������� ������� ����� ��� ��������� */
		/* ������� ������ ����� �� ��������� �������,   */
		/* ������� ���������� ����� ������� �����.      */
		/************************************************/
		if (DirCenterNext == SizeMap) {
			NextCoordinate.X = Center;
			NextCoordinate.Y = Center - DirCenterNext;
			Diagonal = 0;
			DirCenterNext = 1;
			Dir = 'r';
		}
		/************************************************/

	} while ((NextCoordinate.X < 1) || (NextCoordinate.Y < 1) 
		|| (NextCoordinate.X > SizeMap - 2) || (NextCoordinate.Y > SizeMap - 2)); // ���� ���������� ��������� ������ (��� ������� �� �����) �������, �� ������������� ����� ����� ���������
	return;
}

void classLevelStructureGenerator::GenerateTypeRoom() {
	NextCoordinate = structPoint(Center, Center - 1); // ����������� ��������� ��� ������ ����������� �������
	while (RoomNumberNeed + LimitArtifactRoom + LimitBossRoom + LimitShopRoom > 0) { // ���� ��������, ���� ������ ���-�� ������ �� �����������
		if ((LevelMap[NextCoordinate.Y][NextCoordinate.X] == 0) &&
			((LevelMap[NextCoordinate.Y + 1][NextCoordinate.X] > 0) || (LevelMap[NextCoordinate.Y - 1][NextCoordinate.X] > 0)
				|| (LevelMap[NextCoordinate.Y][NextCoordinate.X + 1] > 0) 
				|| (LevelMap[NextCoordinate.Y][NextCoordinate.X - 1] > 0))) { // ������� ��������, ������ � ��� ������, ���� ������� ����� �� ������ � �� �������� "���������" ���� �������
			RoomCreate();
		}
		/* ��������� ��������� �������� ��� ��������� ������� � ������ */
		/********************************************************************************************/
		if ((RoomNumberNeed + LimitArtifactRoom + LimitShopRoom == 0) && (BossRoomCreate == false)) { 
			BossRoomCreate = true;
			Diagonal = 0;
			DirCenterNext = 1;
			Dir = 'r';
			RoomPlaced = false;
			NextCoordinate = structPoint(Center, Center - 1);
		}
		/**********************************************************************************************/
		NextPosition();
	}
}

void classLevelStructureGenerator::IndentifySizeVer() {
	bool ExistRoom = false; // ��������� ���������� �� �������

	for (int i = 0; i < SizeMap; i++) {
		/* �������� ���������� �� ������� � ������ i */
		/*********************************************/
		ExistRoom = false;
		for (int j = 0; j < SizeMap; j++) {
			if (LevelMap[i][j] > 0) {
				ExistRoom = true; 
				break;
			}
		}
		/*********************************************/

		if ((StartVer == -1) && (ExistRoom)) {
			StartVer = i; // ����������� ������� ���������� �������
		}
		if ((StartVer != -1) && (!ExistRoom)) {
			FinishVer = i - 1; // ����������� ���������� ���������� �������
			break;
		}
	}
	*SizeVer = FinishVer - StartVer + 1; // ���������� ������������� ������� "������" �������
	return;
}

void classLevelStructureGenerator::IndentifySizeHor() {
	bool ExistRoom = false; // ��������� ���������� �� �������
	for (int j = 0; j < SizeMap; j++) {
		/* �������� ���������� �� ������� � ������ j */
		/*********************************************/
		ExistRoom = false;
		for (int i = 0; i < SizeMap; i++) {
			if (LevelMap[i][j] > 0) {
				ExistRoom = true;
				break;
			}
		}
		/*********************************************/

		if ((StartHor == -1) && (ExistRoom)) {
			StartHor = j; // ����������� ������ ��������� ������
		}
		if ((StartHor != -1) && (!ExistRoom)) {
			FinishHor = j - 1; // ����������� ��������� ��������� ������
			break;
		}
	}
	*SizeHor = FinishHor - StartHor + 1; // ���������� ��������������� ������� "������" �����
	return;
}

void classLevelStructureGenerator::CompressionMap() {

	int i, j;

	IndentifySizeVer();
	IndentifySizeHor();

	/* ���������� ������ � ������� ����� */
	/*************************************/
	*(SizeHor) = (*SizeVer) + 2;
	*(SizeVer) = (*SizeHor) + 2;
	/*************************************/

	/* �������� ��������� ���� */
	/*************************************/
	int** ReserveMap = new int* [*(SizeVer)];
	int** ReserveMapId = new int* [*(SizeVer)];

	for (i = 0; i < *(SizeVer); i++) {
		ReserveMap[i] = new int[*(SizeHor)];
		ReserveMapId[i] = new int[*(SizeHor)];
	}
	/*************************************/

	/* ����������� �� "��������" ����� �� ��������� ����� */
	/******************************************************/
	for (i = 0; i < *(SizeVer); i++) {
		for (j = 0; j < *(SizeHor); j++) {
			if ((i == 0) || (j == 0) || (i == *(SizeVer)) || (j == *(SizeHor))) {
				ReserveMap[i][j] = 0;
				ReserveMapId[i][j] = 0;
			}
			else {
				ReserveMap[i][j] = LevelMap[i + StartVer - 1][j + StartHor - 1];
				ReserveMapId[i][j] = LevelMapId[i + StartVer - 1][j + StartHor - 1];
			}
		}
	}
	/******************************************************/

	/*  �������� "��������" ����   */
	/*******************************/
	for (i = 0; i < SizeMap; i++) {
		delete[] LevelMap[i];
		delete[] LevelMapId[i];
	}
	delete[] LevelMap;
	delete[] LevelMapId;
	/******************************/

	/* �������� "������" ���� � ����������� � ��� ������ �� */
	/* ��������� ����.                                      */
	/********************************************************/
	LevelMap = new int* [*SizeVer];
	LevelMapId = new int* [*SizeVer];
	for (i = 0; i < *SizeVer; i++) {
		LevelMap[i] = new int[*SizeHor];
		LevelMapId[i] = new int[*SizeHor];
	}

	for (i = 0; i < *SizeVer; i++) {
		for (j = 0; j < *SizeHor; j++) {
			LevelMap[i][j] = ReserveMap[i][j];
			LevelMapId[i][j] = ReserveMapId[i][j];
		}
	}
	/*******************************************************/

	/* �������� ��������� ���� */
	/***************************/
	for (i = 0; i < *SizeVer; i++) {
		delete ReserveMap[i];
		delete ReserveMapId[i];
	}
	/***************************/
	return;
}

void classLevelStructureGenerator::FindStartRoom() {
	bool AllBreak = false;

	for (int i = 0; i < *SizeVer; i++) {
		for (int j = 0; j < *SizeHor; j++) {
			if (LevelMap[i][j] == 1) { // ��������� ������� �������
				AllBreak = true;
				*StartPos = structPoint(i, j); // ����������� ��������� ��������� �������
				break;
			}
		}
		if (AllBreak) {
			break;
		}
	}
	return;
}

void classLevelStructureGenerator::GenerateStructure(int RandomTypeGeneration) {
	/* ���� RandomTypeGeneration = 1, �� ����������� */
	/* ��������� ��������� �����.                    */
	if (RandomTypeGeneration == 1) {
		GenerateTypeRoom();
	}
	CompressionMap();
}

int classLevelStructureGenerator::getNumberRoom() {
	return NowIdRoom;
}

int** classLevelStructureGenerator::getLevelMap() {
	return LevelMap;
}

int** classLevelStructureGenerator::getLevelMapId() {
	return LevelMapId;
}
