#include <bits/stdc++.h>
using namespace std;

class Solution
{
public: 
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        st.erase(startWord); // Remove the startWord from the set to avoid revisiting
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            string word = it.first;
            int steps = it.second;
            if (word == targetWord)
                return steps; // If we have reached the target word, return the number of steps
            for (int i = 0; i < word.size(); i++)
            {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch; // Change one character at a time
                    if (st.find(word) != st.end())
                    {                              // If the new word is in the set
                        st.erase(word);            // Remove it from the set to avoid revisiting
                        q.push({word, steps + 1}); // Push the new word and increment steps
                    }
                }
                word[i] = originalChar; // Restore the original character before moving to the next position
            }
        }
        return 0;
    }
};