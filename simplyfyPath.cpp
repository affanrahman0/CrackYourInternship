class Solution {
public:
    string simplifyPath(string path) {
        stringstream s(path);
        string ans,temp;
        vector<string> a;
        
        while(getline(s,temp,'/'))
        {
            if(temp == "" or temp ==".") continue;
            if(temp == ".." and !a.empty()) a.pop_back();
            else if(temp != "..") a.push_back(temp);
        }
        for(auto i: a) ans+= "/" + i;
        return ans.empty()? "/" : ans;
        
        
    }
};