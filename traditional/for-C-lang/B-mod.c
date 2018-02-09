#include <stdio.h>
#include <math.h>
int main(){
    unsigned long long int a,b,n,ans;
    scanf("%llu %llu %llu",&a,&b,&n);
    /*ans = pow(a,n);
    printf("%llu\n",ans%b);*/
    ans = pow(a%b,n);
    printf("%llu\n",ans%b); 
}