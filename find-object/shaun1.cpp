/*
API : Response getResponse(x, y)

enum Response {
	HOTTER,    // Moving closer to target
	COLDER,    // Moving farther from target
	SAME,      // Same distance
	EXACT      // Reached destination
 *
 * /
 *
 *
class Solution {
	//given a grid nxn, find the object xy in the grid, using given api
	//idea is binary search
	pair<int,int> find(int n) {
		int left = 0, right = n-1, mid;
		//find the column
		while (left < right) {
			mid = left + (right - left)/2;
			Response r = getResponse(0,mid);
			if (r == EXACT) return make_pair(0,mid);
			if (r == HOTTER ) { //closer
				left = mid+1;
			}
			else if (r == SAME) {
				break;
			}else {
				right = mid;
			}
		}
		int j = mid; //found column
		//now left == right
		//now to find row
		int up = 0, down = n-1; 
		while (up < down) {
			mid = up + (down - up)/2;
			Response r = getResponse(i,mid);
			if (r == EXACT) return make_pair(i,mid);
			if (r == HOTTER ) { //closer
				up = mid+1;
			}
			else if (r == SAME) {
				break;
			}else {
				down = mid;
			}
		}
		return make_pair(i,mid);
	}


}
