// Question : Delete the vowels from a given string.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    string ans="";
    cout<<"Enter a string : "<<endl;
    cin>>s;
    for(int i=0;i<s.length();i++){
        char temp = tolower(s[i]);
        if(temp!='a' && temp!='e' && temp!='i' && temp!='o' && temp!='u'){
            ans=ans+s[i];
        }
    }
    cout<<"String after deleting the vowels is : "<<ans<<endl;
    return 0;
}
