#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m = ll(1e9)+7;

ll pow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1) res = (res*a)%m;
		a = (a*a)%m;
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
		ll res = 1;
		while(c){
			if(c&1) res = (res*a)%m;
			a = pow(a, b);
		}
		while(c--)
			a = pow(a, b);
		cout<<a<<endl;
	}
	return 0;
}