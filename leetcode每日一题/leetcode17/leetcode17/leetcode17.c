class Solution {
public:
	vector<string> res;
	vector<string> num{ "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	void dfs(string digits, string str, int start)
	{
		if (str.size() == digits.size())
		{
			res.push_back(str);
			return;
		}
		for (int i = start; i<digits.size(); i++)
			for (int j = 0; j<num[digits[i] - '0' - 1].size(); j++)
				dfs(digits, str + num[digits[i] - '0' - 1][j], i + 1);
	}
	vector<string> letterCombinations(string digits) {

		if (digits.size() == 0)
			return res;
		dfs(digits, "", 0);
		return res;
	}
};