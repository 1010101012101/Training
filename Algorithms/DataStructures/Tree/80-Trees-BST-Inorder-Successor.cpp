#include <stdio.h>
#include <iostream>
#include<queue>
using namespace std;

struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
    
};

BstNode* GetNewNode( int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

BstNode* Insert( BstNode* root, int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }
    else if( data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}



bool Search(BstNode* root, int data)
{
    if(root == NULL) return false;
    if(data == root->data)
    {
        return true;
        
    }
    else if(data <= root->data)
    {
        return Search(root->left, data);
        
    }
    else
    {
        return Search(root->right, data);
        
    }
    
}

int FindMin(BstNode* root)
{
    if( root == NULL)
    {
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    else
    {
        return FindMin(root->left);
    }
}

int FindMax(BstNode* root)
{
    if( root == NULL)
    {
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return FindMax(root->right);
    }
}

int FindHeight(BstNode* root)
{
    if( root == NULL)
    {
        return -1;
    }
    return max( FindHeight(root->left), FindHeight(root->right)  ) +1;
}

void LevelOrder(BstNode* root)
{
    if(root == NULL) return;
    queue<BstNode*> Q;
    Q.push(root);
    //while there is atleast one discovered node
    while(!Q.empty())
    {
        BstNode* current = Q.front();
        cout << current->data << " ";
        if(current->left != NULL) Q.push(current->left);
        if(current->right != NULL) Q.push(current->right);
        Q.pop();  //removing the element at front
        
    }
}

void preorder(BstNode* root)
{
    if( root ==NULL) return;
    printf("%d ", root->data);
    preorder( root->left);
    preorder(root->right);
}

void Inorder(BstNode* root)
{
    if( root ==NULL) return;
    Inorder( root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Postorder(BstNode* root)
{
    if( root ==NULL) return;
    Postorder( root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

bool IsBinarySearchTree(BstNode* root, int minvalue, int maxvalue)
{
    if(root == NULL) return true;
    
    if(root->data > minvalue
    && root->data < maxvalue
    && IsBinarySearchTree(root->left, minvalue, root->data)
    && IsBinarySearchTree(root->right, root->data, maxvalue))
    return true;
    else
    return false;
    
}

//Function to find minimum in a tree. 
BstNode* FindMinNode(BstNode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

BstNode* Delete( BstNode* root, int data)
{
    if(root == NULL) return root;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else  //wohoo...I found you, Get ready to be deleted
    {
        //case1: No Child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
           
        }
        //case 2: One Child
        else if(root->left == NULL)
        {
            BstNode* temp = root;
            root = root->right;
            delete temp;
           
        }
         else if(root->right == NULL)
        {
            BstNode* temp = root;
            root = root->left;
            delete temp;
            
        }
        //case 3: 2 Children
        else
        {
            BstNode* temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
    
}

//Function to find some data in the tree
BstNode* Find(BstNode*root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}

//Function to find Inorder Successor in a Bst
BstNode* GetSuccessor(BstNode* root, int data)
{
    //search the Node - o(h)
    BstNode* current = Find(root, data);
    if(current == NULL) return NULL;
    if(current->right != NULL)  //Case 1: Node has right sub tree
    {
        return FindMinNode(current->right);  //o(h)
    }
    else   //case 2: No right subtree  - o(h)
    {
        BstNode* successor = NULL;
        BstNode* ancestor = root;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;  //so far this is the deepest node for which current node is left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        
        return successor;
            
            
    }
}



int main()
{
    BstNode * root = NULL;
    
    root = Insert(root, 500);
    root = Insert(root, 50);
    root = Insert(root, 5);
    root = Insert(root, 55);
    root = Insert(root, 10);
    root = Insert(root, 8000);
    root = Insert(root, 60);
    root = Insert(root, 160);
    root = Insert(root, 760);
    root = Insert(root, 260);
    
    
     int number;
     cout << "Enter the Number to be searched: \n";
     cin >> number;
     
    if(Search(root, number) == true)
        cout << "found\n";
    else
        cout << "False\n";
    
    int min = FindMin(root);
    cout << "Minimum: " << min << "\n";
    
    int max = FindMax(root);
    cout << "Maximum: " << max << "\n";
    
    int height = FindHeight(root);
    cout << "Height: " << height << "\n";
    
    cout << "Level-order: ";
    LevelOrder(root);
    cout <<endl;
    
    cout << "Pre-order: ";
    preorder(root);
    cout <<endl;
    
    cout << "In-order Binary Search Tree: ";
    cout <<endl;
    cout << "In-order: ";
    Inorder(root);
    cout <<endl;
    
    cout << "Post-order: ";
    Postorder(root);
    cout <<endl;
    
    
    bool isBST =-1;
    isBST = IsBinarySearchTree(root, -10000, 10000);
    
    cout << " IsBinarySearchTree: "<< isBST << endl;
    
    
    Delete( root, 160);
    
    cout << "In-order Binary Search Tree After Delete: ";
    cout <<endl;
    cout << "In-order: ";
    Inorder(root);
    cout <<endl;
    
    
    BstNode* temp1 = GetSuccessor(root,10);
    
    cout << "GetSuccessor 10 is : " << temp1->data ;
    
    return 0;
}

/*
#include <stdio.h>
#include<iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode * left;
    BstNode* right;
};

BstNode* GetNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* Insert( BstNode* root, int data)
{
    if(root == NULL)  //empty node
    {
        root = GetNode(data);
    }
    else if( data <= root-> data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root, int data )
{
    if( root == NULL) return false;
    if(root->data == data) return true;
    else if(data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
    
}

int main()
{
    BstNode* root = NULL;
    
     root = Insert(root,15);     root = Insert(root,10);     root = Insert(root,20);
     root = Insert(root,25);     root = Insert(root,8);     root = Insert(root,12);
     
     int number;
     cout << "Enter the Number to be searched: \n";
     cin >> number;
     
    if(Search(root, number) == true)
        cout << "found\n";
    else
        cout << "False\n";
        
     
    
    printf("Hello World");

    return 0;
}
*/





