#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 11005; 
bool isPrime[MAX_N];
vector <int> save; 
int ways[MAX_N];

void erathones() {
  for (int i = 1; i < MAX_N; i++) {
    isPrime[i] = true; 
  }
  isPrime[1] = false; 
  for (int i = 2; i < MAX_N; i++) {
    for (int j = 2 * i; j < MAX_N; j += i) {
      isPrime[j] = false; 
    }
  }
  for (int i = 2; i < MAX_N; i++) {
    if (isPrime[i] == true) {
      save.push_back(i);
    }
  }
}

int main () {
  erathones();
  for (int i = 0; i < (int) save.size(); i++) {
    int sum = 0;
    for (int j = i; j < (int) save.size(); j++) {
      sum += save[j];
      if (sum < MAX_N) {
        ways[sum]++;
      }
    }
  }
  while (true) {
    int n; 
    cin >> n;
    if (n == 0) {
      break; 
    }
    cout << ways[n] << endl;
  }
  return 0; 
}