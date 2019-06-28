#include<iostream>
#include<stdio.h>
#define nMax 13
#define kMax 99
int main(){
    int t;
    int i,j,k,n;
 
    int dp[kMax][nMax] ;
    int cum[kMax][nMax]={0};
 
    for(i=0;i<nMax;i++){
      dp[0][i]=1;
      cum[0][i]=1;
    }
    for(i=0;i<kMax;i++){
      dp[i][0]=0;
      cum[i][0]=0;
    }
    for(k=1;k<kMax;k++){
        for(n=1; n < nMax ; n++){
             
            if(k>((n*(n-1))/2)){
                dp[k][n] = 0;
            }
            else{
                if(k>=n) dp[k][n] = cum[k][n-1] - cum[k-n][n-1]  ;
                else dp[k][n] = cum[k][n-1];
            }
            cum[k][n] = cum[k-1][n] + dp[k][n];
 
        //  printf("%d:%d ",dp[k][n],cum[k][n]);
        }
    //  printf("\n");
    }
 
 
/*
    t = Integer.parseInt(br.readLine());
    System.out.println(t);
    while(t>0){
        t--;
        String[] tmp = br.readLine().split(" ");
        n = Integer.parseInt(tmp[0]);
        k = Integer.parseInt(tmp[1]);
 
    }*/
    scanf("%d",&t);
    while(t--){
      scanf("%d %d",&n,&k);
      printf("%d\n",dp[k][n]);
    }
    return 0;
}