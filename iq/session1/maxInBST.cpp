#include <iostream>    

using namespace std;
  
struct node {
    int data;
    struct node* left;
    struct node* right;
};
  
struct node* newNode(int data)
{
    struct node* newnode = new node();
    newnode->data = data;
    newnode->left = nullptr;
    newnode->right = nullptr;
  
    return (newnode);
}
  
struct node* insert(struct node* node, int data)
{
    if (node == nullptr)
    {
         return (newNode(data));
    }
    else {
       
        if (data <= node->data)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
  
        return node;
    }
}
  
int maxValue(struct node* node)
{   
    struct node* current = node;
    while (current->right != nullptr) 
        current = current->right;
      
    return (current->data);
}
  
int main()
{
    struct node* root = nullptr;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);
    insert(root, 9);
    insert(root, 8);
  
    cout << "Maximum value in BST is " << maxValue(root);
  
    return 0;
}