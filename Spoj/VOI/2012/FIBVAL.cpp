#include <iostream>
#include <vector>

using namespace std;
// big: 6 - 21
// small: 8 - 8, 16-16

int find(int u, int v) {
  int stepu = (u - 1) / 16;
  int stepv = (v - 1) / 16;
  int tmpu = u % 16;
  if (tmpu == 0) {
    tmpu = 16;
  }
  int tmpv = v % 16;
  if (tmpv == 0) {
    tmpv = 16;
  }
  if (u - v + 1 >= 32) {
    return ((u - v + 1) / 16 * 16);
  }
  if (stepu == stepv && tmpu <= 8 && tmpv >= 9) {
    return 2;
  }
  else if (stepv - stepu >= 1) {
    return 2;
  }
  else {
    return -1;
  }
}

int main () {
  int numTest;
  scanf("%d", &numTest);
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int u, v;
    scanf("%d %d", &u, &v);
    int res = find(u, v);
    cout << res << endl;
  }
  return 0;
}