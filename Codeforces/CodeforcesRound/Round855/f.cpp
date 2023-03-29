#include <bits/stdc++.h> 
using namespace std; 
int numTest; 
int n; 
string a[200005]; 
long long ans = 0LL;
vector <bitset <26> > save;
struct Comparer {
  bool operator() (const bitset <26> &b1, const bitset <26> &b2) const {
    return b1.to_ulong() < b2.to_ulong();
  }
}; 
map <bitset <26>, int, Comparer> cnt; 

int main () {
  ios::sync_with_stdio(false); 
  bitset <26> tmp; 
  for (int i = 0; i < 26; i++) {
    tmp.set(i, 1); 
  }
  for (int i = 0; i < 26; i++) {
    save.push_back(tmp); 
    save.back().set(i, 0);        
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
    vector <int> numb; 
    numb.resize(26, 0); 
    for (int j = 0; j < (int) a[i].size(); j++) {
      numb[a[i][j] - 'a']++; 
      numb[a[i][j] - 'a'] %= 2; 
    }
    bitset <26> mybitset; 
    for (int c = 0; c < 26; c++) {
      if (numb[c] == 1) {
        mybitset.set(c, 1); 
      }
    }
    for (int j = 0; j < 26; j++) {
      bitset <26> other = save[j] ^ mybitset; 
      ans += cnt[other]; 
    }
    cnt[mybitset]++;   
  }
  cout << ans;
  return 0; 
}