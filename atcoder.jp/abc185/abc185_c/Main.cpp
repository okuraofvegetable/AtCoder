#include <bits/stdc++.h>

using namespace std;

template <class T>
T nCr_naive(T n, int r) {
  T ret(1);
  for (int i = 0; i < r; i++) {
    ret *= n;
    ret /= T(i + 1);
    n -= T(1);
  }
  return ret;
}

int main() {
  long long n;
  cin >> n;
  cout << nCr_naive(n - 1, 11) << endl;
  return 0;
}
