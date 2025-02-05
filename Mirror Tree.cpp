### **Intuition & Approach:**
1. **Intuition**: The goal is to convert a binary tree into its mirror image by swapping left and right children at every node.  
2. **Approach**:  
   - If the node is `NULL`, return (base case for recursion).  
   - Swap the left and right child of the current node.  
   - Recursively call `mirror()` on the left and right subtrees (which are now swapped).  
   - This ensures that the entire tree is processed in a top-down manner.  

This approach effectively swaps every node's children, creating a mirrored version of the original tree.

void mirror(Node* node) {
        // code here
         if(node==NULL){
            return;
        }
        Node* lt=node->left;
        Node* rt=node->right;
        node->left=rt;
        node->right=lt;
        mirror(lt);
        mirror(rt);
    }
