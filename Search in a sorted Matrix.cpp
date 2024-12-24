Step 1: Handle Edge Cases
Check if x is smaller than the smallest element in the matrix: If x is smaller than the top-left element (mat[0][0]), return false.
Check if x is larger than the largest element in the matrix: If x is larger than the bottom-right element (mat[n−1][m−1]), return false.

Step 2: Find the Correct Row Using Binary Search
Use a binary search on the first column of the matrix to determine which row may contain x.
Initialize low as the first row index and high as the last row index.
Calculate the middle row index mid.
If the first element of the middle row equals x, return true.
If the first element of the middle row is less than x, move to rows below by setting low = mid + 1.
Otherwise, move to rows above by setting high = mid - 1.
After this search, the potential row where x might be located is determined to be the row at index high.

Step 3: Search Within the Row
Perform another binary search, this time within the identified row:
Initialize l as the first column index and h as the last column index.
Calculate the middle column index mid.
If the middle element equals x, return true.
If the middle element is less than x, search in the right half by setting l = mid + 1.
Otherwise, search in the left half by setting h = mid - 1.

Step 4: Return the Result
If x is not found after both binary searches, return false.

bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=n-1;
        if(x<mat[0][0]){
            return false;
        }
        if(x>mat[n-1][m-1]){
            return false;
        }
        int row=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mat[mid][0]==x){
                return true;
            }
            else if(mat[mid][0]<x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        int l=0;
        int h=m-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mat[high][mid]==x){
                return true;
            }
            else if(mat[high][mid]<x){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return false;
    }
