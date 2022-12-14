#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;
const int inf = 1000000007;
const int MAX_N = 10000007;
int sum[MAX_N];
int ans[MAX_N];
int numTest;

void init() {
  for (int i = 1; i < MAX_N; i++) {
    ans[i] = inf;
  }
  for (int i = 1; i < MAX_N; i++) {
    for (int j = i; j < MAX_N; j += i) {
      sum[j] += i;
    }
    if (sum[i] < MAX_N) {
      ans[sum[i]] = min(ans[sum[i]], i);
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  init();
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    cout << (ans[n] == inf ? -1 : ans[n]) << endl;
  }
  return 0;
}