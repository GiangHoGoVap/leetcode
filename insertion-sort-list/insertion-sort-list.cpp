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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *t1 = head->next;
        while(t1) {
            int sec_data = t1->val;
            int found = 0;
            ListNode *t2 = head;
            while(t2 != t1) {
                if(t2->val > t1->val && found == 0) {
                    sec_data = t2->val;
                    t2->val = t1->val;
                    found = 1;
                    t2 = t2->next;
                } else {
                    if(found == 1) {
                        int temp = sec_data;
                        sec_data = t2->val;
                        t2->val = temp;
                    }
                    t2 = t2->next;
                }
            }
            t2->val = sec_data;
            t1 = t1->next;
        }
        return head;
    }
};