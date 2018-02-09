#include<stdio.h>
int n,k;
long long int maxScr=-1,board[1001][2];
long long int highScr[1001];
long long int myabs(long long int a, long long int b){
    if(a>b) return a-b;
    else return b-a;
}
int playski(int now,int scr){
    //printf("PlaySki (#%d, %d)\n",now,scr);
    if(highScr[now]>0) {
     //   printf(" Find Optimized : %d\n",highScr[now]);
        return highScr[now];
    }

    int i,tmp=0,thisMax=board[now][1];
    for(i=now+1;i<=n;i++){
        if(board[i][0]>board[now][0]||board[now][0]-board[i][0]>k) continue;
        tmp = playski(i,scr);
        if(tmp+scr>thisMax) thisMax = tmp+scr;
    }

    highScr[now] = thisMax;
   //     printf("\t Set Optimized : %d\n",highScr[now]);
    return highScr[now];
}

int main(){

    scanf("%d %d",&n,&k);
    int i,tmp;
    for(i=1;i<=n;i++) scanf("%lli %lli",&board[i][0],&board[i][1]);
    //0 - height, 1 - point
    for(i=n;i>=1;i--){
        tmp = playski(i,board[i][1]);
        if(tmp>maxScr) maxScr = tmp;
    }
    /*for(i=n;i>=1;i--){
        printf("(%d) highScr = %d\n",i,highScr[i]);
    }*/
    printf("%lli",maxScr);
}
