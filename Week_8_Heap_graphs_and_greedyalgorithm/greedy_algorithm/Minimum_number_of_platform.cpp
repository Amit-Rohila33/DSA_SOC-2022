// A list of arrival and departure time is given. Now the problem is to find the minimum number of platforms are required for the railway as no train waits.

// By sorting all timings in sorted order, we can find the solution easily, it will be easy to track when the train has arrived but not left the station.

// The time complexity of this problem is O(n Log n).



// Ans:- The code for the above problem is as follows:

#include<iostream>
#include<algorithm>
using namespace std;

int minPlatform(int arrival[], int departure[], int n) {
   sort(arrival, arrival+n);     //sort arrival and departure times
   sort(departure, departure+n);

   int platform = 1, minPlatform = 1;
   int i = 1, j = 0;

   while (i < n && j < n) {
      if (arrival[i] < departure[j]) {
         platform++;     //platform added
         i++;
         if (platform > minPlatform)    //if platform value is greater, update minPlatform
            minPlatform = platform;
      } else {
         platform--;      //delete platform
         j++;
      }
   }
   return minPlatform;
}

int main() {
   int arrival[] = {900, 940, 950, 1100, 1500, 1800};
   int departure[] = {910, 1200, 1120, 1130, 1900, 2000};
   int n = 6;
   cout << "Minimum Number of Platforms Required: " << minPlatform(arrival, departure, n);
}