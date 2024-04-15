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

	//重写父类
	void operMenu();

	//查看所有预约
	void showAllOrder();

	//预约审核
	void validOrder();

	~Teacher();

	int m_empId;
};


