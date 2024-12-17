#include <bits/stdc++.h> 

using namespace std;
int n;
string s; 
vector <int> pos; 
int sum[500005]; 
int findNext(int l, int numb) {
  int lo = l + 1;
  int hi = (int) pos.size() - 1; 
  int p = -1;          
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    if (sum[pos[mid]] - (l == -1 ? 0 : sum[pos[l]]) >= numb) {
      p = mid;
      hi = mid - 1;  
    }
    else {
      lo = mid + 1; 
    }
  }
  return p; 
}

int main () {
  cin >> n;
  cin >> s; 
  s += '1'; 
  int numbZeros = 0;
  for (int i = 0; i < n; i++) {
    numbZeros += s[i] == '0'; 
  }
  int ans = 0; 
  for (int i = 0; i <= n; i++) {
    if (i > 0) {
      sum[i] = sum[i - 1]; 
    }
    if (s[i] == '0') {
      sum[i]++;  
    }
    else {
      pos.push_back(i);
      ans++;
    }
  }
  ans--;
  for (int i = 1; i <= numbZeros; i++) {
    int p = -1;
    int numbOnes = 0; 
    while (true) {
      p = findNext(p, i);
      if (p != -1) {
        numbOnes++; 
      }
      else {
        break; 
      }
    }            
    if (numbOnes > 1) {
      ans = max(ans, numbOnes - 1 + numbOnes * i); 
    }
  }
  cout << ans; 
  return 0; 
}