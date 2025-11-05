class Solution {
    public boolean isAnagram(String s, String t) {

        char[] sc = s.toCharArray();
        Arrays.sort(sc);
        String sn = new String(sc);

        char[] tc = t.toCharArray();
        Arrays.sort(tc);
        String tn = new String(tc);

        System.out.println(sn + " " + tn);

        return sn.equals(tn);

    }
}