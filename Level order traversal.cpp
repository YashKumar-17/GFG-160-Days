Approach and intuition

1. **Initialize a queue** (`q`) and push the root node into it.  
2. **Process each level** using a loop while the queue is not empty:  
   - Determine the number of nodes in the current level (`size = q.size()`).  
   - Create a temporary list (`res`) to store node values at this level.  
   - Iterate `size` times to process all nodes of the current level:  
     - Pop the front node from the queue.  
     - Push its left and right children (if they exist) into the queue.  
     - Store the node's value in `res`.  
   - Append `res` to the final answer (`ans`).  
3. **Return `ans`**, which contains node values level-wise.  

### **Intuition:**  
- You process nodes **level by level** using BFS.  
- A queue ensures that nodes are processed in the correct order.  
- `size` helps separate nodes level-wise.

 vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>res;
            for(int i=0;i<size;i++){
                Node* node=q.front();
                q.pop();
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                res.push_back(node->data);
            }
            ans.push_back(res);
        }
        return ans;
        
    }
