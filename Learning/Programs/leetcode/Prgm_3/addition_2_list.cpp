
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
    ListNode *reverse(ListNode *head)
    {
        if (head == nullptr or head->next == nullptr)
            return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    void insert(ListNode *&tail, int dt)
    {
        ListNode *tmp = new ListNode(dt);
        if (!tail)
            tail = tmp;
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }
    ListNode *add(ListNode *l1, ListNode *l2)
    {
        int carry = 0, digit = 0;
        ListNode *ans = nullptr;
        while (l1 != nullptr or l2 != nullptr or carry != 0)
        {
            int val1 = 0, val2 = 0;
            if (l1)
                val1 = l1->val;
            if (l2)
                val2 = l2->val;

            int sum = carry + val1 + val2;
            digit = sum % 10;
            carry = sum / 10;
            insert(ans, digit);

            if (l1->next)
                l1 = l1->next;
            if (l1->next)
                l2 = l2->next;
        }
        return ans;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode *ans = add(l1, l2);
        ans = reverse(ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    ListNode l1;
    return 0;
}

ListNode *middleNode(ListNode *head)
{
    ListNode *s = head, *f = head->next;

    for (; f != nullptr and f->next != nullptr; s = s->next, f = f->next->next)
        ;
    return s;
}

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *s = head, *f = head->next;

        for (; f != nullptr and f->next != nullptr; s = s->next, f = f->next->next)
            ;
        return s;
    }

    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *tmphead = dummy;

        while (left and right)
        {

            if (left->val < right->val)
            {
                tmphead->next = left;
                left = left->next;
                tmphead = tmphead->next;
            }
            else
            {
                tmphead->next = right;
                right = right->next;
                tmphead = tmphead->next;
            }
        }
        while (left)
        {
            tmphead->next = left;
            left = left->next;
            tmphead = tmphead->next;
        }
        while (right)
        {
            tmphead->next = right;
            right = right->next;
            tmphead = tmphead->next;
        }
        return dummy->next;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head or !head->next)
            return head;

        ListNode *middle = middleNode(head);

        ListNode *tmp = middle->next;
        middle->next = nullptr;

        ListNode *left, *right;
        left = sortList(head);
        right = sortList(tmp);

        ListNode *ans = merge(left, right);

        return ans;
    }
};

//
//
//
//
//

ListNode *merge(ListNode *left, ListNode *right)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *tmphead = dummy;

    while (left or right)
    {

        if (left->val < right->val)
        {
            if (left)
            {
                tmphead->next = left;
                left = left->next;
                tmphead = tmphead->next;
            }
        }
        else // (right->val < left->val)
        {
            if (right)
            {
                tmphead->next = right;
                right = right->next;
                tmphead = tmphead->next;
            }
        }

        if (!left or !right)
            break;
    }
    return dummy->next;
}

ListNode *sortList(ListNode *head)
{
    if (!head or !head->next)
        return head;

    ListNode *middle = middleNode(head);

    ListNode *tmp = middle->next;
    middle->next = nullptr;

    ListNode *left, *right;
    left = sortList(head);
    right = sortList(tmp);

    ListNode *ans = merge(left, right);

    return ans;
}
// }
// ;
