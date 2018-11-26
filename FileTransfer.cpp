//
// Created by allenhsu on 2018/11/24.
//

#include <iostream>
using namespace std;
// 找到X的根节点
int Find(int S[], int X){
    for (; S[X] >= 0; X = S[X]);
    return X;
}

void Union(int S[], int Root1, int Root2){
    if (S[Root1] > S[Root2]){
        S[Root1] = Root2;
    }else {
        if (S[Root1] == S[Root2]) S[Root1]--;
        S[Root2] = Root1;
    }
}

void Input_connection(int S[]){
    int u, v;
    int root1, root2;
    cin >> u >> v;
    root1 = Find(S, u-1);
    root2 = Find(S, v-1);
    if (root1 != root2){
        Union(S, root1, root2);
    }
}

void Check_connection(int S[]){
    int u, v;
    cin >> u >> v;
    int root1, root2;
    root1 = Find(S, u-1);
    root2 = Find(S, v-1);
    if (root1 != root2){
        cout << "no" << endl;
    }else cout << "yes" << endl;
}

int Check_network(int S[], int n){
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (S[i] < 0) count++;
    }
    if (count == 1) cout << "The network is connected." << endl;
    else cout << "There are " << count << " components." << endl;

    return 0;
}
int main(){
    int n;
    cin >> n;
    int S[10000];
    for (int i = 0; i < n; ++i) {
        S[i] = -1;
    }
    char in = '\0';
    while (in != 'S'){
        cin >> in;
        switch (in){
            case 'I': Input_connection(S); break;
            case 'C': Check_connection(S); break;
            case 'S': Check_network(S, n); break;
        }
    }
    return 0;
}