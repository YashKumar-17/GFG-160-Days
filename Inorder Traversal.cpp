 ### **Intuition & Approach**  

This code performs an **inorder traversal** of a **binary tree**, which means visiting nodes in the **left-root-right** order.  

#### **Steps:**  
1. **Base Case:** If the current node (`root`) is `nullptr`, return.  
2. **Recursive Left Traversal:** First, traverse the left subtree (`inorder(root->left, ans)`).  
3. **Visit Root Node:** Store the current node’s value (`ans.push_back(root->data)`).  
4. **Recursive Right Traversal:** Finally, traverse the right subtree (`inorder(root->right, ans)`).  
5. **Wrapper Function:** `inOrder(root)` initializes the `ans` vector and calls the helper function `inorder()`, then returns the result.  

### **Result:**  
This returns a **sorted sequence of node values** if the given tree is a **Binary Search Tree (BST)**.

void inorder(Node* root, vector<int> &ans){
    if(root == nullptr){
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
