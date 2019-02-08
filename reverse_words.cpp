
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s = "   a   ";
    //reverse(s.begin(), s.end());
        
        int w_ind = 0;
        
        int i = 0;
        while(i < s.length()){
            
            while(i < s.length() && s[i] == ' '){
                i++;
            }
            if( i >= s.length()){
                break;
            }      
            int j = i;
            
            if(w_ind!= 0){
                s[w_ind++] = ' ';
            }

            while(j < s.length() && s[j]!= ' '){
                s[w_ind++] = s[j++];
            }
                        
            reverse(s.begin() + w_ind - (j - i), s.begin() + w_ind);
            i = j + 1;
        }
        
        s.erase(s.begin() + w_ind, s.end());
        reverse(s.begin(), s.end());
        cout <<s<<endl;
        cout << s.length() << endl;
    return 0;
}
