/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;

        struct ListNode *slow = head, *fast = head;

        slow = slow->next;
        fast = fast->next->next;

        while (fast && fast->next)
        {
            if (slow == fast)
                break;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (slow != fast)
            return NULL;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};