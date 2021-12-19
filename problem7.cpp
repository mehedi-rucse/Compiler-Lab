#include<bits/stdc++.h>
using namespace std;

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else 
        return 0;
}
int Precedence(char ch){
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else
        return 1;
}

int main(){
    int i,len =0;
    char ch;
    string str,res;
    res ="";
    getline(cin,str);
    stack <char> st;
    str.insert(0,"(");
    str.push_back(')');
    len = str.size();
    cout<<str<<endl;
    for(i=0;i<len;i++){
        ch = str[i];
        if(ch == '(')
            st.push(ch);

        else if(isOperator(ch)){
            while(isOperator(st.top()) && Precedence(ch) <= Precedence(st.top()) ){
                res += st.top();
                st.pop();
            }
            st.push(ch);
        }
        else if(ch == ')'){
            while(st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else res += ch;
    }
    cout<<res<<endl;

    return 0;
}
