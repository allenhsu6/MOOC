//
// Created by allenhsu on 2018/12/6.
//

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<functional>
#include<set>

using namespace std;

const int N = 10009;//地图范围

int v[N][N] = {};//记录地图
int dx[] = {1,1,1,0,0,-1,-1,-1};  //8个方向
int dy[] = {1,0,-1,1,-1,1,-1,0};
int f[N*N];     //对当前点进行标记，同时记录上一个位置的坐标

struct Node
{
    int x,y,f,g;//坐标与权值
};

struct Nodecmp//优先队列比较函数
{
    bool operator() (const Node &a, const Node &b)
    {
        return a.f > b.f;
    }
};

int leng(Node a, Node b)//求点与终点的几何长度
{
    return sqrt((a.x - b.x)*(a.x - b.x)
                + (a.y - b.y)*(a.y - b.y));
}

void print(int nid, int n)  //输出最短路径
{
    if(nid == -1)
        return;
    print(f[nid],n);
    printf("%d %d\n",(nid-1)/n, nid-(nid-1)/n*n);
}

bool a_start(Node s, Node e, int n)
{
    if(!v[e.x][e.y])//终点不可达
        return false;
    memset(f, 0, sizeof(f));
    priority_queue<Node, vector<Node>, Nodecmp> q;
    int eid = e.x * n + e.y;
    f[s.x * n + s.y] = -1;//二维转一维进行标记，便于操作
    while(!q.empty())
    {
        Node now = q.top();
        q.pop();//出队
        int nid = now.x * n + now.y;
        if(nid == eid)//判断是否为终点
        {
            print(nid, n);
            return true;
        }
        for(int i=0;i<8;i++)//遍历8个方向
        {
            Node t;
            t.x = dx[i] + now.x;
            t.y = dy[i] + now.y;
            int tid = t.x * n + t.y;
            if(v[t.x][t.y] && f[tid] == 0)
            {//符合条件便标记并入队
                f[tid] = nid;
                t.g = now.g + 1;
                t.f = t.g + leng(t, e);
                q.push(t);
            }
        }
    }
    return false;
}

int main()
{
    int n;      // 节点个数
    Node s,e;  // 分别是start和end
    s.g = 0;
    cin>>n>>s.x>>s.y>>e.x>>e.y;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>v[i][j];
    if(!a_start(s,e,n))
        cout<<"无法到达"<<endl;
}
