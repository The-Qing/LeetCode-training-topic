bool canConstruct(char * ransomNote, char * magazine) {
	int map[26] = { 0 };
	memset(map, 0, map[0] * 26);
	int i, len1 = strlen(ransomNote), len2 = strlen(magazine);
	for (i = 0; i < len2; i++)			//统计magazine中的字母个数，按顺序写入map数组
	{
		map[magazine[i] - 'a']++;
	}
	for (i = 0; i < len1; i++)			//顺序比较ransomNote中的字母，若在map中没出现为false出现则减一
	{
		if (map[ransomNote[i] - 'a'] == 0)
			return false;
		map[ransomNote[i] - 'a']--;
	}
	return true;

}