#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 60005; 
int fw[MAX_N];

void update(int index, int value) {
  for (; index < MAX_N; index += index & -index) {
    fw[index] += value;
  }
}

int get(int index) {
  int ans = 0; 
  for (; index > 0; index -= index & -index) {
    ans += fw[index]; 
  } 
  return ans;
}

int main () {
  long long res = 0LL;
  int n; 
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int value; 
    cin >> value;
    res += i - 1 - get(value);
    update(value, 1);
  } 
  cout << res;
  return 0; 
}