class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.empty()) {
            return 0;
        }
        
        std::vector<int> freq(26, 0);
        for (char t : tasks) {
            freq[t - 'A']++;
        }
        
        std::vector<int> prev_cycle(26, -n - 1);
        int cycle = 0;
        int remaining_tasks = tasks.size();

        while (remaining_tasks > 0) {
            int best_task = -1;
            
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0 && (cycle - prev_cycle[i]) > n) {
                    if (best_task == -1 || freq[i] > freq[best_task]) {
                        best_task = i;
                    }
                }
            }

            if (best_task != -1) {
                freq[best_task]--;
                prev_cycle[best_task] = cycle;
                remaining_tasks--;
            }
            cycle++;
        }
        
        return cycle;
    }
};