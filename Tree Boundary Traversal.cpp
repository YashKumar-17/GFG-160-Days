### **Intuition & Approach**  

This code performs a **boundary traversal** of a binary tree, capturing nodes in a specific order:  
1. **Left Boundary:** Traverse from the root down to the leftmost node, storing non-leaf nodes.  
2. **Leaf Nodes:** Collect all leaf nodes using a helper function (`helper`).  
3. **Right Boundary (Reverse Order):** Traverse from the rightmost node up to the root, storing non-leaf nodes in reverse order.  

### **Step-by-Step Execution**  
1. **Left Boundary Traversal:**  
   - Traverse down the left subtree (or right if left is missing).  
   - Mark visited nodes by setting `data = -1`.  

2. **Leaf Node Collection (Helper Function):**  
   - Recursively collect all leaf nodes and mark them as visited.  

3. **Right Boundary Traversal (Reverse Order):**  
   - Traverse down the right subtree (or left if right is missing).  
   - Store nodes but later **reverse** them before appending.  

4. **Final Output:**  
   - Combines left boundary, leaf nodes, and reversed right boundary to form the boundary traversal.  

This ensures an **anti-clockwise** traversal of the tree's boundary.

void helper(Node* root,vector<int>&v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(root->data!=-1) v.push_back(root->data);
            root->data=-1;
            return;
        }
        helper(root->left,v);
        helper(root->right,v);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        Node* temp=root;
        while(temp){
            ans.push_back(temp->data);
            temp->data=-1;
            if(temp->left==NULL && temp!=root) temp=temp->right;
            else temp=temp->left;
        }
        helper(root,ans);
        int l=ans.size();
        temp=root;
        temp=temp->right;
        while(temp && temp->data!=-1){
            ans.push_back(temp->data);
            temp->data=-1;
            if(temp->right==NULL) temp=temp->left;
            else temp=temp->right;
        }
        if(l>=ans.size()) return ans;
        int r=ans.size()-1;
        while(l<r){
            swap(ans[l],ans[r]);
            l++;
            r--;
        }
        return ans;
    }
