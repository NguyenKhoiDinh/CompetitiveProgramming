#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 200005;
int numTest, n, m;
int a[MAX_N];
long long sum1[MAX_N], sum2[MAX_N];
vector <int> b1, b2;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> m;
    b1.clear();
    b2.clear();
    for (int i = 1; i <= n; i++) {
      sum1[i] = sum2[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      int val;
      cin >> val;
      if (val == 1) {
        b1.push_back(a[i]);
      }
      else {
        b2.push_back(a[i]);
      }
    }
    sort(b1.begin(), b1.end());
    sort(b2.begin(), b2.end());
    reverse(b1.begin(), b1.end());
    reverse(b2.begin(), b2.end());
    int sz1 = (int) b1.size();
    int sz2 = (int) b2.size();
    sum1[0] = 0;
    sum2[0] = 0;
    for (int i = 1; i <= sz1; i++) {
      sum1[i] = sum1[i - 1] + b1[i - 1];
    }
    for (int i = 1; i <= sz2; i++) {
      sum2[i] = sum2[i - 1] + b2[i - 1];
    }
    int res = 1000000007;
    for (int num1 = 0; num1 <= sz1; num1++) {
      long long sum = sum1[num1];
      long long rest = m - sum;
      int l = 0;
      int r = sz2;
      int pos = -1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (sum2[mid] >= rest) {
          pos = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }
      if (pos != -1) {
        res = min(res, num1 + 2 * pos);
      }
    }
    cout << (res == 1000000007 ? -1 : res) << endl;
  }
  return 0;
}