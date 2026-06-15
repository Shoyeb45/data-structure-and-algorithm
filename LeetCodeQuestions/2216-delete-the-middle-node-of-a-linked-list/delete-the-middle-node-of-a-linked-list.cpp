/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

using Node = ListNode;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;

        Node *slow = head, *fast = head->next, *prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) {
            prev = slow;
            slow = slow->next;
        }

        // [] ->  [] -> []
        // prev. slow
        prev->next = slow->next;
        slow->next = nullptr;
        delete slow;
        return head;
    }
};