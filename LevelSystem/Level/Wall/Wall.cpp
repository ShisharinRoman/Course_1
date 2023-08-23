/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: Wall.cpp                                              */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов структуры structWall            */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"Wall.h"

structWall::structWall(){
		Point1.X = 0;
		Point1.Y = 0;
		Point2.X = 0;
		Point2.Y = 0;
		door = false;
		breakable = false;
		
	}

void structWall::setSpriteInformation(structPoint Point1, structPoint Point2) {

	Sprite.setPosition(Point1.X,Point1.Y);
	Sprite.setTextureRect(sf::IntRect(Point1.X,Point1.Y,Point2.X,Point2.Y));

	return;
}

void structWall::CreateSprite(sf::Texture* Texture) {

	Sprite.setTexture(*Texture);

	return;
}
