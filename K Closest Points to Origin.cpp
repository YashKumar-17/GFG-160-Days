### **Intuition & Approach**  

This code finds the **K closest points** to the origin (0,0) from a given list of 2D points based on their **Euclidean distance**.  

#### **Step-by-Step Approach**  
1. **Calculate Distance**:  
   - The function `ecd(x, y)` computes the **square** of the Euclidean distance (no square root needed).  

2. **Use a Max Heap (Priority Queue)**:  
   - A **max heap** is used to store the `k` closest points.  
   - Each entry in the heap stores `[distance, index]`, where:
     - `distance = x² + y²`  
     - `index` is the index of the point in the original list.  

3. **Heap Logic**:  
   - **First `k` points**: Directly pushed into the heap.  
   - **Remaining points**:  
     - If a new point has a **smaller distance** than the **farthest point** in the heap (`pq.top()`), replace it.  

4. **Extract `k` Closest Points**:  
   - Pop elements from the heap and retrieve the original points from `points[]`.  

int ecd(int x, int y){
        int ecdis = (x*x) + (y*y);
        return ecdis;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        vector<vector<int>>ans;
        priority_queue<int,vector<vector<int>>>pq;
        int psh;
        for(int i=0;i<points.size();i++){
            if(i >= k){
                psh=ecd(points[i][0],points[i][1]);
                vector<int>vec=pq.top();
                if(psh<vec[0]){
                    pq.pop();
                    vector<int>temp1(2);
                    temp1[0]=psh;
                    temp1[1]=i;
                    pq.push(temp1);
                }
            }
            else{
                vector<int>temp(2);
                psh=ecd(points[i][0],points[i][1]);
                temp[0]=psh;
                temp[1]=i;
                pq.push(temp);
            }
        }
        while(!pq.empty()){
            vector<int>tr=pq.top();
            ans.push_back(points[tr[1]]);
            pq.pop();
        }
        return ans;
    }
