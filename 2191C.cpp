#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		string s;
		cin>>n>>s;
		long long inv=0,ones=0;
		for(char c:s){
			if(c=='1')ones++;
			else inv+=ones;
		}
		if(!(inv&1)){
			cout<<"Bob\n";
			continue;
		}
		int a=-1,b=-1;
		for(int i=0;i<n&&a==-1;i++){
			if(s[i]=='1'){
				for(int j=i+1;j<n;j++){
					if(s[j]=='0'){
						a=i+1;
						b=j+1;
						break;
					}
				}
			}
		}
		cout<<"Alice\n2\n"<<a<<" "<<b<<"\n";
	}
}