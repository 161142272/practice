/*
题目描述
为向量1题目实现的CVector类添加私有静态成员sum，在初始化对象的同时，统计所有对象的n维向量和sum。
主函数生成多个对象，测试向量和。
可根据需要自行添加需要的静态成员函数，添加非静态成员函数不得分。
输入
测试次数t
每组测试数据格式如下：
输入m,表示n维向量的数目
后跟m行，每行格式：向量维数n  n维向量值
输出
对每组测试数据的m个向量，输出所有向量的分量和sum
*/
#include <iostream>
#include <vector>
using namespace std;
class Cvector {
private:
	vector<int> data;
	int n;
	static int sum;
public:
	Cvector() {
		n = 5;
		data.push_back(0);
		data.push_back(1);
		data.push_back(2);
		data.push_back(3);
		data.push_back(4);
		for (int i = 0; i < n; i++) sum += data[i];
	}
	Cvector(int cn, int* cdata) {
		n = cn;
		for (int i = 0; i < n; i++) {
			data.push_back(cdata[i]);
			sum += data[i];
		}
		vectorprint();
	}

	void vectorprint() {
		for (int i = 0; i < n - 1; i++)
		{
			cout << data[i] << ' ';
		}
		cout << data[n - 1] << endl;
	}

	static void resetSum() { 
		sum = 0; 
	}
	static void printSum() {
		cout << sum << endl; 
	}

};
int Cvector::sum = 0;

int main() {
	int t;
	cin >> t;
	while (t--) {
		Cvector::resetSum();
		int cn;
		cin >> cn;
		for (int i = 0; i < cn; i++)
		{
			int nums;
			cin >> nums;
			int n3 = nums;
			int* cdata3 = new int[n3];
			for (int j = 0; j < n3; j++) {
				cin >> cdata3[j]; 
			}
			Cvector v3(n3, cdata3);
			delete[] cdata3;
		}
		Cvector::printSum();
	}
}