#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include"Manager.h"
#include"Student.h"
#include"Teacher.h"

//进入管理员子菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1)//添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			man->cleanFile();
		}
		else
		{
			cout << "注销成功" << endl;
			delete manager;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生子菜单
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
			cout << "注销成功" << endl;
			delete student;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入老师子菜单
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
			cout << "注销成功" << endl;
			delete teacher;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登陆
void LoginIn(string filename, int type)//type---登陆类型
{
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	if (!ifs.is_open())
	{
		cout << "为空或不存在" << endl;
		ifs.close();
		return;
	}


	int id = 0;
	string name;
	string pwd;
	if (type == 1)//学生
	{
		cout << "请输入学号" << endl;
		cin >> id;
	}
	else if (type == 2)//教师
	{
		cout << "请输入职工号" << endl;
		cin >> id;
	}

	cout << "请输入用户名" << endl;
	cin >> name;

	cout << "请输入密码" << endl;
	cin >> pwd;

	if (type == 1)//学生
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				studentMenu(person);

				return;
			}

		}
	}
	else if (type == 2)//教师
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "老师验证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				teacherMenu(person);

				return;
			}

		}
	}
	else if (type == 3)//管理员
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				managerMenu(person);

				return;
			}

		}
	}

	cout << "验证失败" << endl;
	system("pause");
	system("cls");
	return;

}


int main()
{
	int select = 0;

	while (true)
	{
		cout << "*********************欢迎来到机房预约系统*********************" << endl;
		cout << endl << "请输入选择你的身份" << endl;
		cout << "\t\t ------------------------------------ \n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             1.学生                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             2.老师                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             3.管理员               |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             0.退出                 |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t ------------------------------------ \n";

		cout << "请输入你的选择：";
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}
