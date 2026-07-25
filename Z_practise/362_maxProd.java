class Solution {
    public int maxProduct(int n) {

        ArrayList<Integer> arr = new ArrayList<>();

        for (char ch : String.valueOf(n).toCharArray()){
            int ele = Integer.parseInt(ch+"");
            arr.add(ele);
        }
        Collections.sort(arr);

        return arr.get(arr.size()-2) * arr.get(arr.size()-1);
    }
}