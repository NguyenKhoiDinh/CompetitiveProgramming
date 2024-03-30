#include <iostream>

using namespace std;
const int MAX_N = 105;                                   
int numTest;
int n, x, y;
int a[MAX_N][MAX_N];

void processEven(int n) {
  a[1][1] = 1;
  int number = 1;
  for (int x = 2; x <= n; x++) {
    number++;
    a[x][1] = number;
  }
  for (int x = n; x >= 1; x--) {
    if (x % 2 == 0) {
      for (int y = 2; y <= n; y++) {
        number++;
        a[x][y] = number;
      }
    }
    else {
      for (int y = n; y >= 2; y--) {
        number++;
        a[x][y] = number;
      }
    }
  }
  int delta = a[x][y] - 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] -= delta;
      if (a[i][j] <= 0) {
        a[i][j] += n * n;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
}

void processOdd(int n) {
  a[x][y] = 1;
  int number = 1;
  if (y == 1 || y == n) {
    for (int i = x + 1; i <= n; i++) {
      number++;
      a[i][y] = number;
    }
    if (y == 1) {
      for (int i = n; i >= 1; i--) {
        if (i % 2 == 1) {
          for (int j = (i >= x ? 2 : 1); j <= n; j++) {
            number++;
            a[i][j] = number;
          }
        }
        else {
          for (int j = n; j >= (i >= x ? 2 : 1); j--) {
            number++;
            a[i][j] = number;
          }
        }
      }
    }
    else {
      for (int i = n; i >= 1; i--) {
        if (i % 2 == 1) {
          for (int j = (i >= x ? y - 1 : y); j >= 1; j--) {
            number++;
            a[i][j] = number;
          }
        }
        else {
          for (int j = 1; j <= (i >= x ? y - 1 : y); j++) {
            number++;
            a[i][j] = number;
          }
        }
      }
    }
  }
  else if (x == 1 || x == n) {
    for (int j = y + 1; j <= n; j++) {
      number++;
      a[x][j] = number;
    }
    if (x == 1) {
      for (int j = n; j >= 1; j--) {
        if (j % 2 == 1) {
          for (int i = (j >= y ? 2 : 1); i <= n; i++) {
            number++;
            a[i][j] = number;
          }
        }
        else {
          for (int i = n; i >= (j >= y ? 2 : 1); i--) {
            number++;
            a[i][j] = number;
          }
        }
      }
    }
    else {
      for (int j = n; j >= 1; j--) {
        if (j % 2 == 1) {
          for (int i = (j >= y ? x - 1 : x); i >= 1; i--) {
            number++;
            a[i][j] = number;
          }
        }
        else {
          for (int i = 1; i <= (j >= y ? x - 1 : x); i++) {
            number++;
            a[i][j] = number;
          }
        }
      }
    }
  }
  else if (y % 2 == 1) {
    for (int i = x - 1; i >= 1; i--) {
      number++;
      a[i][y] = number;
    }
    for (int i = 1; i <= x; i++) {
      if (i % 2 == 1) {
        for (int j = y - 1; j >= 1; j--) {
          number++;
          a[i][j] = number;
        }
      }
      else {
        for (int j = 1; j <= y - 1; j++) {
          number++;
          a[i][j] = number;
        }
      }
    }
    for (int j = 1; j <= y; j++) {
      if (j % 2 == 1) {
        for (int i = x + 1; i <= n; i++) {
          number++;
          a[i][j] = number;
        }
      }
      else {
        for (int i = n; i >= x + 1; i--) {
          number++;
          a[i][j] = number;
        }
      }
    }
    for (int i = n; i >= 1; i--) {
      if (i % 2 == 1) {
        for (int j = y + 1; j <= n; j++) {
          number++;
          a[i][j] = number;
        }
      }
      else {
        for (int j = n; j >= y + 1; j--) {
          number++;
          a[i][j] = number;
        }
      }
    }
  }
  else {
    number = 0;
    for (int j = y; j >= 1; j--) {
      if (j % 2 == 0) {
        for (int i = x; i >= 1; i--) {
          number++;
          a[i][j] = number;
        }
      }
      else {
        for (int i = 1; i <= x; i++) {
          number++;
          a[i][j] = number;
        }
      }
    }
    for (int i = x + 1; i <= n; i++) {
      if (i % 2 == 1) {
        for (int j = 1; j <= y; j++) {
          number++;
          a[i][j] = number;
        }
      }
      else {
        for (int j = y; j >= 1; j--) {
          number++;
          a[i][j] = number;
        }
      }
    }
    for (int i = n; i >= 1; i--) {
      if (i % 2 == 1) {
        for (int j = y + 1; j <= n; j++) {
          number++;
          a[i][j] = number;
        }
      }
      else {
        for (int j = n; j >= y + 1; j--) {
          number++;
          a[i][j] = number;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
}

int main () {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = 0;
      }
    }
    if (n % 2 == 1 && (x + y) % 2 == 1) {
      cout << "NO" << endl;
    }
    else {
      cout << "YES" << endl;
      if (n % 2 == 0) {
        processEven(n);
      }
      else {
        processOdd(n);
      }
    }
  }
  return 0;
}