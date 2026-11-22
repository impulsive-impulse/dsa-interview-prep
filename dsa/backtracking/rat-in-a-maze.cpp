// Problem: Rat in a Maze (all paths, 4 directions)
// You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach it's destination that is 
// maze[N-1][N-1]. The rat can move in any direction. In the given maze, If maze[][] == 0 =>> Rat can not go anywhere from this cell.
// Pattern: Backtracking | Time: O(3^(n^2)) | Space: O(n^2)
// Edge cases: blocked start or exit, n = 1, no path at all
//
// Coach notes (review, 2026-11-22):
// - Status: the code below does NOT compile yet. The FIX comments show what to change.
// - Why `solution[x][y] == 1` is needed: without it, the rat goes back and forth between
//   two cells forever -> infinite recursion -> stack overflow. Mark the cell on the way in,
//   unmark it on the way out: "on my current path" is not the same as "visited forever".
//
// How to find the time complexity of recursion:
//   Time = (number of calls) x (work per call). Number of calls ~ b^d, where
//   b = branching (calls each call makes), d = depth (how deep the calls go).
//   Example: fib(n) -> b = 2, d = n -> O(2^n).
// For this problem:
//   - b = 3: of the 4 moves, one always goes back to the cell we came from, and that call stops at once.
//   - d = n^2, NOT n: a path can snake through every cell once. For 3x3:
//         1 2 3
//         6 5 4
//         7 8 9
//   - Calls ~ 3^(n^2). Printing each path costs O(n^2) more.
//   - Time: O(3^(n^2)). O(4^(n^2)) is a simpler upper bound that interviewers also accept.
//   - Space: O(n^2) for the solution grid + O(n^2) recursion depth.
//   Lesson: depth = the longest path through the search, not the length of a side.

#include<bits/stdc++.h>
using namespace std;

// FIX 1: Use vectors. They know their own size, so the type always matches the caller.
// void mazeHelp(const vector<vector<int>>& maze, vector<vector<int>>& solution, int x, int y, int n) {
void mazeHelp(int maze[][100], int **solution, int x, int y, int n) {
    // FIX 2: Move the "out of bounds / visited / blocked" check from below to HERE, before the
    // destination check. Otherwise a blocked exit (maze[n-1][n-1] == 0) still prints a path.
    // if (x < 0 || y < 0 || x >= n || y >= n || solution[x][y] == 1 || maze[x][y] == 0) return;
    if(x == n-1 && y == n-1) {
        solution[x][y] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;   // FIX 3: cout << '\n';  (endl flushes every time, which is slow)
        }
        cout << endl;       // FIX 3: cout << '\n';
        solution[x][y] = 0;
        return;
    }

    // FIX 2: Delete this check after moving it to the top of the function.
    if(x>=n || x<0 || y>= n || y < 0 || solution[x][y] == 1 || maze[x][y] == 0) {
        return;
    }

    solution[x][y] = 1;
    mazeHelp(maze, solution, x+1, y, n);
    mazeHelp(maze, solution, x-1, y, n);
    mazeHelp(maze, solution, x, y +1 , n);
    mazeHelp(maze, solution, x, y-1, n);

    solution[x][y] = 0;
}

// FIX 1: void ratInAMaze(const vector<vector<int>>& maze, int n) {
//            vector<vector<int>> solution(n, vector<int>(n, 0));   // replaces all the new[] code below
//            mazeHelp(maze, solution, 0, 0, n);
//        }
// (The new[] memory below is also never deleted: a memory leak. The vector frees itself.)
void ratInAMaze(int maze[][100], int n) {
    int **solution = new int*[n];
    for (int i=0;i < n; i++) {
        solution[i] = new int[n];
        for (int j = 0; j < n; j++) {
            solution[i][j] = 0;
        }
    }

    mazeHelp(maze, solution, 0, 0, n);
}

int main() {

    int n;
    cin >> n;

    // FIX 1: vector<vector<int>> maze(n, vector<int>(n));
    // int maze[n][n] is a variable-length array: not standard C++, and its type int[n][n]
    // can't be passed as int[][100]. That was the compile error.
    int maze[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    ratInAMaze(maze, n);

    return 0;
}