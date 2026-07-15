class StockSpanner {
public:
    vector<int> nums;
    StockSpanner() { // constructor - value initialise
        nums.clear();
    }
    // 60,70,60,80,100,70,75
    int find(){
        int cnt=0;
        int n=nums.size();
        int i=n-1;
        while(i>=0){
            if(nums[i]<=nums[n-1]) cnt++;
            else break;
            i--;
        }
        return cnt;
    }
    int next(int price) {
        nums.push_back(price);
        return find();
    }
};
// class StockSpanner {
// public:
//     vector<int> nums;
//     StockSpanner() { // constructor - value initialise
//         nums.clear();
//     }
//     int next(int price) {
//         nums.push_back(price);
//         // idhar code likh
//         int n= //size of given arr of stocks
//       vector<int>v;
//       stack<pair<int,int>>st;
//       //to find previous greater element
//     for(int i=0; i<n; i++){  //tarversing left to right
//        if(st.size()==0) v.push_back(-1);
//        //if non empty and greater milgya
//        else if(st.size!=0 && st.top()>arr[i]) v.push_back(st.top.first());
//        //if non empty but greater nhi mila
//        else if(st.size()!=0; &&  st.top()<=arr[i]){
//           //pop karte jao
//           while(!st.epmty() && st.top()<=arr[i]) st.pop();
//           if(st.empty()) v.push_back(-1);  //agar khali hogya
//           else v.push_back(st.top.first());  //greater milgya
//        }
//        st.push({arr[i],i});
//     }
//     for(int i=0; i<n; i++){
//         v[i]=i-v[i];
//     }
//     return v;
//     }
// };


// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */
//     int n= //size of given arr of stocks
//     vector<int>v;
//     stack<pair<int,int>>st;
//     //to find previous greater element
//     for(int i=0; i<n; i++){  //tarversing left to right
//        if(st.size()==0) v.push_back(-1);
//        //if non empty and greater milgya
//        else if(st.size!=0 && st.top()>arr[i]) v.push_back(st.top.first());
//        //if non empty but greater nhi mila
//        else if(st.size()!=0; &&  st.top()<=arr[i]){
//           //pop karte jao
//           while(!st.epmty() && st.top()<=arr[i]) st.pop();
//           if(st.empty()) v.push_back(-1);  //agar khali hogya
//           else v.push_back(st.top.first());  //greater milgya
//        }
//        st.push({arr[i],i});
//     }
//     for(int i=0; i<n; i++){
//         v[i]=i-v[i];
//     }
//     return v;