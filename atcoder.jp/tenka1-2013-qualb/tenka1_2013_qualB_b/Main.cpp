#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
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
#define EQ(a,b) (abs((a)-(b))<EPS)
int L,N,M,Q;
string query;
stack<P> st;
int size=0;
int main()
{
	cin >> Q >> L;
	for(int i=0;i<Q;i++)
	{
		cin >> query;
		if(query=="Push")
		{
			cin >> N >> M;
			//cout << st.size() <<' '<<L-N;
			if(size>(L-N))
			{
				cout << "FULL" << endl;
				return 0;
			}
			else
			{
				st.push(mp(M,N));
				size+=N;
			}
		}
		else if(query=="Pop")
		{
			cin >> N;
			if(size<N)
			{
				cout << "EMPTY" << endl;
				return 0;
			}
			while(1)
			{
				P a=st.top();
				st.pop();
				if(a.sec>N)
				{
					a.sec-=N;
					st.push(a);
					size-=N;
					break;
				}
				else if(a.sec==N)
				{
					size-=N;
					break;
				}
				else
				{
					N-=a.sec;
					size-=a.sec;
				}
			}
		}
		else if(query=="Top")
		{
			if((int)st.size()==0)
			{
				cout << "EMPTY" << endl;
				return 0;
			}
			else
			{
				cout << st.top().fi << endl;
			}
		}
		else
		{
			cout << size << endl;
		}
	}
	//cout << st.size() << endl;
	cout << "SAFE" << endl;
	return 0;
}
