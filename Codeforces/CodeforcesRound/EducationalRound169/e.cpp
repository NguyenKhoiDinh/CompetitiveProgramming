#include <bits/stdc++.h>

using namespace std;
const int lim = 10000000; 
bool isPrime[lim + 3]; 
int pos[lim + 3];
int grundy[lim + 3];     
void erathones() {
  grundy[1] = 1; 
  for (int i = 2; i <= lim; i++) {
    isPrime[i] = true; 
  }  
  for (int i = 2; i * i <= lim; i++) {
    if (isPrime[i] == false) {
      continue; 
    }
    for (int j = i * i; j <= lim; j += i) {
      isPrime[j] = false; 
    }
  }
  int numbPrimes = 0; 
  for (int i = 2; i * i <= lim; i++) {
    if (isPrime[i] == true) {
      numbPrimes++; 
      if (i == 2) {
        continue; 
      }
      for (int j = i * i; j <= lim; j += 2 * i) {
        if (grundy[j] == 0) {
          grundy[j] = numbPrimes; 
        }
      }
    }
  }
  numbPrimes = 0;
  for (int i = 2; i <= lim; i++) {
    if (isPrime[i] == true) {
      numbPrimes++; 
      if (i == 2) {
        continue; 
      }
      grundy[i] = numbPrimes; 
    }
  }    
}

int main () {
  erathones();             
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      int x; 
      cin >> x; 
      ans ^= grundy[x]; 
    }      
    cout << (ans > 0 ? "Alice" : "Bob") << endl; 
  }
  return 0; 
}