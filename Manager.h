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

	//��ʾ�˵�
	void operMenu();

	//����˺�
	void addPerson();

	//��ʾ�˺�
	void showPerson();

	//��ʾ������Ϣ
	void showComputer();

	//����ļ�
	void cleanFile();

	//��ʼ������--��ʦ��ѧ������
	void initVectorST();

	//��ʦ����
	vector<Teacher>vTea;

	//ѧ������
	vector<Student>vStu;

	//idȥ��
	bool checkRepeat(int id, int type);

	//��ʼ������--��������
	void initVectorC();

	//������Ϣ����
	vector<ComputerRoom>vCom;


	~Manager();
};

