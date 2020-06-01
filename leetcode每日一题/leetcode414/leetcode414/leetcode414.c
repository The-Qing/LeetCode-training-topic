int thirdMax(int* nums, int numsSize) {
	int max1 = nums[0], max2 = nums[0];
	for (int i = 0; i < numsSize; i++)
	{
		if (max1 < nums[i])
			max1 = nums[i];
		else if (max2 > nums[i])
			max2 = nums[i];
	}
	int t, t1, t2;
	int count = 1;
	t1 = max1;
	for (int i = 0; i < 2; i++)
	{
		t2 = max2;
		for (int j = 0; j < numsSize; j++)
		{
			if (nums[j] > t2 && nums[j] < t1)
			{
				t2 = nums[j];
			}
		}
		if (t2 != t1)
		{
			count++;
			t1 = t2;
		}
	}
	if (count == 3)
		return t1;
	else
		return max1;
}