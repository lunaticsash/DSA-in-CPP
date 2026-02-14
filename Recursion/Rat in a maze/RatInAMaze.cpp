#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &maze)
    {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && maze[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void solve(vector<vector<int>> &maze, int n, vector<string> &ans,
               int x, int y, vector<vector<int>> visited, string path)
    {

        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;

        // Down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, visited, maze))
        {
            path.push_back('D');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, visited, maze))
        {
            path.push_back('L');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, visited, maze))
        {
            path.push_back('R');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // Up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, visited, maze))
        {
            path.push_back('U');
            solve(maze, n, ans, newx, newy, visited, path);
            path.pop_back();
        }
        visited[x][y] = 0;
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        vector<string> ans;
        int n = maze.size();

        if (maze[0][0] == 0)
        {
            return ans;
        }

        int srcx = 0;
        int srcy = 0;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";

        solve(maze, n, ans, srcx, srcy, visited, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution obj;

    // Sample 4x4 maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};

    vector<string> result = obj.ratInMaze(maze);

    cout << "Paths found:\n";
    for (string path : result)
    {
        cout << path << endl;
    }

    return 0;
}
