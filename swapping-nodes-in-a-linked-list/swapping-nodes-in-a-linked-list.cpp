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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> v;
        ListNode* temp = head;
        while (temp){
            v.push_back(temp);
            temp = temp->next;
        }
        int tempo = v[k-1]->val;
        v[k-1]->val = v[v.size()-k]->val;
        v[v.size()-k]->val = tempo;
        return head;
    }
};