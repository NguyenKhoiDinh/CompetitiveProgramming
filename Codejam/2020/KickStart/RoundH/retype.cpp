#include <bits/stdc++.h>

using namespace std;
int numTest;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    int N, K, S;
    cin >> N >> K >> S;
    int ans = K + N;
    ans = min(ans, K + K - S - S + N);
    cout << ans << endl;
  }
  return 0;
}