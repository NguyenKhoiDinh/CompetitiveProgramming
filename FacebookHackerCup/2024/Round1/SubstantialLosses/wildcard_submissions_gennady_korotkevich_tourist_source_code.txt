/**
 *    author:  tourist
 *    created: 05.10.2024 10:32:27
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  friend const Type& abs(const Modular& x) { return x.value; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

// using ModType = int;

// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);

// Mint C(int n, int k) {
//   if (k < 0 || k > n) {
//     return 0;
//   }
//   while ((int) fact.size() < n + 1) {
//     fact.push_back(fact.back() * (int) fact.size());
//     inv_fact.push_back(1 / fact.back());
//   }
//   return fact[n] * inv_fact[k] * inv_fact[n - k];
// }

class Solution {
 public:
  int n;
  vector<string> s;

  void readData() {
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
  }

  void solve(stringstream& out) {
    vector<int> len(n);
    for (int i = 0; i < n; i++) {
      len[i] = int(s[i].size());
    }
    vector<vector<int>> good(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = 0; k < min(len[i], len[j]); k++) {
          if (s[i][k] != '?' && s[j][k] != '?' && s[i][k] != s[j][k]) {
            break;
          }
          good[i][j] += 1;
        }
      }
    }
    const int N = 102;
    const __int128 one = 1;
    vector<__int128> mask(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < len[i]; j++) {
        if (s[i][j] == '?') {
          mask[i] |= one << j;
        }
      }
    }
    vector<Mint> pw(N);
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
      pw[i] = pw[i - 1] * 26;
    }
    vector<int> coeff(N);
    Mint ans = 1;
    auto Dfs = [&](auto&& self, int v, int taken, int mt, int lim, __int128 w) -> void {
      if (v == n) {
        if (taken > 0) {
          int sign = ((taken & 1) ? +1 : -1);
          int cc = 0;
          for (int i = 0; i < lim; i++) {
            cc += ((w >> i) & 1);
            coeff[cc] += sign;
          }
        }
        return;
      }
      self(self, v + 1, taken, mt, lim, w);
      lim = min(lim, len[v]);
      for (int i = 0; i < v; i++) {
        if (mt & (1 << i)) {
          lim = min(lim, good[i][v]);
        }
      }
      self(self, v + 1, taken + 1, mt | (1 << v), lim, w & mask[v]);
    };
    Dfs(Dfs, 0, 0, 0, N, -1);
    for (int i = 0; i < N; i++) {
      ans += coeff[i] * pw[i];
    }
    out << ans() << '\n';
  }
};

const int maxThreads = 8;
const int numTests = 1000;

stringstream out[numTests];
mutex mu;
int cur, tt;
thread threads[maxThreads];

void solutionRunner() {
  while (true) {
    Solution s;
    int id;
    mu.lock();
    if (cur >= tt) {
      mu.unlock();
      return;
    }
    id = cur;
    cur++;
    s.readData();
    mu.unlock();
    s.solve(out[id]);
    cerr << "solved " << id << endl;
  }
}

using namespace std::chrono;

int64_t now() {
  milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
  return ms.count();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  auto start = now();
  cin >> tt;
  cur = 0;
  for (int i = 0; i < maxThreads; i++) {
    threads[i] = thread(solutionRunner);
  }
  for (int i = 0; i < maxThreads; i++) {
    threads[i].join();
  }
  for (int i = 0; i < tt; i++) {
    cout << "Case #" << i + 1 << ": ";
    cout << out[i].str();
  }
  cerr << "time = " << now() - start << " ms" << endl;
  return 0;
}
