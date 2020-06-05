/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* removeElements(struct ListNode* head, int val) {
	while (head && head->val == val)
	{
		head = head->next;
	}
	struct ListNode* cur = head;
	struct ListNode* pnext = NULL;
	while (cur != NULL)
	{
		pnext = cur->next;
		if (pnext && pnext->val == val)
		{
			cur->next = pnext->next;
			free(pnext);
		}
		else
			cur = cur->next;
	}
	return head;
}