#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
#define TASK "input"

#define ll long long

int main() {



    ios ::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
    vector<vector<long long>> f(n + 1, vector<long long>(m + 1, 0));

    int maxSum = 0;

    // Nhập mảng và tính tổng tất cả phần tử trong ma trận
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            maxSum += a[i][j];
        }
    }

    // Tính mảng tổng tích lũy f
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = a[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }

    
    long long ans = 0LL; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (f[i][j] % k == 0) {
                ans = max(ans, f[i][j]); 
            }
        }
    }

    cout << ans; 
    return 0;
}
