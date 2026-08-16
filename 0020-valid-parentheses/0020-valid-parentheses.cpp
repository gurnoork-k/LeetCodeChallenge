class Solution {
private:
    bool matches(char ch, char top){
        if(top == '(' && ch == ')') return true;
        else if(top == '[' && ch == ']') return true;
        else if(top == '{' && ch == '}') return true;
        else return false;
    }

public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0; i< s.length(); i++){
            char ch = s[i];
            //if opening bracket
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            //if closing bracket
            else{
                if(!st.empty()){
                    char top = st.top();
                    if(matches(ch, top)){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{return false;}
    }
};