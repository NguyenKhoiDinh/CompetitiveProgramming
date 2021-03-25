#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <functional>

using namespace std;
const int MAX_N = 10005;
struct police {
  int column, time;
};
struct segment {
  int left, right;
  bool operator < (const segment &hs) const {
    return (left < hs.left || (left == hs.left && right < hs.right));
  }
};
police a[MAX_N];
int n;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].column, &a[i].time);
  }
  int lo = 0;
  int hi = 1000000007;
  int res = -1;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    vector <segment> listCover;
    for (int i = 1; i <= n; i++) {
      int numMove = mid / a[i].time;
      int left = max(1, a[i].column - numMove);
      int right = min(n, a[i].column + numMove);
      listCover.push_back((segment) {left, right});
    }
    sort(listCover.begin(), listCover.end());
    bool check = true;
    priority_queue <int, vector <int>, greater <int> > pq;
    int curSegment = 0;
    for (int x = 1; x <= n; x++) {
      while (curSegment < n) {
        if (listCover[curSegment].left == x) {
          pq.push(listCover[curSegment].right);
          curSegment++;
        }
        else {
          break;
        }
      }
      while (!pq.empty() && pq.top() < x) {
        pq.pop();
      }
      if (!pq.empty()) {
        pq.pop();
      }
      else {
        check = false;
        break;
      }
    }
    if (check == true) {
      res = mid;
      hi = mid - 1;
    }
    else {
      lo = mid + 1;
    }
  }
  printf("%d", res);
  return 0;
}