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
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        auto prev_mid = find_prev_midpoint(head);
        auto mid = prev_mid->next;
        prev_mid->next = nullptr;
        return merge_sorted(sortList(head), sortList(mid));
    }

    ListNode *merge_sorted(ListNode *l1, ListNode *l2)
    {
        if (l1 && l2)
        {
            auto a = (l1->val < l2->val) ? l1 : l2;
            auto b = a == l1 ? l2 : l1;
            a->next = merge_sorted(a->next, b);
            return a;
        }
        else
            return l1 ? l1 : l2;
    }

    ListNode *find_prev_midpoint(ListNode *head)
    {
        auto fast = head;
        auto prev = head;
        while (fast && fast->next)
        {
            prev = head;
            head = head->next;
            fast = fast->next->next;
        }
        return prev;
    }
};