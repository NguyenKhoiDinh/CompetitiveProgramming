#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <bitset>    
#include <stdio.h>
int n, S; 
struct point {
  int x, y, id; 
};
point a[100005]; 
std::vector <int> listDivisors; 
int saveID[2000005]; 
char cntX[100005][300], cntY[100005][300]; 
int divisor[2000005]; 

bool compareToX(const point &a, const point &b) {
  if (a.x < b.x || (a.x == b.x && a.y < b.y)) {
    return true;
  } 
  return false; 
}

bool compareToY(const point &a, const point &b) {
  if (a.y < b.y || (a.y == b.y && a.x < b.x)) {
    return true; 
  } 
  return false; 
}

void processY(const std::vector <int> &v) {
  for (int j = 0; j < (int) listDivisors.size(); j++) {
    int d = listDivisors[j]; 
    for (int i = 0; i < (int) v.size() - 1; i++) {
      if (v[i] + d <= 2000000 && saveID[v[i] + d] != 0) {
        int id = saveID[v[i] + d]; 
        cntY[id][divisor[d]]++; 
      }  
    }
    for (int i = (int) v.size() - 1; i >= 1; i--) {
      if (v[i] - d >= 0 && saveID[v[i] - d] != 0) {
        int id = saveID[v[i] - d]; 
        cntY[id][divisor[d]]++; 
      }
    }
  }
}

void processX(const std::vector <int> &v) {
  for (int j = 0; j < (int) listDivisors.size(); j++) {
    int d = listDivisors[j]; 
    for (int i = 0; i < (int) v.size() - 1; i++) {
      if (v[i] + d <= 2000000 && saveID[v[i] + d] != 0) {
        int id = saveID[v[i] + d]; 
        cntX[id][divisor[d]]++; 
      }  
    }
    for (int i = (int) v.size() - 1; i >= 1; i--) {
      if (v[i] - d >= 0 && saveID[v[i] - d] != 0) {
        int id = saveID[v[i] - d]; 
        cntX[id][divisor[d]]++; 
      }
    }
  }
}

int main () {
  scanf("%d %d", &n, &S);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].x, &a[i].y);                 
    a[i].x += 1000000;
    a[i].y += 1000000;
    a[i].id = i;            
  }
  for (int i = 1; i <= (int) std::sqrt(2 * S); i++) {
    if ((2 * S) % i == 0) {
      listDivisors.push_back(i); 
      if ((2 * S) / i != i) {
        if ((2 * S) / i > 2000000) {
          continue; 
        }                                
        listDivisors.push_back((2 * S) / i); 
      }
    }
  }
  int numbDivisors = (int) listDivisors.size();
  for (int i = 0; i < numbDivisors; i++) {
    divisor[listDivisors[i]] = i; 
  } 
  std::sort(a + 1, a + n + 1, compareToX);
  int start = 1;
  std::vector <int> listY; 
  for (int i = 1; i <= n; i++) {
    if (a[i].x == a[start].x) {
      listY.push_back(a[i].y);
      saveID[a[i].y] = a[i].id;  
    }
    else {
      processY(listY);
      for (int j = 0; j < (int) listY.size(); j++) {
        saveID[listY[j]] = 0; 
      }
      listY.clear();
      start = i;
      listY.push_back(a[start].y);
      saveID[a[start].y] = a[start].id;  
    }    
  }
  processY(listY);
  for (int i = 0; i < (int) listY.size(); i++) {
    saveID[listY[i]] = 0; 
  }                                        
  std::sort(a + 1, a + n + 1, compareToY);
  start = 1;
  std::vector <int> listX; 
  for (int i = 1; i <= n; i++) {
    if (a[i].y == a[start].y) {
      listX.push_back(a[i].x);
      saveID[a[i].x] = a[i].id;  
    }
    else {
      processX(listX);
      for (int j = 0; j < (int) listX.size(); j++) {
        saveID[listX[j]] = 0; 
      }
      listX.clear();
      start = i;
      listX.push_back(a[start].x);
      saveID[a[start].x] = a[start].id;  
    }    
  }
  processX(listX);
  int ans = 0; 
  for (int j = 0; j < (int) listDivisors.size(); j++) {
    int d = listDivisors[j]; 
    int rd = (2 * S) / d; 
    if (rd > 2000000) {
      continue; 
    }
    for (int i = 1; i <= n; i++) {
      ans += cntX[i][divisor[d]] * cntY[i][divisor[rd]];  
    }
  }                                          
  std::cout << ans; 
  return 0; 
}