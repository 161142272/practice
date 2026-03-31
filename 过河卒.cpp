/*
题目描述
棋盘上 A AA 点有一个过河卒，需要走到目标 B BB 点。卒行走的规则：可以向下、或者向右。同时在棋盘上 C CC
点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。
棋盘用坐标表示，A AA 点 ( 0 , 0 ) (0, 0)(0,0)、B BB 点 ( n , m ) (n, m)(n,m)，同样马的位置坐标是需要给出的。
现在要求你计算出卒从 A AA 点能够到达 B BB 点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。
输入格式
一行四个正整数，分别表示 B BB 点坐标和马的坐标。
输出格式
一个整数，表示所有的路径条数。
输入输出样例 #1
输入 #1
6 6 3 3
输出 #1
6
说明/提示
对于 100 % 100 \%100% 的数据，1 ≤ n , m ≤ 20 1 \le n, m \le 201≤n,m≤20，0 ≤ 0 \le0≤ 马的坐标 ≤ 20 \le 20≤20。
*/
#include <iostream>
using namespace std;
int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int block[21][21];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            block[i][j] = 1;
        }
        
    }
    
    int nx,ny;
    int dx[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {0, 2, 1, -1, -2, -2, -1, 1, 2};
    for (int i = 0; i < 9; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            block[nx][ny] = 0;
            nx = 0;
            ny = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (i == 0 || j == 0)
            {
                block[i][j] = 1;
            }
            else
            {
                block[i][j] = block[i][j-1] + block[i-1][j];
            }
        }
        
    }
    
    cout << block[n][m] << endl;
    return 0;
}