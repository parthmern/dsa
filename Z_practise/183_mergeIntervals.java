class Solution {
    public int[][] merge(int[][] intervals) {

        if (intervals.length == 0) return new int[0][];

        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        List<int[]> ans = new ArrayList<>();

        int i = 0;
        int n = intervals.length;

        while (i < n) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // merge overlapping intervals
            while (i + 1 < n && intervals[i + 1][0] <= end) {
                end = Math.max(end, intervals[i + 1][1]);
                i++;
            }

            ans.add(new int[]{start, end});
            i++;
        }

        return ans.toArray(new int[ans.size()][]);
    }
}
