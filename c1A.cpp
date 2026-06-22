#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int c0=0,c1=0,c2=0,x;
        for(int i=0;i<n;i++){
            cin>>x;
            if(x==0) c0++;
            else if(x==1) c1++;
            else c2++;
        }
        int p=min(c1,c2);
        int ans=c0+p+(c1-p)/3+(c2-p)/3;
        cout<<ans<<"\n";
    }
}
