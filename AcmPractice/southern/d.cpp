#include <bits/stdc++.h> 

using namespace std;
struct element {
  int l;
  string in, out;  
};
const int MOD = 1000000007; 
int dp[2][305][305];
int ways[2][305][2][2]; 
int L; 
vector <element> a, other, noneIn, noneOut; 
                
int main () {
  int n;
  cin >> n >> L;
  int res = 0; 
  for (int i = 1; i <= n; i++) {
    int len;
    string in, out; 
    cin >> len >> in >> out; 
    if (in == "none" && out == "none") {
      if (len == L) {
        res++; 
      }
      continue; 
    }
    if (out == "in") {
      out = "out"; 
    }
    else if (out == "out") {
      out = "in"; 
    }
    element e = (element) {len, in, out}; 
    if (in == "none") {
      noneIn.push_back(e); 
    }                      
    else if (out == "none") {
      noneOut.push_back(e); 
    }
    else if (in != out) {
      a.push_back(e); 
    }
    else {
      other.push_back(e); 
    }
  }
  int sza = (int) a.size(); 
  int szOther = (int) other.size(); 
  int szNoneIn = (int) noneIn.size(); 
  int szNoneOut = (int) noneOut.size(); 
  ways[0][0][0][0] = 1; 
  for (int i = 0; i < szOther; i++) {
    int cur = i & 1;
    int nxt = !cur; 
    memset(ways[nxt], 0, sizeof(ways[nxt])); 
    for (int len = 0; len <= L; len++) {
      for (int haveIn = 0; haveIn <= 1; haveIn++) {
        for (int haveOut = 0; haveOut <= 1; haveOut++) {
          if (ways[cur][len][haveIn][haveOut] == 0) {
            continue; 
          }
          int curValue = ways[cur][len][haveIn][haveOut];
          (ways[nxt][len][haveIn][haveOut] += curValue) %= MOD;
          if (len + other[i].l <= L) {
            int newHaveIn = (haveIn | (other[i].in == "in"));
            int newHaveOut = (haveOut | (other[i].out == "out"));
            (ways[nxt][len + other[i].l][newHaveIn][newHaveOut] += curValue) %= MOD; 
          }
        }
      }
    }
  }
  dp[0][0][150] = 1; 
  for (int i = 0; i < sza; i++) {
    int cur = i & 1;
    int nxt = !cur;
    memset(dp[nxt], 0, sizeof(dp[nxt])); 
    for (int len = 0; len <= L; len++) {
      for (int diff = 0; diff <= 300; diff++) {
        if (dp[cur][len][diff] == 0) {
          continue; 
        }
        int curValue = dp[cur][len][diff]; 
        (dp[nxt][len][diff] += curValue) %= MOD; 
        if (len + a[i].l > L) {
          continue; 
        }
        int newDiff = diff;
        if (a[i].in == "in") {
          newDiff++; 
        }
        if (a[i].out == "in") {
          newDiff--; 
        }
        if (newDiff < 0 || newDiff > 300) {
          continue;
        }
        (dp[nxt][len + a[i].l][newDiff] += curValue) %= MOD; 
      }
    }
  }
  for (int i = 0; i < szNoneIn; i++) {
    for (int j = 0; j < szNoneOut; j++) {
      int diff = 0; 
      if (noneIn[i].out == "in") {
        diff--; 
      }
      if (noneOut[j].in == "in") {
        diff++; 
      }
      int totalLen = noneIn[i].l + noneOut[j].l;
      if (totalLen > L) {
        continue; 
      }
      for (int len = 0; len <= L - totalLen; len++) {
        for (int haveIn = 0; haveIn <= 1; haveIn++) {
          for (int haveOut = 0; haveOut <= 1; haveOut++) {
            long long mul = dp[sza & 1][len][150 - diff];
            (mul *= ways[szOther & 1][L - totalLen - len][haveIn][haveOut]) %= MOD; 
            (res += mul) %= MOD; 
          }
        }   
      }
    }
  }
  for (int i = 0; i < szNoneIn; i++) {
    for (int j = 0; j < szNoneOut; j++) {
      if (noneIn[i].out == "in" && noneOut[j].in == "in") {
        long long sum = 0LL;
        int totalLen = noneIn[i].l + noneOut[j].l;
        if (totalLen > L) {
          continue; 
        }
        (sum += ways[szOther & 1][L - totalLen][1][1]) %= MOD;
        (sum += ways[szOther & 1][L - totalLen][0][1]) %= MOD;
        res -= sum;
        (res += MOD) %= MOD;      
      }
      if (noneIn[i].out == "out" && noneOut[j].in == "out") {
        long long sum = 0LL;
        int totalLen = noneIn[i].l + noneOut[j].l;
        if (totalLen > L) {
          continue;
        }
        (sum += ways[szOther & 1][L - totalLen][1][1]) %= MOD;
        (sum += ways[szOther & 1][L - totalLen][1][0]) %= MOD;
        res -= sum;
        (res += MOD) %= MOD;      
      }
    }
  }
  cout << res;
  return 0; 
}