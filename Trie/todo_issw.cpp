#include <iostream>
using namespace std;

struct Node
{
    Node *links[26]; // assuming all lower case
    bool flag = false;
    bool containskey(char ch){
        return links[ch - 'a'] != NULL; // that means this char exist
    }

    void put(char ch , Node * node){ //creating a new ref trie node
        links[ch- 'a'] = node;
    }

    Node* get ( char ch){ // moving
        return links[ch - 'a'];
    }
    
    bool setEnd(){
        flag = false;
    }

    bool isEnd(){
        return flag;
    }

};

class Trie()
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    //TC -> O(length of the word)
    void insert(string word)
    {
        Node* node  = root; //dummy
        for(int i =0; i<word.length();i++){
            if(!node->containskey(word[i])){
                node->put(word[i], new Node());
            }
            //Moves to the reference trie
            node->get(word[i]);
        }

        node->setEnd();
    }

    //O(Length)

    bool search( string word){
        Node * node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){//does not contain the char
                return false;
            }
            node  = node->get(word[i]);
        }

        return node->isEnd();
    }

    //O(len)
    bool startswith(string prefix)
    {
        Node * node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node->containsKey(word[i])){//does not contain the char
                return false;
            }
            node  = node->get(word[i]);
        }

        return true;
    }
};

int
main()
{

    return 0;
}