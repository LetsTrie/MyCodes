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

const int MAXN = 10001;

char str[MAXN];
int N;
int sum[MAXN][26];

void build() 
{
	for(int i = 1 ; i <= N ; i++) 
		FOR(j , 26) sum[i][j] = sum[i - 1][j] + (j == (str[i - 1] - 'a'));
}

int main()
{

#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
    	//freopen("out.txt", "w", stdout);
#endif

    	int test;
    	si(test);
    	while(test--) 
    	{
    		int Q;
    		sii(N , Q);
    		scanf("%s", str);
    		build();
    		while(Q--) 
    		{
    			int x , y;
    			sii(x , y);
    			char ch;
    			scanf("%c", &ch);
    			x-- , y--;
    			int divX = x / N , divY = y / N;
    			int multiple = divY - divX;
    			x %= N , y %= N;
    			int chh = ch - 'a';
    			printf("%d\n", (multiple * sum[N][chh]) + sum[y + 1][chh] - sum[x][chh]);
    		}

    		for(int i = 0 ; i < N ; i++) 
			FOR(j , 26) sum[i][j] = 0;
    	}
}
