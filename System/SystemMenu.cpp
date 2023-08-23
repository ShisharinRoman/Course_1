/* figure.cpp                                                      */
/*******************************************************************/
/* Filename: SystemMenu.cpp                                        */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classSystemMenu          */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"KeyCodes.h"
#include"IdList.h"
#include"SystemMenu.h"

classSystemMenu::classSystemMenu(void* _IdList, int _WightSprite, int _HeightSprite) {
	vIdList = _IdList;
	HeightSprite = _HeightSprite;
	WightSprite = _WightSprite;;
	return;
}

void classSystemMenu::ChangeState(int KeyCode, int& SelectState) {

	if (KeyCode == VK_UP) {
		SelectState -= 1;
	}
	if (KeyCode == VK_DOWN) {
		SelectState += 1;
	}

	return;
}

void classSystemMenu::DrawSprite(structPoint* Coordinate, const char* _TextureName) {

	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classGraphicSystem* IdGraphicSystem = static_cast<classGraphicSystem*>((*IdList).getGraphicSystem());
	sf::Image Image;
	Image.loadFromFile(_TextureName);
	Texture.loadFromImage(Image);
	Sprite.setTexture(Texture);
	Sprite.setTextureRect(sf::IntRect(1, 1, WightSprite, HeightSprite));
	(*IdGraphicSystem).putSprite(&Sprite, Coordinate, 0, false);

	return;
}

classSystemMenu::~classSystemMenu() {
	classIdList* IdList = static_cast<classIdList*>(vIdList);
	classGraphicSystem* IdGraphicSystem = static_cast<classGraphicSystem*>((*IdList).getGraphicSystem());
	(*IdGraphicSystem).deleteSprite(&Sprite);
}