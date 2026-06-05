// Last updated: 5/6/2026, 5:08:09 pm
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();

        set<int> one,two,intsection;
        
        for(int i=0;i<n;++i){
            string s = to_string(arr1[i]);
            int len = s.size();
            string tem = "";
            for(int j=0;j<len;++j){
                tem+=s[j];
                int num = stoi(tem);
                one.insert(num);
            }
        }

        for(int i=0;i<m;++i){
            string s = to_string(arr2[i]);
            int len = s.size();
            string tem = "";
            for(int j=0;j<len;++j){
                tem+=s[j];
                int num = stoi(tem);
                two.insert(num);
            }
        }

        set_intersection(one.begin(),one.end(),two.begin(),two.end(),inserter(intsection,intsection.begin()));

        if(intsection.empty()) return 0;
        else return to_string(*(intsection.rbegin())).size();

    }
};