#include<iostream>
#include"function.h"

using namespace std;

int main()
{
	Point str1(1.0,0.0); //设置构成直线段L1的一个端点str1
	Point end1(1.5,1.5); //设置构成直线段L1的另一端点end1
    Point str2(1.5,1.5); //设置构成直线段L2的一个端点str2
	Point end2(3.0,3.0); //设置构成直线段L2的一个端点end2
	
	Line L1(str1, end1);
	Line L2(str2, end2);
	if (L1.IfBulidLine(str1, end1) && L2.IfBulidLine(str2, end2)) //判断能否构造直线段
	{
		Point* intersection = L1.Intersection(L2);
		if (intersection != NULL)
		{
			Point p = *intersection;
			cout << "两直线段相交，交点为" << endl;
			p.ShowPoint();
		}
	}
	else
		return 0;
	

	return 0;
}