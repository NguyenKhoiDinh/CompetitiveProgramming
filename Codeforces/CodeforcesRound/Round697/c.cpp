#include <iostream>
#include <fstream>

using namespace std;
const int MAX_N = 200005;
int numBoys, numGirls, k;
int boy[MAX_N], girl[MAX_N];
int countBoy[MAX_N], countGirl[MAX_N], numBoy[MAX_N], numGirl[MAX_N];
int numTest;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> numBoys >> numGirls >> k;
    for (int i = 1; i <= k; i++) {
      cin >> boy[i];
      numBoy[boy[i]]++;
    }
    for (int i = 1; i <= k; i++) {
      cin >> girl[i];
      numGirl[girl[i]]++;
    }
    long long ans = 0LL;
    for (int i = 1; i <= k; i++) {
      countBoy[boy[i]]++;
      countGirl[girl[i]]++;
      ans += k - i - (numBoy[boy[i]] - countBoy[boy[i]] + numGirl[girl[i]] - countGirl[girl[i]]);
    }
    cout << ans << endl;
    for (int i = 1; i <= k; i++) {
      countBoy[boy[i]]--;
      countGirl[girl[i]]--;
      numBoy[boy[i]]--;
      numGirl[girl[i]]--;
    }
  }
  return 0;
}