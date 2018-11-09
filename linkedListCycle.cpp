// https://leetcode.com/problems/linked-list-cycle/description/

bool hasCycle(ListNode *head) {
  unordered_set<ListNode*> s;
  while (head != nullptr) {
    if (s.find(head) != s.end())
      return true;
    else
      s.insert(head);
    head = head->next;
  }
  return false;
}