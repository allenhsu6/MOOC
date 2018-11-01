//
// Created by allenhsu on 2018/10/31.
//

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;
// 传入后序序列的引用 核心代码！
void getPostOrder(vector<int> preOrder, int preL, vector<int> inOrder,
                  int inL, vector<int> &postOrder, int postL, int n){
    // 使用递归第一步需要设定跳出边界
    if (n == 0) return;
    if (n == 1) {
        postOrder[postL] = preOrder[preL];
        return;
    }
    auto root = preOrder[preL];
    postOrder[postL + n -1] = root;
    int i =0;
    // 这里 i 的位置是inOrder的root的位置，要按照这个root左右分开为Left和right，然后进行递归求解
    for (; i < n; ++i) {
        if (inOrder[inL + i] == root) break;  //
    }
    int L = i, R = n - i - 1;
    getPostOrder(preOrder, preL + 1, inOrder, inL, postOrder, postL, L);
    getPostOrder(preOrder, preL + L + 1, inOrder, inL + L + 1, postOrder, postL + L, R);

}

/**
 * 根据输入返回前序和中序遍历vertor
 * @param N 该二叉树的节点个数
 * @return 返回两个vertor序列
 */
vector<vector<int>> getOrder(int N){
    vector<int> preOrder(N, 0);
    vector<int> inOrder(N, 0);
    stack<int> s;
    int preL = 0, inL = 0;
    for (int i = 0; i < 2 * N; ++i) {
        string str;
        int tmp;
        cin >> str;
        if (str == "Push"){     // str可以直接比较
            cin >> tmp;
            s.push(tmp);
            preOrder[preL++] = tmp;
        } else if (str == "Pop"){
            inOrder[inL++] = s.top();   // top 返回栈顶元素
            s.pop();
        }
    }
    return {preOrder, inOrder};     // 返回数组vector
}

int main(){
    int N;
    cin >> N;
    auto order = getOrder(N);
    vector<int> postOrder(N,0); // 初始化动态数组要指明参数
    getPostOrder(order[0], 0, order[1], 0, postOrder, 0, N);

    int i = 0;
    for (; i < N - 1; ++i) {
        cout << postOrder[i] << " ";
    }
    cout << postOrder[i] << endl;
    return 0;
}