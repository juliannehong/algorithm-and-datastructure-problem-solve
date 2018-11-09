// https://leetcode.com/problems/add-two-numbers/description/
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x): val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode dummy(0);
  ListNode* tail = &dummy;
  int carry = 0;
  while (l1 != nullptr || l2 != nullptr) {
    int num1 = (l1 == nullptr) ? 0 : l1->val;
    int num2 = (l2 == nullptr) ? 0 : l2->val;
    int sum = num1 + num2 + carry;
    carry = sum / 10;
    tail->next = new ListNode(sum % 10);
    tail = tail->next;
    if (l1 != nullptr) { l1 = l1->next; }
    if (l2 != nullptr) { l2 = l2->next; }
  }
  if (carry > 0){
    tail->next = new ListNode(1);
  }
  return dummy.next;
}