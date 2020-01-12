#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using ld = long double;
using P = std::complex<ld>;
using G = std::vector<P>;
const ld pi = std::acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

ld cross(const P &a, const P &b) { return a.real() * b.imag() - a.imag() * b.real(); }
ld dot(const P &a, const P &b) { return a.real() * b.real() + a.imag() * b.imag(); } /*
                    CCW

 -- BEHIND -- [a -- ON -- b] --- FRONT --

                    CW
 */
enum CCW_RESULT { CCW = +1, CW = -1, BEHIND = +2, FRONT = -2, ON = 0 };
int ccw(P a, P b, P c) {
    b -= a;
    c -= a;
    if (cross(b, c) > eps) return CCW;    // counter clockwise
    if (cross(b, c) < -eps) return CW;    // clockwise
    if (dot(b, c) < 0) return BEHIND;     // c--a--b on line
    if (norm(b) < norm(c)) return FRONT;  // a--b--c on line
    return ON;
}

namespace std {
bool operator<(const P &a, const P &b) {
    return std::abs(real(a) - real(b)) > eps ? real(a) < real(b) : imag(a) < imag(b);
}
}

struct L : public std::vector<P> {
    L(const P &a = P(), const P &b = P()) : std::vector<P>(2) {
        begin()[0] = a;
        begin()[1] = b;
    }

    // Ax + By + C = 0
    L(ld A, ld B, ld C) {
        if (std::abs(A) < eps && std::abs(B) < eps) {
            abort();
        } else if (std::abs(A) < eps) {
            *this = L(P(0, -C / B), P(1, -C / B));
        } else if (std::abs(B) < eps) {
            *this = L(P(-C / A, 0), P(-C / A, 1));
        } else {
            *this = L(P(0, -C / B), P(-C / A, 0));
        }
    }
};

struct C {
    P p;
    ld r;
    C(const P &p = 0, ld r = 0) : p(p), r(r) {}
};
template <class iter>
std::pair<P, ld> min_ball(iter left, iter right, int seed = 1333) {
    const int n = right - left;

    assert(n >= 1);
    if (n == 1) {
        return {*left, ld(0)};
    }

    std::mt19937 mt(seed);
    std::shuffle(left, right, mt);
    // std::random_shuffle(left, right); // simple but deprecated

    iter ps = left;
    using circle = std::pair<P, ld>;

    auto make_circle_3 = [](const P &a, const P &b, const P &c) -> circle {
        ld A = std::norm(b - c), B = std::norm(c - a), C = std::norm(a - b),
           S = cross(b - a, c - a);
        P p = (A * (B + C - A) * a + B * (C + A - B) * b + C * (A + B - C) * c) / (4 * S * S);
        ld r2 = std::norm(p - a);
        return {p, r2};
    };

    auto make_circle_2 = [](const P &a, const P &b) -> circle {
        P c = (a + b) / (ld)2;
        ld r2 = std::norm(a - c);
        return {c, r2};
    };

    auto in_circle = [](const P &a, const circle &c) -> bool {
        return std::norm(a - c.first) <= c.second + eps;
    };

    circle c = make_circle_2(ps[0], ps[1]);

    // MiniDisc
    for (int i = 2; i < n; ++i) {
        if (!in_circle(ps[i], c)) {
            // MiniDiscWithPoint
            c = make_circle_2(ps[0], ps[i]);
            for (int j = 1; j < i; ++j) {
                if (!in_circle(ps[j], c)) {
                    // MiniDiscWith2Points
                    c = make_circle_2(ps[i], ps[j]);
                    for (int k = 0; k < j; ++k) {
                        if (!in_circle(ps[k], c)) {
                            c = make_circle_3(ps[i], ps[j], ps[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}

int main(){
	int n;
  cin >> n;
  vector<P> ps(n);
  for(int i=0;i<n;i++){
    ld x,y;
    cin >> x >> y;
    ps[i].real(x);
    ps[i].imag(y);
  }
  auto ret = min_ball(ps.begin(),ps.end());
  cout << fixed << setprecision(20) <<  sqrt(ret.second) << endl;
	return 0;
}
