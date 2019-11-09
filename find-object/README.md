Given a grid with a target object at some position. You can move to any position and call a method Response getResponse(x, y) which would give you a response w.r.t. to your previous position. Write a program to find the object.

API : Response getResponse(x, y)

enum Response {
	HOTTER,    // Moving closer to target
	COLDER,    // Moving farther from target
	SAME,      // Same distance
	EXACT      // Reached destination
}
| | | | | |
| | | | | |
| | | | | |
| | | | | |
| | | |x| |  <== Object
| | | | | |
Assumptions :

There is always one and only one object.
The first call would always give HOTTER as result.
My approach :
I cameup with a approach O(n) for a n*n grid.
Spend some time trying to comeup with a better approach. Couldn’t improve on time complexity. Couldn’t find a O(log n) approach.

Was asked to write the code for the linear approach. I was able to finsh the code with 10 mins remaining for interview. Was asked again to finish the O(log n) approach which I couldn’t do.
