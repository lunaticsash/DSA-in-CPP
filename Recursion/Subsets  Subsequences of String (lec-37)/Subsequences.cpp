#include <bits/stdc++.h>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans) {
    // Base case
    if (index >= str.length()) {
        if (output.length() > 0) {
            ans.push_back(output);
        }
        return;
    }

    // Exclude the current character
    solve(str, output, index + 1, ans);

    // Include the current character
    output.push_back(str[index]);
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main() {
    string input = "abc";
    vector<string> result = subsequences(input);

    cout << "All non-empty subsequences:\n";
    for (const string& s : result) {
        cout << s << "\n";
    }

    return 0;
}