/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *pa = headA, *pb = headB;
	if (!pa || !pb)
		return NULL;
	int la, lb, lc;
	for (la = 0; pa; pa = pa->next, la++);
	for (lb = 0; pb; pb = pb->next, lb++);
	lc = la - lb;
	if (la > lb)
	{
		while (lc--)
			headA = headA->next;
	}
	else
	{
		while (lc++)
			headB = headB->next;
	}
	while (headA != headB)
	{
		headA = headA->next;
		headB = headB->next;
	}
	return headA;
}