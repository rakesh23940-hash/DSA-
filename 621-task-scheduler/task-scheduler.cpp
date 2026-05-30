class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int m = tasks.size();

        unordered_map<char,int> freq;
        unordered_map<char,int> free;

        for(int i = 0; i < m; i++){
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        priority_queue<pair<int,char>> pq;

        for(auto it : freq){
            pq.push({it.second, it.first});
        }

        int seat = 1;

        while(!pq.empty()){

            vector<pair<int,char>> pull;
            bool executed = false;

            while(!pq.empty()){

                pair<int,char> p = pq.top();
                pq.pop();

                int f = p.first;
                char child = p.second;

                if(free[child] <= seat){

                    executed = true;

                    
                    seat++;

                    if(f > 1){
                        pq.push({f - 1, child});

                       
                        free[child] = seat + n;
                    }

                    break;
                }
                else{
                    
                    pull.push_back(p);
                }
            }

           
            for(int i = 0; i < pull.size(); i++){
                pq.push(pull[i]);
            }

           
            if(!executed){
                seat++;
            }
        }

        return seat - 1;
    }
};
//gpt kiya hai 