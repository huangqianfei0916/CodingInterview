#include <iostream>
using namespace std;
#include <string>

class ReplaceSpace {
public:
    string replaceSpace(string s) {
        string d="";
        int len=s.size();
     
        for(int i=0;i<len;i++){
            if(s[i]==' '){
                d.append("%");
                d.append("2");
                d.append("0");
            }else{
                d+=s[i];
            }
        }
        return d;

    }
};