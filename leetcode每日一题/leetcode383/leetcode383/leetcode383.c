bool canConstruct(char * ransomNote, char * magazine) {
	int map[26] = { 0 };
	memset(map, 0, map[0] * 26);
	int i, len1 = strlen(ransomNote), len2 = strlen(magazine);
	for (i = 0; i < len2; i++)			//ͳ��magazine�е���ĸ��������˳��д��map����
	{
		map[magazine[i] - 'a']++;
	}
	for (i = 0; i < len1; i++)			//˳��Ƚ�ransomNote�е���ĸ������map��û����Ϊfalse�������һ
	{
		if (map[ransomNote[i] - 'a'] == 0)
			return false;
		map[ransomNote[i] - 'a']--;
	}
	return true;

}