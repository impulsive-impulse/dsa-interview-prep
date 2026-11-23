// Problem: Crossword Puzzle (HackerRank: https://www.hackerrank.com/challenges/crossword-puzzle)
// A crossword of 10*10 grid. The grid contains + or - as its cell values. You are also provided with a word list that needs to be placed
// accurately in hte grid. Cells marked with - are to be filled with words. 
// Input: 10 lines of the grid, then one line of words split by ';' (e.g. LONDON;DELHI;ICELAND;ANKARA).
// Words go left-to-right or top-to-bottom. Crossing words share a letter. Print the filled grid. A solution always exists.
// Pattern: Backtracking | Time: O(W! * 2^W * L) worst case, tiny in practice | Space: O(W * L)
// Edge cases: one word only, two words of the same length (order matters!), words crossing on a letter,
//             a word must fill its whole slot exactly (no '-' right before or after it)
//
// Coach notes (2026-11-23):
// - Status: my attempt only reads the grid. The full solution (from the coach, on request) is in FIX 3 below.
// - Idea in plain words: place words one by one. For word i, try every cell and both directions.
//   If it fits, write it, then try to place word i+1. If that fails, ERASE word i and try the next spot.
//   This is the same "choose -> recurse -> undo" shape as N-Queens and Rat in a Maze.
// - Why "it fits" needs 3 checks:
//     1. It stays inside the grid.
//     2. Each cell is '-' or already has the SAME letter (a crossing word).
//     3. The cell just before and just after the word is not '-'. Otherwise the word is shorter than its slot.
// - Why undo only the cells we changed: letters that were already there belong to a crossing word.
//   If we erase them, we break the other word. So remember which cells we filled (the `changed` vector).
// - Complexity: W = number of words (<= 10), L = word length (<= 10).
//     Each word tries 100 cells x 2 directions, but almost all fail the checks at once.
//     Real choices = which slot each word goes into: at most W! orders. Checking/placing costs O(L).
//     Worst case looks big, but with W <= 10 and strict checks it runs instantly.
//     Space: recursion depth W, each level stores a `changed` vector of size L -> O(W * L).
// - Interview follow-up: "Find all slots first, then match words to slots of the same length."
//   That is a cleaner way and prunes faster. Try it when you re-solve.

#include<bits/stdc++.h>
using namespace std;

// FIX 3: The whole approach is missing, so here is the full solution as one block.
//        Uncomment it (and delete my main below) to run it.
//
// vector<string> grid(10);
// vector<string> words;
//
// bool canPlaceH(const string& w, int r, int c) {
//     if (c > 0 && grid[r][c - 1] == '-') return false;                              // slot starts earlier
//     if (c + (int)w.size() > 10) return false;                                      // goes off the grid
//     if (c + (int)w.size() < 10 && grid[r][c + w.size()] == '-') return false;      // slot is longer
//     for (int k = 0; k < (int)w.size(); k++) {
//         char g = grid[r][c + k];
//         if (g != '-' && g != w[k]) return false;                                   // blocked or wrong letter
//     }
//     return true;
// }
//
// bool canPlaceV(const string& w, int r, int c) {
//     if (r > 0 && grid[r - 1][c] == '-') return false;
//     if (r + (int)w.size() > 10) return false;
//     if (r + (int)w.size() < 10 && grid[r + w.size()][c] == '-') return false;
//     for (int k = 0; k < (int)w.size(); k++) {
//         char g = grid[r + k][c];
//         if (g != '-' && g != w[k]) return false;
//     }
//     return true;
// }
//
// // Returns which cells we actually filled, so undo erases only those.
// vector<bool> placeH(const string& w, int r, int c) {
//     vector<bool> changed(w.size(), false);
//     for (int k = 0; k < (int)w.size(); k++) {
//         if (grid[r][c + k] == '-') { grid[r][c + k] = w[k]; changed[k] = true; }
//     }
//     return changed;
// }
//
// vector<bool> placeV(const string& w, int r, int c) {
//     vector<bool> changed(w.size(), false);
//     for (int k = 0; k < (int)w.size(); k++) {
//         if (grid[r + k][c] == '-') { grid[r + k][c] = w[k]; changed[k] = true; }
//     }
//     return changed;
// }
//
// void undoH(const vector<bool>& changed, int r, int c) {
//     for (int k = 0; k < (int)changed.size(); k++) if (changed[k]) grid[r][c + k] = '-';
// }
//
// void undoV(const vector<bool>& changed, int r, int c) {
//     for (int k = 0; k < (int)changed.size(); k++) if (changed[k]) grid[r + k][c] = '-';
// }
//
// bool solve(int idx) {
//     if (idx == (int)words.size()) return true;                 // all words placed
//     const string& w = words[idx];
//     for (int r = 0; r < 10; r++) {
//         for (int c = 0; c < 10; c++) {
//             if (grid[r][c] != '-' && grid[r][c] != w[0]) continue;
//             if (canPlaceH(w, r, c)) {
//                 vector<bool> changed = placeH(w, r, c);     // choose
//                 if (solve(idx + 1)) return true;           // recurse
//                 undoH(changed, r, c);                      // undo
//             }
//             if (canPlaceV(w, r, c)) {
//                 vector<bool> changed = placeV(w, r, c);
//                 if (solve(idx + 1)) return true;
//                 undoV(changed, r, c);
//             }
//         }
//     }
//     return false;                                              // no spot works -> go back
// }
//
// int main() {
//     for (int i = 0; i < 10; i++) cin >> grid[i];               // FIX 1: read each row as a string
//     string line;
//     cin >> line;                                               // FIX 2: read the word list...
//     stringstream ss(line);
//     string w;
//     while (getline(ss, w, ';')) words.push_back(w);            // ...and split it on ';'
//
//     solve(0);
//     for (int i = 0; i < 10; i++) cout << grid[i] << '\n';
//     return 0;
// }

int main() {

    // FIX 1: This works, but vector<string> grid(10) and `cin >> grid[i]` is simpler:
    //        a row is just a string, and you can print it in one go.
    vector<vector<char>> crossword(10, vector<char>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> crossword[i][j];
        }
    }
    // FIX 2: The word list line (e.g. LONDON;DELHI;ICELAND;ANKARA) is never read. Read it and split on ';'.
    // FIX 3: No solving or printing yet. See the full solution block above.
}