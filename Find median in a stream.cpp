### **Intuition**  
The goal is to maintain a dynamic stream of numbers and compute the median after each insertion. Using two heaps (one max-heap and one min-heap) ensures efficient median computation.  

### **Approach**  
1. **Use two heaps**:  
   - **Left max-heap** (stores the smaller half of numbers).  
   - **Right min-heap** (stores the larger half of numbers).  
2. **Insert a new number**:  
   - Push it into the **left max-heap**.  
   - Move the **top element** of the left max-heap to the **right min-heap** (to balance both halves).  
   - If the right min-heap has **more elements**, move its top back to the left max-heap (to maintain balance).  
3. **Find the median**:  
   - If the heaps are **unequal**, the top of the left max-heap is the median.  
   - If the heaps are **equal**, the median is the average of the two tops.  
4. **Store the median** in the result vector after each insertion.  

### **Time Complexity**  
- **O(n log n)** (each insertion in a heap takes O(log n)).  
### **Space Complexity**  
- **O(n)** (for storing medians and maintaining heaps).

vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int>leftmaxheap;
        priority_queue<int,vector<int>,greater<int>>rightminheap;
        vector<double>ans;
        for(int i=0;i<arr.size();i++){
            leftmaxheap.push(arr[i]);
            
            int ele=leftmaxheap.top();
            rightminheap.push(ele);
            leftmaxheap.pop();
            
            if(rightminheap.size()>leftmaxheap.size()){
                int ele=rightminheap.top();
                leftmaxheap.push(ele);
                rightminheap.pop();
            }
            double median;
            if(leftmaxheap.size()!=rightminheap.size())
            median=leftmaxheap.top();
            else
            median=(double)(leftmaxheap.top()+rightminheap.top())/2;
            ans.push_back(median);
        }
        return ans;
    }
