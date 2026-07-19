class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int>taken(26,false);
        vector<int>lastIndex(26,0);
        string result= "";
        for(int i=0;i<n;i++)
            lastIndex[s[i] - 'a']=i;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(taken[ch-'a'])continue;
            while(result.size()>0 && result.back()>ch && lastIndex[result.back()-'a']>i){
                taken[result.back()-'a'] = false;
                result.pop_back();
            }
            result+=ch;
            taken[ch-'a']=true;
        }
    return result;  
    }
};