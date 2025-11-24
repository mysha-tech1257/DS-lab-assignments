#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    int i;
    stack<char> s;
    string str;
    cout << " Enter String : " << endl;
    getline(cin , str);
    for(int i=0; i<str.length() ; i++){
        s.push(str[i]);
    }
    cout << " reversed string : " << endl;

    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;
    
    return 0;   
}