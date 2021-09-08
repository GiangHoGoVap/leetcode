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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode,* curNode;
        if (head!=NULL){
            prevNode = head;
            curNode = head->next;
            head = head->next;
            prevNode->next = NULL;
            while (head!=NULL){
                head = head->next;
                curNode->next = prevNode;
                prevNode = curNode;
                curNode = head;
            }
            head = prevNode;
        }
        return head;
    }
};