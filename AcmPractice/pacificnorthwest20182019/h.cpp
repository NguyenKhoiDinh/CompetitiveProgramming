#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 1000005;
vector <int> listPrimes;
bool isPrime[MAX_N];
int n;

void init() {
  for (int i = 1; i < MAX_N; i++) {
    isPrime[i] = true;
  }
  isPrime[1] = false;
  for (int p = 2; p < MAX_N; p++) {
    if (isPrime[p] == false) {
      continue;
    }
    for (int j = 2 * p; j < MAX_N; j += p) {
      isPrime[j] = false;
    }
  }
  for (int p = 2; p < MAX_N; p++) {
    if (isPrime[p] == true) {
      listPrimes.push_back(p);
    }
  }
}

int main () {
  init();
  cin >> n;
  int ans = 0;
  while (n >= 4) {
    for (int i = 0; i < (int) listPrimes.size(); i++) {
      int p = listPrimes[i];
      if (isPrime[n - p] == true) {
        n -= 2 * p;
        ans++;
        break;
      }
    }
  }
  cout << ans;
  return 0; 
}