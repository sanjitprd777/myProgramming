#include<bits/stdc++.h>
using namespace std;

int a[11][11],b[11][11],vis[11][11],vis1[11][11],n,m;

void bfs(int i,int j,int c,int c1)
{
    if(i<0 || j<0 || i>=n || j>=m)
        return;

    c+=a[i][j];
    c1+=b[i][j];
    if(c<vis[i][j])
    {
        vis1[i][j]=c1;
        vis[i][j]=c;
        bfs(i,j+1,c,c1);
        bfs(i+1,j,c,c1);
        bfs(i-1,j,c,c1);
        bfs(i,j-1,c,c1);
    }
    else if(c==vis[i][j])
    {
        vis1[i][j]=min(c1,vis1[i][j]);
        vis[i][j]=c;
        bfs(i,j+1,c,c1);
        bfs(i+1,j,c,c1);
        bfs(i-1,j,c,c1);
        bfs(i,j-1,c,c1);
    }
}

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n, &m);

        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(vis,0,sizeof(vis));
        memset(vis1,0,sizeof(vis1));


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vis[i][j]=99999999;
                vis1[i][j]=99999999;
                scanf("%d",&a[i][j]);
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                scanf("%d",&b[i][j]);
        }

        bfs(0,0,0,0);
        printf("%d %d\n",vis[n-1][m-1],vis1[n-1][m-1]);
    }
    return 0;
}
