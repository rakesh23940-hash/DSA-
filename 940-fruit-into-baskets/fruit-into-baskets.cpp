class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        

       unordered_map<int,int> f;
       int i=0,j=0;
       int n=fruits.size();
       int res=INT_MIN;
       for(j=0;j<n;j++)
       {
           f[fruits[j]]++;
           while(f.size()>2)
           {
               f[fruits[i]]--;
               if(f[fruits[i]] ==0)
               f.erase(fruits[i]);
               i++;
           }


          
               int len=j-i+1;
               res=max(res,len);
          
       }
       return res;
        
    }
};