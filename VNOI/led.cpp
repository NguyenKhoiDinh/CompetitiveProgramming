#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
/// Tiền xử lí các vạch led bật
vector<int> cntled = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void solve1()
{
    /// Biểu diễn số dưới dạng xâu
    string s;
    cin >> s;

    /// Kết quả là tổng số lượng vạch led bật
    int res = 0;
    for (char c : s)
        res += cntled[c - '0'];

    cout << res;
}

/// Tiền xử lí
/// vector thứ n biểu diễn tất cả các đèn led mà các vạch led có trong n được bật
vector<vector<int> > G = {
    {0, 8},                 /// [0]
    {0, 1, 3, 4, 7, 8, 9},  /// [1]
    {2, 8},                 /// [2]
    {3, 8, 9},              /// [3]
    {4, 8, 9},              /// [4]
    {5, 6, 8, 9},           /// [5]
    {6, 8},                 /// [6]
    {0, 3, 7, 8, 9},        /// [7]
    {8},                    /// [8]
    {8, 9},                 /// [9]
};

int n;                  /// Độ dài của số nhận vào
vector<int> v;          /// vector chứa các chữ số
vector<vector<ll> > f;  /// vector 2 chiều quy hoạch động
/// hàm magic(i, ign)
/// tại vị trí (i) của số biểu diễn bởi vector (v)
/// đếm số cách mà xây dựng được số có (ign) = true
ll magic(int i = 0, bool ign = false) /// O(n * 2 * 7)
{
    /// Nếu đã duyệt hết vector
    if (i >= n) return ign;

    /// Dùng con trỏ để tiện tính toán
    ll &res = f[i][ign];
    if (res != -1) return res; /// Nếu đã được tính trước đó
    else res = 0;              /// Ngược lại thì reset giá trị

    /// Chúng ta chỉ đếm các số lớn hơn
    int lim = ign ? 0 : v[i];
    for (int d : G[v[i]])
        if (d >= lim)
            res += magic(i + 1, ign || (d > lim));

    /// Đừng quên trả về kết quả :D
    return res;
}

void solve2()
{
    /// Biểu diễn số dưới dạng xâu
    string s;
    cin >> s;

    /// Dùng vector (v) độ dài (n) để lưu trữ các chữ số
    n = s.size();
    for (char c : s) v.pb(c - '0');

    /// Khởi tạo -1 tức là chưa được tính trước đó
    f.assign(n + 1, vector<ll>(2, -1));
    cout << magic();
}

int main () {
  int type;
  cin >> type; 
  string s; 
  for (int i = 0; i < (int) s.size(); i++) {
    v.push_back(s[i]);
  }
  n = (int) s.size();
  if (type == 1) {
    solve1(); 
  } 
  else {
    solve2();
  }
  return 0; 
}
