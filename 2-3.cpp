#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
int jie[10];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
vector<int>g[maxn],d[maxn];
string s="123456780",t="123456780";
int sx,tx,ss[9],tt[9],dis[maxn],vis[maxn];
struct node{
    int ps,val;
    bool operator < (const node & rhs) const{
        return val>rhs.val;
    }
};
priority_queue<node>q;
int check(int x,int y){
    if(x>=0&&x<=2&&y>=0&&y<=2)
        return 1;
    return 0;
}
struct sgt{
    int sum[10];
    int lowbit(int x){
    return x&(-x);
    }
    void add(int x,int val){
    for(int i=x;i<=9;i+=lowbit(i))
         sum[i]+=val;
    return;
    }
    int ask(int x){
    int ans=0;
    for(int i=x;i;i-=lowbit(i))
        ans+=sum[i];
    return ans;
    }
    void init(){
    for(int i=1;i<=9;i++)
        sum[i]=0;
    }
}tr;
int kth(int *num){
    tr.init();
    int ans=0;
    for(int i=0;i<8;i++){
        ans+=(num[i]-1-tr.ask(num[i]-1))*jie[8-i];
        tr.add(num[i],1);
    }
    return ans+1;
}
void make_graph(){
    int a[9]={1,2,3,4,5,6,7,8,9},now=0;
    do{
        now++;
        int ps=-1;
        for(int i=0;i<=8;i++)
        if(a[i]==1){
            ps=i;
            break;
        }
        int x=ps/3,y=ps%3;
        for(int i=0;i<=3;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nps=nx*3+ny;
            if(!check(nx,ny)) continue;
            swap(a[ps],a[nps]);
            int nxt=kth(a);
            g[now].push_back(nxt);
            d[now].push_back(i);
            swap(a[ps],a[nps]);
        }
    }while(next_permutation(a,a+9));

}
void dij(){
    for(int i=0;i<=8;i++)
        tt[i]=t[i]-'0'+1;
    tx=kth(tt);
    for(int i=0;i<=1e6;i++) dis[i]=-1;
    dis[tx]=0;
    q.push({tx,0});
    while(q.size()){
        int x=q.top().ps;
        q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=0;i<g[x].size();i++){
            int y=g[x][i],z=1;
            if(dis[y]>dis[x]+z||dis[y]==-1){
                dis[y]=dis[x]+z;
                q.push({y,dis[y]});
            }
        }
    }
}
int main(){
jie[0]=1;
for(int i=1;i<=9;i++)
    jie[i]=jie[i-1]*i;
make_graph();
dij();
for(int i=0;i<=8;i++) {
    cin>>s[i];
    if(s[i]=='x')
        s[i]='0';
}
for(int i=0;i<=8;i++) ss[i]=s[i]-'0'+1;
sx=kth(ss);
cout<<dis[sx];
return 0;
}
/*
3 2 4 1 5 x 7 6 8
*/
