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

	//��д����
	void operMenu();


	//������Ϣ����
	vector<ComputerRoom>vCom;
	//��ʼ������
	void initVectorC();
	//����ԤԼ
	void applyOrder();

	//�鿴ԤԼ
	void showOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	~Student();

	int m_Id;
};

