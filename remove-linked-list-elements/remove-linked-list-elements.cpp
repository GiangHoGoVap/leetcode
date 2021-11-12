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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curNode = head;
        ListNode* pPre = head;
        while(curNode != NULL){
            if (curNode->val == val){
                if (curNode == head){
                    head = curNode->next;  
                }
                else{
                    pPre->next = curNode->next;
                    curNode = curNode->next;
                }
            }
            else{
                pPre = curNode;
                curNode = curNode->next;
            }
        }
        return head;
    }
};