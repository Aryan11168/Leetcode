class Solution {
public:
    void dfs(string word,string &beginWord,unordered_map<string,vector<string>>& adj,vector<string>& temp,vector<vector<string>>& ans){
        temp.push_back(word);
        if(word==beginWord){
            vector<string> v=temp;
            reverse(v.begin(),v.end());
            ans.push_back(v);
            temp.pop_back();
            return;
        }
        for(auto i:adj[word]){
            dfs(i,beginWord,adj,temp,ans);
        }
        temp.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord,string endWord,vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());

        if(st.find(endWord)==st.end()) return {};

        unordered_map<string,int> level;
        unordered_map<string,vector<string>> adj;

        queue<string> q;
        q.push(beginWord);
        level[beginWord]=0;

        while(!q.empty()){
            string word=q.front();
            q.pop();

            string temp=word;

            for(int i=0;i<word.size();i++){
                char ch=temp[i];

                for(char c='a';c<='z';c++){
                    temp[i]=c;

                    if(st.find(temp)==st.end()) continue;

                    if(level.find(temp)==level.end()){
                        level[temp]=level[word]+1;
                        q.push(temp);
                        adj[temp].push_back(word);
                    }
                    else if(level[temp]==level[word]+1){
                        adj[temp].push_back(word);
                    }
                }

                temp[i]=ch;
            }
        }

        vector<vector<string>> ans;

        if(level.find(endWord)==level.end()) return ans;

        vector<string> temp;
        dfs(endWord,beginWord,adj,temp,ans);

        return ans;
    }
};