#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

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

    bool setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

    int getEnd()
    {
        return cntEndWith;
    }

    int getPrefix()
    {
        return cntPrefix;
    }
};

class Trie{
    private:
    Trie* root;
    public:
    Trie()
    {
        root = new Node();
    }

    public: void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if(!node->containskey(word[i])){{
                node->put(word[i], new Node());
            }
        }
        node = node->get(word[i]);
        }
        node -> setEnd();
    }

    public: bool checkifPrefixExists(string word){
        bool f1 = true;
        Node* node = root;
        for(int i =0; i< word.length(); i++){
            if(node->containskey(word[i])){
                node = node->get(word[i]);
                if(node->isEnd() == false){
                    return false;
                }
            }
            return false;
        }
        return true;
    }

};

string completeString(int n , vector<string> &a){
    Trie trie;
    for(auto &it : a){
        trie.insert(it);
    }
    string longest = "";
    for(auto &it : a){
        if(checkifPrefixExists(it)){
            if(it.length() > longest.length()){
                longest = it;
            }
            else if(it.length() == longest.length() && it < longest){
                longest = it;
            }
        }
    }

    if(longest == "") return "None";
    return longest; 

}