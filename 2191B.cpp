#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	while(T--){
		int n,c=0,x;cin>>n;
		while(n--){cin>>x;if(x==0)c++;}
		cout<<(c<=1?"YES":"NO")<<"\n";
	}
}