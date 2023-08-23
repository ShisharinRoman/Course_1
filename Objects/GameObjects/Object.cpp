/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Object.cpp                                            */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classObject              */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/


#include"..\\..\\System\\IdList.h"
#include"Object.h"
#include"MortalObjects\\Player\\Player.h"

classObject::classObject(int _LengthHitMask, int _HeightHitMask, structPoint _Coordinate, const char* _NameImage, int _Priority, int _LengthSprite, int _HeightSprite, void* _IdList) {
	HitMask.Length = _LengthHitMask;
	HitMask.Height = _HeightHitMask;
	Coordinate = _Coordinate;

	/* Координа отрисовки спрайта переносятся в левый верхний угол */
	/***************************************************************/
	CoordinateSprite.X = _Coordinate.X - (_LengthSprite / 2); 
	CoordinateSprite.Y = _Coordinate.Y - (_HeightSprite / 2);
	/***************************************************************/

	vIdList = _IdList;
	CreateSprite(_NameImage, _Priority);

	return;
}

void classObject::CreateSprite(const char* _NameImage, int _Priority) {
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classGraphicSystem* IdGraphicSystem = static_cast<classGraphicSystem*>((*IdList).getGraphicSystem());
	sf::Image Image;

	Image.loadFromFile(_NameImage);
	Texture.loadFromImage(Image);
	Sprite.setTexture(Texture);
	Sprite.setTextureRect(sf::IntRect(1, 1, HitMask.Length, HitMask.Height));
	(*IdGraphicSystem).putSprite(&Sprite, &CoordinateSprite, _Priority, true);

	return;
}

classObject::~classObject() {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classGraphicSystem* IdGraphicSystem = static_cast<classGraphicSystem*>((*IdList).getGraphicSystem());
	(*IdGraphicSystem).deleteSprite(&Sprite);

	return;
}

bool classObject::PlayerTouchObject() {

	bool res;

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classPlayer* IdPlayer = static_cast<classPlayer*>((*IdList).getIdPlayer());

	res = false;

	/* Проверка на столкновение */
	/****************************/
	if (!(((*IdPlayer).Coordinate.X - ((*IdPlayer).HitMask.Length / 2) > Coordinate.X + HitMask.Length / 2) || ((*IdPlayer).Coordinate.Y - ((*IdPlayer).HitMask.Height / 2) > Coordinate.Y + HitMask.Height / 2)
		|| ((*IdPlayer).Coordinate.X + ((*IdPlayer).HitMask.Length / 2) < Coordinate.X - HitMask.Length / 2) || ((*IdPlayer).Coordinate.Y + ((*IdPlayer).HitMask.Height / 2) < Coordinate.Y - HitMask.Height / 2))) {
		res = true;
	}
	/***************************/

	return res;
}
