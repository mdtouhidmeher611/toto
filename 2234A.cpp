#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<long long>b(n);
        for(auto &x:b)cin>>x;

            sort(b.rbegin(),b.rend());

        if(n==2){
            cout<<b[0]<<' '<<b[1]<<'\n';
            continue;
        }

        bool ok=true;

        for(int i=0;i+1<n;i++)
            if(b[i]==b[i+1])
                ok=false;
            for(int i=0;i+2<n;i++)
                if(b[i]%b[i+1]!=b[i+2])
                    ok=false;
                if(ok)
                    cout<<b[0]<<' '<<b[1]<<'\n';
                else 
                    cout<<-1<<'\n';
            }
            return 0;
        }