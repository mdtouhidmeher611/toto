#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        long long n,a,b,k;cin>>n>>a>>b>>k;
        long long d=llabs(a-b);
        d=min(d,n-d);
        if(d==1)cout<<k+1<<"\n";
        else cout<<d+k<<"\n";
    }
    return 0;
}