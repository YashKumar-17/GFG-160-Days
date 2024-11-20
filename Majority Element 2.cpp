Approach
The goal is to identify elements that appear more than (n/3) times in the array. At most, there can be two such elements, because if there were three or more, their combined frequency would exceed the size of the array.

Step 1: Candidate Selection (First Pass)
Key Idea:

Use two variables (el1 and el2) to track potential majority candidates.
Use two counters (ct1 and ct2) to track the frequency of these candidates.
Iterate through the array, updating candidates and their counts based on the following rules:
If ct1 == 0 and the current element is not el2, assign the element to el1 and reset ct1 to 1.
Else if ct2 == 0 and the current element is not el1, assign the element to el2 and reset ct2 to 1.
Else if the current element matches el1 or el2, increment ct1 or ct2 respectively.
Otherwise, decrement both ct1 and ct2 (to "vote out" non-majority elements).
Why this works:

By the end of this step, el1 and el2 will contain the most likely candidates for elements appearing more than n/3 times.
Step 2: Verification (Second Pass)
Key Idea:

After identifying potential candidates, iterate through the array again to verify their actual frequencies.
Count how many times el1 and el2 appear in the array.
Criteria: If the frequency of el1 or el2 is greater than n/3. include it in the result.
Step 3: Return the Result
Sort the Result:

Since the problem might require the result in sorted order, sort the final list of majority elements before returning.
Edge Cases:

If no elements satisfy the majority condition, return an empty list.

vector<int> findMajority(vector<int>& arr) {
        // Your code goes here.
        int ct1=0;
        int ct2=0;
        int el1;
        int el2;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(ct1==0 && arr[i]!=el2){
                ct1=1;
                el1=arr[i];
            }
            else if(ct2==0 && arr[i]!=el1){
                ct2=1;
                el2=arr[i];
            }
            else if(arr[i]==el1){
                ct1++;
            }
            else if(arr[i]==el2){
                ct2++;
            }
            else{
                ct1--;
                ct2--;
            }
            
        }
        ct1=0;
        ct2=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i]==el1){
                ct1++;
            }
            else if(arr[i]==el2){
                ct2++;
            }
           
        }
         if(ct1>n/3){
            ans.push_back(el1);
        }
        if(ct2>n/3){
            ans.push_back(el2);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
