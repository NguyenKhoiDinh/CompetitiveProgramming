#include <iostream> 

using namespace std;
int numTest; 
int n, k, numQuery; 
int a[200005];
int sum[200005]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> numQuery; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      a[i] %= 2; 
      sum[i] = (sum[i - 1] + a[i]) % 2; 
    }
    for (int query = 1; query <= numQuery; query++) {
      int l, r, k;
      cin >> l >> r >> k;
      k %= 2; 
      int value = sum[n]; 
      value -= (sum[r] - sum[l - 1]);
      value += k * (r - l + 1); 
      value += 100 * n;
      value %= 2;
      if (value % 2 == 1) {
        cout << "YES"; 
      } 
      else {
        cout << "NO"; 
      }
      cout << endl;
    }
  }
  return 0;   
}