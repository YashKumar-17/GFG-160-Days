    ### **Intuition & Approach**  
This code corrects a **BST (Binary Search Tree)** where exactly **two nodes have been swapped by mistake**. The goal is to identify and swap them back to restore the BST properties.

### **Steps to Correct the BST:**
1. **Inorder Traversal:** Since an in-order traversal of a BST should give sorted values, we traverse the tree and compare adjacent nodes.
2. **Identify Swapped Nodes:**  
   - If a node’s value is **less than** the previous node’s value (`prev->data`), it indicates an anomaly.  
   - The first occurrence identifies **first and middle** nodes.  
   - The second occurrence identifies the **last node**.
3. **Swap to Fix BST:**  
   - If **two non-adjacent nodes** are swapped → swap `first` and `last`.  
   - If **two adjacent nodes** are swapped → swap `first` and `middle`.

This efficiently restores the BST in **O(n) time** using **O(1) extra space**, apart from recursion.

Node* prev;
    Node* first;
    Node* middle;
    Node* last;
    void inorder(Node* node){
        if(node==NULL){
            return;
        }
        inorder(node->left);
        if(node->data<prev->data){
            if(first==NULL){
                first=prev;
                middle=node;
            }
            else{
                last=node;
            }
        }
        prev=node;
        inorder(node->right);
    }
    void correctBST(Node* root) {
        // add code here.
        first=NULL;
        middle=NULL;
        last=NULL;
        prev= new Node(INT_MIN);
        inorder(root);
        if(first!= NULL && last!=NULL){
            swap(first->data,last->data);
        }
        else{
            swap(first->data, middle->data);
        }
    }
