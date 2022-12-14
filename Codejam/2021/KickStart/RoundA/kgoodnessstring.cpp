#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;
int numTest;
string s;
int n, k;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> k;
    cin >> s;
    int total = 0;
    int l = 0;
    int r = n - 1;
    while (l <= r) {
      if (s[l] != s[r]) {
        total++;
      }
      l++;
      r--;
    }
    cout << abs(k - total) << endl;
  }
  return 0;
}