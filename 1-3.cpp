#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
vector<int>g[maxn],g2[maxn];
int n,m,d[maxn],vis[maxn],s=1;
struct node{
    int ps,val;
    bool operator < (const node & rhs) const{
        return val>rhs.val;
    }
};
priority_queue<node>q;
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
q.push({s,0});
while(q.size()){
    int x=q.top().ps;
    q.pop();
    if(vis[x]) continue;
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i],z=g2[x][i];
        if(d[y]>d[x]+z||d[y]==-1){
            d[y]=d[x]+z;
            q.push({y,d[y]});
        }
    }
}
cout<<d[n];
return 0;
}
/*
3 3
1 2 2
3 2 1
1 3 4

*/
