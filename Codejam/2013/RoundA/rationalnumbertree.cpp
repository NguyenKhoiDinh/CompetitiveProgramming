#include <bits/stdc++.h> 

using namespace std;
int numTest; 

pair <unsigned long long, unsigned long long> solveOne(unsigned long long n) {
  pair <unsigned long long, unsigned long long> res;
  res.first = 1LL;
  res.second = 1LL; 
  string binary = "";
  while (n > 0) {
    if (n % 2 == 1) {
      binary += "1";
      n--;
    }
    else {
      binary += "0";
    }
    n /= 2; 
  }
  reverse(binary.begin(), binary.end());
  for (int i = 1; i < (int) binary.size(); i++) {
    if (binary[i] == '0') {
      res.second += res.first; 
    }
    else {
      res.first += res.second;
    }
  }
  return res; 
}

unsigned long long solveTwo(unsigned long long p, unsigned long long q) {
  unsigned long long res = 0LL;
  string binary = "";
  while (p > 1 || q > 1) {
    if (p > q) {
      p -= q; 
      binary += '1';  
    }
    else {
      q -= p;
      binary += '0';
    }
  }
  binary += '1';
  reverse(binary.begin(), binary.end());
  for (int i = 0; i < (int) binary.size(); i++) {
    res = res * 2LL + binary[i] - '0';
  }
  return res;
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    int type;
    cin >> type; 
    if (type == 1) {
      unsigned long long n; 
      cin >> n;
      pair <unsigned long long, unsigned long long> res = solveOne(n);
      cout << res.first << ' ' << res.second;
    }
    else {
      unsigned long long p, q;
      cin >> p >> q; 
      cout << solveTwo(p, q);
    }
    cout << endl;
  }
  return 0; 
}