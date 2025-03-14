#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
vector<int>g[maxn];
int n,m,d[maxn],q[maxn],h=1,t=0;
int main(){
cin>>n>>m;
for(int i=1;i<=n;i++) d[i]=-1;
for(int i=1;i<=m;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    //g[y].push_back(x);
}
d[1]=0;
q[++t]=1;
while(h<=t){
    int x=q[h++];
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(d[y]==-1){
            d[y]=d[x]+1;
            q[++t]=y;
        }
    }
}
cout<<d[n];
return 0;
}
/*
5 5
1 2
2 3
3 4
3 1
2 3

4 4
1 2
2 3
3 1
3 4
*/
