#include <bits/stdc++.h>

using namespace std; 
vector <long long> valueC; 
int n, k; 
long long sum = 0LL; 

int main () {
  cin >> n >> k;
  default_random_engine engine;
  uniform_int_distribution <long long> dist(1, 16e10);
  valueC.resize(k - 1);
  for (int i = 0; i < k - 1; i++) {
    valueC[i] = dist(engine); 
    sum += valueC[i];
  }   
  valueC.push_back(-sum); 
  int ans = 0; 
  map <long long, int> pos; 
  sum = 0LL;
  pos[0] = 0; 
  for (int i = 0; i < n; i++) {
    int candy;
    cin >> candy; 
    sum += valueC[candy - 1];
    if (pos.find(sum) != pos.end()) {
      int lastPos = pos[sum]; 
      ans = max(ans, i - lastPos + 1); 
    } 
    else {
      pos[sum] = i + 1;
    }
  }
  cout << ans;
  return 0; 
}