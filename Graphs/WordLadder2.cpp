#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList)
    {

        // Store all words for O(1) lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Queue stores full path (not just word)
        queue<vector<string>> q;
        q.push({beginWord});

        // Words used in current level (to remove later)
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);

        int level = 0; // tracks BFS depth
        vector<vector<string>> ans;

        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // If we moved to next level → remove used words
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it); // avoid revisiting
                }
                usedOnLevel.clear();
            }

            string word = vec.back(); // current word

            // If reached endWord → store shortest paths only
            if (word == endWord)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(vec); // first shortest path
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec); // same length → valid
                }
            }

            // Try all 1-letter transformations
            for (int i = 0; i < word.size(); i++)
            {
                char original = word[i];

                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c; // change character

                    // If valid word in dictionary
                    if (st.count(word))
                    {
                        vec.push_back(word); // add to path
                        q.push(vec);         // push new path

                        usedOnLevel.push_back(word); // mark used
                        vec.pop_back();              // backtrack
                    }
                }

                word[i] = original; // restore word
            }
        }
        return ans;
    }
};

// Optimized
class Solution2
{
private:
    vector<vector<string>> ans;

    //  DFS to build paths from endWord → beginWord
    void dfs(string word, string beginWord,
             vector<string> &seq,
             unordered_map<string, int> &mpp)
    {

        // If reached beginWord → store answer
        if (word == beginWord)
        {
            reverse(seq.begin(), seq.end()); // reverse path
            ans.push_back(seq);
            reverse(seq.begin(), seq.end()); // restore
            return;
        }

        int steps = mpp[word]; // current level
        int size = word.size();

        // Try all transformations
        for (int i = 0; i < size; i++)
        {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                // Go to previous level word only
                if (mpp.find(word) != mpp.end() &&
                    mpp[word] + 1 == steps)
                {

                    seq.push_back(word);
                    dfs(word, beginWord, seq, mpp);
                    seq.pop_back(); // backtrack
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList)
    {

        unordered_set<string> st(wordList.begin(), wordList.end());

        // Step map → stores level (distance from beginWord)
        unordered_map<string, int> mpp;

        queue<string> q;
        q.push(beginWord);

        mpp[beginWord] = 1;
        st.erase(beginWord);

        int size = beginWord.size();

        // BFS → build levels
        while (!q.empty())
        {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if (word == endWord)
                break;

            for (int i = 0; i < size; i++)
            {
                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;

                    if (st.count(word))
                    {
                        q.push(word);
                        st.erase(word); // mark visited
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        // If endWord not reached → return empty
        if (mpp.find(endWord) == mpp.end())
            return ans;

        //  DFS → generate all shortest paths
        vector<string> seq;
        seq.push_back(endWord);

        dfs(endWord, beginWord, seq, mpp);

        return ans;
    }
};