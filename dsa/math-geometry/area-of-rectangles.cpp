// Find total area covered by two rectangles given their coordinates; 
// Sample input: 1 1 3 4 (x1,y1, x2,y2) and 2 3 6 7 (x3, y3, x4, y4)
// Given the coordinates are bottom left and top right corners of each rectangle.

#include <bits/stdc++.h>
using namespace std;
 
long long areaOfRectangles(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    long long area1 = 1LL * (x2 - x1) * (y2 - y1); // area of the first rectangle where 1LL means the multiplication is performed using long long to avoid integer overflow.
    long long area2 = 1LL* (x4 - x3) * (y4 - y3); // area of the second rectangle

    long long overlapWidth = max(0, min(x2, x4) - max(x1, x3));
    long long overlapHeight = max(0, min(y2, y4) - max(y1, y3));

    return area1 + area2 - overlapWidth * overlapHeight;
}
