#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int> pq;
       for(int i = 0;i<h.size()-1;i++)
       {
           int d = h[i+1] - h[i];
           if(d<=0) continue;
           if(d<=b)
           {
               b-= d;
               pq.push(d);
           }
           else if(l>0 )
           {
               if(!pq.empty())
               {
                   int a = pq.top();
                   if(a>d)
                   {
                       b+= a;
                       b-= d;
                       pq.pop();
                       pq.push(d);
                   }
               }
               l--;
           }
           else return i;
       }
       return h.size()-1; 
           
           
    }
};