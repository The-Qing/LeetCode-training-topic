/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* p1 = head;
	struct ListNode* p2 = head;
	struct ListNode* t = head;
	while (p1 && p1->next)
	{
		head = head->next;
		p1 = p1->next->next;
		if (p1 == head)
		{
			t = p1;
			p1 = p2;
			while (p1 != t)
			{
				p1 = p1->next;
				t = t->next;
			}
			return t;
		}
	}
	return NULL;
}