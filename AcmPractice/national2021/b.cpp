#include <bits/stdc++.h> 

using namespace std;
char a[55][55]; 
int R, C; 
int ans = 0; 

int distance(char c1, char c2) {
  int ret = abs(c1 - c2);
  ret = min(ret, 26 - ret);  
  return ret; 
}

int calc(const vector <char> &save, char newchar) {
  int ret = 0;                 
  for (int i = 0; i < (int) save.size(); i++) {
    ret += distance(save[i], newchar); 
  }
  return ret; 
}

char change(vector <char> &save) {
  int maxi = 1005; 
  char ret; 
  for (int i = 0; i < (int) save.size(); i++) {
    if (maxi > calc(save, save[i])) {
      maxi = calc(save, save[i]); 
      ret = save[i]; 
    }
  }
  ans += maxi; 
  return ret; 
}

int main () {
  cin >> R >> C; 
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> a[i][j]; 
    }
  }
  int headRow = 0, tailRow = R - 1; 
  int headCol = 0, tailCol = C - 1;  
  while (headRow <= tailRow) {
    headCol = 0;
    tailCol = C - 1; 
    while (headCol <= tailCol) {
      vector <char> save;
      save.push_back(a[headRow][headCol]); 
      if (tailCol > headCol) {
        save.push_back(a[headRow][tailCol]); 
      }
      if (tailRow > headRow) {
        save.push_back(a[tailRow][headCol]); 
        if (tailCol > headCol) {
          save.push_back(a[tailRow][tailCol]); 
        }
      }
      char nextChar = change(save); 
      a[headRow][headCol] = nextChar;
      a[headRow][tailCol] = nextChar;
      a[tailRow][headCol] = nextChar;
      a[tailRow][tailCol] = nextChar;
      headCol++; 
      tailCol--; 
    }
    headRow++;
    tailRow--; 
  }
  cout << ans;
  return 0;         
}