1. Initialization:

n and m are the number of rows and columns in the matrix, respectively.
Four boundary variables are defined:
top: Tracks the topmost row of the remaining matrix to traverse.
bottom: Tracks the bottommost row of the remaining matrix to traverse.
left: Tracks the leftmost column of the remaining matrix to traverse.
right: Tracks the rightmost column of the remaining matrix to traverse.
ans: A vector to store the elements of the matrix in spiral order.

2. While Loop Condition:
The loop runs as long as the boundaries do not cross each other:

left <= right: Ensures there are still columns left to traverse.
top <= bottom: Ensures there are still rows left to traverse.

3. Traversal Logic:
Inside the loop, the traversal happens in four steps (corresponding to the four directions: left-to-right, top-to-bottom, right-to-left, and bottom-to-top):

a. Left-to-Right Traversal (Top Row):
Traverse the elements of the top row from left to right.
Add these elements to the ans vector.
Increment top to mark that the top row has been processed.

b. Top-to-Bottom Traversal (Right Column):
Traverse the elements of the right column from top to bottom.
Add these elements to the ans vector.
Decrement right to mark that the rightmost column has been processed.

c. Right-to-Left Traversal (Bottom Row, if applicable):
Check if top <= bottom to ensure there are still rows left to process.
Traverse the elements of the bottom row from right to left.
Add these elements to the ans vector.
Decrement bottom to mark that the bottom row has been processed.

d. Bottom-to-Top Traversal (Left Column, if applicable):
Check if left <= right to ensure there are still columns left to process.
Traverse the elements of the left column from bottom to top.
Add these elements to the ans vector.
Increment left to mark that the leftmost column has been processed.

4. Return the Result:
Once all rows and columns are processed (left > right or top > bottom), the loop terminates, and the function returns the ans vector containing the spiral order of the matrix.


vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int top=0;
        int bottom=n-1;
        int left=0;
        int right=m-1;
        vector<int>ans;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
            }
            if(right>=left){
            for(int i=bottom;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
            }
        }
        return ans;
    }
