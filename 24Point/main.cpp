#include <iostream>
#include <string>
#include <math.h>

using namespace std;
const  double Threshold = 1e-6;
const int CardsNumber = 4;
const int ResultValue = 24;
double number[CardsNumber];
string result[CardsNumber];
bool all = true;//allΪtrue������д𰸣�Ϊfalse���һ����


bool PointGame(int n)
{
	if(n == 1)
	{
		if(fabs(number[0] - ResultValue) < Threshold)
		{
			cout << result[0] << endl;
			if (!all)
			{
				return true;
			}

		}
		else
		{
			if (!all)
			{
				return false;
			}

		}
	}

	//����forѭ����ó�ʼ����������i=0:[((a,b),d),c];i=1:[((b,c),a),d];i=2:[(c,d),(a,b)]��
	for(int i = 0; i < n; i++)
	{

		for(int j = i + 1 ; j < n; j++)
		{
			double a, b;  //a������һ�������Ľ����b������һ�ν�Ҫ��������
			string expa, expb; //expa�������еı��ʽ�� expb���潫Ҫ�����ı��ʽ

			a = number[i];  //������һ�������Ľ�������ݳ�ʼi�Ĳ�ͬ��a,b,number�Ĺ����軥����
			b = number[j];  //������һ����������
			number[j] = number[n - 1]; //��ȡ��һ��Ҫ��������

			expa = result[i];          //������һ�������ı��ʽ
			expb = result[j];          //������һ�������ı��ʽ
			result[j] = result[n-1];   //��ȡ��һ�������ı��ʽ

			number[i] = a + b;                          //�洢�����Ľ��
			result[i] = '(' + expa + '+' + expb + ')';  //�洢�����ı��ʽ
			if(PointGame(n-1))
			{
				return true;
			}

			number[i] = a - b;
			result[i] = '(' + expa + '-' + expb + ')';
			if(PointGame(n-1))
			{
				return true;
			}

			number[i] = b - a;
			result[i] = '(' + expb + '-' + expa + ')';
			if(PointGame(n-1))
			{
				return true;
			}

			number[i] = a * b;
			result[i] = '(' + expa + '*' + expb + ')';
			if(PointGame(n-1))
			{
				return true;
			}

			if(b != 0)
			{
				number[i] = a / b;
				result[i] = '(' + expa + '/' + expb + ')';
				if(PointGame(n-1))
				{
					return true;
				}
			}                     

			if(a != 0)
			{
				number[i] = b / a;
				result[i] = '(' + expb + '/' + expa + ')';
				if(PointGame(n-1))
				{
					return true;
				}
			}

			number[i] = a;
			number[j] = b;
			result[i] = expa;
			result[j] = expb;

		}
	}
	return false;

}

void main()
{
	int a = 1;
	int b = (a++) + (a) +(++a);

	int x;
	for(int i =0; i< CardsNumber; i++)
	{
		cout << "the " << i << "the number: ";
		cin >> x;
		number[i] = x;
		result[i] = (char)(x + '0');
	}

	if(PointGame(CardsNumber))
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "failure" << endl;
	}
	system("pause");

}