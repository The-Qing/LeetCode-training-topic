
µ¹ÖÃ×Ö·û´®
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s2;
	while (cin >> s1)
		s2 = s1 + " " + s2;
	cout << s2;
}

int main()
{
	string s1;
	string s2;
	getline(cin, s1);
	s2.resize(s1.size());
	int max = 0, count = 0, begin = 0;
	for (int i = 0; i<s1.size(); ++i)
	{
		begin = i;
		while (i<s1.size() && '0'<=s1[i] && s1[i] >= '9')
	//	while(i<s1.size()&&isdigit(s1[i]))
		{
			++count;
			++i;
		}
		if (count > max)
		{
			max = count;
			s2 = s1.substr(begin, count);
		}
		count = 0;
	}
	cout << s2 << endl;
}