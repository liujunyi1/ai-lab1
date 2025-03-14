#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+9;
int vis[maxn],d[maxn],pre1[maxn],jie[11],sx,tx;
int pre2[maxn];
string s="123456780",tt="123456780";
int dx[4]={0,-1,1,0},tp=0;
int dy[4]={1,0,0,-1},h=1,t=0;
char dz[4]={'r','u','d','l'};
int ans[100009];
int check(int x,int y){
    if(x>=0&&x<=2&&y>=0&&y<=2)
        return 1;
    return 0;
}
int posx[9]={2,0,0,0,1,1,1,2,2};
int posy[9]={2,0,1,2,0,1,2,0,1};
/*
123
456
780
*/
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
        tr.add(num[i]-'0'+1,1);
    }
    return ans+1;
}
struct node{
    string s;
    int val;
    bool operator < ( const node & rhs) const{
        return val>rhs.val;
    }
};
priority_queue<node>q;
int g(string x){
    int res=0;
    for(int i=0;i<=8;i++){
        if(x[i]=='0') continue;
        int xx=i/3,yy=i%3,val=s[i]-'0';
        res+=abs(posx[val]-xx)+abs(posy[val]-yy);
    }
    return res;
}
void out(string s){
    for(int i=0;i<=8;i++){
        cout<<s[i];
        if(i%3==2)
            cout<<'\n';
        if(i%9==8)
            cout<<"----------\n";
    }
}

int main(){
jie[0]=1;
for(int i=1;i<=9;i++)
    jie[i]=jie[i-1]*i;
for(int i=0;i<=8;i++){
    cin>>s[i];
    if(s[i]=='x')
        s[i]='0';
}
//swap(s[0],s[1]);
//tt="123804765";
//cout<<kth(s)<<"------------\n";
sx=kth(s);
tx=kth(tt);
d[sx]=1;
q.push({s,d[sx]+g(s)});
while(q.size()){
    string x=q.top().s;
    q.pop();
    int id=kth(x);
    //cout<<x<<'\n';
    if(x==tt)
    break;
    if(vis[id]) continue;
    vis[id]=1;
    if(id==tx)
        break;
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
        int nid=kth(tmp);
        if(d[nid]==0||d[nid]>d[id]+1){
            d[nid]=d[id]+1;
            pre1[nid]=i;
            pre2[nid]=id;
            q.push({tmp,d[nid]+g(tmp)});
        }
}
}
//cout<<d[tt]-1;
/*
3 2 4 1 5 x 7 6 8
*/
if(!d[tx]){
    cout<<"unsolvable";
    return 0;
}
int now=tx;
while(now!=sx){
    //cout<<now<<'\n';
    //out(now);
    ans[++tp]=pre1[now];
    now=pre2[now];

}
for(int i=tp;i;i--)
    cout<<dz[ans[i]];
return 0;
}
//234150768
