
/*-------------------------------------------------------
【程序设计】
---------------------------------------------------------

题目：

有一只兔子，囤积了6种蔬菜，编号为0-5，准备过冬

  它把蔬菜的数量记录在数组t中，数组元素t[i]为编号i蔬菜的数量,数量各不相同

  为了能顺利度过冬天，兔子会检查蔬菜的囤积数量

  请编写check函数帮助兔子统计囤积数量低于平均数量的蔬菜有多少，并将这些蔬菜的编号记录在数组b中
  
  请编写函数rep告诉兔子囤积数量最少的蔬菜编号和囤积数量最多的蔬菜编号
  
  兔子向农夫购买蔬菜时，看到了蔬菜的价格表数组p,数组元素p[i]为编号i蔬菜的单价，单价各不相同
  
  请编写函数sort帮助兔子和农夫按照单价从便宜到贵的顺序重新对蔬菜编号，并按照新编号整理数组p和t

输出结果见图：样张.JPG
-------------------------------------------------------*/
#include <iostream>
#include <iomanip>
using namespace std;
int check(int t[],int s,int b[]);
void rep(int t[],int s,int &m, int &n);
void sort(int t[],int s,int p[]);

/**********Program**********/
int check(int t[],int s,int b[])
{
	double avg=0;
	for(int i=0;i<s;i++)avg+=t[i];
	avg=avg/s;
	int w=0;
	int j=0;
	for(int i=0;i<s;i++)
	{
		
		if (t[i]<avg)
		{
			w++;
			b[j]=i;
			j++;
		}
	}
	return w;
}
void rep(int t[],int s,int &max, int &min)
{
	max=0;
	min=0;
	for(int i=0;i<s;i++)
	{
		if(t[i]>t[max])max=i;
		if(t[i]<t[min])min=i;
	}
	return;
}
void sort(int t[],int s,int p[])
{
	for(int i=0;i<s-1;i++)
	{
		for(int j=i+1;j<s;j++)
		{
			if(p[i]>p[j])
			{
				p[i]=p[i]+p[j];
				p[j]=p[i]-p[j];
				p[i]=p[i]-p[j];
				t[i]=t[i]+t[j];
				t[j]=t[i]-t[j];
				t[i]=t[i]-t[j];
				//p,t exchange
			}
		}
	}
}

/**********  End  **********/


  int main()
{
        int t[6]={20,180,67,96,12,40};
        int p[6]={23,11,4,3,17,33};
        int b[6]={-1,-1,-1,-1,-1,-1};

        int i;

        int w=check(t,6,b);
        cout<<"兔子,低于平均数量的蔬菜有"<<w<<"种，分别是: "<<endl;
        for (i=0;i<w;i++) cout<<setw(5)<<b[i];
        cout<<endl;

        int max,min;
        rep(t,6,max,min);
        cout<<"兔子,最少的蔬菜是"<<min<<", 数量为"<<t[min]<<endl;
        cout<<"兔子,最多的蔬菜是"<<max<<", 数量为"<<t[max]<<endl;
    
        sort(t,6,p);
        cout<<"重新编号后"<<endl;
        cout<<setw(15)<<"蔬菜编号"<<setw(15)<<"蔬菜价格"<<setw(15)<<"蔬菜数量"<<endl;
        for (i=0;i<6;i++) cout<<setw(15)<<i<<setw(15)<<p[i]<<setw(15)<<t[i]<<endl;

        return 0;
}