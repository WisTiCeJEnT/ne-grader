#include <stdio.h>
int n;
char tbl[21][21];
void g()
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        char tmp[n];
        k = 0;
        for(j=n-1;j>=0;j--)
        {
            if (tbl[j][i]!='-')
            {
                tmp[k] = tbl[j][i];
                k++;
            }
        }
        for(j=k;j<n;j++)
        {
            tmp[j] = '-';
        }
        for(j=0;j<n;j++)
        {
            tbl[n-j-1][i] = tmp[j];
        }
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
    for(i=0;i<t;i++)
        scanf(" %c",&cmd[i]);
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
        //===============
        /*
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                printf("%c ",tbl[j][k]);
            }
            printf("\n");
        }
        printf("\n");
        */
        //===============
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
