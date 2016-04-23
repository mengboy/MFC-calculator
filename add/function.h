#pragma once
#include "stdafx.h"

bool isPatch = 1; //判断是否是首括号(30)s
bool ifMod = 0;
bool Inv = 0;
bool Asin = 0;
bool Atan = 0;
bool Acos = 0;
//优先级矩阵              +    -    *    /    %    ^    sin  cos  log  ln   tan  !    (    )
char s[14][14] =/*+*/{ { '>', '>', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '>' },
/*-*/{ '>', '>', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '>' },
/***/{ '>', '>', '>', '>', '>', '<', '<', '<', '<', '<', '<', '<', '<', '>' },
/*/*/{ '>', '>', '>', '>', '>', '<', '<', '<', '<', '<', '<', '<', '<', '>' },
/*%*/{ '>', '>', '>', '>', '>', '<', '<', '<', '<', '<', '<', '<', '<', '>' },
/*^*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '<', '>' },
/*sin*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '<', '<', '>' },
/*cos*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '<', '<', '>' },
/*log*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '<', '<', '>' },
/*ln*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '<', '>' },
/*tan*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '<', '>' },
/*!*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '<', '>' },
/*(*/{ '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '<', '>' },
/*)*/{ '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '>', '<', '>' } };
//字符串转化
int sNum(0), cNum(0), tNum(0), gNum(0), lNum(0);

//解析字符串
CString getString(CString &str)
{
	CString strTemp;
	for (size_t i = 0; i < str.GetLength(); i++)
	{
		if (str[i] == 's')
		{
			sNum++;
			i += 2;
		}
		else if (str[i] == 'c')
		{
			cNum++;
			i += 2;
		}
		else if (str[i] == 't')
		{
			tNum++;
			i += 2;
		}
		else if (str[i] == 'l' && str[i + 1] == 'o')
		{
			gNum++;
			i += 2;
		}
		else if (str[i] == 'l' && str[i + 1] == 'n')
		{
			lNum++;
			i += 2;
		}
		else
		{
			if (str[i] == ')' && sNum > 0)
			{
				strTemp += str[i];
				strTemp += 's';
				sNum--;
			}
			else if (str[i] == ')' && cNum > 0)
			{
				strTemp += str[i];
				strTemp += 'c';
				cNum--;
			}
			else if (str[i] == ')' && tNum > 0)
			{
				strTemp += str[i];
				strTemp += 't';
				tNum--;
			}
			else if (str[i] == ')' && gNum > 0)
			{
				strTemp += str[i];
				strTemp += 'g';
				gNum--;
			}
			else if (str[i] == ')' && lNum > 0)
			{
				strTemp += str[i];
				strTemp += 'l';
				lNum--;
			}
			else
			{
				strTemp += str[i];
			}
		}
	}
	return strTemp;
}

//cstr2str
string CStr2str(CString& cstr)
{
	string strTemp;
	for (int i = 0; i < cstr.GetLength(); i++)
	{
		strTemp += cstr[i];
	}
	return strTemp;
}

//阶乘
int fac(int n)
{
	int result = 1;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		for (; n >= 1; n--)
		{
			result *= n;
		}
		return result;
	}
}

//计算反三角函数时获取输入的数字
double getNum(CString& cstr)
{
	string snum;
	for (int i = 0; i < cstr.GetLength(); i++)
	{
		if (cstr[i] == '0' || cstr[i] == '1' || cstr[i] == '2' || cstr[i] == '3' || cstr[i] == '4' || cstr[i] == '5' || cstr[i] == '6' || cstr[i] == '7' || cstr[i] == '8' || cstr[i] == '9' || cstr[i] == '.')
		{
			snum += cstr[i];
		}
	}
	double num;
	num = atof(snum.c_str());
	return num;
}

//获取运算符对应的行和列，用来比较优先级
void getRowCol(const char stackCh, const char ch, int& row, int&col)
{
	switch (stackCh)
	{
	case '+':
		row = 0;
		break;
	case '-':
		row = 1;
		break;
	case '*':
		row = 2;
		break;
	case '/':
		row = 3;
		break;
	case '%':
		row = 4;
		break;
	case '^':
		row = 5;
		break;
	case 's':
		row = 6;
		break;
	case 'c':
		row = 7;
		break;
	case 'g':
		row = 8;
		break;
	case 'l':
		row = 9;
		break;
	case 't':
		row = 10;
		break;
	case '!':
		row = 11;
		break;
	case '(':
		row = 12;
		break;
	case ')':
		row = 13;
		break;
	}
	switch (ch)
	{
	case '+':
		col = 0;
		break;
	case '-':
		col = 1;
		break;
	case '*':
		col = 2;
		break;
	case '/':
		col = 3;
		break;
	case '%':
		col = 4;
		break;
	case '^':
		col = 5;
		break;
	case 's':
		col = 6;
		break;
	case 'c':
		col = 7;
		break;
	case 'g':
		col = 8;
		break;
	case 'l':
		col = 9;
		break;
	case 't':
		col = 10;
		break;
	case '!':
		col = 11;
		break;
	case '(':
		col = 12;
		break;
	case ')':
		col = 13;
		break;
	}
}

double countAnswer(string& str)
{
	int temp = 0;
	int row = 0, col = 0;
	stack<double> dStk;
	stack<char> cStk;
	char stackCh = '\0';
	char ch = '\0';
	string num;
	//第一轮计算，去除括号等
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '.')
		{
			num += str[i];
		}
		if ((str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.') || (i == str.length() - 1)) {
			if (num.size() != NULL)
			{
				dStk.push(atof(num.c_str()));
			}
			num.clear();
			if (cStk.size() == 0)
			{
				cStk.push(str[i]);
			}
			else
			{//最后一位是数字和')'等的情况
				if (i == str.length() - 1 && str[i] != ')' && str[i] != 's' && str[i] != 'c' && str[i] != 't' && str[i] != 'g' && str[i] != 'l' && str[i] != '!')
				{
					ch = cStk.top();
					cStk.pop();
					//解决两个数的运算
					if (cStk.size() == 0)
					{
						double num1 = dStk.top();
						cout << "num1:" << num1 << endl;
						dStk.pop();
						double num2 = dStk.top();
						cout << "num2:" << num2 << endl;
						dStk.pop();
						switch (ch)
						{
						case '+':
							num1 += num2;
							dStk.push(num1);
							break;
						case '-':
							num2 -= num1;
							dStk.push(num2);
							break;
						case '*':
							num1 *= num2;
							dStk.push(num1);
							break;
						case '/':
							num2 /= num1;
							dStk.push(num2);
							break;
						case '%':
							num2 = (int)num2 % (int)num1;
							dStk.push(num2);
							break;
						case '^':
							num1 = pow(num2, num1);
							dStk.push(num1);
							break;
						case 's':
							dStk.push(num2);
							num1 = sin(num1 / 180.0 * 3.1415926);
							dStk.push(num1);
							break;
						case 'c':
							dStk.push(num2);
							num1 = cos(num1 / 180.0 * 3.1415926);
							dStk.push(num1);
							break;
						case 'g':
							dStk.push(num2);
							num1 = log10(num1);
							dStk.push(num1);
							break;
						case 'l':
							dStk.push(num2);
							num1 = log(num1); //计算ln
							dStk.push(num1);
							break;
						case 't':
							dStk.push(num2);
							num1 = tan(num1 / 180.0 * 3.1415926);
							dStk.push(num1);
							break;
						default:
							break;
						}
						break;
					}
					else
					{
						stackCh = cStk.top();
						cStk.push(ch);
					}
				}
				else
				{
					stackCh = cStk.top();
					ch = str[i];
				}
				getRowCol(stackCh, ch, row, col);
				switch (s[row][col])
				{
				case '>':
				{
					double num1 = dStk.top();
					dStk.pop();
					double num2;
					//解决算式开头是()[s,c,g,l,t,!]的情况
					if (dStk.size() == 0)
					{
						num2 = 0;
						isPatch = 0;
					}
					else
					{
						num2 = dStk.top();
						dStk.pop();
						isPatch = 1;
					}
					stackCh = cStk.top();
					switch (stackCh)
					{
					case '+':
						num1 += num2;
						cStk.pop();
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!')
							{
								cStk.push(str[i]);
							}
						}
						dStk.push(num1);
						break;
					case '-':
						num2 -= num1;
						cStk.pop();
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						dStk.push(num2);
						break;
					case '*':
						num1 *= num2;
						cStk.pop();
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						dStk.push(num1);
						break;
					case '/':
						num2 /= num1;
						cStk.pop();
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						dStk.push(num2);
						break;
					case '^':
						num1 = pow(num2, num1);
						cStk.pop();
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						dStk.push(num1);
						break;
					case 's':
						if (isPatch)
						{//判断是否push num2
							dStk.push(num2);
						}
						num1 = sin(num1 / 180.0 * 3.1415926);
						cStk.pop();
						dStk.push(num1);
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						break;
					case '%':
						num2 = (int)num2 % (int)num1;
						cStk.pop();
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						dStk.push(num2);
						break;
					case 'c':
						if (isPatch)
						{
							dStk.push(num2);
						}
						num1 = cos(num1 / 180.0 * 3.1415926);
						cStk.pop();
						dStk.push(num1);
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						break;
					case 't':
						if (isPatch)
						{
							dStk.push(num2);
						}
						num1 = tan(num1 / 180.0 * 3.1415926);
						cStk.pop();
						dStk.push(num1);
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						break;
					case 'g':
						if (isPatch)
						{
							dStk.push(num2);
						}
						num1 = log10(num1);
						cStk.pop();
						dStk.push(num1);
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						break;
					case 'l':
						if (isPatch)
						{
							dStk.push(num2);
						}
						num1 = log(num1);
						cStk.pop();
						dStk.push(num1);
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						break;
					case '!':
						if (isPatch)
						{
							dStk.push(num2);
						}
						if (num1 >= 0)
						{
							num1 = fac(num1);
						}
						cStk.pop();
						dStk.push(num1);
						if (str[i] == ')')
						{
							cStk.pop();
						}
						else
						{
							if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == 's' || str[i] == 'c' || str[i] == 'g'/*log*/ || str[i] == 'l'/*ln*/ || str[i] == 't' || str[i] == '!' || str[i] == '%')
							{
								cStk.push(str[i]);
							}
						}
						break;
					case '(':
						if (isPatch)
						{
							dStk.push(num2);
							dStk.push(num1);
							dStk.push(0);
							cStk.push('+');
						}
						else
						{
							dStk.push(num2);
							dStk.push(num1);
							cStk.push('+');
						}
						i--;
						break;
					default:
						break;
					}
				}
				break;
				case '<':
					if (i == str.length() - 1)
					{
						double num1 = dStk.top();
						dStk.pop();
						double num2 = dStk.top();
						dStk.pop();
						stackCh = cStk.top();
						switch (ch)
						{
						case '+':
							num1 += num2;
							dStk.push(num1);
							break;
						case '-':
							num2 -= num1;
							dStk.push(num2);
							break;
						case '*':
							num1 *= num2;
							dStk.push(num1);
							break;
						case '/':
							num2 /= num1;
							dStk.push(num2);
							break;
						case '%':
							num2 = (int)num2 % (int)num1;
							dStk.push(num2);
							break;
						case '^':
							num1 = pow(num2, num1);
							dStk.push(num1);
							break;
						case 's':
							dStk.push(num2);
							num1 = sin(num1 / 180.0 * 3.1415926);
							dStk.push(num1);
							break;
						case 'c':
							dStk.push(num2);
							num1 = cos(num1 / 180.0 * 3.1415926);
							dStk.push(num1);
							break;
						case 'g':
							dStk.push(num2);
							num1 = log10(num1);
							dStk.push(num1);
							break;
						case 'l':
							dStk.push(num2);
							num1 = log(num1);
							dStk.push(num1);
							break;
						case 't':
							dStk.push(num2);
							num1 = tan(num1);
							dStk.push(num1);
							break;
						case '!':
							dStk.push(num2);
							if (num1 >= 0)
							{
								num1 = fac(num1);
							}
							dStk.push(num1);
							break;
						default:
							break;
						}
					}
					else
					{
						cStk.push(str[i]);
					}
					break;
				default:
					break;
				}
			}
		}
	}

	/*若第一轮计算不彻底进行第二轮计算*/
	string strTemp;
	string sNum;
	while (cStk.size() > 0)
	{
		stack<double> dTemp;
		while (dStk.size() != 0)
		{
			dTemp.push(dStk.top());
			dStk.pop();
		}
		stack<char> cTemp;
		while (cStk.size() != 0)
		{
			cTemp.push(cStk.top());
			cStk.pop();
		}
		while (dTemp.size() != 0)
		{
			stringstream ss;
			ss << dTemp.top();
			dTemp.pop();
			strTemp += ss.str();
			if (cTemp.size() > 0)
			{
				strTemp += cTemp.top();
				cTemp.pop();
			}
		}
		for (size_t i = 0; i < strTemp.length(); i++)
		{
			if (strTemp[i] == '0' || strTemp[i] == '1' || strTemp[i] == '2' || strTemp[i] == '3' || strTemp[i] == '4' || strTemp[i] == '5' || strTemp[i] == '6' || strTemp[i] == '7' || strTemp[i] == '8' || strTemp[i] == '9' || strTemp[i] == '.')
			{
				sNum += strTemp[i];
			}
			if ((strTemp[i] != '0' && strTemp[i] != '1' && strTemp[i] != '2' && strTemp[i] != '3' && strTemp[i] != '4' && strTemp[i] != '5' && strTemp[i] != '6' && strTemp[i] != '7' && strTemp[i] != '8' && strTemp[i] != '9' && strTemp[i] != '.') || strTemp[i] == '%' || (i == strTemp.length() - 1)) {
				if (sNum.size() != NULL)
				{
					dStk.push(atof(sNum.c_str()));
				}
				sNum.clear();
				if (cStk.size() == 0)
				{
					cStk.push(strTemp[i]);
					//计算只有一个s、c、t、g....的情况
					if (i == strTemp.length() - 1)
					{
						double num = dStk.top();
						dStk.pop();
						switch (strTemp[i])
						{
						case 's':
							num = sin(num / 180.0 * 3.1415926);
							dStk.push(num);
							break;
						case 'c':
							num = cos(num / 180.0 * 3.1415926);
							dStk.push(num);
							break;
						case 't':
							num = tan(num / 180.0 * 3.1415926);
							dStk.push(num);
							break;
						case 'g':
							num = log10(num);
							dStk.push(num);
							break;
						case 'l':
							num = log(num);
							dStk.push(num);
							break;
						case '!':
							num = fac(num);
							dStk.push(num);
							break;
						}
						cStk.pop();
						break;
					}
				}
				else
				{
					if (i == strTemp.length() - 1)
					{
						if (strTemp[i] != '0' && strTemp[i] != '1' && strTemp[i] != '2' && strTemp[i] != '3' && strTemp[i] != '4' && strTemp[i] != '5' && strTemp[i] != '6' && strTemp[i] != '7' && strTemp[i] != '8' && strTemp[i] != '9' && strTemp[i] != '.')
						{
							cStk.push(strTemp[i]);
						}
						ch = cStk.top();
						cStk.pop();
						/*只剩下一个运算符*/
						if (cStk.size() == 0)
						{
							double num1 = dStk.top();
							dStk.pop();
							double num2 = dStk.top();
							dStk.pop();
							switch (ch)
							{
							case '+':
								num1 += num2;
								dStk.push(num1);
								break;
							case '-':
								num2 -= num1;
								dStk.push(num2);
								break;
							case '*':
								num1 *= num2;
								dStk.push(num1);
								break;
							case '/':
								num2 /= num1;
								dStk.push(num2);
								break;
							case '%':
								num2 = (int)num2 % (int)num1;
								dStk.push(num2);
								break;
							case '^':
								num1 = pow(num2, num1);
								dStk.push(num1);
								break;
							case 's':
								dStk.push(num2);
								num1 = sin(num1 / 180.0 * 3.1415926);
								dStk.push(num1);
								break;
							case 'c':
								dStk.push(num2);
								num1 = cos(num1 / 180.0 * 3.1415926);
								dStk.push(num1);
								break;
							case 'g':
								dStk.push(num2);
								num1 = log10(num1);
								dStk.push(num1);
								break;
							case 'l':
								dStk.push(num2);
								num1 = log(num1); //计算ln
								dStk.push(num1);
								break;
							case 't':
								dStk.push(num2);
								num1 = tan(num1 / 180.0 * 3.1415926);
								dStk.push(num1);
								break;
							default:
								break;
							}
							break;
						}
						else
						{
							stackCh = cStk.top();
							cStk.push(ch);
						}
					}
					else
					{
						stackCh = cStk.top();
						ch = strTemp[i];
					}
					//还剩下多个运算符
					getRowCol(stackCh, ch, row, col);
					switch (s[row][col])
					{
					case '>':
					{
						double num1 = dStk.top();
						dStk.pop();
						double num2 = dStk.top();
						dStk.pop();
						stackCh = cStk.top();
						switch (stackCh)
						{
						case '+':
							num1 += num2;
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num1);
							break;
						case '-':
							num2 -= num1;
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num2);
							break;
						case '*':
							num1 *= num2;
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num1);
							break;
						case '/':
							num2 /= num1;
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num2);
							break;
						case '%':
							num2 = (int)num2 % (int)num1;
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num2);
							break;
						case '^':
							num1 = pow(num2, num1);
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num1);
							break;
						case 's':
							dStk.push(num2);
							num1 = sin(num1 / 180.0 * 3.1415926);
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num1);
							break;
						case 'c':
							dStk.push(num2);
							num1 = cos(num1 / 180.0 * 3.1415926);
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num1);
							break;
						case 'g':
							dStk.push(num2);
							num1 = log10(num1);
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num1);
							break;
						case 'l':
							dStk.push(num2);
							num1 = log(num1); 
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num1);
							break;
						case 't':
							dStk.push(num2);
							num1 = tan(num1 / 180.0 * 3.1415926);
							cStk.pop();
							if (strTemp[i] == '+' || strTemp[i] == '-' || strTemp[i] == '*' || strTemp[i] == '/' || strTemp[i] == '/' || strTemp[i] == 'g' || strTemp[i] == 'l' || strTemp[i] == 't' || strTemp[i] == '%' || strTemp[i] == '!')
							{
								cStk.push(strTemp[i]);
							}
							dStk.push(num1);
							break;
						default:
							break;
						}
					}
					break;
					case '<':
						if (i == strTemp.length() - 1)
						{
							double num1 = dStk.top();
							dStk.pop();
							double num2 = dStk.top();
							dStk.pop();
							stackCh = cStk.top();
							switch (stackCh)
							{
							case '+':
								num1 += num2;
								cStk.pop();
								dStk.push(num1);
								break;
							case '-':
								num2 -= num1;
								cStk.pop();
								dStk.push(num2);
								break;
							case '*':
								num1 *= num2;
								cStk.pop();
								dStk.push(num1);
								break;
							case '/':
								num2 /= num1;
								cStk.pop();
								dStk.push(num2);
								break;
							case '%':
								num2 = (int)num2 % (int)num1;
								cStk.pop();
								dStk.push(num2);
								break;
							case '^':
								num1 = pow(num1, num2);
								cStk.pop();
								dStk.push(num1);
								break;
							case 's':
								dStk.push(num2);
								num1 = sin(num1 / 180.0 * 3.1415926);
								cStk.pop();
								dStk.push(num1);
								break;
							case 'c':
								dStk.push(num2);
								num1 = cos(num1 / 180.0 * 3.1415926);
								cStk.pop();
								dStk.push(num1);
								break;
							case 'g':
								dStk.push(num2);
								num1 = log10(num1);
								cStk.pop();
								dStk.push(num1);
								break;
							case 'l':
								dStk.push(num2);
								num1 = log(num1);
								cStk.pop();
								dStk.push(num1);
								break;
							case 't':
								dStk.push(num2);
								num1 = tan(num1);
								cStk.pop();
								dStk.push(num1);
								break;
							default:
								break;
							}
						}
						else
						{
							cStk.push(strTemp[i]);
						}
						break;
					default:
						break;
					}
				}
			}
		}
		strTemp.clear();
	}
	return dStk.top();
}
