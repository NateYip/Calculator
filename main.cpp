//
//  main.cpp
//  calculator
//
//  Created by nate yip on 2019/9/23.
//  Copyright © 2019 nate yip. All rights reserved.
/*
 这个程序是用来计算矩阵的
 */
#include <iostream>
#include<algorithm>
using namespace std;
struct juzhen{
    int len,wid;
    float in[8][8];
};//这是一个矩阵；

struct juzhen a[8];//全局定义矩阵

void input_a()//手动输入数据
{
    int n;
    
    cout<<"你有几个矩阵需要输入：";
    cin>>n;
    for(int q=1;q<=n;q++)
    {
        cout<<"第"<<q<<"个矩阵的数据："<<endl;
        cout<<"请输入它的长：";
        cin>>a[q].len;
        cout<<"请输入它的宽：";
        cin>>a[q].wid;
        cout<<"请从左至右，再从上到下输入数据"<<endl;
        cout<<"输入将每个数据用空格隔开，每行结束后，请输入回车："<<endl;
        for(int i=1;i<=a[q].wid;i++)
            {
                 cout<<"第"<<i<<"行:";
                 for (int j=1; j<=a[q].len; j++)
                 {
                      cin>>a[q].in[i][j];
                }
        
            }
    }
    
    
}

void input_b()//读取文件数据
{
    
   
}

void add1()
{
    cout<<"以下是你输入的两个矩阵相加的结果"<<endl;
    for (int i=1;i<=a[1].len;i++)
    {
        for(int j=1;j<=a[1].wid;j++)
        {
            printf ("%-8.2f",a[1].in[i][j]*a[2].in[i][j]);
            cout <<' ';
            
        }
        cout<<endl;
    }
    cout <<"结果仅供参考"<<endl;

}

void mul1()
{
    float mulnum;//这个用来记录相乘实数的值
    
    cout <<"请输入与矩阵相乘的实数：";
    cin>>mulnum;
    cout <<"以下是你输入矩阵与实数相乘的结果:"<<endl;
    for (int i=1;i<=a[1].len;i++)
    {
         for(int j=1;j<=a[1].wid;j++)
         {
             printf("%-8.2f",a[1].in[i][j]*mulnum);
             cout <<' ';

         }
        cout <<endl;
    }
    
    cout <<"结果仅供参考"<<endl;
}

void mul2()
{
    cout <<"以下是你输入矩阵与矩阵相乘的结果:"<<endl;
    for (int i=1;i<=a[1].len;i++)
    {
        for(int j=1;j<=a[2].wid;j++)
        {
            float ans =0;
            for (int q=1;q<=a[1].wid;q++)
            {
                ans=ans+a[1].in[i][q]*a[2].in[q][j];
                printf("%-8.2f",ans);
                cout <<' ';
                
            }
            cout <<endl;
        }
        cout <<endl;
    }
    
    cout <<"结果仅供参考"<<endl;
   
}

int main()
{
    char way;//这个值用来记录输入数据的方式
    int how;//这个值用来记录计算类型
    
    cout<<"本程序是用来计算矩阵运算的，目前单个矩阵最大5*5，最多录入两个矩阵,计算结果精确度在小数点后两位。"<<endl;
    cout<<"<!!!caution!!!：目前读取文件的数据的方式还在搭建,乘法也在调试>";
    cout <<"是否有需要手动输入文件(y=yes/n=no):";
    cin>>way;
   
    if (way == 'y')
        input_a();
    else input_b();
    
    cout<<"请输入计算方式，矩阵与矩阵相加请输入“1”，矩阵与实数相乘请输入“2”，矩阵与矩阵相乘请输入“3”："<<endl;
    cin>>how;
    
    if (how == 1)
        add1;
    else if (how == 2)
        mul1;
    else mul2;
    
    
    /*
     switch (way)
    {
        case 'y':input_a;break;
            //case 'n':input_b;break;通过文件读取不能用
    }
    
    switch (how)
    {
        case 1:add1;break;
        case 2:mul1;break;
        case 3:mul2;break;
    }
    */
    
    cout <<"感谢使用"<<endl;
    return 0;
}
