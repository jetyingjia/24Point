#include <iostream>
#include <string>
#include <math.h>

using namespace std;
const  double Threshold = 1e-6;
const int CardsNumber = 4;
const int ResultValue = 24;
double number[CardsNumber];
string result[CardsNumber];
bool all = true;//all为true输出所有答案，为false输出一个答案


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

	//两个for循环获得初始的两个数（i=0:[((a,b),d),c];i=1:[((b,c),a),d];i=2:[(c,d),(a,b)]）
	for(int i = 0; i < n; i++)
	{

		for(int j = i + 1 ; j < n; j++)
		{
			double a, b;  //a保存上一步操作的结果，b保存这一次将要操作的数
			string expa, expb; //expa保存已有的表达式， expb保存将要操作的表达式

			a = number[i];  //保留上一步操作的结果（根据初始i的不同，a,b,number的功能需互换）
			b = number[j];  //保留这一步操作的数
			number[j] = number[n - 1]; //获取下一步要操作的数

			expa = result[i];          //保留上一步操作的表达式
			expb = result[j];          //保留这一步操作的表达式
			result[j] = result[n-1];   //获取下一步操作的表达式

			number[i] = a + b;                          //存储操作的结果
			result[i] = '(' + expa + '+' + expb + ')';  //存储操作的表达式
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