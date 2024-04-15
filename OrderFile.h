#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<fstream>
#include<string>


class OrderFile
{
public:

	OrderFile();

	//更新预约记录
	void updataOrder();

	//记录容器  key---记录条数  value---记录的键值对信息
	map<int, map<string, string>>m_orderData;

	//预约记录条数
	int m_Size;

	~OrderFile();
};

