struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* pHead = new ListNode(-1, nullptr);
		ListNode* pre = pHead;
		int tmpSum = 0;
		int carry = 0;
		do {
			tmpSum = 0;
			if (l1 != nullptr) {
				tmpSum += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) {
				tmpSum += l2->val;
				l2 = l2->next;
			}
			tmpSum += carry;
			carry = 0;

			if (tmpSum >= 10) {
				// carry
				tmpSum -= 10;
				carry = 1;
			}

			// put
			pre->next = new ListNode(tmpSum, nullptr);
			pre = pre->next;

		} while (l1 != nullptr || l2 != nullptr || carry != 0);
		return pHead->next;
	}
};