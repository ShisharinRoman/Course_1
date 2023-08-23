/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: GraphicSystem.cpp                                     */
/* Abstract: This is a simple C++ program                          */
/* Description ���������� ������� ������ classGraphicSystem        */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include<cstring>
#include"GraphicSystem.h"
#include"..\\Objects\\OtherObjects\\Camera.h"
#include"IdList.h"

classGraphicSystem::structSpriteInformation::structSpriteInformation() {
	Sprite = nullptr;
	Coordinate = nullptr;
	Priority = 0;
	CameraDependent = false;
	return;
}


classGraphicSystem::classGraphicSystem(void* _IdList) {
	Size = 0;
	SpriteInformation = new structSpriteInformation[40];
	vIdList = _IdList;
	return;
}


void classGraphicSystem::putSprite(sf::Sprite* _IdSprite, structPoint* _CoordinateSprite, int _Priority, bool _CameraDependent) {
	SpriteInformation[Size].Sprite = _IdSprite;
	SpriteInformation[Size].Coordinate = _CoordinateSprite;
	SpriteInformation[Size].Priority = _Priority;
	SpriteInformation[Size].CameraDependent = _CameraDependent;
	Size++;
	Sort = false;
	return;
}

void classGraphicSystem::putSpriteArray(sf::Sprite** _IdSpriteArray, structPoint** _CoordinateSpriteArray, int _Size, int _Priority, bool _CameraDependent) {
	for (int i = 0; i < _Size; i++) {
		SpriteInformation[Size].Sprite = _IdSpriteArray[i];
		SpriteInformation[Size].Coordinate = _CoordinateSpriteArray[i];
		SpriteInformation[Size].Priority = _Priority;
		SpriteInformation[Size].CameraDependent = _CameraDependent;
		Size++;
	}
	Sort = false; 
	return;
}

void classGraphicSystem::deleteSprite(sf::Sprite* _IdSprite) {
	bool DeleteSprite = false;
	for (int i = 0; i < Size; i++) {
		if (SpriteInformation[i].Sprite == _IdSprite) {
			DeleteSprite = true;
		}
		if (i + 1 < Size) {
			if (DeleteSprite == true) {
				SpriteInformation[i] = SpriteInformation[i + 1]; // �������� �������� ��� "��������" "���������" �������
			}
		}
	}
	Sort = false;
	Size--;
	return;
}

void classGraphicSystem::deleteSpriteArray(sf::Sprite* _IdSprite, int _Size) {
	bool DeleteSprite = false;
	for (int i = _Size; i < Size; i++) {
		if (SpriteInformation[i - _Size].Sprite == _IdSprite) {
			DeleteSprite = true;
		}
		if (DeleteSprite == true) {
			SpriteInformation[i - _Size] = SpriteInformation[i]; // �������� �������� ��� "��������" "��������" ��������
		}
	}
	Size -= _Size;
	Sort = false;
	return;
}

void classGraphicSystem::DrawTextures() {
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	sf::RenderWindow* IdWindow = static_cast<sf::RenderWindow*>((*IdList).getIdWindow());
	classCamera* IdCamera = static_cast<classCamera*>((*IdList).getIdCamera());

	if (Sort == false) {// ���� ������ �� ����������
		SortArray();
	}

	/* ��������� �������� */
	/**********************/
	for (int i = 0; i < Size; i++) {
		if (SpriteInformation[i].CameraDependent) {
			(*SpriteInformation[i].Sprite).setPosition(((*SpriteInformation[i].Coordinate).X - (*IdCamera).CameraCoordinate.X), ((*SpriteInformation[i].Coordinate).Y - (*IdCamera).CameraCoordinate.Y));
			(*IdWindow).draw(*(SpriteInformation[i].Sprite));
		}
		else {
			(*SpriteInformation[i].Sprite).setPosition((*SpriteInformation[i].Coordinate).X, (*SpriteInformation[i].Coordinate).Y);
			(*IdWindow).draw(*(SpriteInformation[i].Sprite));
		}
	}
	/**********************/

	return;
}

void classGraphicSystem::SortArray() {

	int MinPriority;
	int MinElement;
	structSpriteInformation TempleSpriteInformation;

	/* ���������� �������� �� �� ���������� ���������  */
	/* (������� ���� � ������� ����������� ��          */
	/* �����������).                                   */
	/***************************************************/
	for (int i = 0; i < Size; i++) {
		MinPriority = 100;
		for (int j = i; j < Size; j++) {
			if (MinPriority > SpriteInformation[Size].Priority) {
				MinPriority = SpriteInformation[Size].Priority;
				MinElement = j;
			}
		}
		TempleSpriteInformation = SpriteInformation[i];
		SpriteInformation[i] = SpriteInformation[MinElement];
		SpriteInformation[MinElement] = TempleSpriteInformation;
	}
	/***************************************************/

	Sort = true; // ������ ������������
	return;
}