/*
题目描述
本题要求编写程序，顺序输出给定字符串中所出现过的大写英文字母，每个字母只输出一遍；若无大写英文字母则输出“Not Found”。
输入
输入为一个以回车结束的字符串（少于80个字符）。
输出
按照输入的顺序在一行中输出所出现过的大写英文字母，每个字母只输出一遍。若无大写英文字母则输出“Not Found”。
*/


#include <iostream>
#include <cstring>
using namespace std;

int main() 
{
    char ch[80];
    cin.getline(ch, 80);
    char bigc[26] = {0};
    int k = 0;
    for (int i = 0; i < strlen(ch); i++)
    {
        if (ch[i] >= 'A' && ch[i] <= 'Z')
        {
            int flag = 0;
            for (int j = 0; j < k; j++)
            {
                if (bigc[j] == ch[i])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                bigc[k] = ch[i];
                k++;
            }
        }
    }
    if (k == 0)
    {
        cout << "Not Found" << endl;
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            cout << bigc[i];
        }
        cout << endl;
    }
}