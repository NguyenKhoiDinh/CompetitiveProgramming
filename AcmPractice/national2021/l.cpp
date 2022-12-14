#include <bits/stdc++.h> 

using namespace std;
bool isPrime[10000005];
int n;
int a[300005];  
long long ans = 0LL; 
map <vector <int>, int> cnt; 
vector <int> listPrime; 
vector <int> listDivisor[10000005]; 

void erathones() {
  for (int i = 2; i <= 10000000; i++) {
    isPrime[i] = true; 
  }
  for (int i = 2; i <= (int) sqrt(10000000); i++) {
    if (isPrime[i] == true) {
      for (int j = i * i; j <= 10000000; j += i) {
        isPrime[j] = false; 
      }
    }
  }
  for (int i = 2; i <= 10000000; i++) {
    if (isPrime[i] == true) {
      listPrime.push_back(i); 
    }
  }
}

int main () {
  cin >> n; 
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
  }
  erathones(); 
  for (int i = 1; i <= n; i++) {
    if (listDivisor[a[i]].empty() == true) {
      int value = a[i];
      for (int j = 0; j < (int) listPrime.size(); j++) {
        if (listPrime[j] * listPrime[j] <= value) {
          if (value % listPrime[j] == 0) {
            listDivisor[a[i]].push_back(listPrime[j]); 
            while (value % listPrime[j] == 0) {
              value /= listPrime[j]; 
            }
          }
        }
        else {
          break;
        }
      }
      if (value > 1) {
        listDivisor[a[i]].push_back(value);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += cnt[listDivisor[a[i]]]; 
    cnt[listDivisor[a[i]]]++; 
  }
  cout << ans;
  return 0; 
}                             