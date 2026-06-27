#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		vector<int>p(n+1);
		for(int i=1,x;i<=n;i++){
			cin>>x;
			p[x]=i;
		}
		bool ok=1;
		for(int i=1;i<n;i++){
			if(abs(p[i]-p[i+1])%2==0)ok=0;
		}
		cout<<(ok?"YES":"NO")<<"\n";
	}
}