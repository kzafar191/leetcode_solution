// Last updated: 5/6/2026, 5:08:37 pm
class Solution {
    public String findDifferentBinaryString(String[] a) {
        StringBuilder r = new StringBuilder();
        for (int i = 0; i < a.length; i++) {
            r.append(a[i].charAt(i) == '0' ? '1' : '0');
        }
        return r.toString();
    }
}