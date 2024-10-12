/*
Sweep Line Algorithm:
The sweep line algorithm is very useful for solving problems related to intervals, such as:

1.Finding how many intervals overlap at a particular point – The sweep line method helps you find this efficiently.

2.Finding the maximum number of overlapping intervals – Another common problem solved by the sweep line approach.

3.Dividing intervals into the minimum number of groups – The goal is to ensure that no two intervals in the same group overlap. Sweep line helps with this as well.

These types of questions may come in different forms, but the idea remains the same.

Steps to Implement the Sweep Line Algorithm:

1.Find the minimum start time and maximum end time of the intervals.

    This will give you the range in which the intervals lie.
    Calculate the range:

    The range is the difference between the maximum end time and minimum start time.
    Range = maxEndTime .
    Create a vector:

2.Make a vector v of size range + 2 to store the count of active intervals at each point.
    Update the vector based on the intervals:

3.For each interval, increment the start point and decrement just after the end point.

    v[intervals[i][0]]++ (increment at the start of the interval).
    v[intervals[i][1] + 1]-- (decrement just after the end of the interval).
4.Count the overlapping intervals:

    Declare a variable count = 0 to keep track of the number of active intervals.
    Iterate over the vector v and do count += v[i] to update the current number of active intervals.
    At each point, check if this count is the maximum by doing maxOverlaps = max(maxOverlaps, count).
    
 */
// Time Complexity:O(N+rangeend+2)
// Space Complexity:O(rangeend+2)


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Find the minimum and maximum value in the interval
        int rangeStart = INT_MAX;
        int rangeEnd = INT_MIN;
        for (vector<int> interval : intervals) {
            rangeStart = min(rangeStart, interval[0]);
            rangeEnd = max(rangeEnd, interval[1]);
        }

        // Initialize the list with all zeroes
        vector<int> v(rangeEnd + 2, 0);
        for (vector<int> interval : intervals) {
            v[interval[0]]++;
            v[interval[1] + 1]--;
        }

        int count = 0;
        int maxOverlappingIntervals = 0;
        for (int i = rangeStart; i <= rangeEnd; i++) {
            // Update currently active intervals
            count += v[i];
            maxOverlappingIntervals =
                max(maxOverlappingIntervals, count);
        }

        return maxOverlappingIntervals;
    }
};

// Other way to do it is 
// Time Complexity: O(N log(N))
// Space Complexity: O(N)

// critical points mean where the number of overlapping intervals changing 
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
       map<int, int> criticalPoints;

        // Sweep line: increment at interval start, decrement at interval end + 1
        for (const auto& interval : intervals) {
            criticalPoints[interval[0]]++;    // Increment at the start of the interval
            criticalPoints[interval[1] + 1]--; // Decrement after the end of the interval
        }

        int ans = 0;
        int count = 0;

        // Traverse through the map to calculate the maximum number of overlapping intervals
        for (const auto& [point, value] : criticalPoints) {
            count += value;
            ans = max(ans, count); // Keep track of the maximum count
        }

        return ans;
    
        
    }
};