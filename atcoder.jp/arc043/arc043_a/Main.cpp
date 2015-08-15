#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#include <iomanip>
ll S[100100];
int main()
{
	int N;
	ll A,B;
	cin >> N >> A >> B;
	for(int i=0;i<N;i++)cin >> S[i];
	sort(S,S+N);
	ll sum = 0ll;
	for(int i=0;i<N;i++)sum+=S[i];
	double P,Q;
	if(S[0]==S[N-1])
	{
		if(B!=0)
		{
			cout << -1 << endl;
			return 0;
		}
		cout << setprecision(16) << (double)A/(double)sum << ' ' << 0 << endl;
	}
	P = (double)B/(S[N-1]-S[0]);
	Q = (double)A-(double)P*(double)sum/(double)N;
	cout  << setprecision(16) << P << ' ' << Q << endl;
	return 0;
}
