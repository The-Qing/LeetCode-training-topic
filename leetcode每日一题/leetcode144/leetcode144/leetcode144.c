/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + TreeSize(root->left) + TreeSize(root->right);
}
void BinaryTreePrevOrder(struct TreeNode* root, int* retA, int* i)
{
	if (root == NULL)
		return;
	retA[(*i)++] = root->val;
	BinaryTreePrevOrder(root->left, retA, i);
	BinaryTreePrevOrder(root->right, retA, i);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int size = TreeSize(root);
	int* retA = malloc(sizeof(int)*size);
	*returnSize = size;

	int i = 0;
	BinaryTreePrevOrder(root, retA, &i);
	return retA;
}