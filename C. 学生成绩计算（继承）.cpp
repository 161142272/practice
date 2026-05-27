/*
题目描述
定义Person类具有姓名、年龄等属性，具有输出基本信息的display函数。
选修《面向对象程序设计》课程的学生在Person类的基础上，派生出子类：
免听生和非免听生。子类继承父类成员，新增其他成员、改写display函数。
非免听生具有平时成绩、考试成绩和总评成绩三个属性，总评成绩根据（平时成绩*40%+考试成绩*60%）
计算的结果，85分（包含）以上为A，75分（包含）-85分（不包含）为B，65分（包含）-75分
（不包含）为C，60分（包含）-65分（不包含）为D，60分（不包含）以下为F。
免听生只有考试成绩和总评成绩两个属性，总评成绩100%根据考试成绩对应上述等级制成绩。
定义上述类并编写主函数，输入类型符号，若输入R，根据学生基本信息、平时成绩和考试成绩，
建立非免听生对象，若输入S，根据学生基本信息、考试成绩，建立免听生对象。计算学生的总评成绩，并输出。

输入
测试次数t
随后每行输入学生类型 相关信息，姓名的最大字符长度为20

输出
每个学生基本信息和总评成绩
*/
#include<iostream>
#include<cstring>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	Person() {
		name = "";
		age = 0;
	}
	Person(string name,int age):name(name),age(age){
	}
	void display() {
		cout << name << " " << age << endl;
	}

	string GetName() {
		return name;
	}
	int GetAge() {
		return age;
	}
};
class listenP :public Person {
private:
	int usualScore;
	int examScore;
public:
	listenP(string name, int age, int usualScore, int examScore) :Person(name, age), usualScore(usualScore), examScore(examScore) {
	}
	void display(listenP const& p1) {
		cout << this->GetName() << " " << this->GetAge()<<" "<< this->Sumlevel() << endl;
	}

	char Sumlevel() {
		int sum = this->usualScore * 0.4 + this->examScore * 0.6;
		if (sum >= 85) {
			return 'A';
		}
		else if (sum >= 75) {
			return 'B';
		}
		else if (sum >= 65) {
			return 'C';
		}
		else if (sum >= 60) {
			return 'D';
		}
		else {
			return 'F';
		}
	};
};

class unlistenP :public Person {
private:
		int examScore;
public:
	unlistenP(string name, int age, int examScore) :Person(name, age), examScore(examScore) {
		}
	void display() {
			cout << this->GetName() << " " << this->GetAge() << " " << this->Sumlevel() << endl;
		}
	char Sumlevel() {
			int sum = this->examScore;
			if (sum >= 85) {
				return 'A';
			}
			else if (sum >= 75) {
				return 'B';
			}
			else if (sum >= 65) {
				return 'C';
			}
			else if (sum >= 60) {
				return 'D';
			}
			else {
				return 'F';
			}
		}
	};
	
	int main() {
		int t;
		cin >> t;
		while (t--)
		{
			char type;
			string name;
			int age;
			int examScore;
			cin >> type;
			if (type == 'R')
			{
				int usualScore;
				cin >> name >> age >> usualScore >> examScore;
				listenP p(name, age, usualScore, examScore);

			}
			else
			{
				cin >> name >> age >> examScore;
			}
			unlistenP p(name, age, examScore);
			p.display();
		}
	}