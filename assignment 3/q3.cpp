#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool arepair(char opening , char closing){
    if(opening=='(' && closing==')' ) return true ;
    else if(opening=='{' && closing=='}' ) return true;
    else if(opening=='[' && closing==']' ) return true;
    return false;
}

bool areBalanced(string str){
    stack<char>s;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='[' ){
            s.push(str[i]);
        }
        else if( str[i]==')' || str[i]=='}' || str[i]==']' ){
            if(s.empty() || !arepair(s.top() , str[i])  )
            return false;
            else 
            s.pop();
        }
    }
    return s.empty();
}

int main()
{
    stack<char>s;
    string str;
    cout << " Enter : " << endl;
    getline(cin , str );
    if(areBalanced(str)){
        cout << "Balanced " << endl;
    }
    else{
        cout << " Not Balanced " << endl;
    }
    return 0;
}