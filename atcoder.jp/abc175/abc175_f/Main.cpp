// #pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
// #pragma GCC option("arch=native", "tune=native", "no-zero-upper")
// #pragma GCC
// target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("tree-vectorize","openmp","predictive-commoning")
// #pragma GCC option("D_GLIBCXX_PARALLEL","openmp")

// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
// #define int long long
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000               // 2e9
#define LLINF 2000000000000000000ll  // 2e18 (llmax:9e18)
#define fi first
#define sec second
#define all(x) (x).begin(), (x).end()
#define sq(x) ((x) * (x))
#define dmp(x) cerr << #x << ": " << x << endl;

template <class T>
void chmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, const T &b) {
  if (a < b) a = b;
}

template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T>
vector<T> vect(int len, T elem) {
  return vector<T>(len, elem);
}

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << p.fi << ',' << p.sec;
  return os;
}
template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &p) {
  is >> p.fi >> p.sec;
  return is;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i + 1 < vec.size()) os << ' ';
  }
  return os;
}
template <class T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) is >> vec[i];
  return is;
}
void fastio() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
}

template <typename T>
struct Edge {
  int to;
  T cost;
  Edge() {}
  Edge(int to, T cost) : to(to), cost(cost) {}
};

void solve() {
  int N;
  std::cin >> N;
  std::vector<std::string> S(N);
  std::vector<std::string> revS(N);
  std::vector<ll> C(N);
  for (int i = 0; i < N; i++) cin >> S[i] >> C[i];
  for (int i = 0; i < N; i++) {
    revS[i] = S[i];
    reverse(all(revS[i]));
  }

  auto isPalindrome = [](const std::string &s) -> bool {
    std::string t = s;
    reverse(all(t));
    return t == s;
  };

  using Node = std::pair<string, bool>;
  std::map<Node, int> NodeMap;
  std::vector<int> PalindromeNodeIdx;
  NodeMap[Node("", false)] = 0;
  NodeMap[Node("", true)] = 1;
  PalindromeNodeIdx.push_back(1);
  int Idx = 2;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= S[i].size(); j++) {
      std::string prefix = S[i].substr(0, j);
      std::string suffix = S[i].substr(j);
      Node add_right(prefix, true);
      Node add_left(suffix, false);
      if (NodeMap.find(add_right) == NodeMap.end()) {
        if (isPalindrome(add_right.first)) PalindromeNodeIdx.push_back(Idx);
        NodeMap[add_right] = Idx++;
      }
      if (NodeMap.find(add_left) == NodeMap.end()) {
        if (isPalindrome(add_left.first)) PalindromeNodeIdx.push_back(Idx);
        NodeMap[add_left] = Idx++;
      }
    }
  }

  using edge = Edge<ll>;
  std::vector<std::vector<edge>> G(Idx);
  auto addEdge = [&](int from, int to, ll cost) {
    G[from].emplace_back(to, cost);
  };

  // construct graph
  for (auto NodeIdxPair : NodeMap) {
    // dmp(NodeIdxPair);
    Node V = NodeIdxPair.first;
    int NodeId = NodeIdxPair.second;
    std::string &VS = V.first;
    int VSlen = VS.size();
    if (V.second == false) {
      // [...VS...]  |
      //             |   [...S...]
      for (int i = 0; i < N; i++) {
        int Slen = S[i].size();
        int min_len = std::min(VSlen, Slen);
        if (VS.substr(0, min_len) != revS[i].substr(0, min_len)) continue;
        if (VSlen < Slen) {
          Node To(S[i].substr(0, Slen - VSlen), true);
          addEdge(NodeId, NodeMap[To], C[i]);
          if (To.first.size() == 0) {
            To.second ^= true;
            addEdge(NodeId, NodeMap[To], C[i]);
          }
        } else {
          Node To(VS.substr(Slen), false);
          addEdge(NodeId, NodeMap[To], C[i]);
          if (To.first.size() == 0) {
            To.second ^= true;
            addEdge(NodeId, NodeMap[To], C[i]);
          }
        }
      }
    } else {
      //                  [...VS...]
      // [...S...]
      for (int i = 0; i < N; i++) {
        int Slen = S[i].size();
        int min_len = std::min(VSlen, Slen);
        if (VS.substr(VSlen - min_len) != revS[i].substr(Slen - min_len))
          continue;
        if (VSlen < Slen) {
          Node To(S[i].substr(VSlen), false);
          addEdge(NodeId, NodeMap[To], C[i]);
          if (To.first.size() == 0) {
            To.second ^= true;
            addEdge(NodeId, NodeMap[To], C[i]);
          }
        } else {
          Node To(VS.substr(0, VSlen - Slen), true);
          addEdge(NodeId, NodeMap[To], C[i]);
          if (To.first.size() == 0) {
            To.second ^= true;
            addEdge(NodeId, NodeMap[To], C[i]);
          }
        }
      }
    }
  }

  vector<ll> Dist(G.size());
  auto dijkstra = [&](int s) {
    for (int i = 0; i < Dist.size(); i++) Dist[i] = LLINF;
    using D = pair<ll, int>;
    priority_queue<D, vector<D>, greater<D>> q;
    Dist[s] = 0ll;
    q.push(D(0ll, s));
    while (!q.empty()) {
      D a = q.top();
      q.pop();
      int v = a.second;
      if (Dist[v] < a.first) continue;
      for (const edge &e : G[v]) {
        if (Dist[e.to] > Dist[v] + e.cost) {
          Dist[e.to] = Dist[v] + e.cost;
          q.push(D(Dist[e.to], e.to));
        }
      }
    }
  };
  dijkstra(0);

  ll ans = LLINF;
  for (int Idx : PalindromeNodeIdx) { chmin(ans, Dist[Idx]); }

  std::cout << ((ans == LLINF) ? -1 : ans) << std::endl;

  return;
}

signed main() {
  fastio();
  solve();
  // int t; cin >> t; while(t--)solve();

  // int t; cin >> t;
  // for(int i=1;i<=t;i++){
  //   cout << "Case #" << i << ": ";
  //   solve();
  // }
  return 0;
}
