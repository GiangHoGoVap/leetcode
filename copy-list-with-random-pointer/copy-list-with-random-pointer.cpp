/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> map;
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        if (map[head]) return map[head];
        map[head] = new Node(head->val);
        map[head]->next = copyRandomList(head->next);
        map[head]->random = copyRandomList(head->random);
        return map[head];
    }
};