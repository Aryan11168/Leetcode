class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> digsum(n,0);
        for(int i=0;i<n;i++){
            int t=nums[i];
            int sum=0;
            while(t>0){
                sum+=t%10;
                t/=10;
            }
            digsum[i]=sum;
        }
        vector<int> indicies(n);
        iota(indicies.begin(),indicies.end(),0);
        sort(indicies.begin(),indicies.end(),[&](int a,int b){
            if(digsum[a]==digsum[b]){
                return nums[a]<nums[b];
            }
            return digsum[a]<digsum[b];
        });
        vector<int> targetpos(n);
        for(int pos=0;pos<n;pos++){
            targetpos[indicies[pos]]=pos;
        }
        vector<int> visited(n);
        int cycles = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cycles++;
                int j=i;
                while(!visited[j]){
                    visited[j]=true;
                    j=targetpos[j];
                }
            }
        }
        return n-cycles;
        
    }
};