#include <bits/stdc++.h> 

using namespace std;
int n;
vector <int> a; 
vector <int> prefix, suffix; 

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout); 
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
  cin >> n;
  a.clear(); 
  a.resize(n);
  prefix.clear();
  suffix.clear();  
  prefix.resize(n, false);
  suffix.resize(n, false); 
  for (int i = 0; i < n; i++) {
    cin >> a[i]; 
  }
  vector <int> b;
  b = a; 
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      prefix[i] = true; 
    }
    else {
      break; 
    }
  } 
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == b[i]) {
      suffix[i] = true; 
    }
    else {
      break; 
    }
  }
  long long ans = 1000000000000007LL; 
  for (int i = 0; i < n; i++) {
    vector <int> tmp = a; 
    long long sum = 0LL;
    if (prefix[i] == false) {
      sum += (long long) (i + 1) * (i + 1); 
    }
    sort(tmp.begin(), tmp.begin() + i + 1);
    int p = -1;
    for (int i = 0; i < n; i++) {
      if (tmp[i] != b[i]) {
        p = i; 
        break; 
      }
    }
    if (p != -1) {
      sum += (long long) (n - p) * (n - p); 
    }
    ans = min(ans, sum);  
  }
  for (int i = n - 1; i >= 0; i--) { 
    vector <int> tmp = a; 
    long long sum = 0LL; 
    if (suffix[i] == false) {
      sum += (long long) (n - i) * (n - i); 
    }
    sort(tmp.begin() + i, tmp.end());
    int p = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (tmp[i] != b[i]) {
        p = i;
        break; 
      }
    }
    if (p != -1) {
      sum += (long long) (p + 1) * (p + 1); 
    } 
    ans = min(ans, sum); 
  }
  cout << ans << endl;                                 
  }

  return 0; 
}