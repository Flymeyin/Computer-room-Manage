#pragma once
#include"Identity.h"
#include<vector>
#include"Teacher.h"
#include"Student.h"
#include<algorithm>
#include"ComputerRoom.h"
#include"OrderFile.h"


class Student :public Identity
{
public:
	Student();

	Student(int id, string name, string pwd);

	//重写父类
	void operMenu();


	//机房信息容器
	vector<ComputerRoom>vCom;
	//初始化机房
	void initVectorC();
	//申请预约
	void applyOrder();

	//查看预约
	void showOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	~Student();

	int m_Id;
};

