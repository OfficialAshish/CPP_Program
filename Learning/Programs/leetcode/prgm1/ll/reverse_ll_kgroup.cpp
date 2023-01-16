#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
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
    bool hasCycle(ListNode *head)
    {
        map<ListNode *, bool> sto;
        ListNode *tmp = head;
        while (tmp != nullptr)
        {
            sto[tmp] = false;
            tmp = tmp->next;
            if (sto[tmp] == false)
                return true;
        }
        return false;
        // tmp = head;
        // while (tmp != nullptr and sto[tmp] != true)
        // {
        //     tmp = tmp->next;
        // }
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr or head->next == nullptr)
            return nullptr;
        ListNode *prev = nullptr, *nextP = nullptr, *curr = head;
        int i = 1;

        while (i <= k and curr != nullptr)
        {
            nextP = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextP;
            i++;
        }

        // sv = head->next;
        // nextP = head->next->next;
        // head->next->next = head;
        if (nextP != nullptr)
            head->next = reverseKGroup(nextP, k);
        return prev;
    }
};

int main()
{
    // Create a map of strings to integers
    std::map<std::string, bool> map;

    // Insert some values into the map

    /*map["one"] = 1;
  map["two"] = 2;
  map["three"] = 3;
  */
    cout << (map["str"]);
    // cout << map["str"];

    // Get an iterator pointing to the first element in the map
    // std::map<std::string, int>::iterator it = map.begin();

    // Iterate through the map and print the elements
    // while (it != map.end())
    // {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    //     ++it;
    // }

    return 0;
}
