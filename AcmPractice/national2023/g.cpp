#include <iostream>
#include <string>
#include <math.h>
#include <vector>
int numTest;
int n, k, p; 
std::vector <std::string> a;
std::vector <int> row, col;
bool change(std::vector <std::string> &a, int addx, int addy, int addRook) {
  std::vector <int> emptyRow, emptyCol;
  for (int i = 0; i < n; i++) {
    if (row[i] == 0) {
      emptyRow.push_back(i);
    }
    if (col[i] == 0) {
      emptyCol.push_back(i); 
    }
  }
  if (addx > (int) emptyRow.size() || addy > (int) emptyCol.size()) {
    return false; 
  }
  while (addx > 0 && addy > 0) {
    a[emptyRow.back()][emptyCol.back()] = 'R';
    row[emptyRow.back()]++;
    col[emptyCol.back()]++; 
    addRook--; 
    emptyRow.pop_back();
    emptyCol.pop_back();
    addx--;
    addy--; 
  }
  int nonEmptyRow = -1; 
  int nonEmptyCol = -1; 
  for (int i = 0; i < n; i++) {
    if (row[i] > 0) {
      nonEmptyRow = i;
    }
    if (col[i] > 0) {
      nonEmptyCol = i;
    }
  }
  while (addx > 0) {
    a[emptyRow.back()][nonEmptyCol] = 'R';
    row[emptyRow.back()]++;  
    col[nonEmptyCol]++; 
    addRook--; 
    emptyRow.pop_back();
    addx--;
  }
  while (addy > 0) {
    a[nonEmptyRow][emptyCol.back()] = 'R';
    col[emptyCol.back()]++; 
    row[nonEmptyRow]++; 
    addRook--;  
    emptyCol.pop_back();
    addy--;
  }
  for (int i = 0; i < n; i++) {
    if (addRook == 0) {
      break;
    }
    if (row[i] > 0) {
      for (int j = 0; j < n; j++) {
        if (addRook == 0) {
          break;
        }
        if (col[j] > 0 && addRook > 0 && a[i][j] == '.') {
          a[i][j] = 'R';
          addRook--; 
        }
      }
    }
  }
  return true;   
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  while (true) {
    std::cin >> n >> k >> p;
    if (n == 0 && k == 0 && p == 0) {
      break;
    }
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i]; 
    }
    row.clear();
    col.clear(); 
    row.resize(n, 0); 
    col.resize(n, 0);
    int placed = 0;  
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == 'R') {
          row[i]++; 
          col[j]++;
          placed++;  
        }
      }
    }
    int x0 = 0;
    int y0 = 0;
    for (int i = 0; i < n; i++) {
      if (row[i] > 0) {
        x0++; 
      }
      if (col[i] > 0) {
        y0++; 
      }
    }
    bool ok = false; 
    for (int x = x0; x <= n; x++) {
      int y = 2 * (placed + k) - p - x; 
      if (y < y0 || y > n) {
        continue; 
      }
      if (x == 0 && y != 0) {
        continue; 
      }
      if (x != 0 && y == 0) {
        continue; 
      }
      if (placed + k > x * y) {
        continue;   
      }
      if (k < std::max(x - x0, y - y0)) {
        continue; 
      }
      ok = change(a, x - x0, y - y0, k); 
      if (ok == true) {
        break;
      } 
    } 
    if (ok == true) {
      std::cout << "YES" << std::endl; 
      for (int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl; 
      }
    }
    else {
      std::cout << "NO" << std::endl;
    }
  }
  return 0;               
}
