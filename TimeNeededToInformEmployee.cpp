#include<bits/stdc++.h>
using namespace std;
string func(int input1,string input2)
{
    string ans = "";
    int j = 0,k=0;
    vector<char> med(input1);
    for(int i=0;i<input1;i++)
    {
        //cout<<"hkh"<<endl;
        if(i==0 || med[j-1]<=input2[i])
        {
            
            med[j++] = input2[i]; 
           // cout<<med[j-1]<<"  "<<input2[i]<<endl;
        }
        else
        {
            ans+= input2[i];
        }
    }

   // cout<<ans<<endl;
    for(int i= j;i>=0;i--)
    {
        
        ans+= med[i];
    }
    return ans;
}

int main()
{
    string s = "cba";

    string a = func(3,s);

    cout<<a<<endl;



    return 0;
}
