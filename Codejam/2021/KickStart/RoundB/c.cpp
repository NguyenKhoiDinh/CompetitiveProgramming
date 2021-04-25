#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std; 
int numTest;

bool isPrime(long long p) {
  if (p == 1) {
    return false;
  }
  for (long long i = 2; i <= (long long) sqrt(p); i++) {
    if (p % i == 0) {
      return false; 
    }
  }
  return true; 
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    long long N; 
    cin >> N; 
    long long mid = (long long) sqrt(N); 
    vector <long long> Left; 
    for (int i = 0; ; i++) {
      long long p = mid - i; 
      if (p <= 1) {
        break; 
      }
      if ((int) Left.size() == 2) {
        break; 
      }
      if (isPrime(p) == true) {
        Left.push_back(p); 
      }
    }
    long long Right; 
    for (int i = 0; ; i++) {
      long long p = mid + i; 
      if (isPrime(p) == true) {
        Right = p; 
        break; 
      }
    }
    long long ans = 0LL;
    reverse(Left.begin(), Left.end());
    if (1LL * Left.back() * Right <= N) {
      ans = 1LL * Left.back() * Right; 
    }
    else {
      ans = 1LL * Left[0] * Left[1]; 
    }
    cout << ans << endl;
  }
  return 0;
}