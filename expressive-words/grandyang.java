//grandyang idea, shaun java code, 6ms faster than 84%
class Solution {
    public int expressiveWords(String S, String[] words) {
        int res = 0;
        char [] s = S.toCharArray();
        int m = s.length, n = words.length;
        for (String word : words) {
            //for each word, check if word can strech to S with 3 reps of a char
            int i = 0, j = 0;
            char [] w = word.toCharArray();
            //i from 0 to m-1 of s
            for (; i < m; ++i) {
                //j from 0 to w.len-1 of w
                //match, j++
                if (j < w.length && s[i] == w[j]) ++j;
                //not match, s reps 3
                else if (i > 0 && i < m-1 && s[i] == s[i - 1] && s[i] == s[i + 1]) ++i;
                //not match, s no reps3
                else if (!(i > 1 && s[i] == s[i - 1] && s[i] == s[i - 2])) break;
            }
            if (i == m && j == w.length) ++res;
        }
        return res;
    }
}

/*
grandyang 4ms and faster than 100%
定义了一种富于表现力的单词，就是说某个字母可以重复三次或以上，那么对于这种重复后的单词，我们称之为可拉伸的（stretchy）。现在给了我们一个拉伸后的单词S，又给了我们一个单词数组，问我们里面有多少个单词可以拉伸成为S。其实这道题的关键就在于看某个字母是否被重复了三次，重复两次是不行的。那么我们就只能遍历单词数组words中的单词，来分别和S比较了。每个遍历到的单词的长度suppose是应该小于等于S的，因为S是拉伸后的单词，当然S也可以和遍历到的单词相等，那么表示没有拉伸。我们需要两个指针i和j来分别指向S和遍历单词word，我们需要逐个比较，由于S的长度要大于等于word，所以我们for循环直接遍历S的字母就好了，首先看如果j没越界，并且此时S[i]和word[j]相等的话，那么j自增1，i在for循环中也会自增1，遍历下一个字母。如果此时不相等或者j已经越界的话，我们再看当前的S[i]是否是3个重复中的中间那个，即S[i-1]和S[i+1]需要等于S[i]，是的话，i自增1，然后加上for循环中的自增1，相当于总共增了2个，正好跳过这个重复三连。否则的话再看是否前两个都和当前的字母相等，即S[i-1]和S[i-2]需要等于S[i]，因为可能重复的个数多于3个，如果这个条件不满足的话，直接break就行了。for循环结束或者跳出后，我们看S和word是否正好遍历完，即i和j是否分别等于S和word的长度，是的话结果res自增1，
*/
/*
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = 0, m = S.size(), n = words.size();
        for (string word : words) {
            int i = 0, j = 0;
            for (; i < m; ++i) {
                if (j < word.size() && S[i] == word[j]) ++j;
                else if (i > 0 && S[i] == S[i - 1] && i + 1 < m && S[i] == S[i + 1]) ++i;
                else if (!(i > 1 && S[i] == S[i - 1] && S[i] == S[i - 2])) break;
            }
            if (i == m && j == word.size()) ++res;
        }
        return res;
    }
};
*/
