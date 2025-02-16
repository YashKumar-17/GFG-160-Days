### **Intuition & Approach for Finding LCA in a BST**  

The given function finds the **Lowest Common Ancestor (LCA)** of two nodes (`n1` and `n2`) in a **Binary Search Tree (BST)**. The approach leverages BST properties to efficiently locate the LCA.  

### **Approach (Step-by-Step)**  

1. **Start from the root**  
   - We compare `root->data` with `n1->data` and `n2->data`.

2. **Move to the right subtree if both nodes are greater than root**  
   - If `n1->data > root->data` **and** `n2->data > root->data`, LCA must be in the **right subtree**.  
   - Recursively call `LCA(root->right, n1, n2)`.

3. **Move to the left subtree if both nodes are smaller than root**  
   - If `n1->data < root->data` **and** `n2->data < root->data`, LCA must be in the **left subtree**.  
   - Recursively call `LCA(root->left, n1, n2)`.

4. **If the root splits the nodes (one in the left, one in the right)**  
   - This means the **current root** is the LCA because it's the first common ancestor where the paths to `n1` and `n2` diverge.  

### **Time Complexity:**  
- Since we are only traversing down the BST, the time complexity is **O(h)**, where **h** is the height of the tree.  
- In a balanced BST, this is **O(log N)**, and in the worst case (skewed tree), it is **O(N)**.

Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        int curr=root->data;
        if(curr<n1->data && curr<n2->data){
            return LCA(root->right,n1,n2);
        }
        else if(curr>n1->data && curr>n2->data){
            return LCA(root->left,n1,n2);
        }
        return root;
    }
