//shaun's own idea compare from left to right, shaun uses getline(stringstream, token_string, sep_char)
//accepted after 1 bug fix
// runtime 0ms, faster than 100%, mem less than 33%
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1), v2(version2);
        int d1 = 0, d2 = 0;
        string t1, t2;
        char dot = '.';
        //while (getline(v1, t1, '.') || getline( v2, t2, '.')) { //bug only 1 getline is executed
        while (true) {
            getline(v1, t1, '.');
            getline(v2, t2, '.');
            if (!v1 && !v2) break;
            //cout << t1 << ":" << t2 << d endl;
            if (v1 ) d1 = stoi(t1);
            if (v2 ) d2 = stoi(t2);
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            d1 = d2 = 0;
        }
        return 0;
    }
};

//shaun has the same idea, but not clear about implementation
//istringstream .good() >> type1 >> type2
//runtime 4ms, faster than 
class Solution2 {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1 + "."), v2(version2 + ".");
        int d1 = 0, d2 = 0;
        char dot = '.';
        while (v1.good() || v2.good()) {
            if (v1.good()) v1 >> d1 >> dot;
            if (v2.good()) v2 >> d2 >> dot;
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            d1 = d2 = 0;
        }
        return 0;
    }
};
