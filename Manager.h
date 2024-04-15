#pragma once
#include"Identity.h"
#include<vector>
#include"Teacher.h"
#include"Student.h"
#include<algorithm>
#include"ComputerRoom.h"

class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	//显示菜单
	void operMenu();

	//添加账号
	void addPerson();

	//显示账号
	void showPerson();

	//显示机房信息
	void showComputer();

	//清空文件
	void cleanFile();

	//初始化容器--老师和学生容器
	void initVectorST();

	//教师容器
	vector<Teacher>vTea;

	//学生容器
	vector<Student>vStu;

	//id去重
	bool checkRepeat(int id, int type);

	//初始化容器--机房容器
	void initVectorC();

	//机房信息容器
	vector<ComputerRoom>vCom;


	~Manager();
};

