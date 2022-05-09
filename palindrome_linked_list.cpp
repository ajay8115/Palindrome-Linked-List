#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next = head->next;

        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL or head->next == NULL)
        {
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != NULL)
        {
            slow = slow->next;
        }

        slow = reverse(slow);
        ListNode *cur = head;
        while (slow)
        {
            if (fast->val != slow->val)
            {
                return false;
            }

            slow = slow->next;
            cur = cur->next;
        }

        return true;
    }
};