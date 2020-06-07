/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool ismirror(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL&&q == NULL)
		return true;
	if (!p || !q)
		return false;
	if (p->val != q->val)
		return false;
	return ismirror(p->left, q->right) &&
		ismirror(p->right, q->left);
}
bool isSymmetric(struct TreeNode* root) {
	if (!root)
		return true;
	return ismirror(root->left, root->right);
}

