#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    int length(int num){
        int len = 0;
        while (num>0){
            len++;
            num/=10;
        }
        return len;
    }
    string exchange(int n,string &s,int len){
        string x="", y="", z="";
        switch (len) {
            case 4:x="M";
                break;
            case 3:{x="C";y="D";z="M";}
                break;
            case 2:{x="X";y="L";z="C";}
                break;
            case 1:{x="I";y="V";z="X";}
                break;
        }
        //test
//        cout << "x="<<x<<" y="<<y<<" z="<<z<<endl;
        //end
        if(n==9) s=s+x+z;
        else if(n==4) s=s+x+y;
        else if(n<4&&n>=1){
            while(n--) s+=x;
        } else if (n==5) s+=y;
        else if(n>5&&n<9){
            n-=5;
            s+=y;
            while (n--) s+=x;
        } else s+="";
        return s;
    }
    string intToRoman(int num){
        string final = "";
        int len = length(num);
        int s[len], n = num;
        for(int i = len-1; i>=0;i--){
            s[i]=n%10;
            n/=10;
        }
        //test
//        for(int i = 0; i < len; i++){
//            cout << s[i] << " ";
//        }
//        cout << endl;
//        cout << "len="<< len << endl;
        //end
        for(int i = 0; i < length(num); i++){
            final=exchange(s[i],final,len);
            len--;
            if(len==0) break;
        }
        return final;
    }

};
