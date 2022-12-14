#include <iostream>
#include <tuple> 
#include <math.h>
#include <algorithm>
int r, c, E, J, numTest; 

int sum(int n) {
  return n * (n + 1) / 2; 
}

std::tuple <int, int, int> constructInfo(const int &xE, const int &yE, const int &xJ, const int &yJ) {
  int positionInFirstRow;
  int positionInLastRow;
  int firstRow;
  int lastRow; 
  if (std::abs(xE - xJ) == std::abs(yE - yJ)) {
    if (xE < xJ) {
      positionInFirstRow = xJ - xE + yE - 1; 
      positionInLastRow = yE;
      return std::make_tuple(positionInFirstRow, positionInLastRow, std::abs(sum(std::max(positionInFirstRow, positionInLastRow)) - sum(std::min(positionInLastRow, positionInFirstRow) - 1)));  
    }
    else {
      positionInFirstRow = yE; 
      positionInLastRow = xE - xJ + yE - 1;
      return std::make_tuple(positionInFirstRow, positionInLastRow, std::abs(sum(std::max(positionInFirstRow, positionInLastRow)) - sum(std::min(positionInLastRow, positionInFirstRow) - 1)));
    }
  }
  int halfDist = std::abs(xJ - xE) + std::abs(yJ - yE);
  halfDist--;
  halfDist /= 2;
  firstRow = std::min(xE, xJ);
  positionInFirstRow = halfDist - std::abs(firstRow - xE) + yE;
  lastRow = std::max(xE, xJ); 
  positionInLastRow = halfDist - std::abs(lastRow - xE) + yE; 
  return std::make_tuple(positionInFirstRow, positionInLastRow, std::abs(sum(std::max(positionInFirstRow, positionInLastRow)) - sum(std::min(positionInLastRow, positionInFirstRow) - 1))); 
}

bool solve1(const int &r, const int &c, const int &type, const int &numbAdd) {
  for (int i = 1; i <= r; i++) {
    for (int row = 1; i + row - 1 <= r; row++) {
      for (int col = row + 1; col <= c; col++) {
        if (numbAdd > 0 && (row + col) % 2 != 0) {
          continue;
        }
        if (numbAdd == 0 && (row + col) % 2 == 0) {
          continue; 
        }
        int xE = i;
        int yE = 1;
        int xJ = i + row - 1;
        int yJ = col;
        std::tuple <int, int, int> value = constructInfo(xE, yE, xJ, yJ); 
        int positionInFirstRow = std::get <0> (value);                    
        int positionInLastRow = std::get <1> (value);    
        int numbCellsBelongToElon = std::get <2> (value);
        numbCellsBelongToElon += positionInFirstRow * (std::min(xE, xJ) - 1); 
        numbCellsBelongToElon += positionInLastRow * (r - std::max(xE, xJ));
        int numbCellsBelongToJeff = r * c - numbAdd - numbCellsBelongToElon;   
        if ((E >= numbCellsBelongToElon) && (E - numbCellsBelongToElon) % r == 0 && (numbCellsBelongToJeff - J) % r == 0 && (E - numbCellsBelongToElon) / r == (numbCellsBelongToJeff - J) / r) {
          int ansXE = xE;
          int ansYE = yE;
          ansYE += (E - numbCellsBelongToElon) / r;
          int ansXJ = xJ; 
          int ansYJ = yJ; 
          ansYJ += (E - numbCellsBelongToElon) / r;
          if (type == 1) {                 
            if (ansYE <= c && ansYJ <= c) {
              std::swap(ansXE, ansYE);
              std::swap(ansXJ, ansYJ);
              std::cout << ansXE << ' ' << ansYE << ' ' << ansXJ << ' ' << ansYJ << std::endl; 
              return true;
            }  
          }
          if (ansYE <= c && ansYJ <= c) {
            std::cout << ansXE << ' ' << ansYE << ' ' << ansXJ << ' ' << ansYJ << std::endl; 
            return true;
          } 
        }
        xE = i + row - 1;
        yE = 1; 
        xJ = i;
        yJ = col; 
        value = constructInfo(xE, yE, xJ, yJ); 
        positionInFirstRow = std::get <0> (value);                    
        positionInLastRow = std::get <1> (value);    
        numbCellsBelongToElon = std::get <2> (value);    
        numbCellsBelongToElon += positionInFirstRow * (std::min(xE, xJ) - 1); 
        numbCellsBelongToElon += positionInLastRow * (r - std::max(xE, xJ));
        numbCellsBelongToJeff = r * c - numbAdd - numbCellsBelongToElon;
        if ((E >= numbCellsBelongToElon) && (E - numbCellsBelongToElon) % r == 0 && (numbCellsBelongToJeff - J) % r == 0 && (E - numbCellsBelongToElon) / r == (numbCellsBelongToJeff - J) / r) {
          int ansXE = xE;
          int ansYE = yE;
          ansYE += (E - numbCellsBelongToElon) / r;
          int ansXJ = xJ; 
          int ansYJ = yJ; 
          ansYJ += (E - numbCellsBelongToElon) / r;  
          if (type == 1) {
            if (ansYE <= c && ansYJ <= c) {
              std::swap(ansXE, ansYE);
              std::swap(ansXJ, ansYJ);
              std::cout << ansXE << ' ' << ansYE << ' ' << ansXJ << ' ' << ansYJ << std::endl; 
              return true;
            }   
          }
          if (ansYE <= c && ansYJ <= c) {
            std::cout << ansXE << ' ' << ansYE << ' ' << ansXJ << ' ' << ansYJ << std::endl; 
            return true;
          } 
        } 
      }
    }
  }  
  return false; 
}

bool solve2(const int &r, const int &c, const int &type, const int &numbAdd) {
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      for (int len = 1; i + len <= r && j + len <= c; len++) {
        int xE = i;
        int yE = j;
        int xJ = i + len;
        int yJ = j + len;
        std::tuple <int, int, int> value = constructInfo(xE, yE, xJ, yJ); 
        int positionInFirstRow = std::get <0> (value);                    
        int positionInLastRow = std::get <1> (value);           
        int numbCellsBelongToElon = std::get <2> (value);
        int numbEmpties = len - 1; 
        numbCellsBelongToElon += (xE - 1) * positionInFirstRow;
        numbEmpties += xE * (c - positionInFirstRow);
        numbEmpties += positionInLastRow * (r - xJ + 1);
        if (type == 1) {
          std::swap(xE, yE);
          std::swap(xJ, yJ);   
        }
        if (E == numbCellsBelongToElon && numbEmpties == numbAdd) {
          std::cout << xE << ' ' << yE << ' ' << xJ << ' ' << yJ << std::endl;
          return true; 
        }
        xE = i + len;
        yE = j; 
        xJ = i; 
        yJ = j + len; 
        value = constructInfo(xE, yE, xJ, yJ); 
        positionInFirstRow = std::get <0> (value);                    
        positionInLastRow = std::get <1> (value);    
        numbCellsBelongToElon = std::get <2> (value);
        numbEmpties = len - 1; 
        numbCellsBelongToElon += (r - xE) * positionInLastRow;
        numbEmpties += positionInFirstRow * xJ;
        numbEmpties += (r - xE + 1) * (c - positionInLastRow);     
        if (type == 1) {
          std::swap(xE, yE);
          std::swap(xJ, yJ);    
        }
        if (E == numbCellsBelongToElon && numbEmpties == numbAdd) {
          std::cout << xE << ' ' << yE << ' ' << xJ << ' ' << yJ << std::endl;
          return true; 
        }
      }     
    }
  }
  return false;
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> r >> c >> E >> J; 
    bool answer = solve2(r, c, 0, r * c - E - J); 
    if (answer == true) {
      continue; 
    }
    answer = solve2(c, r, 1, r * c - E - J);
    if (answer == true) {
      continue; 
    } 
    if (E + J == r * c) {
      answer = solve1(r, c, 0, 0); 
      if (answer == true) {
        continue; 
      }
      answer = solve1(c, r, 1, 0); 
      if (answer == true) {
        continue; 
      }
    }
    else {
      if (E + J + r == r * c) {
        answer = solve1(r, c, 0, r); 
        if (answer == true) {
          continue;   
        }
      }
      if (E + J + c == r * c) {
        answer = solve1(c, r, 1, c);
        if (answer == true) {
          continue; 
        } 
      }
    }
    std::cout << "-1 -1 -1 -1" << std::endl;
  }
  return 0; 
}