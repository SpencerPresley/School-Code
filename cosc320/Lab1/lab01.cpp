// Programmer: Spencer Presley
// Date: 2/8/23

#include "deSelsort.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Unsorted Array: ";
    for(int i = 0; i < size; i++) // Simply print out initial array as is for comparison later with sorted array
    {
       cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Sorted Array: ";
    deSelsort(arr, size); // calling sort function

    for(int j = 0; j < size; j++) // print out array in to show the newly sorted fashion
        cout << arr[j] << " ";
    cout << endl;

    return 0;
}
void deSelsort(int arr[], int size) // Function takes in array and integer size which matches size of array passed in
{
    int j = 0; // declaring the two variable I'll need to start here, at first just declared them in for loop but that wasn't working for some reason so just decided to declare them outside to 0 outside.
    int i = 0;

    for(i = 0, j = size-1; i < j; i++, j--) // starting i at 0, and j at the size-1 as to not be out of array bounds at the end, and the current i is less than the current j (meaning still not done) go into for loop
    {
        int min = arr[i]; // Setting current min = value at front of unsorted array
        int max = arr[i]; // setting current max = value at the front of unsorted array also, initially had this set to back of array but for some reason I couldn't work out it messed up the comparisons after a certain point leading to only a partially sorted array with some values in incorrect places, plan to look into it more later via tracing outputs on paper
        int locMin = i; // location of min index starts at i (first iteration is 0). Idea here is as the list from the front half gets sorted the i value will move up as no longer need to compare the stuff before it.
        int locMax = size-1; // location of max index always starts at back of array, this can and will likely change depending on where the ne max is in the array, if max is found in a different location this index will change to that location

        for(int k = i; k <= j; k++) // set k = i, then check if k is <= current j (to begin is size-1 which is value 21 in array), since k is = i and first pass i = 0, 0 <= 21 is true so go into for loop (this obviously is not the same every time but just using example to explain the logic)
        {
            // check if arr[k] is less than or greater than min/max values. Starting values of min and max are both arr[i], as min and max values change though depending on the below comparisons the subsequent comparisons will also change

            if(arr[k] < min) // first check if k value is < than the current min. On first pass min is arr[i] or arr[0] which is value 13. So first pass comparision says is arr[k] (k being = i which is currently 0 will be arr[0] which on first pass is 13) < min. Since starting min is arr[0] (since first pass i = 0) min is = 13. 13 < 13 is not true so skip for now. On next iteration of inner for loop while still in first iteration of the outer for loop (i.e i = 0) k will = 1, here it will say is arr[1] < current min. Since current min is arr[i] or 13 and arr[1] is 5, 5<13 will be true and thus enter if statement. 
            {
                min = arr[k];
                locMin = k;
            }

            if(arr[k] > max) // check if arr[k] value is > than current max. Similar to before 13 > 13 is not true so move on. On subesequent iterations k increases, k on second pass will be = to 1 (this is still with the outer most for loop being in it's first iteration i.e i = 0). With k = 1 comparison becomes is arr[1] > max. Since arr[1] will be 5 in the initial loop of outer for loop and second iteration of this one value will be 5, so this will say is arr[1] (5) < current max which is arr[i] or 13 (again first iteration for outer for loop where i = 0, and second iteration for inner where k=1) so comparioson will be 5 > 13 which is false so doesn't go inside if. This logic will continue through every iteration. 
            {
                max = arr[k];
                locMax = k;
            }

        }

        //cout << endl << iMin << " " << max << endl; 
        //cout << endl << j << " " << iMax << endl;
        // The two lines above were here for my own testing, I left them here in the event someone would like to check what's happening through each iteration themselves as I partially outline in my comment on the below else statement. 
	
	if(arr[i] != arr[locMin])
       		swap(arr[i], arr[locMin]); //swap current arr[i] value with the arr[min index]. Since min index will change depending on results of inner for loop if there was a change it will swap those values succesfully, if there was no change if statement will fail and move on to rest of code
cout << endl << arr[locMin] << " " << max << endl;
        if(arr[locMin] == max)  // if these two values end up being the same then swap arr[j] with the arr[minimum index]. First pass for example iMin is 2, max is 47, since these are not = will not enter if and do swap, will go to else.
            swap(arr[j], arr[locMin]);
        else // in event the upper if fails it will travel here and swap arr[j value] and arr[maximum index value]. First pass through j is = 7 and iMax is = 4, so would swap arr[7] and arr[4] or swap values 21 and 47. Next iteration values come to 6 and 3 so swap arr[6] and arr[3] which is swapping values 8 and 25. After those two iterations order would be {13, 5, 2, 8, 21, 17, 25, 47}
            swap(arr[j], arr[locMax]);
    }
}

void swap(int x, int y) // utility swap function
{
    int temp = x;
    x = y;
    y = temp;
}
