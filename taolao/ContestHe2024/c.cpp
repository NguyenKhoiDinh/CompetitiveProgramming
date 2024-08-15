#include <bits/stdc++.h> 

using namespace std;
int numTest; 
int cnt[26]; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s;
    int k; 
    cin >> s >> k; 
    for (int ch = 0; ch < 25; ch++) {
      cnt[ch] = 0; 
    }
    long long ans = 0LL; 
    int l = 0; 
    for (int i = 0; i < (int) s.size(); i++) {
      cnt[s[i] - 'a']++;
      while (cnt[s[i] - 'a'] > k) {
        cnt[s[l] - 'a']--;
        l++;   
      }
      ans += i - l + 1;  
    }
    cout << ans << endl;
  }
  return 0;
}