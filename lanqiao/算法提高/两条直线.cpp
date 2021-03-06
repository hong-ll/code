#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

const int N=100000;
struct P{int x,y;};
bool cmp(P a,P b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
P d[N+5];
struct F{int max,min;};
F fl[N+5],fr[N+5];
inline double Max(double a,double b){return a>b?a:b;}
inline double Min(double a,double b){return a>b?b:a;}
bool check(double m,int n){
    m*=2;
    int i,j=0;
    for(i=0;i<n;i++){
        while(j<n&&d[j].x-d[i].x<=m)j++;
        double MAX=-1e10;
        double MIN=1e10;
        if(j!=n){
            MAX=Max(MAX,fr[j].max);
            MIN=Min(MIN,fr[j].min);
        }
        if(i-1>=0){
            MAX=Max(MAX,fl[i-1].max);
            MIN=Min(MIN,fl[i-1].min);
        }
     //   cout<<i<<" "<<j<<" "<<MAX<<" "<<MIN<<endl;
        if(MAX-MIN<=m)return true;
    }
    return false;
}
//????????????
void init(int n){
    int i;
    fl[0].min=fl[0].max=d[0].y;
    for(i=1;i<n;i++){
        fl[i].max=Max(fl[i-1].max,d[i].y);
        fl[i].min=Min(fl[i-1].min,d[i].y);
    }
    fr[n-1].min=fr[n-1].max=d[n-1].y;
    for(i=n-2;i>=0;i--){
        fr[i].max=Max(fr[i+1].max,d[i].y);
        fr[i].min=Min(fr[i+1].min,d[i].y);
    }
}
int main(){
    int i,n;
    cin>>n;
    for(i=0;i<n;i++){
        int x,y;
		//???45????????????????45?
        scanf("%d%d",&x,&y);
        d[i].x=x+y;
        d[i].y=x-y;
    }
	//????????
    sort(d,d+n,cmp);
	
    init(n);
    double l=0.0;
    double r=1000000000;
    while(r-l>=0.01){
        double m=(l+r)/2;
      //  cout<<m<<endl;
        if(check(m,n))r=m;
        else l=m;
    }
    printf("%.1f\n",r);
    return 0;
}
