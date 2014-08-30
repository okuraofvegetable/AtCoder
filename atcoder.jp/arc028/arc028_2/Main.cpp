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
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<eps)
int n,k;
int a[100100];
int rank[100100];
int main()
{
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		rank[a[i]]=i+1;
	}
	priority_queue<int> q;
	for(int i=0;i<k;i++)
	{
		q.push(a[i]);
	}
	int c=q.top();
	printf("%d\n",rank[c]);
	for(int i=k;i<n;i++)
	{
		if(a[i]>c)
		{
			printf("%d\n",rank[c]);
			continue;
		}
		q.pop();
		q.push(a[i]);
		c=q.top();
		printf("%d\n",rank[c]);
	}
	return 0;
}
