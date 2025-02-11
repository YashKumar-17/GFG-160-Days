### **Intuition & Approach:**  

1. **Problem Understanding:** Check if a given binary tree is a **Binary Search Tree (BST)** where for every node:  
   - Left subtree values must be **less** than the node's value.  
   - Right subtree values must be **greater** than the node's value.  

2. **Recursive Validation Using a Range:**  
   - Start with a valid range: **(INT_MIN, INT_MAX)**.  
   - For each node:  
     - Ensure its value lies within the range.  
     - Recursively check left subtree with **updated max** (`node->data`).  
     - Recursively check right subtree with **updated min** (`node->data`).  

3. **Base Case:** If the node is `NULL`, return `true` (an empty tree is a BST).  

4. **Final Check:** Return the result of the recursive function for the root node.  

### **Why This Works Efficiently?**  
✅ Uses **range-based validation** instead of naive **inorder traversal**, ensuring **O(N) time complexity**.

 bool check(Node* node, int maxi, int mini){
         if(node==NULL){
            return true;
        }
        if(node->data >= maxi || node->data <=mini){
            return false;
        }
        return check(node->left,node->data,mini) && check(node->right,maxi,node->data);
       
    }
    bool isBST(Node* root) {
        // Your code here
        return check(root,INT_MAX,INT_MIN);
       
    }
