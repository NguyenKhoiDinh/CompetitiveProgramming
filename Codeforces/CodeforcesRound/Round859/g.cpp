#include <iostream>
#include <algorithm> 

using namespace std;
int numTest; 
int n;
int a[200005]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }   
    sort(a + 1, a + n + 1); 
    if (a[1] != 1) {
      cout << "NO" << endl;
      continue;  
    }
    long long sum = 0LL; 
    bool found = true; 
    for (int i = 2; i <= n; i++) {
      sum += a[i - 1]; 
      if (sum < a[i]) {
        found = false; 
        break; 
      }
    }
    cout << (found == true ? "YES" : "NO") << endl;
  }
  return 0;   
}