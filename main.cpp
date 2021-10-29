#include <iostream>

using namespace std;

struct BiNode{
    char data;
    BiNode *lchild, *rchild;
};

class BiTree{
public:
    BiTree(){ root = Creat(); }
    ~BiTree(){ Release(root); }
    void PreOrder(){ PreOrder(root); }
    void InOrder(){ InOrder(root); }
    void PostOrder(){ PostOrder(root); }
    void LevelOrder();
private:
    BiNode *Creat();
    void Release(BiNode *bt);
    void PreOrder(BiNode *bt);
    void InOrder(BiNode *bt);
    void PostOrder(BiNode *bt);
    BiNode *root;
};

BiNode *BiTree::Creat(){
    BiNode *bt;
    char ch;
    cin >> ch;
    if(ch == '#') bt = NULL;
    else{
        bt = new BiNode;
        bt->data = ch;
        bt->lchild = Creat();
        bt->rchild = Creat();
    }
    return bt;
}

void BiTree::Release(BiNode *bt){
    if(bt == NULL) return;
    else{
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}

void BiTree::PreOrder(BiNode *bt){
    if(bt == NULL) return;
    else{
        cout << bt->data << " ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

void BiTree::InOrder(BiNode *bt){
    if(bt == NULL) return;
    else{
        PreOrder(bt->lchild);
        cout << bt->data << " ";
    PreOrder(bt->rchild);
    }
}

void BiTree::PostOrder(BiNode *bt){
    if(bt == NULL) return;
    else{
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
        cout << bt->data << " ";
    }
}

void BiTree::LevelOrder(){
    BiNode *Q[100], *q = NULL;
    int front = -1, rear = -1;
    if(root == NULL) return;
    Q[++rear] = root;
    while(front != rear){
        q = Q[++front];
        cout << q->data << " ";
        if(q->lchild != NULL) Q[++rear] = q->lchild;
        if(q->rchild != NULL) Q[++rear] = q->rchild;
    }
}

int main(){
    BiTree bt;
    // a b # d # # c # #
    bt.PreOrder();
    cout << endl;
    bt.InOrder();
    cout << endl;
    bt.PostOrder();
    cout << endl;
    bt.LevelOrder();
    return 0;
}
