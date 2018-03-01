//Andrew Hubbard
//Lab 6
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void binarysearch(int arr[], int n, int x);
void bubblesort(int arr[], int n);
void doublebubblesort(int arr[], int n);
void selectionsort(int arr[], int n);
void doubleselectionsort(int arr[], int n);
void insertionsort(int arr[], int n);       
void animatedbubblesort(int arr[], int n);
void animateddoublebubblesort(int arr[], int n);
void animatedselectionsort(int arr[], int n);
void animateddoubleselectionsort(int arr[], int n)
void animatedinsertionsort(int arr[], int n);       

int main()
{
    //    system ("clear");
    cout << "\nLab 6: written by Andrew Hubbard\n";
    cout << "This program demonstrates a binary search.\n";
    cout << "The program will fill an array with randoms,\n";
    cout << "sort the array, then find a value\n\n";

    srand(time(NULL));

    int n;
    cout << "how many numbers in array?: ";
    cin >> n; cout << endl;
    int arr[n];

    int max;
    int min;
    cout << "\nWhat's the maximum number in the array?: ";
    cin >> max; cout << endl;
    cout << "\nWhat's the minimum number in the array?: ";
    cin >> min; cout << endl;

    cout << "\nCreating random numbers array, please wait..." << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (max-min + 1) + min;
        //      cout << arr[i] << " ";              // Not showing randoms
    } 
    cout << "Complete.\n\n\n";

    int sortchoice;
    cout << "Which sort would you like to use?\n";
    cout << "[1]bubble sort, [2]double bubble sort, [3]selection sort, [4]double selection sort, [5]insertion sort\n";
    cout << "ANIMATED SORTS!!!";
    cout << "[6]bubble sort, [7]double bubble sort, [8]selection sort, [9]double selection sort, [10]insertion sort\n";
    cin >> sortchoice;  cout << endl;
    while(sortchoice > 10 || sortchoice < 1)
    {   
        cout << "Not a valid selection!\n";
        cout << "Which sort would you like to use?\n";
        cout << "[1]bubble sort, [2]double bubble sort, [3]selection sort, [4]double selection sort, [5]insertion sort\n";
        cout << "ANIMATED SORTS!!!";
        cout << "[6]bubble sort, [7]double bubble sort, [8]selection sort, [9]double selection sort, [10]insertion sort\n";
        cin >> sortchoice;  cout << endl;
    }
    int start_time = time(0);
    switch(sortchoice)
    {
        case 1:
            cout << "You've chosen...BUBBLE SORT\n";
            bubblesort(arr, n);     
            break;
        case 2:
            cout << "You've chosen...DOUBLE BUBBLE SORT\n";
            doublebubblesort(arr, n);     
            break;
        case 3:
            cout << "You've chosen...SELECTION SORT\n";
            selectionsort(arr, n);
            break;
        case 4:
            cout << "You've chosen...DOUBLE SELECTION SORT\n";
            doubleselectionsort(arr, n);
            break;
        case 5:
            cout << "You've chosen...INSERTION SORT\n";
            insertionsort(arr, n);
            break;
        case 6:
            cout << "You've chosen...ANIMATED BUBBLE SORT\n";
            bubblesort(arr, n);     
            break;
    } 
    cout << "Sorting array, please wait..." << endl;
    bool ordered = true;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {    
            cout << arr[i] << endl;
            ordered = false;
        }
    }
    if (!ordered)
        cout << "Out of order!\n\n";
    else
        cout << "Sort Success!\n\n";      
    int stop_time = time(0);
    int total_time = stop_time -start_time;
    cout << "Time to sort: " << total_time << endl;
    
 
    char print;
    do
    {
        cout << "\nDo you want a printout of the sorted array?(y/n)  ";
        cin >> print;
    }
    while(print != 'y' && print != 'n');
    if(print == 'y')
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 10 == 0)
                cout << endl;
            cout << arr[i] << "\t";

        }
    }
    cout << endl;

    return 0;
}

void binarysearch(int arr[], int n, int x)      //n=size, x = search value
{
       int start = 0;
       int end = n-1;
       int mid;
       int x;
       int count = 1;
       cout << "What value are we searching for?: ";
       cin >> x; cout << endl;
       int index = -1;
       while(start <= end)
       {
       mid = (start + end)/2;
       cout << "search attempt: " << count << endl;
       cout << "start: " << start << " ";
       cout << "mid: " << mid << " ";
       cout << "end: " << end << endl;

       if (arr[mid] == x)
       {
       index = mid;
       break;
       }
       if (x < arr[mid])
       {
       end = mid - 1;
       cout << "LOWER!\n";
       }
       if (x > arr[mid])
       {
       start = mid +1;
       cout << "HIGHER!\n";
       }
       count++;
       }
       if (index == -1)
       {
       cout << "value was not found:(\n";
       }
       else
       cout << x << " was found at index " << index << endl;
}                  

void bubblesort(int arr[], int n)
{
    bool noswap;                             
    do
    {    
        noswap = true;
        for (int j = 0; j < n-1; j++)           
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                noswap = false;  
            }  
        }
    }while(!noswap);
}

void doublebubblesort(int arr[], int n)
{
    bool noswap;                             
    do
    {    
        noswap = true;
        for (int j = 0; j < n-1; j++)           
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                noswap = false;  
            }  
            if(arr[n-1-j] < arr[n-2-j])
            {
                int temp = arr[n-1-j];
                arr[n-1-j] = arr[n-2-j];
                arr[n-2-j] = temp;
                noswap = false;  
            }
        }
    }while(!noswap);
}

void selectionsort(int arr[], int n)
{
    int lowswaps = 0;                      
    int lowkeeps = 0;
    for (int i = 0; i < n; i++)
    {
        int lowestNumberIndex = i;  
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[lowestNumberIndex])
            {
                lowestNumberIndex = j;
            }
        }
        if (lowestNumberIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[lowestNumberIndex];
            arr[lowestNumberIndex] = temp;
            lowswaps++;
        }
        else
            lowkeeps++;   
    }
    cout << "low swaps: " << lowswaps << endl << "low keeps: " << lowkeeps << endl;
    cout << "total(swaps + keeps) = " << lowswaps + lowkeeps  << endl;
}


void doubleselectionsort(int arr[], int n)
{
    int lowswaps = 0;                       
    int hiswaps = 0;
    int lowkeeps = 0;
    int hikeeps = 0;
    bool swappedlow = false;
    bool swappedhi = true;
    for (int i = 0; i < n/2; i++)
    {
        int lowestNumberIndex = i;  
        int highestNumberIndex = n-1-i;
        for (int j = i ; j < n-i; j++)
        {
            if (arr[j] < arr[lowestNumberIndex])
            {
                lowestNumberIndex = j;
            }
            if (arr[j] > arr[highestNumberIndex])
            {
                highestNumberIndex = j;
            }
        }
        swappedlow = false;
        swappedhi = false;
        if (lowestNumberIndex == n-1-i && highestNumberIndex == i)
        {
            int temp = arr[i];
            arr[i] = arr[n-1-i];
            arr[n-1-i] = temp;
            lowswaps++; hiswaps++;
            swappedlow = true;
            swappedhi = true;
        }
        if(highestNumberIndex == i && lowestNumberIndex != n-1-i)
        {
            int temp = arr[n-1-i];
            arr[n-1-i] = arr[highestNumberIndex];
            arr[highestNumberIndex] = temp;
            temp = arr[i];
            arr[i] = arr[lowestNumberIndex];
            arr[lowestNumberIndex] = temp;
            lowswaps++; hiswaps++;
            swappedlow = true;
            swappedhi = true;

        }
        if (lowestNumberIndex != i && swappedlow == false)
        {
            int temp = arr[i];
            arr[i] = arr[lowestNumberIndex];
            arr[lowestNumberIndex] = temp;
            lowswaps++;
        }
        if(lowestNumberIndex ==i)
        {
            lowkeeps++;   
        }
        if (highestNumberIndex != n-1-i && swappedhi == false)
        {
            int temp = arr[n-1-i];
            arr[n-1-i] = arr[highestNumberIndex];
            arr[highestNumberIndex] = temp;
            hiswaps++;
        }
        else if(highestNumberIndex ==n-1-i)
        {
            hikeeps++;
        }
    }
    cout << "low swaps: " << lowswaps << endl << "hi swaps: " << hiswaps << endl;
    cout << "low keeps: " << lowkeeps << endl << "hi keeps: " << hikeeps << endl;
    cout << "total(swaps + keeps) = " << lowswaps + hiswaps + lowkeeps + hikeeps << endl;
}
void insertionsort(int arr[], int n)       
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        j = i;
        while( j > 0 && arr[j-1] > arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}


void animatedbubblesort(int arr[], int n)
{
    system("clear");
    bool noswap;                             
    do
    {    
        noswap = true;
        for (int j = 0; j < n-1; j++)           
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                noswap = false;  
            }
            for(int i = 0; i < arr[j]; i++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }while(!noswap);
    usleep(100000);
}

void animateddoublebubblesort(int arr[], int n)
{
    bool noswap;                             
    do
    {    
        noswap = true;
        for (int j = 0; j < n-1; j++)           
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                noswap = false;  
            }  
            if(arr[n-1-j] < arr[n-2-j])
            {
                int temp = arr[n-1-j];
                arr[n-1-j] = arr[n-2-j];
                arr[n-2-j] = temp;
                noswap = false;  
            }
        }
    }while(!noswap);
}

void animatedselectionsort(int arr[], int n)
{
    int lowswaps = 0;                      
    int lowkeeps = 0;
    for (int i = 0; i < n; i++)
    {
        int lowestNumberIndex = i;  
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[lowestNumberIndex])
            {
                lowestNumberIndex = j;
            }
        }
        if (lowestNumberIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[lowestNumberIndex];
            arr[lowestNumberIndex] = temp;
            lowswaps++;
        }
        else
            lowkeeps++;   
    }
    cout << "low swaps: " << lowswaps << endl << "low keeps: " << lowkeeps << endl;
    cout << "total(swaps + keeps) = " << lowswaps + lowkeeps  << endl;
}


void animateddoubleselectionsort(int arr[], int n)
{
    int lowswaps = 0;                       
    int hiswaps = 0;
    int lowkeeps = 0;
    int hikeeps = 0;
    bool swappedlow = false;
    bool swappedhi = true;
    for (int i = 0; i < n/2; i++)
    {
        int lowestNumberIndex = i;  
        int highestNumberIndex = n-1-i;
        for (int j = i ; j < n-i; j++)
        {
            if (arr[j] < arr[lowestNumberIndex])
            {
                lowestNumberIndex = j;
            }
            if (arr[j] > arr[highestNumberIndex])
            {
                highestNumberIndex = j;
            }
        }
        swappedlow = false;
        swappedhi = false;
        if (lowestNumberIndex == n-1-i && highestNumberIndex == i)
        {
            int temp = arr[i];
            arr[i] = arr[n-1-i];
            arr[n-1-i] = temp;
            lowswaps++; hiswaps++;
            swappedlow = true;
            swappedhi = true;
        }
        if(highestNumberIndex == i && lowestNumberIndex != n-1-i)
        {
            int temp = arr[n-1-i];
            arr[n-1-i] = arr[highestNumberIndex];
            arr[highestNumberIndex] = temp;
            temp = arr[i];
            arr[i] = arr[lowestNumberIndex];
            arr[lowestNumberIndex] = temp;
            lowswaps++; hiswaps++;
            swappedlow = true;
            swappedhi = true;

        }
        if (lowestNumberIndex != i && swappedlow == false)
        {
            int temp = arr[i];
            arr[i] = arr[lowestNumberIndex];
            arr[lowestNumberIndex] = temp;
            lowswaps++;
        }
        if(lowestNumberIndex ==i)
        {
            lowkeeps++;   
        }
        if (highestNumberIndex != n-1-i && swappedhi == false)
        {
            int temp = arr[n-1-i];
            arr[n-1-i] = arr[highestNumberIndex];
            arr[highestNumberIndex] = temp;
            hiswaps++;
        }
        else if(highestNumberIndex ==n-1-i)
        {
            hikeeps++;
        }
    }
    cout << "low swaps: " << lowswaps << endl << "hi swaps: " << hiswaps << endl;
    cout << "low keeps: " << lowkeeps << endl << "hi keeps: " << hikeeps << endl;
    cout << "total(swaps + keeps) = " << lowswaps + hiswaps + lowkeeps + hikeeps << endl;
}
void animatedinsertionsort(int arr[], int n)       
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        j = i;
        while( j > 0 && arr[j-1] > arr[j])
        {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

