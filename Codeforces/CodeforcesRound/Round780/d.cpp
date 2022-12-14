#include <bits/stdc++.h> 

using namespace std;
int numTest; 
int n; 
int a[200005]; 
int cnt[200005]; 

int main () {
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    int firstNeg = -1; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      if (a[i] < 0 && firstNeg == -1) {
        firstNeg = i; 
      }
      cnt[i] = cnt[i - 1]; 
      if (abs(a[i]) == 2) {
        cnt[i]++; 
      }
    }
    int numb = -1;
    int numbNeg = 0;
    int l = 1, r = 1; 
    for (int i = 1; i <= n; i++) {
      if (a[i] < 0) {
        numbNeg++; 
        numbNeg %= 2; 
      }
      if (numbNeg == 0) {
        if (numb < cnt[i]) {
          numb = cnt[i]; 
          r = i; 
          l = 1; 
        }  
      }
      else {
        if (numb < cnt[i] - cnt[firstNeg]) {
          numb = cnt[i] - cnt[firstNeg]; 
          l = firstNeg + 1; 
          r = i; 
        }
      }
    }
    cout << l - 1 << ' ' << n - r << endl;    
  }
  return 0; 
}