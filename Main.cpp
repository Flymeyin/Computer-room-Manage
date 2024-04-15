#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"Manager.h"
#include"Student.h"
#include"Teacher.h"

//�������Ա�Ӳ˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1)//����˺�
		{
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			man->cleanFile();
		}
		else
		{
			cout << "ע���ɹ�" << endl;
			delete manager;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else
		{
			cout << "ע���ɹ�" << endl;
			delete student;
			system("pause");
			system("cls");
			return;
		}
	}
}

//������ʦ�Ӳ˵�
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			cout << "ע���ɹ�" << endl;
			delete teacher;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��½
void LoginIn(string filename, int type)//type---��½����
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "Ϊ�ջ򲻴���" << endl;
		ifs.close();
		return;
	}


	int id = 0;
	string name;
	string pwd;
	if (type == 1)//ѧ��
	{
		cout << "������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ
	{
		cout << "������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	if (type == 1)//ѧ��
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				studentMenu(person);

				return;
			}

		}
	}
	else if (type == 2)//��ʦ
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				teacherMenu(person);

				return;
			}

		}
	}
	else if (type == 3)//����Ա
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				managerMenu(person);

				return;
			}

		}
	}

	cout << "��֤ʧ��" << endl;
	system("pause");
	system("cls");
	return;

}


int main()
{
	int select = 0;

	while (true)
	{
		cout << "*********************��ӭ��������ԤԼϵͳ*********************" << endl;
		cout << endl << "������ѡ��������" << endl;
		cout << "\t\t ------------------------------------ \n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             1.ѧ��                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             2.��ʦ                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             3.����Ա               |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             0.�˳�                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t ------------------------------------ \n";

		cout << "���������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
