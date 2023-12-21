// The maximum path-sum
// Given a matrix A
//  of size N
// *M
// . Print the maximum sum of numbers that can be obtained when you take a path from A1,1
//  to AN,M
// .

// If you stay in Ai,j
//  you can only go to :

// Ai+1,j
//  if and only if i≤N
// Ai,j+1
//  if and only if j≤M
// Note: Solve this problem using recursion.

// Input
// First line contains two numbers N
//  and M
//  (1≤N,M≤10)
//  N
//  donates number of rows and M
//  donates number of columns.

// Next N
//  lines each of them will contain M
//  numbers (−105≤Ai,j≤105)
// 


#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1000000007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

int helper(int row, int col, int nrow, int ncol, vvi mat){
  if(row == nrow && col == ncol) return mat[row][col] ;
  int down = -1e9 ;
  if(row + 1 <= nrow) down = mat[row][col] + helper(row+1,col,nrow,ncol,mat) ;
  int right = -1e9 ;
  if(col + 1 <= ncol) right = mat[row][col] + helper(row,col+1,nrow,ncol,mat) ;
  return max(down,right) ;
}

void solve() {
  int i, j, n, m;
  cin>>n>>m ;
  vvi mat(n, vi(m,0)) ; fo(i,n) fo(j,m) cin>>mat[i][j] ;
  cout<<helper(0,0,n-1,m-1,mat) ;

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

