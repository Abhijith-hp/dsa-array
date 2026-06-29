class Solution {
public:
    bool isSubstring(string word,string pattern){
        int m = word.size();
        int n = pattern.size();
        for(int i=0;i<=m-n;i++){
            int j=0;
            while(j<n && word[i+j]==pattern[j]){
                j++;
                if(j==n)return true;
            }
        }
    return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(string s:patterns){
            if(isSubstring(word,s)) count++;
        }
    return count;
    }
};