class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        int n=list1.size();
        int m=list2.size();
        int least=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(list1[i]==list2[j]){
                    if(i+j==least){
                        ans.push_back(list1[i]);
                    }
                    else if(i+j<least){
                        least=i+j;
                        vector<string> temp;
                        ans=temp;
                        ans.push_back(list1[i]);
                    }
                }
            }
        }
        return ans;
    }
};