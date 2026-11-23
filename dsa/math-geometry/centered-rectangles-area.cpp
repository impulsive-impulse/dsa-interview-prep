// Problem: Area covered by centered rectangles
// You are given N rectangles, whcih are centered in a center foa corrdinate system.
// Each rectangle is defined by its width and height. Your task is to calculate the total area covered by these rectangles.
// Limits: not given. Tested with widths up to 20000 and heights up to 10^6.
// Example: 2 rectangles "6 2" and "2 10" -> 28   (6*2 + 2*10 - 2*2 overlap)
// Pattern: Bucket by width + suffix max | Time: O(n + W) | Space: O(n + W)   (W = largest width)
// Edge cases: odd widths, the largest width (index past the end), big answers (overflow), n = 1, same width twice
//
// Coach notes (review, 2026-11-23):
// - Idea: the shape is symmetric, so cut it into thin vertical strips. A strip's height is the height of the
//   TALLEST rectangle that is at least as wide as that strip's distance from the center.
//   "Tallest among all rectangles at least this wide" = a suffix max. That's why the loop must go backwards.
// - FIX 1 (odd widths): x/2 rounds down, so width 3 was treated as width 2 -> lost area.
//   Index by the FULL width instead. Index i then means "a strip 0.5 wide on the left + 0.5 wide on the right"
//   = 1 unit of width in total. So each index adds height * 1, and the final *2 goes away.
// - FIX 2 (crash): the loop reads height[i+1]. When i is the last index, i+1 is past the end.
//   Size the vector from the input (maxWidth + 2), not a guessed magic number.
// - FIX 3 (overflow): on Windows, `long` is 32 bits (max ~2.1 * 10^9). Width 20000 * height 10^6 = 2 * 10^10.
//   Use `long long`.
//
// How to work out the complexity:
//   - Reading and bucketing: n rectangles, O(1) each -> O(n).
//   - Suffix-max loop: one pass over widths W..1 -> O(W).
//   - Time: O(n + W). Space: O(n) to store the rectangles + O(W) for the buckets -> O(n + W).
//   - Trade-off: if W is huge (say 10^9), the bucket array is too big. Then sort by width, largest first, and add
//     runningMaxHeight * (width - nextWidth) for each step -> O(n log n) time, O(n) space, no matter how big W is.

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // FIX 2: Read all rectangles first, find the largest width, THEN size the bucket array.
    // vector<pair<int,int>> rects(n);                       // {width, height}
    // int maxWidth = 0;
    // for (auto& [w, h] : rects) { cin >> w >> h; maxWidth = max(maxWidth, w); }
    // vector<int> tallest(maxWidth + 2, 0);                  // +2 so tallest[i + 1] is always safe
    vector<int> height(10001, 0); // assuming max x/2 won't exceed 10000
    int max_x = 0;
    for (int i =0 ;i < n ; i++) {
        int x, y;
        cin>>x>>y;

        // FIX 1: index by the full width, not x/2 (x/2 drops half a unit when x is odd).
        // for (auto& [w, h] : rects) tallest[w] = max(tallest[w], h);
        if(height[x/2] < y) height[x/2] = y;
        if (x/2 > max_x) max_x = x/2;
    }

    // FIX 3: long long area = 0;   (`long` is 32 bits on Windows and overflows)
    long area = 0;
    // FIX 1 + 2: loop over full widths. tallest[] has maxWidth + 2 slots, so i + 1 never goes past the end.
    // for (int i = maxWidth; i >= 1; i--) {
    //     tallest[i] = max(tallest[i], tallest[i + 1]);       // suffix max: tallest rectangle at least i wide
    //     area += tallest[i];                                 // strip of total width 1 (0.5 each side)
    // }
    for (int i = max_x; i > 0; i--) {
        if ( height[i] < height[i+1]) height[i] = height[i+1];
        area += height[i];
    }

    // FIX 1: cout << area << '\n';   (no *2: each full-width index already covers both sides)
    cout<< area *2;
    return 0;
}