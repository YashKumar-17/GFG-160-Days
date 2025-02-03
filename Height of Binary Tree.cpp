 ### **Intuition & Approach**  

1. **Base Case (Leaf Nodes & NULL)**:  
   - If the node is `NULL`, return `-1` (height of an empty tree is conventionally `-1`).  
   - This ensures that the recursion stops at leaf nodes.  

2. **Recursive Computation**:  
   - Recursively calculate the height of the left and right subtrees.  
   - The height of a node is determined by taking the maximum of its left and right subtree heights.  

3. **Final Height Calculation**:  
   - Add `1` to account for the current node in the height computation.  
   - This ensures the correct height is returned up the recursive calls.  

4. **Why It Works**:  
   - The recursion ensures that all nodes are visited.  
   - The `max(left, right) + 1` correctly counts the longest path from root to leaf.  
   - Since we go bottom-up, we get the correct height for each subtree before computing the root height.

int height(Node* node) {
        // code here
        if(node==NULL){
            return -1;
        }
        int left=height(node->left);
        int right=height(node->right);
        return 1+ max(left,right);
    }
