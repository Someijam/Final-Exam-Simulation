
/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：

输入某一个班所有学生的计算机考试成绩（int score[100]），以负数
表示输入结束。统计学生人数并对成绩进行分析，找出其中的最高分并
求出平均分。

输出结果见图：样张.JPG

要求与输出样张一样才能得到满分。
-------------------------------------------------------*/
#include <iostream>
using namespace std;
int main( )
{
        

/**********Program**********/
	cout<<"输入成绩且负数表示结束"<<endl;
	int score[100]={0};
	int sumScore=0;
	int i=0;
	int max=0;
	for(i=0;;i++)
	{
		cin>>score[i];
		if(score[i]>max)max=score[i];
		if(score[i]<0)break;
		sumScore+=score[i];
	}
	cout<<"共有"<<i<<"人"<<endl<<"成绩如下"<<endl;
	for(i=0;;i++)
	{
		if (score[i]<0)break;
		cout<<score[i]<<'\t';
	}
	cout<<endl;
	cout<<"最高分"<<max<<endl;
	cout<<"平均分"<<double(sumScore)/i<<endl;
/**********  End  **********/
        return 0;
}

