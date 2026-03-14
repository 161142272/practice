/*
题目描述
一开始未知数组长度，根据要求创建不同类型的指针，并且使用指针创建相应长度的数组，然后再完成不同的要求
若要求创建整数数组，计算数组内所有数据的平均值
若要求创建字符数组，找出数组内的最大字母
若要求创建浮点数数组，找出数组的最小值
要求程序整个过程不能使用数组下标，从数组创建、输入到搜索、比较、计算，到输出都必须使用指针
提示：使用new关键字
输入
第一行输入t表示有t个测试实例
第二行先输入一个大写字母表示数组类型，I表示整数类型，C表示字符类型，F表示浮点数类型；然后输入n表示数组长度。
第三行输入n个数据
依次输入t个实例
输出
每个根据不同的数组类型输出相应的结果
*/
#include <iostream>
using namespace std;

int main ()
{
    int t,n;
    for (int i = 0; i < t; i++)
    {
        char sp;
        cin >> sp;
        cin >> n;

        if (sp == 'I')
        {
            int *number = new int [n];
            for (int j = 0; j < n; j++)
            {
            cin >> *(number + j);
            }

            int sum;
            for (int j = 0; j < n; j++)
            {
                sum += *(number + j);
            }
            cout << sum/n << endl;
        }

        if (sp == 'C')
        {
            char *number = new char [n];
            for (int j = 0; j < n; j++)
            {
            cin >> *(number + j);
            }

            char max;
            max = *number;
            for (int j = 0; j < n; j++)
            {
                if (max < *(number + j))
                {
                    max = *(number + j);
                }               
            }
            cout << max << endl;
            
        }

        if (sp == 'F')
        {
            float *number = new float [n];
            for (int j = 0; j < n; j++)
            {
            cin >> *(number + j);
            } 

            int min;
            min = *number;
            for (int j = 0; j < n; j++)
            {
                if (min > *(number + j))
                {
                    min = *(number + j);
                }               
            }
            cout << min << endl;           
        }
    }
    
}