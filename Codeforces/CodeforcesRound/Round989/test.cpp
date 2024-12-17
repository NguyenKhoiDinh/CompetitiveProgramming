#include <bits/stdc++.h> 

using namespace std;
vector <vector <int> > save;
vector <int> p;
int n, k;  
vector <vector <int> > ans; 
void backTrack(int start) {
  if ((int) ans.size() == k) {
    vector <int> v; 
    for (int j = 0; j < (int) ans[0].size(); j++) {
      int sum = 0;
      for (int i = 0; i < (int) ans.size(); i++) {
        sum += ans[i][j]; 
      }
      v.push_back(sum);   
    }
    bool check = true;
    for (int i = 1; i < (int) v.size(); i++) {
      if (v[i] != v[0]) {
        check = false;
        break; 
      }
    }
    if (check == true) {
      for (int i = 0; i < (int) ans.size(); i++) {
        for (int j = 0; j < (int) ans[i].size(); j++) {
          std::cout << ans[i][j] << "     "; 
        }
        cout << endl; 
      }
      exit(0);   
    }
    return; 
  }
  for (int i = start; i < (int) save.size(); i++) {
    ans.push_back(save[i]); 
    if (i < (int) save.size() - 1) {
      backTrack(i + 1); 
    }
    ans.pop_back(); 
  }
}

int main () {
  freopen("output.txt", "w", stdout); 
  cin >> n >> k; 
  for (int i = 1; i <= n; i++) {
    p.push_back(i); 
  }
  do {
    save.push_back(p); 
  }
  while (next_permutation(p.begin(), p.end()));
  backTrack(0);  
  return 0; 
}