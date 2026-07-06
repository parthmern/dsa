class Solution {

    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private int pivot(int[] arr, int s, int e) {

        int pi = e;
        int pe = arr[pi];

        int i = s - 1;
        int j = s;

        while (j < pi) {

            if (arr[j] < pe) {
                // swap with i
                i++;
                this.swap(arr, i, j);
            }

            j++;
        }

        // end swap i++ and 
        i++;
        this.swap(arr, i, j);

       // System.out.println("pivot at " + Arrays.toString(arr) + i);
        return i;
    }

    private int[] qs(int[] arr, int s, int e) {

        if (s > e) return arr;

        int p = pivot(arr, s, e);

        //System.out.println("here at" + s + e);

        qs(arr, s, p - 1);
        qs(arr, p + 1, e);

        return arr;

    }

    public int[] sortArray(int[] nums) {
        return this.qs(nums, 0, nums.length - 1);
    }
}