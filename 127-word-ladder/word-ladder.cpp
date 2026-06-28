class Solution {
public:
bool isDiffOne(string &a, string &b) {
    if (a.length()!=b.length()) return false;
    int diff=0;
    for (int i=0;i<a.length();i++) {
        if (a[i]!=b[i]) diff++;
        if (diff>1) return false;
    }
    return diff==1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    int n = wordList.size();
    if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
        wordList.push_back(beginWord);
    int start = -1, end = -1;
    for (int i = 0; i < wordList.size(); i++) {
        if (wordList[i] == beginWord) start = i;
        if (wordList[i] == endWord) end = i;
    }
    if (end == -1) return 0; // endWord not in list
    vector<vector<int>> adj(wordList.size());
    for (int i = 0; i < wordList.size(); i++) {
        for (int j = i + 1; j < wordList.size(); j++) {
            if (isDiffOne(wordList[i], wordList[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    queue<pair<int, int>> q; // (node, distance)
    vector<int> vis(wordList.size(), 0);
    q.push({start, 1});
    vis[start] = 1;
    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();
        if (node == end) return dist;
        for (auto neigh : adj[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push({neigh, dist + 1});
            }
        }
    }
    return 0;
}

};