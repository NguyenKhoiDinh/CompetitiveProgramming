#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 1000005; 

int a[MAX_N]; 
int n; 
int fw[MAX_N]; 
int smaller[MAX_N], bigger[MAX_N]; 
long long totalSmaller[MAX_N], totalBigger[MAX_N]; 

void update(int index, int value) {
  for (; index < MAX_N; index += index & -index) {
    fw[index] += value; 
  }
}

int get(int index) {
  int ret = 0;
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  for (int i = 1; i <= n; i++) {     
    smaller[a[i]] = a[i] - 1 - get(a[i] - 1); 
    bigger[a[i]] = i - 1 - get(a[i] - 1);
    update(a[i], 1); 
  }
  for (int i = 1; i <= n; i++) {
    totalSmaller[i] = totalSmaller[i - 1] + smaller[i];
  }
  for (int i = n; i >= 1; i--) {
    totalBigger[i] = totalBigger[i + 1] + bigger[i]; 
  }
  long long ans = 1000000000000007LL; 
  for (int i = 1; i <= n; i++) {
    ans = min(ans, totalSmaller[i - 1] + totalBigger[i + 1]); 
  }
  cout << ans; 
  return 0; 
}