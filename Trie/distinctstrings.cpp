#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node
{
public:
    Node *links[26];
    bool containskey(char ch)
    {
        return links[ch - 'a'];
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    { // creating a new ref trie node
        links[ch - 'a'] = node;
    }
};

int countDistinctStrings(string &s)
{
    int cnt = 0;
    Node *root = new Node();
    for (int i = 0; i < s.length(); i++)
    {
        Node *node = root;
        for (int j = i; j < s.length(); j++)
        {
            if (!node->containskey(s[i]))
            {
                cnt++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return cnt + 1; // for empty string
}

int main()
{

    return 0;
}