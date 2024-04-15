#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"globalFile.h"


class Identity//身份类---抽象类
{
public:

	//菜单
	virtual void operMenu() = 0;

	string m_Name;
	string m_Pwd;
};







