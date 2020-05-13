#include<stdio.h>
#include<stdbool.h>
bool isValid(char * s) {
	int top = 0;
	char* arr = (char*)malloc(strlen(s) + 1);
	for (int i = 0; s[i]; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			top++;
			arr[top] = s[i];
		}
		else
		{
			if ((s[i] == arr[top] + 1) || (s[i] == arr[top] + 2))
				top--;
			else
				return false;
		}
	}
	return(!top);
}