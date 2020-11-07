Alexander is a well-known programmer. Today he decided to finally go out and play football, but with the first hit he left a dent on the new Rolls-Royce of the wealthy businessman Big Vova. Vladimir has recently opened a store on the popular online marketplace "Zmey-Gorynych", and offers Alex a job: if he shows his programming skills by solving a task, he'll work as a cybersecurity specialist. Otherwise, he'll be delivering some doubtful products for the next two years.

You're given n positive integers a1,a2,…,an. Using each of them exactly at once, you're to make such sequence b1,b2,…,bn that sequence c1,c2,…,cn is lexicographically maximal, where ci=GCD(b1,…,bi) - the greatest common divisor of the first i elements of b.

Alexander is really afraid of the conditions of this simple task, so he asks you to solve it.

A sequence a is lexicographically smaller than a sequence b if and only if one of the following holds:

a is a prefix of b, but a≠b;
in the first position where a and b differ, the sequence a has a smaller element than the corresponding element in b.
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤103). Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤103)  — the length of the sequence a.

The second line of each test case contains n integers a1,…,an (1≤ai≤103)  — the sequence a.

It is guaranteed that the sum of n over all test cases does not exceed 103.

Output
For each test case output the answer in a single line  — the desired sequence b. If there are multiple answers, print any.

input
7
2
2 5
4
1 8 2 3
3
3 8 9
5
64 25 75 100 50
1
42
6
96 128 88 80 52 7
5
2 4 8 16 17

output
5 2 
8 2 1 3 
9 3 8 
100 50 25 75 64 
42 
128 96 80 88 52 7 
17 2 4 8 16 





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

//template <class T> T gcd(T a , T b){ while(a != 0){T temp = a; a = b % a; b = temp;}return b;}
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

int pow(int x, int y){
    int res = 1;
    x = x%MOD;
    if(x==0) return 0;

    while(y>0){
        if(y&1) res = ((res*x)%MOD+MOD)%MOD;
        y = y>>1;
        x = ((x*x)%MOD+MOD)%MOD;
    }
    return res%MOD;
}

void solve(int test){
    int n;
    cin>>n;

    arr.resize(n);
    int maxi = -1;
    FOR(i, n) {
        cin>>arr[i];
    }

    sort(all(arr), greater<int>());

    cout<<arr[0]<<' ';
    int g = arr[0];
    arr.erase(arr.begin());

    while(arr.size()>0){
        int it = -1, m = 0;
        FOR(i, arr.size()){
            int t = gcd(arr[i], g);
            if(t > m){
                m = t;
                it = i;
            }
        }

        cout<<arr[it]<<' ';
        g = gcd(g, m);
        arr.erase(arr.begin()+it);
    }

    cout<<endl;
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

