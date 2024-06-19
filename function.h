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
	Line(Point& pstr, Point& pend);//构造函数
	bool CanBuild(Point& pstr, Point& pend);//判断两点能否生成一条直线
	bool IfBulidLine(Point& pstr, Point& pend);//根据CanBuild的结果构造直线段
	bool IfEqualSlope(Line& L);//判断两线段是否斜率相等
	bool Location(Line& L); //判断两直线段是否重合、共线或平行
	Point* Intersection(Line &L);//判断两线段是否相交，如果相交的话求出求两线段的交点
	double GetY(double x);//由x的值获取直线的y值

private:
	Point m_pstr;
	Point m_pend;

};
