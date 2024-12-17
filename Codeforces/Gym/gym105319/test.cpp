#include <stdio.h>
#include <bits/stdc++.h> 
void printPascal(int n)
{
    for (int line = 1; line <= n; line++) {
        // used to represent C(line, i)
        long long coef = 1;
        std::vector <long long> save; 
        for (int i = 1; i <= line; i++) {
            // The first value in a line
            // is always 1
            coef = coef * (line - i) / i;
            if (coef != 1) {
              save.push_back(coef); 
            }
        }
        std::cout << line - 1 << ":     "; 
        long long gcd = save[0];
        for (int i = 1; i < (int) save.size(); i++) {
          gcd = std::__gcd(gcd, save[i]); 
        }
        std::cout << gcd << std::endl; 
    }
}

// Driver code
int main()
{
    freopen("output.txt", "w", stdout);
    int n = 330;
    printPascal(n);
    return 0;
}