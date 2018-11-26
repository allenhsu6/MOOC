#include <iostream>
#include <string>
using namespace std;
#define MaxNum 64

struct TreeNode{
    int Weight = 0;
    TreeNode *Left = nullptr;
    TreeNode *Right = nullptr;
};

struct HeapNode{ // 堆
    TreeNode Data[MaxNum];
    int Size = 0;
};

HeapNode *CreateHeap(){
    HeapNode *H = new(HeapNode);
    H->Data[0].Weight = -1; // 哨兵设置为-1
    return H;
}

// 最小堆的删除
TreeNode *DeleteMin(HeapNode *H){
    int Parent = 0, Child = 0;
    TreeNode temp;
    TreeNode *MinItem = new(TreeNode);
    *MinItem = H->Data[1]; // 保存树根

    temp = H->Data[(H->Size)--]; // 拿到最后的数据，并将总容量size-1

    for (Parent = 1; Parent * 2 <= H->Size ; Parent = Child) {
        Child = Parent * 2;
        // 左右儿子都在并且左儿子比右儿子大
        if (Child != H->Size && (H->Data[Child].Weight > H->Data[Child + 1].Weight)){
            Child ++;
        }
        // 如果尾权重比左右儿子最小的那个还小， 不用改变
        if(temp.Weight <= H->Data[Child].Weight) break;
        else H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = temp;
    return MinItem;
}

// 最小堆的插入
void Insert(HeapNode *H, TreeNode *item){
    int i = 0;
    i = ++(H->Size); // i 为当前总容量
    for (; item->Weight < H->Data[i/2].Weight; i = i / 2) {
        H->Data[i] = H->Data[i/2];
    }
    H->Data[i] = *item;
}

HeapNode *ReadData(int N, HeapNode *H, int A[]){
    char s;
    int value;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        cin >> value;
        A[i] = value;
        TreeNode* T = new(TreeNode);
        T->Weight = value;
        Insert(H, T);
    }
    return H;
}
// 下面构造哈夫曼树的过程是一个由Heap变哈夫曼树的过程
TreeNode *Huffman(HeapNode *H){
    TreeNode *T = nullptr;
    int num = H->Size;
    // 两两合并，必定是进行n - 1次
    for (int i = 0; i < num - 1; ++i) {
        T = new(TreeNode);
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight;
        Insert(H, T);
    }
    T = DeleteMin(H);
    return T;
}

// 计算Huffman树的权重
int WPL(TreeNode *H, int n){
    if (!H->Right) return H->Weight * n;
    else return WPL(H->Left, n + 1) + WPL(H->Right, n + 1);
}

struct JNode{
    // 每个点非0即1 flag为1代表这里已经有一个前辈住进去了只要我完全走了前辈走的路，就重复出现
    int Flag = 0;
    JNode *Left = nullptr;
    JNode *Right = nullptr;
};

// 判断编码是否符合前缀码要求
bool Judge(string s, JNode *J){
    int i = 0;
    for (; i < s.length(); ++i) {
        if (s[i] == '0'){
            if (J->Left == nullptr){
                JNode *j = new(JNode);
                J->Left = j;
            }else{
                if (J->Left->Flag == 1){
                    return false;
                }
            }
            J = J->Left;
        }else{
            if (J->Right == nullptr){
                JNode *j = new(JNode);
                J->Right = j;
            }else{
                if (J->Right->Flag == 1){
                    return false;
                }
            }
            J = J->Right;
        }
    }
    J->Flag = 1;
    if (J->Left == nullptr && J->Right == nullptr){
        return true;
    }else return false;
}

int main(){
    int N = 0, n = 0;
    cin >> N;
    HeapNode *H = CreateHeap();
    int Value[MaxNum] = {};
    ReadData(N, H, Value);
    TreeNode *T = Huffman(H);
    int CodeLen = WPL(T, 0);
    cin >> n;

    string temp;
    char c;
    bool result;
    for (int i = 0; i < n; ++i) {
        int count = 0, flag = 0;
        JNode *J = new(JNode);
        for (int j = 0; j < N; ++j) {
            cin >> c >> temp;
            count += temp.length() * Value[j]; // 这就是Value的作用啊
            // 开始判断是否符合前缀码要求
            if (!flag){
                result = Judge(temp, J);
                if (!result) {
                    flag = 1;
                }
            }
        }
        delete J;
        if (result && count == CodeLen){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}