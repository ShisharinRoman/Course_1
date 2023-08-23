/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: PassNextLevel.cpp                                     */
/* Abstract: This is a simple C++ program                          */
/* Description: Реализация методов класса classPassNextLevel       */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/

#include"PassNextLevel.h"
#include"..\\..\\..\\..\\System\\IdList.h"
#include"..\\..\\..\\..\\LevelSystem\\LevelSystem.h"

classPassNextLevel::classPassNextLevel(void* _IdList, structPoint _Coordinate) : 
	classStaticObject(_Coordinate,30,30,"images\\StaticObjects\\PassNextLevelObj.png",3,40,40,_IdList,"Static",false) {
	return;
}

void classPassNextLevel::ObjectBehavior() {

	if (PlayerTouchObject()) { // Если игрок коснулся данного объекта
		classIdList* IdList = static_cast<classIdList*>(vIdList);
		classLevelSystem* IdLevelSystem = static_cast<classLevelSystem*>((*IdList).getIdLevelSystem());
		(*IdLevelSystem).NextLevel(); // Переход на следующий уровень
	}

	return;
}
