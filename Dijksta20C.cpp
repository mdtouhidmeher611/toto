#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin>>n>>m;

	vector<vector<pair<int,long long>>>adj(n+1);

	for(int i=0;i<m;i++){
		int u,v;
		long long w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	const long long INF=1e18;
	vector<long long>dist(n+1,INF);
	vector<int>par(n+1,-1);

	priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;

	dist[1]=0;
	pq.push({0,1});

	while(!pq.empty()){
		auto[d,u]=pq.top();
		pq.pop();

		if(d!=dist[u])continue;

		for(auto[v,w]:adj[u]){
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				par[v]=u;
				pq.push({dist[v],v});
			}
		}
	}

	if(dist[n]==INF){
		cout<<-1<<'\n';
		return 0;
	}

	vector<int>path;
	for(int cur=n;cur!=-1;cur=par[cur])path.push_back(cur);

		reverse(path.begin(),path.end());

	for(int i=0;i<(int)path.size();i++){
		if(i)cout<<' ';
		cout<<path[i];
	}
	cout<<'\n';
}