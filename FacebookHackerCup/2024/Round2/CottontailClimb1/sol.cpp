#include <bits/stdc++.h> 

using namespace std;
struct elementUp {
  long long value; 
  int len, firstDigit; 
  bool operator < (const elementUp &other) {
    return (len < other.len || (len == other.len && firstDigit < other.firstDigit));
  }
}; 
struct elementDown {
  long long value; 
  int len, lastDigit; 
  bool operator < (const elementDown &other) {
    return (len < other.len || (len == other.len && lastDigit < other.lastDigit));
  }
};
vector <elementUp> up;
vector <elementDown> down; 
void generateUp() {
  for (int d = 1; d <= 8; d++) {
    long long cur = d;
    int len = 1;
    int firstDigit = d;  
    int dig = d;  
    while (true) {
      up.push_back((elementUp) {cur, len, firstDigit});
      dig++;
      if (dig >= 9) {
        break; 
      } 
      cur = cur * 10 + dig; 
      len++; 
    }
  }                                   
  sort(up.begin(), up.end()); 
}
void generateDown() {
  for (int d = 1; d <= 8; d++) {
    long long cur = d;
    int len = 1;  
    int dig = d; 
    while (true) {
      down.push_back((elementDown) {cur, len, dig});
      dig--;
      if (dig <= 0) {
        break; 
      } 
      cur = cur * 10 + dig; 
      len++;
    }
  }                                       
  sort(down.begin(), down.end()); 
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  generateUp(); 
  generateDown();          
  int numTest;                 
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    long long A, B, mod; 
    cin >> A >> B >> mod;
    vector <long long> power10(20);
    power10[0] = 1LL;
    for (int i = 1; i < 19; i++) {
      power10[i] = (power10[i - 1] * 10LL); 
    }
    int ans = 0; 
    for (int i = 0; i < (int) up.size(); i++) {
      long long value = (up[i].value * 10LL + up[i].firstDigit + up[i].len) * power10[up[i].len] + down[i].value;
      if (A <= value && value <= B && value % mod == 0) {
        ans++; 
      }
    }
    for (int i = 1; i <= 9; i++) {
      if (A <= i && i <= B && i % mod == 0) {
        ans++;
      }
    }
    cout << ans << endl; 
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}