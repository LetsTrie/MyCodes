#include<bits/stdc++.h>

#define fi first
#define endl '\n'
#define se second
#define LL long long
#define pb push_back
#define vi vector<int>
#define mod 1000000007
#define EPS (double)1e-8
#define pii pair<int , int>
#define sz(x) (int) x.size()
#define sl(x) scanf("%lld",&x)
#define sii(x, y) si(x) , si(y)
#define all(x) (x).begin() , (x).end()
#define lg2(X) (31 - __builtin_clz(X))
#define Min(a , b) ( (a < b) ? a : b )
#define Max(a , b) ( (a < b) ? b : a )
#define llg2(X) (63 - __builtin_clzll(X))
#define rall(x) (x).rbegin() , (x).rend()
#define siii(x, y, z) si(x) , si(y) , si(z)
#define mem(a , b) memset((a), (b), sizeof(a))
#define FOR(i , n) for(int i = 0 ; i < n ; i++)
#define FOR1(i , n) for(int i = 1 ; i <= n ; i++)
#define _ceil(n, a) ((n)%(a)==0?((n)/(a)):((n)/(a)+1))
#define mlr int mid = (lo + hi) / 2 , l = node << 1 , r = l | 1 // 1 based
#define itr(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
template <typename T> T si(T &n){n = 0;bool neg = false;char c = getchar();while( c < '0' || c > '9'){if(c == '-') neg = true;c = getchar();}while(c >= '0' && c <= '9'){n = n*10 + c-48;c = getchar();}if(neg) n = ~(n-1);return n;}

using namespace std;

 int fx[] = {1 , 0 , -1 , 0}; //, 1 , 1 , -1 , -1};
 int fy[] = {0 , 1 , 0 , -1}; //, 1 , -1 , 1 , -1};

/********************* OverFlow ***********************/

const int MAXN = 555;
const LL inf = 1000000000000;

struct info {
	LL dis;
	int x;
	info(){}
	info(LL _dis , int _x) : dis(_dis) , x(_x) {}
	bool operator < (const info &other) const {
		return dis > other.dis;
	}
};

LL dist[MAXN];
priority_queue<info> pq;
vector<pii> G[MAXN];
vector<pii> ForBinarySearch;
LL sudo[MAXN];

int s , eg;

LL Dijkstra(int node) {
	LL mx = -1;
	FOR1(i , eg) sudo[i] = dist[i];
	sudo[node] = 0; 
	FOR1(i , eg) if( !sudo[i] ) pq.push(info(0 , i));
	while(!pq.empty()) {
		info u = pq.top(); pq.pop();
		FOR(i , sz(G[u.x])) {
			int v = G[u.x][i].fi;
			int w = G[u.x][i].se;
			if(sudo[v] > sudo[u.x] + w) {
				sudo[v] = sudo[u.x] + w;
				pq.push(info(sudo[v] , v));
			}
		}
    	}
	FOR1(i , eg) mx = Max(mx , sudo[i]);
    	return mx;
}

int main()
{

#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	//freopen("out.txt", "w", stdout);
#endif

    	int test;
    	int T = 1;
    	si(test); int newLine = 0;
    	while(test--) {
    		if(newLine) printf("\n"); newLine = 1;
    		sii(s , eg); int xx;
    		FOR1(i , eg) dist[i] = inf;
    		FOR(i , s) si(xx) , dist[xx] = 0 , pq.push({0 , xx});
    		string str;
    		while(getline(cin , str) && str.size() != 0) {
    			stringstream ss(str);
    			int xx , yy  , zz;
    			ss >> xx;
    			ss >> yy;
    			ss >> zz;
    			G[xx].pb({yy , zz});
    			G[yy].pb({xx , zz});
    		} 
    		while(!pq.empty()) {
    			info u = pq.top(); pq.pop();
    			FOR(i , sz(G[u.x])) {
    				int v = G[u.x][i].fi;
    				int w = G[u.x][i].se;
				if(dist[v] > dist[u.x] + w) {
					dist[v] = dist[u.x] + w;
					pq.push(info(dist[v] , v));
				}
    			}
    		}
    		LL idx , mx = inf; 
    		FOR1(i , eg) {
    			LL D = Dijkstra(i);
    			if(mx > D) {
    				mx = D;
    				idx = i;
    			}
    		}
    		printf("%lld\n",idx);
    		FOR1(i , eg) G[i].clear();
    	}
}
