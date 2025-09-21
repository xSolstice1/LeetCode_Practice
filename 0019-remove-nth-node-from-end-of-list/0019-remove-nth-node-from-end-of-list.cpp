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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int> v;

        while (head != nullptr) {
            v.push_back(head->val);
            head=head->next;
        }

        ListNode* res = new ListNode();
        ListNode* dummy = res;

        for (int i=0; i<v.size(); i++) {
            if (i != v.size()-n) {
                dummy->next = new ListNode(v[i]);
                dummy=dummy->next;
            }
        }

        return res->next;
    }
};