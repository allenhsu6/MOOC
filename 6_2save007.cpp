//
// Created by allenhsu on 2018/11/26.
// 能跳过去说明有连接，从起点开始，有多个

#include <iostream>
#include <vector>
#include "math.h"

typedef struct XNode *Crocodile;
struct XNode{
    int x;
    int y;
};

bool FirstJump(Crocodile pNode);

bool DFS(int i);

bool isSafe(int i);

bool Jump(int x, int y);

using namespace std;
bool answer = false;
int visit[101] = {0};
vector<Crocodile> V;
int n, m;


int main(){
    int a, b;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        Crocodile C = new(XNode);
        C->x = a;
        C->y = b;
        V.push_back(C);
    }

    if (m >= 42.5) answer = true;
    else{
        for (int j = 0; j < n; ++j) {
            if (!visit[j] && FirstJump(V[j])){
                answer = DFS(j);
                if (answer) break;
            }
        }
    }
    if(answer) cout << "Yes" ;
    else cout << "No" ;
    return 0;
}


// 递归判断能否跳过去
bool DFS(int i) {
    visit[i] = 1;
    if (isSafe(i)){
        answer = true;
    }else{
        for (int j = 0;  (j < n); ++j) {
            if (!visit[j] && Jump(i,j)){
                answer = DFS(j);
                if (answer) break;
            }
        }
    }
    return answer;
}

bool Jump(int x, int y) {
    int distance = (V[x]->x - V[y]->x)*(V[x]->x - V[y]->x) + (V[x]->y - V[y]->y)*(V[x]->y - V[y]->y);
    if (distance <= m * m) return true;
    else return false;
}

bool isSafe(int i) {
    // if ((-30 < V[i]->x < 30) && (-30 < V[i]->y < 30)){
    if (V[i]->x > (-50 + m) && V[i]->x < (50 - m) && V[i]->y >(-50 + m) && V[i]->y < (50 - m)){
       // cout << V[i]->x << " " <<V[i]->y << endl;
        return false;
    }
    else return true;
}


// 判断第一跳能不能跳过去
bool FirstJump(Crocodile pNode) {
    int temp = pNode->x * pNode->x + pNode->y * pNode->y;
    if (temp <= (m + 7.5) * (m + 7.5)) return true;
    else return false;
}

