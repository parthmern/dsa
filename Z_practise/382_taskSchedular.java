class Solution {
    public int leastInterval(char[] tasks, int n) {

        // Step 1: Count the frequency of each task
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char task : tasks) {
            freqMap.put(task, freqMap.getOrDefault(task, 0) + 1);
        }

        // Step 2: Build a max heap based on frequencies
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        maxHeap.addAll(freqMap.values());

        // Step 3: Process tasks
        int time = 0;

        while (!maxHeap.isEmpty()) {

            List<Integer> temp = new ArrayList<>();

            // Execute up to (n + 1) tasks in one cycle
            for (int i = 0; i < n + 1; i++) {
                if (!maxHeap.isEmpty()) {
                    temp.add(maxHeap.poll());
                }
            }

            // Decrease frequency and push back if still remaining
            for (int freq : temp) {
                if (--freq > 0) {
                    maxHeap.add(freq);
                }
            }

            // Update total time
            time += maxHeap.isEmpty() ? temp.size() : n + 1;
        }

        return time;
    }
}