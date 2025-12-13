class Solution {
    public int findMinDifference(List<String> timePoints) {
        List<Integer> mins = new ArrayList<>();

        for(String ele : timePoints){

            int hr = Integer.valueOf( ele.substring(0,2) );
            int min = Integer.valueOf( ele.substring(3,5) );

            mins.add(hr*60+min);
        }

        Collections.sort(mins);

        int mini = Integer.MAX_VALUE;

        for(int i=0; i<mins.size()-1; i++){
            int diff = Math.abs(mins.get(i) - mins.get(i+1));
            mini = Math.min(mini, diff);
        }

        int lastDiff = Math.abs((mins.get(0) + 1440) - mins.get(mins.size()-1));
        mini = Math.min(mini, lastDiff);

        return mini;

    }
}