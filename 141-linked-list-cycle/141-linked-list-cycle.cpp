/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* ptr_prev = head;
        ListNode* ptr_next = head;
        while (ptr_prev && ptr_next){
            if (ptr_next->next) ptr_next = ptr_next->next->next;
            else ptr_next = nullptr;
            ptr_prev = ptr_prev->next;
            if (ptr_next && ptr_next == ptr_prev) return true;
        }
        return false;
    }
};