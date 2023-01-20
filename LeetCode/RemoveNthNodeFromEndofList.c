/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
  struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
  struct ListNode *start = head, *end = head, *pre = NULL;
  while (--n) 
    end = end->next;

  if (end->next != NULL)
    end = end->next;
  else
    return head->next;

  while (end->next != NULL) {
    end = end->next;
    start = start->next;
  }

  start->next = (start->next)->next;
  return head;
}