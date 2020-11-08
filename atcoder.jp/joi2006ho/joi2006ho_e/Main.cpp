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
typedef pair<P,int> T;
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
#define EQ(a,b) (abs((a)-(b))<EPS)
int a,b,c,d,n,r;
int le,ri,up,down;
int area,len;
vector<T> vec;
map<P,int> m;
map<P,int>::iterator it;
int imos[2][10004];
int main()
{
    //while(1)
    {
        memset(imos,0,sizeof(imos));
        area=0;len=0;
        le=down=INF;
        ri=up=1;
        m.clear();
        scanf("%d %d",&n,&r);
        //if(n==0&&r==0)break;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d %d",&a,&b,&c,&d);
            a++;b++;c++;d++;
            ri=max(ri,c);
            le=min(le,a);
            up=max(up,d);
            down=min(down,b);
            m[P(a,b)]++;
            m[P(a,d)]--;
            m[P(c,b)]--;
            m[P(c,d)]++;
        }
        vec.pb(T(P(INF,INF),INF));
        SORT(vec);
        int index=0;
        for(int i=le;i<=ri+1;i++)
        {
            for(int j=down;j<=up+1;j++)
            {
                imos[i%2][j]=imos[i%2][j-1];
                it=m.find(P(i,j));
                if(it!=m.end())imos[i%2][j]+=(*it).sec;
            }
            for(int j=down;j<=up+1;j++)
            {
                imos[i%2][j]+=imos[(i-1)%2][j];
                if(imos[i%2][j]>0)area++;
                if(!!imos[i%2][j-1]!=!!imos[i%2][j])len++;
                if(!!imos[(i-1)%2][j]!=!!imos[i%2][j])len++;
            }
        }
        cout << area << endl;
        if(r==2)cout << len << endl;
    }
    return 0;
}
