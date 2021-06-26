class Solution {
    class Solution1 {
        //grandyang idea using sets, shaun code, beats 98.62%
        public int[] intersection(int[] nums1, int[] nums2) {
            Set<Integer> s1 = new HashSet<>();
            for (int i =0; i < nums1.length; i++) {
                s1.add(nums1[i]);
            }
            //using List<Integer> res does not work, duplicates
            Set<Integer> s2 = new HashSet<>();
            for (int i = 0; i < nums2.length; i++) {
                if (s1.contains(nums2[i])) s2.add(nums2[i]);
            }

            int n = s2.size();
            int [] arr = new int[n];
            int i = 0;
            for (Integer I: s2) {
                arr[i++] = I.intValue();
            }
            return arr;
        }
    }
    //grandyang idea 2, shaun code, beats 75%
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int i = 0, j = 0;
        List<Integer> res = new ArrayList<>();
        //either i reaches end1 or j reaches end2
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) i++;
            else if (nums1[i] > nums2[j]) j++;
            else { // nums1[i] == nums2[j]
                if ( (res.size() ==0) || res.get(res.size()-1) != nums1[i]) {
                    res.add(nums1[i]);
                    //i++; j++ //can not put here
                }
                i++;
                j++;
                
            }
            
        }
        int n = res.size();
        int [] arr = new int[n];
        for (int k = 0; k < n; k++) {
            arr[k] = res.get(k);
        }
        return arr;
        
        
    }
    
}
