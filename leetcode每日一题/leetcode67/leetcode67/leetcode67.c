char *rever(char* a)
{
	int la = strlen(a);
	int j = 0;
	for (int i = 0, j = la - 1; i < j; i++, j--)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
	return a;
}
char * addBinary(char * a, char * b) {
	int la = strlen(a), lb = strlen(b);
	int lmin = la < lb ? la : lb;
	int lmax = la > lb ? la : lb;
	rever(a);
	rever(b);
	char* returnval = (char*)malloc(lmax + 2);
	int temp = 0;
	memset(returnval, 0, lmax + 2);
	if (lmin == lmax && lmin == 1 && a[0] == '0' && b[0] == '0')
	{
		returnval[0] = '0';
		return returnval;
	}
	char t = '0';
	int count = 0;
	for (int i = 0; i < lmin; i++)
	{
		if (a[i] == '1' && b[i] == '1') //11
		{
			returnval[i] = (t == '0') ? '0' : '1';
			t = '1';
		}
		else //<2    00 10 01 
		{
			if (a[i] + b[i] == 97) // 10 01
			{
				returnval[i] = (t == '0') ? '1' : '0';
				t = (returnval[i] == '0') ? '1' : '0';
			}
			else //00
			{
				returnval[i] = (t == '0') ? '0' : '1';
				t = '0';
			}
		}
		count++;
	}
	char *c = (lmax == la) ? a : b;
	if (t == '0')
		for (int i = lmin; i < lmax; returnval[i] = c[i], i++);
	else //t==1
	{
		for (int i = lmin; i < lmax; i++)
		{ //01 10//00 11
			(c[i] != t) ? (returnval[i] = '1', t = '0') : ((c[i] == '0') ? (returnval[i] = '0') : (returnval[i] = '0', t = '1'));
		}
	}
	if (t == '1')
	{
		returnval[lmax] = '1';
	}
	return rever(returnval);
}