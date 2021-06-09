#include<bits/stdc++.h>
#define mxn 200005
#define ll long long
using namespace std;
vector<int>adj[mxn];
ll res, cnt[mxn][2], val[mxn][2];
void dfs(int x, int par)
{
    for(int i=0; i<adj[x].size(); i++)
    {
        int y= adj[x][i];
        if(y==par)continue;

        dfs(y, x);

        ll oddCnt= cnt[y][0]+1;
        ll oddSum= val[y][0]+oddCnt;
        res+= oddSum;

        ll evenCnt= cnt[y][1];
        ll evenSum= val[y][1];
        res+= evenSum;

        res+= oddSum*cnt[x][1]+oddCnt*val[x][1];
        res-= cnt[x][1]*oddCnt;
        res+= oddSum*cnt[x][0]+oddCnt*val[x][0];
        res+= evenSum*cnt[x][1]+evenCnt*val[x][1];
        res+= evenSum*cnt[x][0]+evenCnt*val[x][0];

        cnt[x][0]+= cnt[y][1];
        cnt[x][1]+= 1+cnt[y][0];
        val[x][0]+= evenSum;
        val[x][1]+= oddSum;
    }

    return;
}
int main()
{
    int n, x, y;
    scanf("%d", &n);

    for(int i=1; i<n; i++)
    scanf("%d %d", &x, &y),
    adj[x].push_back(y), adj[y].push_back(x);

    dfs(1, 1);
    printf("%lld\n", res);

    return 0;
}
