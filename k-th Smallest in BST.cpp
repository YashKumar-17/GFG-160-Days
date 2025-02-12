 ### **Intuition & Approach**  

**Intuition:**  
The code finds the **k-th smallest element** in a Binary Search Tree (BST) using an **inorder traversal** (which visits nodes in sorted order for a BST).  

**Approach:**  
1. Perform an **inorder traversal** (Left → Root → Right).  
2. Maintain a **counter (`count`)** to track visited nodes.  
3. When **`count == k`**, store the current node's value in `ans` and return.  
4. Return `ans` as the final answer.  

**Time Complexity:** \(O(k)\) (in the worst case, visiting `k` nodes).  
**Space Complexity:** \(O(H)\) (due to recursion stack, where `H` is the tree height).

void inorder(Node *node, int k, int &count, int &ans){
        if(node==NULL){
            return;
        }
        inorder(node->left,k,count,ans);
        count++;
        if(count==k){
           ans=node->data;
           return;
        }
        inorder(node->right,k,count,ans);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        int count=0;
        int ans=-1;
        inorder(root,k,count,ans);
        return ans;
    }
