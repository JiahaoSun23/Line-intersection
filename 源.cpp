#include<iostream>
#include"function.h"

using namespace std;

int main()
{
	Point str1(1.0,0.0); //���ù���ֱ�߶�L1��һ���˵�str1
	Point end1(1.5,1.5); //���ù���ֱ�߶�L1����һ�˵�end1
    Point str2(1.5,1.5); //���ù���ֱ�߶�L2��һ���˵�str2
	Point end2(3.0,3.0); //���ù���ֱ�߶�L2��һ���˵�end2
	
	Line L1(str1, end1);
	Line L2(str2, end2);
	if (L1.IfBulidLine(str1, end1) && L2.IfBulidLine(str2, end2)) //�ж��ܷ���ֱ�߶�
	{
		Point* intersection = L1.Intersection(L2);
		if (intersection != NULL)
		{
			Point p = *intersection;
			cout << "��ֱ�߶��ཻ������Ϊ" << endl;
			p.ShowPoint();
		}
	}
	else
		return 0;
	

	return 0;
}