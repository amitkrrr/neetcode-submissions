class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto s : strs){
            int n = s.size();
            ans.push_back((char)n);
            ans+=(s);
        }

        return ans;
    }

    vector<string> decode(string s) {

        int n = s.size();
        int i = 0;
        vector<string> ans;

        while (i < n) {
            int len = (unsigned char)s[i];
            i++;

            string temp = s.substr(i, len);
            ans.push_back(temp);

            i += len;
        }

        return ans;
    }
};
