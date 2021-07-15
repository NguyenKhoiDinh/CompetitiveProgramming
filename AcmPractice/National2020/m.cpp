#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
int numTest;
long long X1, Y1, X2, Y2;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> X1 >> Y1 >> X2 >> Y2;
    long long deltaX = abs(X2 - X1);
    long long deltaY = abs(Y2 - Y1);
    if (deltaX % 2 == deltaY % 2) {
      cout << 2LL * max(deltaX, deltaY);
    }
    else {
      cout << 2LL * max(deltaX, deltaY) - 1;
    }
    cout << endl;
  }
  return 0;
}