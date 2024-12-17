#include <bits/stdc++.h> 

using namespace std;
vector <long long> up[10];
vector <long long> down[10]; 
void generateUp(long long value, int len, int lastDigit) {
  if (len >= 1) {
    up[len].push_back(value); 
  }
  if (len < 8) {
    for (int d = 0; d <= 8 - lastDigit; d++) {
      generateUp(value * 10LL + lastDigit + d, len + 1, lastDigit + d); 
    }
  } 
}
void generateDown(long long value, int len, int lastDigit) {
  if (len >= 1) {
    down[len].push_back(value); 
  } 
  if (len < 8) {
    for (int d = 0; d <= lastDigit - 1; d++) {
      generateDown(value * 10LL + lastDigit - d, len + 1, lastDigit - d); 
    }
  }
}
long long f(long long n, int mod) {
  long long ans = 0LL; 
  for (int d = 1; d <= 9; d++) {
    if (d <= n && d % mod == 0) {
      ans++; 
    }
  }
  vector <int> N; 
  while (n > 0) {
    int r = n % 10;
    n /= 10;
    N.push_back(r);   
  }
  reverse(N.begin(), N.end());
  int lenN = (int) N.size(); 
  vector <long long> power10(lenN + 2); 
  power10[0] = 1LL; 
  for (int i = 1; i <= lenN; i++) {
    power10[i] = (power10[i - 1] * 10LL) % mod; 
  }
  for (int len = 1; len <= 8; len++) {
    if (2 * len + 1 < lenN) {
      map <int, int> cnt[9];
      for (int i = 0; i < (int) down[len].size(); i++) {
        long long value = down[len][i]; 
        int firstDigit = -1;          
        while (value > 0) {
          int r = value % 10;
          firstDigit = r; 
          value /= 10; 
        }
        cnt[firstDigit][down[len] % mod]++; 
      }
      for (int i = 0; i < (int) up[len].size(); i++) {
        long long value = up[len][i]; 
        int lastDigit = value % 10; 
        for (int addDigit = lastDigit; addDigit <= 9; addDigit++) {
          long long r1 = ((long long) (value * 10 + addDigit) * power10[len]) % mod;
          for (int nextDigit = addDigit; nextDigit >= 1; nextDigit--) {
            ans += cnt[nextDigit][(mod - r1) % mod]; 
          } 
        }
      }  
    }
    else if (2 * len + 1 == lenN) {
      
    }
  } 
  return ans; 
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  generateUp(0, 0, 1);
  generateDown(0, 0, 1);          
  int numTest;                 
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    long long A, B, mod; 
    cin >> A >> B >> mod;
    cout << f(A, mod) - f(B - 1, mod) << endl;  
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}