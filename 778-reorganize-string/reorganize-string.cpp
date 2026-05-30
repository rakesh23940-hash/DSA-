class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

        string res = "";

        while (!pq.empty()) {

            pair<int,char> p = pq.top();
            pq.pop();

            if (res.empty() || res.back() != p.second) {

                res.push_back(p.second);
                p.first--;

                if (p.first > 0) {
                    pq.push(p);
                }
            }
            else {

               
                if (pq.empty()) {
                    return "";
                }

                pair<int,char> p2 = pq.top();
                pq.pop();

                res.push_back(p2.second);
                p2.first--;

                if (p2.first > 0) {
                    pq.push(p2);
                }

               
                pq.push(p);
            }
        }

        return res;
    }
};