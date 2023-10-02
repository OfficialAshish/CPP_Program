
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch) : data(ch), isTerminal(false)
    {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    friend class Trie;
};

class Trie
{
public:
    TrieNode *root;

    Trie() { root = new TrieNode('\0'); }

    void insertUtil(TrieNode *node, string word)
    {
        if (word.length() == 0)
        {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (node->children[index] != nullptr)
            child = node->children[index];
        else
        {
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'a';

        if (root->children[index] != nullptr)
        {
            TrieNode *child = root->children[index];
            // cout << child->data << ",";
            
            return (searchUtil(child, word.substr(1)));
        }
        else
            return false;
    }
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }
    bool prefixUtil(TrieNode* root, string prefix)
    {
        if (prefix.length() == 0)
            return true;

        int index = prefix[0] - 'a';

        if (root->children[index] != nullptr)
        {
            TrieNode *child = root->children[index];
            // cout << child->data << ",";
            
            return (searchUtil(child, prefix.substr(1)));
        }
        else
            return false;
    }
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

int main()
{
    string a1 = "hell", a2 = "heap", a3 = "head", a4 = "heal", a5 = "hello";
    Trie TrieDicti;
    TrieDicti.insertWord(a1);
    TrieDicti.insertWord(a2);
    TrieDicti.insertWord(a3);
    TrieDicti.insertWord(a4);
    cout << "Present ? " << TrieDicti.searchWord(a3) << endl;
}