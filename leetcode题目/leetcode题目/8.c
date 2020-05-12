#include<stdio.h>
#define INT_MAX  2147483647
#define INT_MIN  -2147483648
//字符串转换整数
int myAtoi(char * str) {
	int i = 0;
	long sum = 0;
	int len = strlen(str);
	if (str == NULL)
		return 0;
	for (i; i < len && str[i] == ' '; i++);//定位到第一个非空格字符
	int begin = i, over = 0;
	if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9')) || (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9')))
	{
		for (i++; str[i] >= '0' && str[i] <= '9'; i++);//定位到数字结束(数字后一个位置)
		over = i;
	}
	else
		return 0;
	if (str[begin] == '-')
	{
		begin++;
		for (begin; begin < over; begin++)
		{
			sum = (str[begin] - '0')*pow(10, over - begin - 1) + sum;
			if ((int)sum != sum)
				return INT_MIN;
		}
		sum = sum*(-1);
	}
	else
	{
		if (str[begin] == '+')
			begin++;
		for (begin; begin < over; begin++)
		{
			sum = (str[begin] - '0')*pow(10, over - begin - 1) + sum;
			if ((int)sum != sum)
				return INT_MAX;
		}
	}
	return (int)sum;
}