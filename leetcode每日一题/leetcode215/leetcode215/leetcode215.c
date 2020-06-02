class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int>temp;
		for (auto ch : nums) {
			temp.push(ch);
		}

		while (--k) {
			temp.pop();
		}
		return temp.top();
	}
};