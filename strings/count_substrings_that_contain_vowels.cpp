#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c){
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'o' || c =='O' || c =='I' || c == 'i' || c == 'u' || c =='U'){
        return true;
    }
    return false;
}

int main(){
    string s;cin>>s;
    int n = s.size();
    // count substrings that contain all 5 vowels
    map<char,int> mp;
    int cnt=0;
    int i=0, j =0;
    while(j < n){
        if(isVowel(s[i])) mp[s[j]]++;
        while(mp.size() == 5){
            cnt += n - j;
            mp[s[i]]--;
            i++;
        }
        j++;
    }

    cout<<cnt<<endl;
    return 0;
}