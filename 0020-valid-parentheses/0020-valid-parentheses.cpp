class Solution {
public:
    bool isValid(string s) {
        stack <char> a;
        for(auto i:s){
            if(i==')'){
                if(a.empty() || a.top()!='(') return 0;
                a.pop();
            }
            else if(i==']'){
                if(a.empty() || a.top()!='[') return 0;
                a.pop();
            }
            else if(i=='}'){
                if(a.empty() || a.top()!='{') return 0;
                a.pop();
            }
            else a.push(i);
        }
        if(a.empty())
        return 1;
        else return 0;
    }
};