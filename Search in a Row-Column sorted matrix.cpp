 Approach (Two-pointer technique):
Initialization:

Determine the number of rows (n) and columns (m) in the matrix.
Start the search from the top-right corner of the matrix. This is done by initializing:
st = 0 (row index starts at the first row).
ed = m - 1 (column index starts at the last column).

Iterative Search:

While st < n (row index is within bounds) and ed >= 0 (column index is within bounds), perform the following checks:
Match Found:
If mat[st][ed] == x, return true as the element x is found.
Move Down:
If mat[st][ed] < x, move down to the next row (st++) because all elements in the current row to the left of mat[st][ed] are smaller than x due to row-wise sorting.
Move Left:
If mat[st][ed] > x, move left to the previous column (ed--) because all elements below mat[st][ed] in the current column are larger than x due to column-wise sorting.

Exit Condition:

If the loop exits without finding x (i.e., st >= n or ed < 0), return false.
Time Complexity:
The algorithm eliminates either a row or a column in each iteration. Therefore, in the worst case, it takes O(n+m) time, where: n is the number of rows. m is the number of columns.
Space Complexity:
The algorithm uses O(1) additional space, as the search is performed in-place with only a few variables.

bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int n=mat.size();
        int m=mat[0].size();
        int st=0;
        int ed=m-1;
        while(st<n && ed>=0){
            if(mat[st][ed]==x){
                return true;
            }
            else if(mat[st][ed]<x){
                st++;
            }
            else{
                ed--;
            }
        }
        return false;
        
    }
