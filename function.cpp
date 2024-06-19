#include<istream>
#include<math.h>
#include"function.h"
using namespace std;

Line::Line(Point& pstr, Point& pend)
{
	m_pstr = pstr;
	m_pend = pend;
}

bool Line::CanBuild(Point& pstr, Point& pend)
{
	if (sqrt((pstr.m_X - pend.m_X) * (pstr.m_X - pend.m_X) + (pstr.m_Y - pend.m_Y) * (pstr.m_Y - pend.m_Y))<=0.001)
	{
		cout << "ĳ��ֱ�߶���������㲻������ֱ�ߣ���������������" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool Line::IfBulidLine(Point& pstr, Point& pend)
{
	if (CanBuild(pstr, pend))
	{
		Line(pstr, pend);
		if (pstr.m_X <= pend.m_X) //��������X����С����һ����Ϊ��ʼ��
		{

			m_pstr = pstr;
			m_pend = pend;
		}
		else
		{
			m_pstr = pend;
			m_pend = pstr;
		}
		return true;
	}
	else
		return false;
}

bool Line::IfEqualSlope(Line& L)
{
	if (((m_pend.m_Y - m_pstr.m_Y == 0) && (L.m_pend.m_Y - L.m_pstr.m_Y == 0)) || ((L.m_pend.m_X - L.m_pstr.m_X == 0) && (m_pend.m_X - m_pstr.m_X == 0)))//���߶ζ�ƽ����������ʱ
	{
		
		return true;
	}
	else if ((m_pend.m_Y - m_pstr.m_Y) * (L.m_pend.m_X - L.m_pstr.m_X) == (m_pend.m_X - m_pstr.m_X) * (L.m_pend.m_Y - L.m_pstr.m_Y))//б�����
	{
		return true;
	}
	else
		return false;
}

bool Line::Location(Line& L)
{
	if (IfEqualSlope(L))
	{
		if (L.GetY(m_pend.m_X) == GetY(m_pend.m_X) || L.GetY(L.m_pend.m_X) == GetY(L.m_pend.m_X))
		{
			
			if ((m_pstr.m_X <= L.m_pend.m_X && m_pstr.m_X >= L.m_pstr.m_X) || (L.m_pstr.m_X <= m_pend.m_X && L.m_pstr.m_X >= m_pstr.m_X))
			{
				cout<<"��ֱ�߶ι��߲����غϲ���"<<endl;
				return true;
			}
			else
			{
				cout << "��ֱ�߶ι��ߵ����غϲ���" << endl;
				return true;
			}
		}
		else
		{
			cout << "��ֱ�߶�ƽ��" << endl;
			return true;
		}
	}
	else
		return false;
}

double Line::GetY(double x)
{
	return (m_pend.m_Y - m_pstr.m_Y) / (m_pend.m_X - m_pstr.m_X) * (x - m_pstr.m_X) + m_pstr.m_Y;
}

Point* Line::Intersection(Line& L)
{
	if (Location(L))
		return NULL;

	Point intersection;

	if (m_pend.m_X - m_pstr.m_X == 0 || L.m_pend.m_X - L.m_pstr.m_X==0)//�߶���Y��ƽ��,���ܸ���Xֵ�����ϵ�Yֵ
	{
		if (m_pend.m_X - m_pstr.m_X == 0)//���߶���Y��ƽ��
		{
			if ((m_pstr.m_Y - L.GetY(m_pstr.m_X)) * (m_pend.m_Y - L.GetY(m_pstr.m_X)) <= 0 && L.m_pstr.m_X<=m_pstr.m_X && m_pstr.m_X<=L.m_pend.m_X)
			{
				intersection.m_X = m_pstr.m_X;
				intersection.m_Y = L.GetY(m_pstr.m_X);
				return &intersection;
			}
			else
				return NULL;
		}
		else if (L.m_pend.m_X - L.m_pstr.m_X == 0)//L�߶���Y��ƽ��
		{
			if ((L.m_pstr.m_Y - GetY(L.m_pstr.m_X)) * (L.m_pend.m_Y - GetY(L.m_pstr.m_X)) <= 0 && m_pstr.m_X <= L.m_pstr.m_X && L.m_pstr.m_X <= m_pend.m_X)
			{
				intersection.m_X = L.m_pstr.m_X;
				intersection.m_Y = GetY(L.m_pstr.m_X);
				return &intersection;
			}
			else
				return NULL;
		}
	}

	else
	{
		double str_x;
		if (L.m_pstr.m_X <= m_pstr.m_X)
			str_x = m_pstr.m_X;
		else
			str_x = L.m_pstr.m_X;//����ѭ����������

		double end_x;
		if (L.m_pend.m_X <= m_pend.m_X)
			end_x = L.m_pend.m_X;
		else
			end_x = m_pend.m_X; //����ѭ����������


		for (; str_x <= end_x; str_x += 0.001)
		{
			
			if (abs(GetY(str_x) - L.GetY(str_x)) <= 0.001)
			{
				intersection.m_X = str_x;
				intersection.m_Y = GetY(str_x);
				return &intersection;
				break;
			}
		}
		cout << "��ֱ�߶β��ཻ" << endl;
		return NULL;
	}
}


