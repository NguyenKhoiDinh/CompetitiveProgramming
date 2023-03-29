#include <iostream> 

using namespace std;
int numTest; 
int n;
int a[200005]; 
long long sum[200005]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      sum[i] = sum[i - 1] + a[i]; 
    }
    int lo = 1; 
    int hi = n; 
    int ans = -1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      cout << "? " << mid - lo + 1 << ' '; 
      for (int i = lo; i <= mid; i++) {
        cout << i << ' '; 
      }
      cout << endl; 
      fflush(stdout); 
      long long weight; 
      cin >> weight; 
      if (sum[mid] - sum[lo - 1] == weight) {
        ans = mid + 1; 
        lo = mid + 1; 
      }
      else {
        ans = lo;
        hi = mid - 1;   
      }
    }
    cout << "! " << ans << endl; 
    fflush(stdout); 
  }
  return 0;   
}