#include <stdio.h>
int isP(int x)
{
    int ans = 1;
    int i;
    for(i=2;i<x;i++)
    {
        if(x%i==0)
        {
            ans = 0;
            break;
        }
    }
    //printf("        %d\n",ans);
    return ans;

}
int main(){
    int i,j,n,t;
    i = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(t<=2)
        {
            t = 2;
        }
        for(j=0;j<t;j++)
        {
            if(isP(t+j)==1)
            {
                printf("%d\n",t+j);
                break;
            }
            if(isP(t-j)==1)
            {
                printf("%d\n",t-j);
                break;
            }

        } 
    }


    return 0;
}