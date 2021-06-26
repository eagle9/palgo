//https://blog.csdn.net/qq508618087/article/details/51435944 
//divide and conquer merge sort application, 
//runtime 28ms, faster than 91.38%, mem less than 14%, merge with local temp
//runtime 20ms, faster than 99.61% mem less than 91%, merge2 with private member temp
class Solution {
public:
    //sum from index left to right(not inclusive)
    int mergeSort(vector<long>& sum, int lower, int upper, int left, int right){
        if(right-left <= 1) return 0;
        int mid = left + (right-left)/2;
        int count = mergeSort(sum,lower,upper,left,mid) + mergeSort(sum,lower,upper,mid,right);
        
        //start from mid, find first m such that sum[m] - sum[i]>= lower
		//start from mid, find last n such that sum[n] - sum[i] <= upper
        int m = mid, n = mid;
		//note sum[left, mid) and sum[mid,right) are sorted now, use this property!
        for(int i =left; i< mid; i++){
			//for each sum[i], in the range of [mid,right), find first m such that sum[m] - sum[i] >= lower
            while(m < right && sum[m] - sum[i] < lower) m++;
			//for each sum[i], in the range of [mid,right), find last n such that sum[m] - sum[i] <= upper 
            while(n < right && sum[n] - sum[i] <= upper) n++;
            count += n - m; //found n-m range sums in [lower,upper] for the particular sum[i]
        }
        //inplace_merge(sum.begin()+left, sum.begin()+mid, sum.begin()+right);
        //merge(sum, left, mid, right);
        merge2(sum,left,mid,right);
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
        vector<long> sum(nums.size()+1, 0);
        for(int i =0; i< nums.size(); i++) sum[i+1] = sum[i]+nums[i];
        
        temp =vector<long>(sum.size());
        return mergeSort(sum, lower, upper, 0, sum.size());
    }
    //my own implementation of inplace_merge, use local buffer temp
    // a index range [left,right)
    void merge(vector<long>& a, int left, int mid, int right) {
        vector<long> temp (right-left);
        int k = 0; //index for temp
        int i = left, j = mid; // left .. mid-1  mid ... right-1 right
        while (i < mid && j < right) {
            if (a[i] < a[j]) temp[k++] = a[i++]; //take smaller
            else temp[k++] = a[j++];
        }
        while (i < mid) temp[k++] = a[i++];
        while (j < right) temp[k++] = a[j++];
        for (k = 0; k < right-left; ++k) a[k+left] = temp[k];
    }
	//my own implementation of inplace_merge, use private member buffer temp, more efficient
    void merge2(vector<long>& a, int left, int mid, int right) {
        
        int k = left; //index for temp as private member
        int i = left, j = mid; // left .. mid-1  mid ... right-1 right
        while (i < mid && j < right) {
            if (a[i] < a[j]) temp[k++] = a[i++]; //take smaller
            else temp[k++] = a[j++];
        }
        while (i < mid) temp[k++] = a[i++];
        while (j < right) temp[k++] = a[j++];
        for (k = left; k < right; ++k) a[k] = temp[k];
    }
private:
    vector<long> temp;
};

