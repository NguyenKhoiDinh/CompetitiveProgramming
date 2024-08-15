#include <bits/stdc++.h>

using namespace std;
int numTest; 
int n;
int a[200005]; 
long long ans = 0LL; 
void process(const vector <int> &a) {
  int len = 0; 
  int p = 0;
  long long sum = (int) a.size();
  long long sumSquare = 0;  
  for (int i = 0; i < (int) a.size(); i++) { 
    if (a[i] == a[p]) {
      len++;    
    }
    else {
      sumSquare += 1LL * len * len; 
      len = 1; 
      p = i; 
    }
  }
  sumSquare += 1LL * len * len;
  ans += (sum * sum - sumSquare) / 2;  
}
void solve(int p0, int p1, int p2) {
  vector <vector <int> > v; 
  for (int i = 1; i <= n - 2; i++) {
    vector <int> tmp(3);
    tmp[p0] = a[i];
    tmp[p1] = a[i + 1];
    tmp[p2] = a[i + 2];
    v.push_back(tmp);  
  }
  sort(v.begin(), v.end()); 
  vector <int> tmp = {-1, -1, -1}; 
  v.push_back(tmp);
  int p = 0;
  vector <int> b; 
  for (int i = 0; i < (int) v.size(); i++) {
    if (v[i][0] == v[p][0] && v[i][1] == v[p][1]) {
      b.push_back(v[i][2]);   
    }  
    else {
      process(b); 
      b.clear();
      b.push_back(v[i][2]);  
      p = i; 
    }
  } 
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    ans = 0LL;
    solve(0, 1, 2);
    solve(1, 2, 0);
    solve(2, 0, 1);
    cout << ans << endl;  
  }
  return 0; 
}