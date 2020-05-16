int removeDuplicates(int* nums, int numsSize) {
	if (numsSize == 0 || numsSize == 1) {
		return numsSize;
	}
	int length = 1;
	int count = 1;
	for (int i = 1; i<numsSize; i++) {
		if (nums[i] == nums[length - 1] && count<2) {
			nums[length++] = nums[i];
			count++;
		}
		else if (nums[i] != nums[length - 1]) {
			nums[length++] = nums[i];
			count = 1;
		}
	}
	return length;

}