#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    string s = "abcbaa";
    int k = 3;

    int start = 0, end = 0;

    int res = 0;

    unordered_map<char,int> charct;

    while(end < s.length()){
        if(charct.size() < k || charct.count(s[end])){
            charct[s[end]]++;
            end++;
            if(charct.size() == k){
                res++;
            }
        }else{
            charct[s[start]]--;
            if(!charct[s[start]]){
                charct.erase(s[start]);
            }
            start++;
            if(charct.size() == k){
                res++;
            }
        }
    }

    while(start < s.length()){
        charct[s[start]]--;
        if(!charct[s[start]]){
            charct.erase(s[start]);
        }
        if(charct.size() == k){
            res++;
        }
        start++;
    }

    cout << res << endl;

    return 0;


}