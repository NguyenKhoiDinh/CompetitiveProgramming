#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1000005; 

double phi[MAX_N];
bool isPrime[MAX_N];
int numTest; 
int n; 

void init() {
  for (int i = 1; i < MAX_N; i++) {
    isPrime[i] = true; 
  }
  isPrime[1] = false; 
  for (int i = 2; i < MAX_N; i++) {
    if (isPrime[i] == true) {
      for (int j = 2 * i; j < MAX_N; j += i) {
        isPrime[j] = false; 
      }
    }
  }
  for (int i = 1; i < MAX_N; i++) {
    phi[i] = 1.0 * i;
  }
  for (int i = 2; i < MAX_N; i++) {
    if (isPrime[i] == true) {
      for (int j = i; j < MAX_N; j += i) {
        phi[j] *= 1.0 * (1.0 - 1.0 / (double) i);
      }
    }
  }
}

int main () {
  init();
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    cout << (int) phi[n] << endl;
  }
  return 0; 
}