#include <bits/stdc++.h> 

using namespace std;

long long fw[1000005];

void update(int index, long long value) {
  for (; index > 0; index -= index & -index) {
    fw[index] += value;
  }  
} 

long long get(int index) {
  long long ret = 0LL;
  for (; index < 1000005; index += index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

class MedianSegments {
  public:
  long long count(int N, int K, vector <int> Aprefix, int M) {
    vector <int> a; 
    for (int i = 0; i < (int) Aprefix.size(); i++) {
      a.push_back(Aprefix[i]); 
    }
    long long state = a.back();
    for (int i = (int) Aprefix.size(); i <= N; i++) {
      state = (state * 1103515245LL + 12345LL) % (1LL << (long long) 31); 
      a.push_back(state % M); 
    }
    int smaller = 0;
    int value = a[K];
    update(N, 1); 
    long long ans = 0LL;  
    for (int i = 1; i <= N; i++) {
      if (a[i] <= value) {
        smaller++;
        if (i >= K + 1) {
          ans += get(2 * smaller - i + N); 
        }
        if (i < K) {
          update(2 * smaller - i + N, 1LL); 
        }  
      }
    }
    return ans; 
  }
};

MedianSegments M; 
int main () {
  cout << M.count(10     ,
3                         ,
{30, 40, 50, 60, 70, 80, 90, 100, 110, 120}  ,
12345                                         );
  return 0; 
}