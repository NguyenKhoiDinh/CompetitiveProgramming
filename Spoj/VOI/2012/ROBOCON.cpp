#include <iostream>
#include <queue>

using namespace std;
struct element {
  int x1, y1, x2, y2;
  int distance;
  bool operator < (const element &hs) const {
    return (x1 < hs.x || (x1 == hs.x && y1 < hs.y1) ||
    (x1 == hs.x1 && y1 == hs.y1 && x2 < hs.x2) ||
    (x1 == hs.x1 && y1 == hs.y1 && x2 == hs.x2 && y2 < hs.y2));
  }
};

set <element> S;


int main () {
  return 0;
}