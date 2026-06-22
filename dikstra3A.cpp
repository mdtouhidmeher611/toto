#include<bits/stdc++.h>
using namespace std;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};
string mv[8]={"LD","L","LU","D","U","RD","R","RU"};

int id(int x,int y){
    return x*8+y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s,t;
    cin>>s>>t;

    int sx=s[0]-'a';
    int sy=s[1]-'1';
    int tx=t[0]-'a';
    int ty=t[1]-'1';

    vector<int>dist(64,1e9);
    vector<int>par(64,-1);
    vector<string>how(64);

    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
    >pq;

    dist[id(sx,sy)]=0;
    pq.push({0,id(sx,sy)});

    while(!pq.empty()){
        auto[d,u]=pq.top();
        pq.pop();

        if(d!=dist[u])
            continue;

        int x=u/8;
        int y=u%8;

        for(int k=0;k<8;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx<0||nx>=8||ny<0||ny>=8)
                continue;

            int v=id(nx,ny);

            if(dist[v]>dist[u]+1){
                dist[v]=dist[u]+1;
                par[v]=u;
                how[v]=mv[k];
                pq.push({dist[v],v});
            }
        }
    }

    int target=id(tx,ty);

    cout<<dist[target]<<"\n";

    vector<string>ans;

    while(target!=id(sx,sy)){
        ans.push_back(how[target]);
        target=par[target];
    }

    reverse(ans.begin(),ans.end());

    for(auto&s:ans)
        cout<<s<<"\n";
}