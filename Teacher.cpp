#include"Teacher.h"

Teacher::Teacher()
{}

Teacher::Teacher(int empid, string name, string pwd)
{
	this->m_empId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//重写父类---菜单
void Teacher::operMenu()
{
	cout << "欢迎老师： " << this->m_Name << " 登陆！ " << endl;
	cout << "\t\t ------------------------------------ \n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           1.查看所有预约           |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           2.审核预约               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|           0.注销登陆               |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------ \n";
	cout << "请选择你的操作：" << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["data"] << " ";
		cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学号：" << of.m_orderData[i]["stuId"] << " ";
		cout << "姓名：" << of.m_orderData[i]["stuName"] << " ";
		cout << "机房号：" << of.m_orderData[i]["roomId"] << " ";

		string status = "状态 ";
		//1审核中 2已预约 -1预约失败 0取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败";
		}
		else
		{
			status += "取消预约";
		}
		cout << status << " " << endl;
	}
	system("pause");
	system("cls");
}

//预约审核
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核预约记录" << endl;

	vector<int>v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);

			cout << index++ << " ";

			cout << "预约日期：周" << of.m_orderData[i]["data"] << " ";
			cout << "时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午") << " ";
			cout << "机房号：" << of.m_orderData[i]["roomId"] << " ";
			string status = "状态";
			//1审核中 2已预约 -1预约失败 0取消预约
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
	}
	cout << "请输入取消记录，0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				if (v.size() == 0)
				{
					break;
				}
				else
				{
					cout << "请输入审核结果" << endl;
					cout << "1、通过" << endl;
					cout << "2.不通过" << endl;
					cin >> ret;
					if (ret == 1)
					{
						of.m_orderData[v[select - 1]]["status"] = "2";
					}
					else
					{
						of.m_orderData[v[select - 1]]["status"] = "-1";
					}
					of.updataOrder();
					cout << "审核完毕" << endl;
					break;
				}
			}
		}
		cout << "输入错误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}

Teacher::~Teacher()
{

}
