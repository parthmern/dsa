class Solution {
	
	private void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	
	private void swap(int[] a, int[] b, int i, int j) {
		int temp = a[i];
		a[i] = b[j];
		b[j] = temp;
	}
	
	public void mergeArrays(int a[], int b[]) {
		
		int gap = (a.length + b.length + 1)/2;
		
		boolean isGapOneTimeOne = false;
		
		while (gap > 0) {
			
			int i = 0;
			int j = i + gap;
			
			while (j < (a.length + b.length)){
			    
			    // if i and j are in a[]
			    if(i < a.length && j < a.length){
			        if(a[i] > a[j]){
			            swap(a, i, j);
			        }
			    }
			    
			    // if i is in a[] and j is in b[]
			    else if(i < a.length && j >= a.length){
			        if(a[i] > b[j - a.length]){
			            swap(a, b, i, j - a.length);
			        }
			    }
			    
			    // if i and j are in b[]
			    else if(i >= a.length && j >= a.length){
			        if(b[i - a.length] > b[j - a.length]){
			            swap(b, i - a.length, j - a.length);
			        }
			    }
			    
			    i++;
			    j++;
			}
			
			if(isGapOneTimeOne){
			    gap = 0;
			    break;
			}
			
			if(gap == 1){
			    isGapOneTimeOne = true;
			}
			
			gap = (gap + 1) / 2;
		}
	}
}