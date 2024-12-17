#include <bits/stdc++.h> 

using namespace std; 
string a[6]; 
bool checkCol(int x, int y, char c) {
  if (a[x][y] == c && a[x - 1][y] == c && a[x - 2][y] == c && a[x - 3][y] == c) {
    return true;
  }
  return false; 
}
bool checkRow(int x, int y, char c) {
  if (a[x][y] == c && a[x][y + 1] == c && a[x][y + 2] == c && a[x][y + 3] == c) {
    return true; 
  }
  return false; 
}
bool checkDia1(int x, int y, char c) {
  if (a[x][y] == c && a[x + 1][y + 1] == c && a[x + 2][y + 2] == c && a[x + 3][y + 3] == c) {
    return true; 
  }
  return false; 
}
bool checkDia2(int x, int y, char c) {
  if (a[x][y] == c && a[x + 1][y - 1] == c && a[x + 2][y - 2] == c && a[x + 3][y - 3] == c) {
    return true;
  }
  return false; 
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    for (int i = 0; i < 6; i++) {
      cin >> a[i]; 
    }
    const int r = 6, c = 7;
    bool isValidC = false, isValidF = false; 
    for (int j = 0; j < 7; j++) {
      for (int i = r - 1; i >= 3; i--) {
        if (checkCol(i, j, 'C') == true) {
          isValidC = true; 
        }  
        if (checkCol(i, j, 'F') == true) {
          isValidF = true; 
        }
      }
    }
    for (int i = r - 1; i >= 0; i--) {
      for (int j = 0; j < 4; j++) {
        if (checkRow(i, j, 'C') == true) {
          bool ok = false; 
          for (int x = i + 1; x < r; x++) {
            if (checkRow(x, j, 'F') == true) {
              ok = true; 
            }
          }
          if (ok == false) {
            isValidC = true; 
          }
        }
        if (checkRow(i, j, 'F') == true) {
          bool ok = false; 
          for (int x = i + 1; x < r; x++) {
            if (checkRow(x, j, 'C') == true) {
              ok = true;
            }
          }
          if (ok == false) {
            isValidF = true; 
          }
        }
      }
    }
    for (int i = 2; i >= 0; i--) {
      for (int j = 3; j >= 0; j--) {
        if (checkDia1(i, j, 'C') == true) {
          for (int x = i + 4; x < r; x++) {
            bool ok = false; 
            if (checkRow(x, j, 'F') == true) {
              ok = true;   
            }
            if (ok == false) {
              isValidC = true; 
            }
          }  
        }
        if (checkDia1(i, j, 'F') == true) {
          for (int x = i + 4; x < r; x++) {
            bool ok = false; 
            if (checkRow(x, j, 'C') == true) {
              ok = true;   
            }
            if (ok == false) {
              isValidF = true; 
            }
          }  
        }
      }
    }
    for (int i = 2; i >= 0; i--) {
      for (int j = 3; j < 7; j++) {
        if (checkDia2(i, j, 'C') == true) {
          for (int x = i + 4; x < r; x++) {
            bool ok = false; 
            if (checkRow(x, j, 'F') == true) {
              ok = true;   
            }
            if (ok == false) {
              isValidC = true; 
            }
          }  
        }
        if (checkDia2(i, j, 'F') == true) {
          for (int x = i + 4; x < r; x++) {
            bool ok = false; 
            if (checkRow(x, j, 'C') == true) {
              ok = true;   
            }
            if (ok == false) {
              isValidF = true; 
            }
          }  
        }
      }
    }
    if (isValidC == true && isValidF == true) {
      cout << '?';
    }
    else if (isValidC == false && isValidF == false) {
      cout << '0'; 
    }
    else if (isValidC == true) {
      cout << 'C'; 
    }
    else {
      cout << 'F';
    }
    cout << endl;
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}