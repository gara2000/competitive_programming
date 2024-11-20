#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m = ll(1e9)+7;

ll pow(ll a, ll b, ll mod){
	ll res = 1;
	while(b){
		if(b&1) res = (res*a)%mod;
		a = (a*a)%mod;
		b >>=1;
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n;
	cin>>n;
	while(n--){
		ll a, b, c;
		cin>>a>>b>>c;
		cout<<pow(a, pow(b, c, m-1), m)<<endl;
	}
	return 0;
}