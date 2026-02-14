#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans) {
    // Base case
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }

    // Exclude the current element
    solve(nums, output, index + 1, ans);

    // Include the current element
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> result = subsets(arr);

    cout << "All subsets are:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}


// | Part       | Meaning                                                          |
// | ---------- | ---------------------------------------------------------------- |
// | `for`      | Start of the loop                                                |
// | `const`    | We don’t want to accidentally change the subset inside the loop  |
// | `auto`     | Automatically figures out the type (in this case: `vector<int>`) |
// | `&`        | Pass by reference (faster than making a copy of the subset)      |
// | `subset`   | A name you give to the current subset (can be anything)          |
// | `: result` | Loop through each subset inside `result`                         |
