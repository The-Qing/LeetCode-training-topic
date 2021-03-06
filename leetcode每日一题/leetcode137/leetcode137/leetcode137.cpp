class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int length = nums.size();
		int result = 0;
		for (int i = 0; i < 32; i++) {
			int count = 0;
			int mask = 1 << i;
			for (int j = 0; j<length; j++) {
				if (nums[j] & mask)
					count++;
			}
			if (count % 3)
				result |= mask;
		}
		return result;
	}
};