package org.voyiger.algo;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
/*
For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

 */
public class GroupShiftedStrings {
    List<List<String>> groupStrings(List<String> strings) {

        Map<String, List<String>> m = new HashMap<>();
        for (String a : strings) {
            String t = "";
            for (char c : a.toCharArray()) {
                t += (c  - a.charAt(0)) + ",";
            }
            List<String> list = m.getOrDefault(t, new ArrayList<>());
            list.add(a);
            m.put(t, list);
        }

        List<List<String> > res = new ArrayList<>();
        for (String key: m.keySet()) {
            System.out.println("key = " + key);
            res.add(m.get(key));
        }
        return res;
    }

    @Test
    public void test() {
        String [] a = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
        List<String> input = Arrays.asList(a);
        List<List<String>> output = groupStrings(input);
        System.out.println(output);
    }
}

