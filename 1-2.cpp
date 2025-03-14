#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
vector<int>g[maxn],g2[maxn];
int n,m,d[maxn],vis[maxn],s=1;
int main(){
cin>>n>>m;
//cin>>s;
for(int i=1;i<=n;i++) d[i]=-1;
for(int i=1;i<=m;i++){
    int x,y,z;
    cin>>x>>y>>z;
    g[x].push_back(y);
    g2[x].push_back(z);
}
d[s]=0;
for(int tim=1;tim<=n;tim++){
    int ps=0;
    for(int i=1;i<=n;i++){
        if(vis[i]||d[i]==-1) continue;
        if(ps==0||d[ps]>d[i])
            ps=i;
    }
   // cout<<ps<<'\n';
    if(ps==0) break;
    vis[ps]=1;
    for(int i=0;i<g[ps].size();i++){
        int y=g[ps][i];
        if(d[y]>d[ps]+g2[ps][i]||d[y]==-1)
            d[y]=d[ps]+g2[ps][i];
    }
}
cout<<d[n];
return 0;
}
/*
3 3
1 2 2
3 2 1
1 2 4

*/
