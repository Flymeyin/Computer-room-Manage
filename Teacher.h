#pragma once
#include"Identity.h"
#include<vector>
#include"Teacher.h"
#include"Student.h"
#include<algorithm>
#include"ComputerRoom.h"

class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int empid, string name, string pwd);

	//��д����
	void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//ԤԼ���
	void validOrder();

	~Teacher();

	int m_empId;
};


