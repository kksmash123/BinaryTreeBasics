// BinaryTreeBasics.cpp : 
// counting the nodes in binary tree
//finding the height of the binary tree
//


#include <iostream>
#include<queue>

using namespace std;


struct Node
{
    int data;
    struct Node* lc;
    struct Node* rc;
}*root=NULL;


queue<Node*> q;

struct Node* createNode(int x);
struct Node* createTree(int x);
void inorder(struct Node* p);
void preorder(struct Node* p);
void postorder(struct Node* p);
int countNodeTree(struct Node* p);
int countDeg2(struct Node* p);
int countLeafNode(struct Node* p);
int countDeg1(struct Node* p);
int HeightTree(struct Node* p);
int countD1D2Nodes(struct Node* p);



//function definition

struct Node* createNode(int x)
{
    struct Node* p = new Node;
    p->data = x;
    p->lc = p->rc = NULL;

    return p;
}

struct Node* createTree(int x)
{
    struct Node* root = createNode(x);

    q.push(root);

    struct Node* p;

    while (!q.empty())
    {
        p = q.front();
        cout << "left child of " << p->data << " :";
        cin >> x;
       
        if (x != -1)
        {
            p->lc = createNode(x);
            q.push(p->lc);
        }

        cout << "right child of " << p->data << " :";
        cin >> x;

        if (x != -1)
        {
            p->rc = createNode(x);
            q.push(p->rc);
        }
        q.pop();

    }
    return root;
}

void inorder(struct Node* p)
{
    if (p)
    {
        inorder(p->lc);
        cout << p->data << " ";
        inorder(p->rc);
    }
}

void preorder(struct Node* p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lc);
        preorder(p->rc);
    }
}

void postorder(struct Node* p)
{
    if (p)
    {
        postorder(p->lc);
        postorder(p->rc);
        cout << p->data << " ";
    }
}

int countNodeTree(struct Node* p)
{
    if (!p)
        return 0;

    return countNodeTree(p->lc) + countNodeTree(p->rc) + 1;
}

int countDeg2(struct Node* p)
{
    if (!p)
        return 0;

    else if (p->lc && p->rc)
        return countDeg2(p->lc) + countDeg2(p->rc) + 1;
    else
        return countDeg2(p->lc) + countDeg2(p->rc);



}

int countLeafNode(struct Node* p)
{
    if (!p)
        return 0;
    if (!p->lc && !p->rc)
        return 1;

    return countLeafNode(p->lc) + countLeafNode(p->rc);

}

int countDeg1(struct Node* p)
{
    if (!p)
        return 0;

    if (p->lc && !p->rc || p->rc && !p->lc)
        return countDeg1(p->lc) + countDeg1(p->rc) + 1;

    else
        return countDeg1(p->lc) + countDeg1(p->rc);

}

//int countDeg1XOR(struct Node* p)
//{
//    if (!p)
//        return 0;
//    if ((p->lc!=NULL) xor (p->rc!=NULL))
//        return 1;
//    return countDeg1XOR(p->lc) + countDeg1XOR(p->rc);
//
//
//}

int HeightTree(struct Node* p)
{
    int x, y;

    if (!p)
        return 0;
    
    x = HeightTree(p->lc);
    y = HeightTree(p->rc);

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int countD1D2Nodes(struct Node* p)
{
    if (!p)
        return 0;

    if (p->lc || p->rc)
    return countD1D2Nodes(p->lc) + countD1D2Nodes(p->rc)+1;

    return 0;

}



int main()
{

    root =createTree(5);

    cout << "Tree Traversal ." << endl;

    cout << "Inorder :";
    inorder(root);

    cout << endl<<"preorder : ";
    preorder(root);

    cout << endl<<"postorder : ";
    postorder(root);

    cout <<endl<< "Tree Components ." << endl;

    cout << "Total count of Nodes in a tree : " << countNodeTree(root) << endl;

    cout << "count of Degree 2 Nodes: " << countDeg2(root) << endl;

    cout << "count leaf nodes in tree : " << countLeafNode(root) << endl;

    cout << "count of Degree 1 Nodes : " << countDeg1(root) << endl;

    cout << "Height of the tree : " << HeightTree(root) << endl;

    cout << "count of Deg1 and deg2 nodes in tree : " << countD1D2Nodes(root) << endl;


    
}
