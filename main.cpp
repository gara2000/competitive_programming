#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
using namespace std;

typedef complex<double> pt;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(17);

	/// SAVE THE FILE !!!///
	ll n, k;
	cin>>n>>k;
	set<pll> s;
	loop(n){
		ll curr = i+1;
		ll q = (k+1)/n;
		curr+=q*n;
		while(curr%(k+1)){
			curr+=n-(curr/(k+1));
		}
		s.insert({curr, i+1});
	}
	for(auto p: s)
		cout<<p.second<<" ";
	cout<<endl;
	return 0;
}