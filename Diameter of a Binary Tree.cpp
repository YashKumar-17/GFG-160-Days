### **Approach & Intuition**  

1. **Recursive Height Calculation**  
   - A helper function `height(root, diameter)` is used to calculate the height of the tree while simultaneously updating the `diameter`.  

2. **Base Case (Stopping Condition)**  
   - If the node is `NULL`, return `0` (i.e., height of an empty tree is `0`).  

3. **Recursive Calls for Left and Right Subtrees**  
   - Compute the height of the left subtree (`lh`) and right subtree (`rh`) recursively.  

4. **Updating Diameter**  
   - At each node, the possible diameter passing through it is `lh + rh`.  
   - Update `diameter = max(diameter, lh + rh)` to keep track of the maximum diameter found.  

5. **Return Height for Parent Nodes**  
   - Return `1 + max(lh, rh)` to represent the height of the current node.  

6. **Final Diameter Calculation**  
   - The function `diameter(root)` initializes `diameter = 0`, calls `height(root, diameter)`, and returns the final computed `diameter`.  

### **Key Idea**  
The diameter of a binary tree is the **longest path between two leaf nodes**, which may or may not pass through the root. 
This approach efficiently computes it in **O(N) time** by calculating the height and diameter in a single traversal.

int diameter(Node* root) {
        // Your code here
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
    int height(Node* root, int &diameter){
        if(root==NULL){
            return 0;
        }
        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
