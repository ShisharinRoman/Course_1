/* figure .cpp                                                     */
/*******************************************************************/
/* Filename: LevelSystem.h                                         */
/* Abstract: This is a simple C++ program                          */
/* Description: ���������� ������ classLevelSystem                 */
/* Create Date: 2020 / 04 / 13                                     */
/* Author: Shisharin Roman Alexandrovich                           */
/* Notes / Platform / Copyright UNIX/Linux, Freeware               */
/*******************************************************************/



/* classLevelSystem                           */
/**********************************************/
/* classLevelSystem - �����, ������� �������� */
/* �������� ���������� ��������.              */
/**********************************************/
class classLevelSystem {
private:

	void* vIdList; // ��������� �� ��������� �������� �������
	int NumberLevel; // ����� ������

	/* CreateNewLevel() - ����� ������, ������� */
	/* ������ ����� �������.                   */
	void CreateNewLevel();

	/* DeleteLevel() - ����� ������, �������    */
	/* ������� ������� �������.                 */
	void DeleteLevel();


public:

	/* classLevelSystem() - ����������� ������, */
	/* ������� ��������� ��������: ��������� �� */
	/* ��������� �������� ������� ��������.     */
	classLevelSystem(void* _IdList);

	/* Start() - ����� ������, ������� �������� */
	/* ��������� �������.                       */
	void Start();
	
	/* NextLevel() - ����� ������, �������      */
	/* ��������� �������� �������� ������ �     */
	/* ������ �����.                           */
	void NextLevel();

	/* ~classLevelSustem() - ���������� ������  */
	~classLevelSystem();

};