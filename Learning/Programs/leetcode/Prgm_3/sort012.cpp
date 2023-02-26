class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void insert(Node *&tail, Node *tmp)
{
    tail->next = tmp;
    tail = tmp;
}
/*
Node *sortList1(Node *head)
{
    Node *dummy = new Node(-1);
    Node *tmp = dummy;
    Node *zeroHead = nullptr;
    Node *zeroTail = nullptr;
    Node *oneHead = nullptr;
    Node *oneTail = nullptr;
    Node *secondHead = nullptr;
    Node *secondTail = nullptr;

    Node *tmpHead = head;

    while (tmpHead != nullptr)
    {
        if (tmpHead->data == 0)
        {
            if (!zeroHead)
            {
                zeroHead = tmpHead;
                zeroTail = tmpHead;
            }
            else
                insert(zeroTail, tmpHead);
        }
        else if (tmpHead->data == 1)
        {
            if (!oneHead)
            {
                oneHead = tmpHead;
                oneTail = tmpHead;
            }
            else
                insert(oneTail, tmpHead);
        }
        else if (tmpHead->data == 2)
        {
            if (!secondHead)
            {
                secondHead = tmpHead;
                secondTail = tmpHead;
            }
            else
                insert(secondTail, tmpHead);
        }
        tmpHead = tmpHead->next;
    }

    if (zeroTail)
    {
        dummy->next = zeroHead;
    }
    else if (zeroHead == nullptr)
    {
        dummy->next = oneHead;
    }
    if (oneHead == nullptr and zeroHead == nullptr)
    {
        // dummy->next = secondHead;
        return secondHead;
    }
    else if (oneHead == nullptr and zeroHead != nullptr)
    {
        zeroTail->next = secondHead;
        return dummy->next;
    }
    if (secondHead != nullptr)
    {
        if (oneHead != nullptr)
        {
            oneTail->next = secondHead;
        }
    }
}
 */

Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *secondHead = new Node(-1);
    Node *secondTail = secondHead;

    Node *tmpHead = head;

    while (tmpHead != nullptr)
    {
        if (tmpHead->data == 0)
            insert(zeroTail, tmpHead);
        else if (tmpHead->data == 1)
            insert(oneTail, tmpHead);
        else if (tmpHead->data == 2)
            insert(secondTail, tmpHead);

        tmpHead = tmpHead->next;
    }

    if (oneHead != nullptr)
    {
        zeroTail->next = oneHead->next;
    }
    else
    {
        zeroTail->next = secondHead->next;
    }
    oneTail->next = secondHead->next;
    secondTail->next = nullptr;

    return zeroHead->next;
}
