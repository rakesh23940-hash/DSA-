class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            bool forward = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {
               
                int nextSlow =
                    (slow + nums[slow] % n + n) % n;

                if (nums[slow] == 0 ||
                    (nums[slow] > 0) != forward ||
                    nextSlow == slow) {
                    break;
                }

                slow = nextSlow;

                
                int nextFast =
                    (fast + nums[fast] % n + n) % n;

                if (nums[fast] == 0 ||
                    (nums[fast] > 0) != forward ||
                    nextFast == fast) {
                    break;
                }

                fast = nextFast;

              
                nextFast =
                    (fast + nums[fast] % n + n) % n;

                if (nums[fast] == 0 ||
                    (nums[fast] > 0) != forward ||
                    nextFast == fast) {
                    break;
                }

                fast = nextFast;

                
                if (slow == fast) {
                    return true;
                }
            }

          
            int curr = i;

            while (nums[curr] != 0 &&
                   (nums[curr] > 0) == forward) {

                int next =
                    (curr + nums[curr] % n + n) % n;

                if (next == curr) {
                    break;
                }

                nums[curr] = 0;
                curr = next;
            }
        }

        return false;
    }
};