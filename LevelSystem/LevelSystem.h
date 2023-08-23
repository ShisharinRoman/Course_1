/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: LevelSystem.h                                         */
/* Abstract: This is a simple C++ program                          */
/* Description: Объявление класса classLevelSystem                 */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/



/* classLevelSystem                           */
/**********************************************/
/* classLevelSystem - класс, который является */
/* системой управления уровнями.              */
/**********************************************/
class classLevelSystem {
private:

	void* vIdList; // Указатель на структуру хранящую адресса
	int NumberLevel; // Номер уровня

	/* CreateNewLevel() - метод класса, который */
	/* создаёт новый уровень.                   */
	void CreateNewLevel();

	/* DeleteLevel() - метод класса, который    */
	/* удаляет текущий уровень.                 */
	void DeleteLevel();


public:

	/* classLevelSystem() - конструктор класса, */
	/* который принимает значения: указатель на */
	/* структуру хранящую адресса объектов.     */
	classLevelSystem(void* _IdList);

	/* Start() - метод класса, который начинает */
	/* создавать уровень.                       */
	void Start();
	
	/* NextLevel() - метод класса, который      */
	/* запускает удаление текущего уровня и     */
	/* создаёт новый.                           */
	void NextLevel();

	/* ~classLevelSustem() - деструктор класса  */
	~classLevelSystem();

};