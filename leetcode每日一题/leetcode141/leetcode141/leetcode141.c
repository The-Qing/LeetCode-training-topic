/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
bool hasCycle(struct ListNode *head) {
	struct ListNode* p1 = head;
	while (p1 && p1->next)
	{
		head = head->next;
		p1 = p1->next->next;
		if (p1 == head)
			return true;
	}
	return false;
}