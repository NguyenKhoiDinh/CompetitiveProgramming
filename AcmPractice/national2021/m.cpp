#include <bits/stdc++.h> 

using namespace std; 
int n;
vector <vector <int> > save;
int p[105];
int other_p[105];   

int main () {
  cin >> n; 
  if (n == 2) {
    cout << 3 << endl; 
    cout << "1 2" << endl;
    cout << "2 3" << endl; 
    cout << "3 1" << endl; 
  }
  else {
    cout << 1 + (n - 1) * n << endl; 
    for (int i = 1; i <= n; i++) {
      cout << i << ' '; 
    }
    cout << endl; 
    save.resize(n - 1); 
    int numb = n; 
    for (int i = 1; i < n; i++) {
      cout << 1 << ' ';
      for (int j = 1; j <= n - 1; j++) {
        numb++; 
        cout << numb << ' '; 
        save[i - 1].push_back(numb); 
      }  
      cout << endl; 
    }
    for (int i = 2; i <= n; i++) {
      for (int k = 1; k <= n - 2; k++) {
        other_p[k] = (p[k] + k * (i - 1)) % (n - 1); 
      }
      other_p[0] = 0; 
      for (int j = 1; j <= n - 1; j++) {
        cout << i << ' '; 
        for (int k = 1; k <= n - 1; k++) {
          cout << save[k - 1][other_p[k - 1]] << ' '; 
        }
        cout << endl; 
        for (int k = 1; k <= n - 1; k++) {
          other_p[k - 1]++; 
          other_p[k - 1] %= n - 1; 
        }
      }
    } 
  }
  return 0; 
}