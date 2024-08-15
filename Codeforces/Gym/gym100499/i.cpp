#include <iostream>
#include <string> 
#include <algorithm>
#include <math.h> 
int numTest; 
std::string frac; 
long long power10[16]; 

int main () {
  power10[0] = 1LL;
  for (int i = 1; i <= 15; i++) {
    power10[i] = power10[i - 1] * 10LL; 
  }
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::cin >> frac; 
    long long a = 0;
    int posDot = -1; 
    for (int i = 0; i < (int) frac.size(); i++) {
      if (frac[i] == '.') {
        posDot = i; 
        break; 
      }
      else {
        a = a * 10LL + frac[i] - '0'; 
      }
    }
    long long deno = -1, nume = -1;
    if (posDot == -1) {
      std::cout << a << '/' << 1 << std::endl; 
    }   
    else {
      long long b = 0; 
      int posBrack = -1; 
      for (int i = posDot + 1; i < (int) frac.size(); i++) {
        if (frac[i] == '(') {
          posBrack = i; 
          break; 
        }
        else {
          b = b * 10LL + frac[i] - '0'; 
        }
      }
      if (posBrack == -1) {
        deno = b;
        nume = power10[(int) frac.size() - posDot - 1];
        long long gcd = std::__gcd(deno, nume);
        deno /= gcd;
        nume /= gcd;
        deno += a * nume;
        std::cout << deno << '/' << nume << std::endl;   
      }
      else {
        long long tmpDeno = b; 
        long long tmpNume = power10[posBrack - posDot - 1];
        long long gcd = std::__gcd(tmpDeno, tmpNume);
        tmpDeno /= gcd;
        tmpNume /= gcd;
        long long x = 0LL; 
        for (int i = posBrack + 1; i < (int) frac.size() - 1; i++) {
          x = x * 10LL + frac[i] - '0'; 
        } 
        long long y = power10[(int) frac.size() - 2 - posBrack];  
        y--; 
        y *= power10[posBrack - posDot - 1];
        gcd = std::__gcd(x, y);
        x /= gcd;
        y /= gcd;
        x = x * tmpNume + tmpDeno * y;
        y *= tmpNume;
        gcd = std::__gcd(x, y);
        x /= gcd;
        y /= gcd;
        x += a * y;
        std::cout << x << "/" << y << std::endl;   
      }
    }
  }

  return 0; 
}