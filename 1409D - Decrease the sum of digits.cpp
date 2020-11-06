You are given a positive integer n. In one move, you can increase n by one (i.e. make n:=n+1). Your task is to find the minimum number of moves you need to perform in order to make the sum of digits of n be less than or equal to s.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.

The only line of the test case contains two integers n and s (1≤n≤1018; 1≤s≤162).

Output
For each test case, print the answer: the minimum number of moves you need to perform in order to make the sum of digits of n be less than or equal to s.

input
5
2 1
1 1
500 4
217871987498122 10
100000000000000001 1

output
8
0
500
2128012501878
899999999999999999

Solution -

/*
    Author -: @namanworld
*/

// ░░░░░░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░░░░░
// ░░░░░░█░░▄▀▀▀▀▀▀▀▀▀▀▀▀▀▄░░█░░░░░
// ░░░░░░█░█░▀░░░░░▀░░▀░░░░█░█░░░░░
// ░░░░░░█░█░░░░░░░░▄▀▀▄░▀░█░█▄▀▀▄░
// █▀▀█▄░█░█░░▀░░░░░█░░░▀▄▄█▄▀░░░█░
// ▀▄▄░▀██░█▄░▀░░░▄▄▀░░░░░░░░░░░░▀▄
// ░░▀█▄▄█░█░░░░▄░░█░░░▄█░░░▄░▄█░░█
// ░░░░░▀█░▀▄▀░░░░░█░██░▄░░▄░░▄░███
// ░░░░░▄█▄░░▀▀▀▀▀▀▀▀▄░░▀▀▀▀▀▀▀░▄▀░
// ░░░░█░░▄█▀█▀▀█▀▀▀▀▀▀█▀▀█▀█▀▀█░░░
// ░░░░▀▀▀▀░░▀▀▀░░░░░░░░▀▀▀░░▀▀░░░░

#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define endl '\n'
#define root2 1.41421
#define root3 1.73205
#define cntbit __builtin_popcountll
#define MOD 1000000007
#define sz(s) s.size()
#define INF 10000000000000000
// find_by_order(), order_of_key()
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define FORI(i,j,n) for(int i=j; i<=n; i++)
#define FOR(i, n) for(int i=0; i<n; i++)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define vi vector<int>
#define ss second
#define pb push_back
#define ff first
#define pii pair<int,int>
#define vii vector<pii>
#define pq priority_queue<int>
#define pdq priority_queue<int, vi, greater<int> >
#define gethash(l, r) (MOD-(h[r+1]*p_pow[r-l+1])%MOD+h[l])%MOD;
#define gcd(a, b) __gcd(a, b)
//#define lcm(a, b) (a*b)/gcd(a, b)
#define sqr(x) (x*x)
#define single solve(0)

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

const lld pi = 3.14159265358979323846;

//mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

using namespace __gnu_pbds;
using namespace std;

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}


/*----------------------------- # --- MATH ALGORITHMS --- # -----------------------------*/

template <class T> T gcd(T a , T b){ while(a != 0){T temp = a; a = b % a; b = temp;}return b;}
template <class T> T egcd(T a , T b , T &x , T &y){T gcd , xt , yt;if(a == 0){gcd = b;x = 0 , y = 1;}else {gcd = egcd(b % a , a , xt , yt);x = yt - (b/a)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T a , T mod){T x , y; egcd<T>(a , mod , x , y);while(x < 0) x += mod; while(x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T a , T mod){return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b){return a > b;}
template <class T> ll maxpower(T a , T b){ll ans = 0;while(a > 0 && a % b == 0){ans++;a /= b;}return ans;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
//template <class T> T lcm(T a, T b) {return (a*b)/gcd<T>(a, b);}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

/// ////////////////////////////////////////////////////////////////////////
/// ///////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
/// ////////////////////////////////////////////////////////////////////////

const int N = 3e5+5;
vi arr(N);
//int primes[N];

/*int pow(int x, int y){
    int res = 1;
    x = x%MOD;
    if(x==0) return 0;

    while(y>0){
        if(y&1) res = ((res*x)%MOD+MOD)%MOD;
        y = y>>1;
        x = ((x*x)%MOD+MOD)%MOD;
    }
    return res%MOD;
}*/

ull powx(int n, int x){
    if(x == 0) return 1;
    return n*powx(n, x-1);
}

int sum(int n){
    int ans = 0;
    while(n){
        ans += n%10;
        n/=10;
    }
    return ans;
}

void solve(int test){
    int n, k;
    cin>>n>>k;

    if(sum(n)<=k){
        cout<<0<<endl;
        return;
    }

    int ans = 0;
    int p = 1;

    FOR(i, 18){
        int dig = (n/p)%10;
        int add = p*((10-dig)%10);
        n += add;
        ans += add;
        if(sum(n) <= k) break;
        p*=10;
    }

    cout<<ans<<endl;
}

signed main()
{
    fastIO

   /*#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif*/

    ///Prime factors formations:
    //genprimes(1e6);

    //single;
    int t; cin>>t; FOR(i, t) {solve(i);}

    //cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

    return 0;
}

