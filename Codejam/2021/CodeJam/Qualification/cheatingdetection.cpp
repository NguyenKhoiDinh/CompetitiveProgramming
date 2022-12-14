#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 105;
int numTest;
int P;
string a[MAX_N];

int main () {
  srand (time(NULL));
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  cin >> P;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    for (int i = 1; i <= 100; i++) {
      cin >> a[i];
    }
    int cheater = -1;
    int maxi = -1;
    for (int i = 1; i <= 100; i++) {
      int cntRand = 0;
      int cntReal = 0;
      for (int j = 1; j < (int) a[i].size(); j++) {
        if (a[i][j] == '1') {
          cntReal++;
        }
      }
      if (maxi < cntReal) {
        maxi = cntReal;
        cheater = i;
      }
    }
    cout << cheater << endl;
  }
  return 0;
}