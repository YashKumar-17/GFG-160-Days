Approach in Simple Steps:
1️⃣ Loop through the intervals and decide whether to merge or add them as-is.
2️⃣ Use start and end to track the new interval boundaries.
3️⃣ Handle edge cases where no merging is needed or the interval spans till the end.
4️⃣ Return the updated list of intervals.

vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        vector<vector<int>>ans;
        int start=-1;
        int end=-1;
        int n=intervals.size();
        int cm1=newInterval[0];
        int cm2=newInterval[1];
        int fl=0;
        for(int i=0;i<n;i++){
            if(cm1<=intervals[i][0] && start==-1){
                start=cm1;
                fl=1;
            }
            else if(cm1<=intervals[i][1] && start==-1){
                start=intervals[i][0];
                fl=1;
            }
            if(fl==0){
                vector<int>temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                ans.push_back(temp);
            }
            if(start!=-1 && cm2<intervals[i][0] && fl==1){
                end=cm2;
                vector<int>temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                fl=0;
                if(fl==0){
                vector<int>temp;
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                ans.push_back(temp);
            }
            }
            else if(start!=-1 && cm2<intervals[i][1] && fl==1){
                end=intervals[i][1];
                vector<int>temp;
                temp.push_back(start);
                temp.push_back(end);
                ans.push_back(temp);
                fl=0;
            }
        }
        if(start==-1){
            vector<int>temp1;
            temp1.push_back(cm1);
            temp1.push_back(cm2);
            ans.push_back(temp1);
        }
        else if(end==-1){
            vector<int>temp1;
            temp1.push_back(start);
            temp1.push_back(cm2);
            ans.push_back(temp1);
        }
        return ans;
    
    }
