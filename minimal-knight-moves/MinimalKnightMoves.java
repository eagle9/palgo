package org.voyiger.algo;

import org.junit.Test;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.concurrent.LinkedBlockingDeque;

import static org.junit.Assert.assertEquals;

public class MinimalKnightMoves {
    int [][] directions = {
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, -2},
        {-2, -1},
        {-2, 1},
        {-1, 2}
    };
    static final int WIDTH = 1024;
    int minKnightMoves(int x, int y) {
        Set<Integer> visited = new HashSet<>();
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int []{0, 0});

        int level = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int n = 0; n < size; ++n) {
                int [] pos = q.poll();
                if (Math.abs(pos[0]) == Math.abs(x) && Math.abs(pos[1]) == Math.abs(y))  return level;

                int nodeId = pos[0] * WIDTH + pos[1];
                if (visited.contains(nodeId)) continue;
                visited.add(nodeId);
                for (int i = 0; i < 8; ++i) {
                    q.offer(new int [] {pos[0] + directions[i][0], pos[1] + directions[i][1]});
                }
            }
            ++level;
        }
        return -1;
    }
    /*
    Input: x = 5, y = 5
Output: 4
Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
     */
    @Test
    public void test() {
        assertEquals(minKnightMoves(5,5), 4);
    }

};
