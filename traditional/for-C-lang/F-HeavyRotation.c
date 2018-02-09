#include <stdio.h>
int n;
char tbl[21][21];
void g()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        int tmp = 0;
        j = n-1;
        while(tbl[j][i] == '-' && j>=0)
        {
            tmp ++;
            j--;
        }
        for(k=n-1;k>=j;k--)
        {
            if(k-tmp<0)
                tbl[k][i] = '-';
            else
                tbl[k][i] = tbl[k-tmp][i];
        }
        for(k=0;k<tmp;k++)
            tbl[k][i] = '-';
    }
}
void r()
{
    char x[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x[i][j] = tbl[n-1-j][i];
        }
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tbl[i][j]=x[i][j];
        }
    }
    g();
}
void l()
{
    char x[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            x[i][j] = tbl[j][n-1-i];
        }
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tbl[i][j]=x[i][j];
        }
    }
    g();
}

int main()
{
    int t;
    scanf("%d %d",&n,&t);
    char cmd[t+1];
    int i,j,k;
    scanf("%s",cmd);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf(" %c",&tbl[i][j]);
        }
    }
    for(i=0;i<t;i++)
    {
        if(cmd[i]=='R')
        {
            r();
        }
        else
        {
            l();
        }
    }

    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
            printf("%c ",tbl[j][k]);
        }
        printf("\n");
    }
    return 0;
}
