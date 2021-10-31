/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void dfs(Node* node, vector<Node*>& vec) {
    
        while (node) {
            vec.push_back(node);
            if (node->child) dfs(node->child, vec);
            node = node->next; 
        }
    }
    
    Node* flatten(Node* head) {
        if (!head)  return NULL;
        vector<Node*> vec;
        dfs(head, vec);
        for (int i = 0; i < vec.size(); i++) {
            //cout << vec[i]->val << " ";
            if (i != 0) {
                vec[i - 1]->next = vec[i];
                vec[i]->prev = vec[i - 1];
            } else {
                vec[i]->prev = NULL;
            }
            vec[i]->child = NULL;
        }
        vec[vec.size() - 1]->next = NULL;
        return vec[0];
    }
};