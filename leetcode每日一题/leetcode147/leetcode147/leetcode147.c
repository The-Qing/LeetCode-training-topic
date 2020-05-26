/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* insertionSortList(struct ListNode* head) {
	if (head == NULL)
		return NULL;
	struct ListNode * p = head, *q;
	int temp = 0;
	for (p; p; p = p->next)
	{
		for (q = p->next; q; q = q->next)
		{
			if (p->val > q->val)
			{
				temp = p->val;
				p->val = q->val;
				q->val = temp;
			}
		}

	}
	return head;
}