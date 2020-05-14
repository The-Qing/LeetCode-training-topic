/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int RetSize(int numsSize) {
	int size = 1;
	while (numsSize > 0) {
		size *= 2;
		numsSize--;
	}
	return size;
}

void back(int* nums, int numsSize, int** ansArr, int* ansArrIndex, int* curArr, int *curArrIndex, int index, int** returnColumnSizes) {
	if (index == numsSize) {
		int copyBytes = sizeof(int) * (*curArrIndex);
		int* oneOfAns = (int*)malloc(copyBytes);
		memcpy(oneOfAns, curArr, copyBytes);
		ansArr[*ansArrIndex] = oneOfAns;
		(*returnColumnSizes)[*ansArrIndex] = *curArrIndex;
		(*ansArrIndex)++;
		return;
	}
	curArr[*curArrIndex] = nums[index];
	(*curArrIndex)++;
	back(nums, numsSize, ansArr, ansArrIndex, curArr, curArrIndex, index + 1, returnColumnSizes);
	(*curArrIndex)--;
	back(nums, numsSize, ansArr, ansArrIndex, curArr, curArrIndex, index + 1, returnColumnSizes);
	return;
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	if (!nums || numsSize <= 0) {
		*returnSize = 0;
		return NULL;
	}
	int retSize = RetSize(numsSize);
	*returnSize = retSize;
	int** ansArr = (int**)malloc(sizeof(int*) * retSize);
	int* curArr = (int*)malloc(sizeof(int) * numsSize);
	*returnColumnSizes = (int*)malloc(sizeof(int) * retSize);
	int curArrIndex = 0, ansArrIndex = 0;
	back(nums, numsSize, ansArr, &ansArrIndex, curArr, &curArrIndex, 0, returnColumnSizes);
	free(curArr);
	return ansArr;
}