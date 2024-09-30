#include <bits/stdc++.h>
#include <iomanip>
#include <cmath>
// #define endl '\n' 
#define mod 1000000007ll
#define pb push_back
#define all(v) v.begin(),v.end()
#define M_PI           3.14159265358979323846
#define prime6 347717
#define loop(start, end, step) for(int i=start; i<end; i+=step)
#define fi first
#define se second
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> plli;
 
const ll inf=ll(1e14)+5;
const ll mo=998244353;
//const int p=31;
 
template<typename T>
void repr(vector<T> a, int N)
{
	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
 
void no(){
    cout<<"NO"<<endl;
}
void yes(){
    cout<<"YES"<<endl;
}

typedef struct entry{
	int a;
	int b;
	int c;
	int f;
} entry;

vector<entry> v;

vector<plli> adj[1001];
vector<ll> dist(1001);

bool f(string s, int k){
		map<string, int> m;
		int n = s.size();
		bool test = true;
		for(int pos = 0; pos<=n-k; pos++){
			string sub = s.substr(pos, k);
			m[sub]++;
			if(m[sub]>1)
			{
				test = false;
				break;
			}
		}	
		return test;
}

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int l = 1, r=n;
	// for(;k<=n;k++){
	while(l<r){
		int k = (l+r)/2;
		if(f(s, k)){
			r = k;
		}
		else l = k+1;
	}
	cout<<l<<endl;
	return;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
 
	// freopen("polygon.in", "r", stdi n);
 
    cout<<setprecision(20);
 
	int t=1;
	bool test = false;
	if(test)
		cin>>t;
	while(t--)
		solve();
 
	return 0;
}

