 int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n1=a.size();
        int n2=b.size();
        if(n2<n1){
            return kthElement(b,a,k);
        }
        int left=k;
        int low=max(0,k-n2);
        int high=min(k,n1);
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX;
            int r2=INT_MAX;
           if (mid1 == 0) {
                 l1 = INT_MIN; 
                 } else {
        l1 = a[mid1 - 1];
                 }

           if (mid1 == n1) {
                r1 = INT_MAX;
               } else {
             r1 = a[mid1];
               }

             if (mid2 == 0) {
               l2 = INT_MIN;
                 } else {
        l2 = b[mid2 - 1];
    }


    if (mid2 == n2) {
        r2 = INT_MAX;
    } else {
        r2 = b[mid2];
    }

    if (l1 <= r2 && l2 <= r1) {
        return max(l1, l2);
    } else if (l1 > r2) {
        high = mid1 - 1; 
    } else {
        low = mid1 + 1;
    }
        }
        return 0;
    }
