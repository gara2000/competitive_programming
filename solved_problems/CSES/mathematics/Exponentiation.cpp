#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n;
	cin>>n;
	while(n--){
		ll a, b;
		cin>>a>>b;
		ll m = ll(1e9)+7;
		ll res = 1;
		while(b){
			if(b&1) res = (res*a)%m;
			a = (a*a)%m;
			b>>=1;
		}
		cout<<res<<endl;
	}
	return 0;
}