class Node{
    int key;
    int val;

    Node(int k, int v){
        this.key = k;
        this.val = v;
    }

}

class Solution {
    public String frequencySort(String s) {

        Map<Character, Integer> mp = new TreeMap<>();

        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);
            //System.out.println("ch"+ ch);
            if(mp.get(ch) == null) mp.put(ch, 1);
            else mp.put(ch, mp.get(ch)+1);
        }

        for(char key : mp.keySet()) System.out.println(key + "=" + mp.get(key));

        List<Character> list = new ArrayList<>(mp.keySet());
        Collections.sort(list, (a, b) -> mp.get(b) - mp.get(a));

        
        StringBuilder sb = new StringBuilder();
        for (char ch : list) {
            int freq = mp.get(ch);
            while (freq-- > 0) {
                sb.append(ch);
            }
        }
        return sb.toString();


        // ArrayList<Node> arr = new ArrayList<>();

        // for(int j=0; j<26; j++){
        //     arr.add(j, new Node(0,0));
        // }

        // for(int i=0; i<s.length(); i++){
        //     char ch = s.charAt(i);

        //     int key = ch-'a';
            
        //     System.out.println(ch-'a');

        //     if( arr.get(key).key == -1 ) {
        //         arr.get(key).val++ ;
        //     }else{
        //         arr.get(key).val++ ;
        //     }
        
        // }

        // Collections.sort(arr, (a,b)-> a.val - b.val);

        // for(Node ele: arr) System.out.println(ele.key + "-" + ele.val);
        

        //return "";
        
    }
}