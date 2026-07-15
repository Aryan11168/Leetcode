class StockSpanner {
public:
    stack<pair<int, int>> stk;
    int day;
    StockSpanner() {
        day = 0;
    }
    int next(int price) {
        int res = 1;
        while (!stk.empty() && stk.top().first <= price) {
            stk.pop();
        }
        if (!stk.empty()) {
            res =  day - stk.top().second;
        }
        else {
            res = day + 1; 
        }
        stk.push({price, day++});
        return res;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// class StockSpanner {
// public:
//     vector<int> nums;
//     StockSpanner() { // constructor - value initialise
//         nums.clear();
//     }
//     // 60,70,60,80,100,70,75
//     int find(){
//         int cnt=0;
//         int n=nums.size();
//         int i=n-1;
//         while(i>=0){
//             if(nums[i]<=nums[n-1]) cnt++;
//             else break;
//             i--;
//         }
//         return cnt;
//     }
//     int next(int price) {
//         nums.push_back(price);
//         return find();
//     }
// };
// class StockSpanner {
// public:
//     vector<int> nums;
//     StockSpanner() { // constructor - value initialise
//         nums.clear();
//     }
//     int next(int price) {
//         nums.push_back(price);
//         // idhar code likh
//         vector<int> arr=nums;
//         int n=arr.size();
//       vector<int>v;
//       stack<pair<int,int>>st;
//       //to find previous greater element
//     for(int i=0; i<n; i++){  //tarversing left to right
//        if(st.size()==0) v.push_back(-1);
//        //if non empty and greater milgya
//        else if(st.size()>0 && st.top().first>arr[i]) v.push_back(st.top().second);
//        //if non empty but greater nhi mila
//        else if(st.size()>0 &&  st.top().first<=arr[i]){
//           //pop karte jao
//           while(!st.empty() && st.top().first<=arr[i]) st.pop();
//           if(st.empty()) v.push_back(-1);  //agar khali hogya
//           else v.push_back(st.top().second);  //greater milgya
//        }
//        st.push({arr[i],i});
//     }
//     for(int i=0; i<n; i++){
//         v[i]=i-v[i];
//     }
//     return v.back();
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