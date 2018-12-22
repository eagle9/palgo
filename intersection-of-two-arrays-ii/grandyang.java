class Solution {
    
    class Solution1 {
        //grandyang idea, shaun java code, beats 98.49%
        public int[] intersect(int[] nums1, int[] nums2) {
            Arrays.sort(nums1);
            Arrays.sort(nums2);
            int i = 0, j = 0; 

            List<Integer> res = new ArrayList<>();
            while (i < nums1.length && j < nums2.length) {
                if (nums1[i] == nums2[j]) {
                    res.add(nums1[i]);
                    i++;
                    j++;
                }else if (nums1[i] < nums2[j])  i++;
                else j++;
            }
            int n = res.size();
            int [] arr = new int[n];
            for (int k = 0; k < n; k++) {
                arr[k] = res.get(k);
            }
            return arr;
        }
    }
    //grandyang idea, shaun java code, beats 82%
    public int[] intersect(int[] nums1, int[] nums2) {
        Map<Integer, Integer> m = new HashMap<>();
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums1.length; i++) {
            if (m.containsKey(nums1[i]))
                m.put(nums1[i], m.get(nums1[i]) + 1);
            else
                m.put(nums1[i],1);
        }
        for (int i = 0; i < nums2.length; i++) {
            if (m.containsKey(nums2[i])) {
                if (m.get(nums2[i]) > 0)
                    res.add(nums2[i]);
                m.put(nums2[i], m.get(nums2[i])-1);
            }
            
        }
        int n = res.size();
        int [] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = res.get(i);
        }
        return arr;
    }
    
}
