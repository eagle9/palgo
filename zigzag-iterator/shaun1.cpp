//shaun original idea, 1st round, first sub accepted after fixing typo
//runtime 28ms, faster than 20%, mem less than 31%
class ZigzagIterator00 {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int i = 0, j = 0,k=0;
        int size1 = v1.size(), size2 = v2.size();
        data.resize(size1+size2);
        while (i < size1 && j < size2) {
            data[k++] = v1[i++];
            data[k++] = v2[j++];
        }
        while (i < size1) data[k++] = v1[i++];
        while (j < size2) data[k++] = v2[j++];
        
    }

    int next() {
        int res = data[0];
        data.erase(data.begin());
        return res;
    }

    bool hasNext() {
        return !data.empty();
    }
private: 
    vector<int> data;
};

