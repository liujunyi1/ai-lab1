#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+9;
int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1},tp=0,jie[10];
int vis[maxn];
string stk[maxn];
string s="123456780",tt="123456780";
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
int kth(string num){
    tr.init();
    int ans=0;
    for(int i=0;i<8;i++){
        ans+=(num[i]-'0'-tr.ask(num[i]-'0'))*jie[8-i];
        tr.add(num[i]+1-'0',1);
    }
    return ans+1;
}
int dfs(string st){
    stk[++tp]=st;
    while(tp){
        string x=stk[tp--];
        int id=kth(x);
        vis[id]=1;
        if(x==tt) return 1;
    int ps=-1;
    for(int i=0;i<=8;i++){
        if(x[i]=='0'){
            ps=i;
            break;
        }
    }
    int xx=ps/3,yy=ps%3;
    for(int i=0;i<=3;i++){
        int nx=xx+dx[i];
        int ny=yy+dy[i];

        if(check(nx,ny)==0)
           continue;
        string tmp=x;
        int nps=nx*3+ny;
        swap(tmp[ps],tmp[nps]);
        if(vis[kth(tmp)]) continue;
        stk[++tp]=tmp;
    }
}
return 0;
}
/*
123
804
765

213804765
213456780

2 1 3 x 4 6 7 5 8
*/
int main(){
jie[0]=1;
for(int i=1;i<=9;i++) jie[i]=jie[i-1]*i;
for(int i=0;i<=8;i++){
    cin>>s[i];
    if(s[i]=='x')
        s[i]='0';
}
//tt="123804765";
cout<<dfs(s);
return 0;
}
