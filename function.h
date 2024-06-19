#pragma once
#include<iostream>
using namespace std;

class Point
{
	friend class Line;
public:
	
	Point() {};
	~Point() {};
	Point(double x, double y)
	{
		m_X = x;
		m_Y = y;
	}
	void ShowPoint()
	{
		cout << "x=" << m_X << " " << "y=" << m_Y << endl;
	}

private:
	double m_X;
	double m_Y;
};

class Line
{
public:
	Line() {};
	~Line() {};
	Line(Point& pstr, Point& pend);//���캯��
	bool CanBuild(Point& pstr, Point& pend);//�ж������ܷ�����һ��ֱ��
	bool IfBulidLine(Point& pstr, Point& pend);//����CanBuild�Ľ������ֱ�߶�
	bool IfEqualSlope(Line& L);//�ж����߶��Ƿ�б�����
	bool Location(Line& L); //�ж���ֱ�߶��Ƿ��غϡ����߻�ƽ��
	Point* Intersection(Line &L);//�ж����߶��Ƿ��ཻ������ཻ�Ļ���������߶εĽ���
	double GetY(double x);//��x��ֵ��ȡֱ�ߵ�yֵ

private:
	Point m_pstr;
	Point m_pend;

};
