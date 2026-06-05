// Last updated: 5/6/2026, 5:11:00 pm
class Solution {
public:

    vector<string> ansList;
    void addAnsToList(int n , int stack, string &str ){
        if(stack < 0 || n < 0 ) return;
        if(n == 0 && stack == 0){
            ansList.push_back(str);
            return;
        }
        
        str.push_back('(');
        n = n-1;
        stack = stack+1;
        addAnsToList(n, stack, str);
        str.pop_back();
        stack = stack-1;
        n = n+1;
        str.push_back(')');
        stack = stack -1;
        addAnsToList(n, stack, str);
        str.pop_back();
        stack = stack+1;
    }

    vector<string> generateParenthesis(int n) {
        string str = "";
        addAnsToList(n, 0, str);
        return ansList;
    }
};