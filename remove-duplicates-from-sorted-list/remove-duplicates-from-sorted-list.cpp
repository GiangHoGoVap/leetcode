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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL){
            if (temp->next == NULL) break;
            if (temp->val == temp->next->val){
                ListNode* tempo = temp->next;
                while (tempo != NULL){
                    if (tempo->next == NULL) break;
                    if (tempo->val == tempo->next->val){
                        tempo = tempo->next;
                    }
                    else break;
                }
                temp->next = tempo->next;
            }
            temp = temp->next;
        }
        return head;
    }
};