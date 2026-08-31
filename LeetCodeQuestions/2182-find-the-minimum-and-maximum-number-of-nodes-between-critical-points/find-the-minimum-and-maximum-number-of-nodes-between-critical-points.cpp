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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next) return {-1, -1};

        ListNode *curr = head;
        ListNode *prev = nullptr;

        vector<int> critical_points;
        int node_num = 1;
        
        while (curr) {
            ListNode* next = curr->next;
            if (prev && next) {
                int prev_val = prev->val, next_val = next->val, curr_val = curr->val;
                if ((curr_val > next_val && curr_val > prev_val) || (curr_val < next_val && curr_val < prev_val)) {
                    critical_points.push_back(node_num);
                }
            }
            node_num++;
            prev = curr;
            curr = next;
        }

        int n = critical_points.size();
        if (n < 2) return {-1, -1};
        
        int mn = INT_MAX, mx = critical_points[n - 1] - critical_points[0];
        for (int i = 0; i < n - 1; i++) {
            mn = min(mn, critical_points[i + 1] - critical_points[i]);
        }

        return {
            mn,
            mx
        };
    }
};