#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <math.h>
#define N 100
#define M 20

//  Functions.  -------------------------------------------------------------------------------------------------------------------------------------------------------
void keys(char key);   // Back, Reset and Quit command handler.
void signup(FILE *fp); // Signup yourself.
void list();           // List of all Programs.

void searching();
int linearSearch(int *a, int beg, int end, int x);
int jumpSearch(int *a, int beg, int end, int x);
int binarySearch(int *a, int beg, int end, int x);
int interpolationSearch(int *a, int beg, int end, int x);
int exponentialSearch(int *a, int beg, int end, int x);

void sorting();
void selectionSort(int *a, int beg, int end);
void bubbleSort(int *a, int beg, int end);
void insertionSort(int *a, int beg, int end);
void combSort(int *a, int beg, int end);
void bitonicSort(int *a, int beg, int end, int x);
void bitonicMerge(int *a, int beg, int end, int x);
void bitonicSwap(int *a, int beg, int end, int x);
void pegionholeSort(int *a, int beg, int end);
void quickSort(int *a, int beg, int end);
void normalQuickSort(int *a, int beg, int end, int code);
void tailOptimizationQuickSort(int *a, int beg, int end, int code);
int lomutoPartitionScheme(int *a, int beg, int end);
int hoarePartitionScheme(int *a, int beg, int end);
void mergeSort(int *a, int beg, int end);
void mergeAll(int *a, int beg, int mid, int end);
void heapSort(int *a, int beg, int end);
void heapify(int *a, int end, int i);
void array(int *a, int n);

void maths();
void factorial();
int fac(int n);

void pattern();
void star(int n);
void hollowStar(int n);
void hollowStarInRect(int n);
void butterfly(int n);
void floyed();
void pascal();
void pattern1();
void pattern2();
void fibonacci();
int fib(int n);

void matrix();

void sum();
void difference();
void multiplication();
void input(int **num, int x, int y);
void output(int **num, int x, int y);
void login(FILE *fp);
void details(FILE *fp);
void finish();

//  Variables.  ----------------------------------------------------------------------------------------------------------------------------------------------------
char choose;
struct Registor
{
    char name[M];
} registor;

//  Programs.   -------------------------------------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------- ( Home Page ) --------------------------------------------------------------------------------
int main()
{
    system("cls");
    FILE *fp = malloc(sizeof(registor));
    fp = fopen("warehouse.txt", "a+");

rev:;
    printf("WELCOME\n");
    printf("-------\n");
    printf("[1]: Fill Details\n");
    printf("[2]: View Details\n\n");
    printf("^> Please choose one (To quit, press \"q/Q\"): ");
    scanf(" %c", &choose);
    switch (choose)
    {
    case '1':
        signup(fp);
        break;
    case '2':
        login(fp);
        break;
    case 'q':
    case 'Q':
        finish();
        break;
    default:
        system("cls");
        printf("Error! Please choose it carefully.\n\n");
        goto rev;
    }
}

// ---------------------------------------------------------------------------- ( Keys ) --------------------------------------------------------------------------------
void keys(char key)
{
    printf("\n\n");
    if (key != '0')
        printf("^> Please choose one (To back, press \"b/B\" | To reset, press \"r/R\" | To quit, press \"q/Q\"): ");
    else
        printf("^> Please choose one (To back, press \"b/B\" | To quit, press \"q/Q\"): ");
    scanf(" %c", &choose);
    switch (choose)
    {
    case 'b':
    case 'B':
        switch (key)
        {
        case '0':
            main();
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            list();
            break;
        default:
            break;
        }
    case 'r':
    case 'R':
        switch (key)
        {
        case '1':
            searching();
            break;
        case '2':
            sorting();
            break;
        case '3':
            maths();
            break;
        case '4':
            pattern();
            break;
        case '5':
            matrix();
            break;
        default:
            break;
        }
    case 'q':
    case 'Q':
        finish();
        break;
    default:
        system("cls");
        printf("Error! Please choose it carefully.\n");
        keys(key);
    }
}

// ---------------------------------------------------------------------------- ( Registation Page ) --------------------------------------------------------------------------------
void signup(FILE *fp)
{
    system("cls");
    printf("SIGNUP\n");
    printf("------\n");
    printf("Name: ");
    scanf(" %[^\n]", &registor.name);
    fflush(stdin);
    fputs("->", fp);
    fputs(registor.name, fp);
    fputs("\n", fp);
    fclose(fp);
    list();
}

// ---------------------------------------------------------------------------- ( Program List Page ) --------------------------------------------------------------------------------
void list()
{
    system("cls");
rev:;
    printf("PROGRAMS\n");
    printf("--------\n");
    printf("[1]: Searching\n");
    printf("[2]: Sorting\n");
    printf("[3]: Mathematical Terms\n");
    printf("[4]: Pattern\n");
    printf("[5]: Matrix\n\n");
    printf("^> Please choose one (To quit, press \"q/Q\"): ");
    scanf("%c", &choose);
    switch (choose)
    {
    case '1':
        searching();
        break;
    case '2':
        sorting();
        break;
    case '3':
        maths();
        break;
    case '4':
        pattern();
        break;
    case '5':
        matrix();
        break;
    case 'q':
    case 'Q':
        finish();
        break;
    default:
        system("cls");
        printf("Error! Please choose it carefully.\n\n");
        goto rev;
    }
}

// ---------------------------------------------------------------------------- ( 1. Searching ) --------------------------------------------------------------------------------
void searching()
{
    system("cls");
    int n, x, i;
    printf("SEARCHING ALGORITHM\n");
    printf("-------------------\n");
    printf("It is the process of finding element in the list.\n\n");

    printf("^> Enter the length of the array: ");
    scanf("%d", &n);

    int *a = malloc(sizeof(int) * n);
    printf("^> Enter the element of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", (a + i));

    printf("^> Enter the number you want to Search: ");
    scanf(" %d", &x);
rev:;
    printf("\n");
    printf("[1]: Linear Search\n");
    printf("[2]: Jump Search\n");
    printf("[3]: Binary Search\n");
    printf("[4]: Interpolation Search\n");
    printf("[5]: Exponential Search\n\n");
    printf("^> Please choose one: ");
    scanf(" %c", &choose);
    system("cls");
    switch (choose)
    {
    case '1':
        printf("LINEAR SEARCH\n");
        printf("-------------\n");
        printf("It is a Searching Algorithm to find an element in the list using sequencial comparing.\n");
        printf("Time Complexity: O(n)\n");
        printf("Auxilary Space: O(1)\n\n");
        array(a, n - 1);
        i = linearSearch(a, 0, n - 1, x);
        break;
    case '2':
        printf("JUMP SEARCH\n");
        printf("-----------\n");
        printf("It is a Searching Algorithm to find an element in the list by jumping ahead by some fixed steps and check using linear search.\n");
        printf("Time Complexity: O(n^0.5)\n");
        printf("Auxilary Space: O(1)\n\n");
        mergeSort(a, 0, n - 1);
        array(a, n - 1);
        i = jumpSearch(a, 0, n - 1, x);
        break;
    case '3':
        printf("BINARY SEARCH\n");
        printf("-------------\n");
        printf("It is a Searching Algorithm to find an element in the sorted list by repeatly divide the search interval in half.\n");
        printf("Time Complexity: O(log(n))\n");
        printf("Auxilary Space: O(1)\n\n");
        mergeSort(a, 0, n - 1);
        array(a, n - 1);
        i = binarySearch(a, 0, n - 1, x);
        break;
    case '4':
        printf("INTERPOLATION SEARCH\n");
        printf("--------------------\n");
        printf("It is a Searching Algorithm to find an element in the sorted list by going different location in the list according to the value of the element.\n");
        printf("General equation : y = m*x + c\n"
               "\t\ta[end] = m*end + c  --- (1)\n"
               "\t\ta[begin] = m*begin + c --- (2)\n"
               "\t\tX = m*position + c --- (3)\n"
               "\t\tsubtract (2) from (3)\n"
               "\t\tX - a[begin] = m*position - m*begin\n"
               "\t\tposition = begin + (X - a[begin])*(end - begin) / (a[end] - a[begin])\n");
        printf("Time Complexity: O(log(n))\n");
        printf("Auxilary Space: O(1)\n\n");
        mergeSort(a, 0, n - 1);
        array(a, n - 1);
        i = interpolationSearch(a, 0, n - 1, x);
        break;
    case '5':
        printf("EXPONENTIAL SEARCH\n");
        printf("------------------\n");
        printf("It is a Searching Algorithm to find an element in the sorted and unbounded list for a specified input value.\n");
        printf("Time Complexity: O(log(n))\n");
        printf("Auxilary Space: O(1)\n\n");
        mergeSort(a, 0, n - 1);
        array(a, n - 1);
        i = exponentialSearch(a, 0, n - 1, x);
    default:
        printf("Error! Please choose it carefully.\n");
        goto rev;
    }

    (i != -1) ? printf("Data found at postion %d.", i) : printf("Data not found.");
    keys('1');
}

// Time Complexity: O(n).
// Auxilary Space: O(1).
int linearSearch(int *a, int beg, int end, int x)
{
    for (int i = beg; i <= end; i++)
    {
        printf("-> Element %d is comparing with the list number %d.\n", x, *(a + i));
        if (*(a + i) == x)
            return i;
    }
    return -1;
}

// Time Complexity : O(n^0.5).
// Auxilary Space : O(1).
int jumpSearch(int *a, int beg, int end, int x)
{
    int i, d = sqrt(end - beg);
    printf("-> %d is the distance to jump ahead. It should be calculated as square root of %d.\n", d, (end - beg));

    for (i = beg; i <= end; i += d)
    {
        printf("-> Element %d is comparing with the number %d.\n", x, *(a + i));
        if (x == *(a + i))
            return i;

        if (x < *(a + i))
        {
            printf("-> Element %d is smaller than the number %d.\n", x, *(a + i));
            printf("-> Performing linear search between position %d to %d.\n", (i - d), i);
            return linearSearch(a, i - d, i, x);
        }
    }
    printf("-> Performing linear search between position %d to %d.\n", (i - d), end);
    linearSearch(a, i - d, end, x);
}

// Time Complexity : O(logn).
//  Auxilary Space : O(1).
int binarySearch(int *a, int beg, int end, int x)
{
    if (beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        printf("-> Middle postion in the current list is %d.\n", mid);
        printf("-> Element %d is comparing with the list number %d.\n", x, *(a + mid));
        if (*(a + mid) == x)
            return mid;

        if (*(a + mid) > x)
        {
            printf("-> Element is smaller than the list number. Moving to left side of the list.\n");
            return binarySearch(a, beg, mid - 1, x);
        }
        else
        {
            printf("-> Element is greater than the list number. Moving to right side of the list.\n");
            return binarySearch(a, mid + 1, end, x);
        }
    }
    return -1;
}

// Time Complexity : O(logn).
//  Auxilary Space : O(1).
int interpolationSearch(int *a, int beg, int end, int x)
{
    if (beg <= end && x >= *(a + beg) && x <= *(a + end))
    {
        int pos = beg + (x - *(a + beg)) * (end - beg) / (*(a + end) - *(a + beg));
        printf("-> Position of the element using above formula is %d.\n", pos);
        printf("-> Element %d is comparing with the list number %d.\n", x, *(a + pos));
        if (*(a + pos) == x)
            return pos;

        if (*(a + pos) > x)
        {
            printf("-> Element is smaller than the list number. Moving to left side of the list.\n");
            return interpolationSearch(a, beg, pos - 1, x);
        }
        else
        {
            printf("-> Element is greater than the list number. Moving to right side of the list.\n");
            return interpolationSearch(a, pos + 1, end, x);
        }
    }
    return -1;
}

// Time Complexity: O(log(n)).
// Auxilary Space: O(1) to O(log(n)).
int exponentialSearch(int *a, int beg, int end, int x)
{
    printf("-> Comparing first number %d of the list with given element %d.", *(a + beg), x);
    if (*(a + beg++) == x)
        return -1;

    while (beg <= end && *(a + beg) <= x)
    {
        beg *= 2;
        printf("-> Postion of the number in the list till list number is greater than given element: %d", beg);
    }

    int min = (beg > end) ? end : beg;
    printf("-> Performing Binary Search between interval %d to %d.", beg / 2, min);
    return binarySearch(a, beg / 2, min, x);
}

// ---------------------------------------------------------------------------- ( 2. Sorting ) --------------------------------------------------------------------------------
void sorting()
{
    system("cls");
    int n, i, j;
    printf("SORTING ALGORITHM\n");
    printf("-----------------\n");
    printf("It is a method for reorganizing a large number of items into a specific order.\n\n");
    printf("^> Enter the length of the Array: ");
    scanf("%d", &n);

    int *a = malloc(sizeof(int) * n);
    printf("^> Enter the element of the array: ");
    for (i = 0; i < n; i++)
        scanf("%lld", (a + i));
rev:;
    printf("\n");
    printf("[1]: Selection Sort\n");
    printf("[2]: Bubble Sort\n");
    printf("[3]: Insertion Sort\n");
    printf("[4]: Comb Sort\n");
    printf("[5]: Bitonic Sort\n");
    printf("[6]: Pegionhole Sort\n");
    printf("[7]: Quick Sort\n");
    printf("[8]: Merge Sort\n");
    printf("[9]:. Heap Sort\n\n");
    printf("^> Please choose one: ");
    scanf(" %c", &choose);
    system("cls");
    switch (choose)
    {
    case '1':
        printf("SELECTION SORT\n");
        printf("--------------\n");
        printf("It is an array by repeatedly finding the minimum element from unsorted part and putting it at the beginning.\n");
        printf("Time Complexity: O(n^2)\n");
        printf("Auxiliary Space: O(1)\n\n");
        printf("Unsorted List\n");
        array(a, n - 1);
        selectionSort(a, 0, n - 1);
        break;
    case '2':
        printf("BUBBLE SORT\n");
        printf("-----------\n");
        printf("It is an array that works by repeatedly swapping the adjacent elements if they are in the wrong order.\n");
        printf("Time Complexity: O(n^2) to O(n)\n");
        printf("Auxiliary Space: O(1)\n\n");
        printf("Unsorted List\n");
        array(a, n - 1);
        bubbleSort(a, 0, n - 1);
        break;
    case '3':
        printf("INSERTION SORT\n");
        printf("--------------\n");
        printf("It is an array that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.\n");
        printf("Time Complexity: O(n^2) to O(n)\n");
        printf("Auxiliary Space: O(1)\n\n");
        printf("Unsorted List\n");
        array(a, n - 1);
        insertionSort(a, 0, n - 1);
        break;
    case '4':
        printf("COMB SORT\n");
        printf("---------\n");
        printf("It is a simple comparison-based sorting algorithm. It is an improved form of bubble sort.\n");
        printf("Time Complexity: O(n^2) to O(n)\n");
        printf("Auxiliary Space: O(1)\n\n");
        printf("Unsorted List\n");
        array(a, n - 1);
        combSort(a, 0, n - 1);
        break;
    case '5':
        printf("BITONIC SORT\n");
        printf("------------\n");
        printf("It is a classic parallel algorithm for sorting.\n\n");
        printf("Unsorted List\n");
        array(a, n - 1);
        printf("{1}: First element is greater than Second element         {2}. Second element is greater than first element.\n");
        bitonicSort(a, 0, n, 1);
        break;
    case '6':
        printf("PEGIONHOLE SORT\n");
        printf("---------------\n");
        printf("It is an array that is suitable for sorting lists of elements where the number of elements (n) and the length of the range of possible key values (N) are approximately the same.\n\n");
        printf("Unsorted List\n");
        array(a, n - 1);
        pegionholeSort(a, 0, n - 1);
        break;
    case '7':
        printf("Unsorted List\n");
        array(a, n - 1);
        quickSort(a, 0, n - 1);
        break;
    case '8':
        printf("MERGE SORT\n");
        printf("----------\n");
        printf("It is an array that is considered as an example of the divide and conquer strategy. So, in this algorithm, the array is initially divided into two equal halves and then they are combined in a sorted manner.\n\n");
        printf("Unsorted List\n");
        array(a, n - 1);
        mergeSort(a, 0, n - 1);
        break;
    case '9':
        printf("HEAP SORT\n");
        printf("---------\n");
        printf("It is a comparison-based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the minimum element and place the minimum element at the beginning. We repeat the same process for the remaining elements.\n\n");
        printf("Unsorted List\n");
        array(a, n - 1);
        heapSort(a, 0, n - 1);
        break;
    default:
        printf("Error! Please choose it carefully.\n");
        goto rev;
    }
    printf("Sorted List\n");
    array(a, n - 1);
    keys('2');
}

// Time Complexity : O(n^2).
// Space Complexity : O(n).
void selectionSort(int *a, int beg, int end)
{
    for (int i = beg; i <= end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            printf("-> First element %d is comparing with Second element %d.\n", *(a + i), *(a + j));
            if (*(a + i) > *(a + j))
            {
                printf("-> First element %d is greater than Second element %d. so, we swaped it.\n", *(a + i), *(a + j));
                int change = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = change;
                array(a, end);
            }
        }
    }
}

// Time Complexity : O(n^2) (worst case) to O(n) (Best case).
// Space Complexity : O(1).
void bubbleSort(int *a, int beg, int end)
{
    for (int i = beg; i < end; i++)
    {
        for (int j = beg; j < end - i; j++)
        {
            printf("-> First element %d is comparing with alternating element %d.\n", *(a + j), *(a + j + 1));
            if (*(a + j) > *(a + j + 1))
            {
                printf("-> First element %d is greater than alternating element %d. so, we swaped it.\n", *(a + j), *(a + j + 1));
                int change = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = change;
                array(a, end);
            }
        }
    }
}

//  Time Complexity : O(n^2).
// Space Complexity : O(1).
void insertionSort(int *a, int beg, int end)
{
    int i, j, key;
    for (i = beg + 1; i <= end; i++)
    {
        key = *(a + i);
        j = i - 1;
        printf("-> Taken a key as %d and position of element is %d.\n", key, j);
        while (j >= beg && *(a + j) > key)
        {
            printf("-> %d element is greater than key element %d.\n", *(a + j + 1), key);
            *(a + j + 1) = *(a + j);
            j -= 1;
            array(a, end);
        }
        *(a + j + 1) = key;
        array(a, end);
    }
}

//  Time Complexity : O((n^2)/(2^p)) p = no. of increment.
// Auxilary Space : O(1).
// Improvement over Bubble Sort.
void combSort(int *a, int beg, int end)
{
    int gap = end + 1;
    int check = 1;
    while (gap != 1 || check == 1)
    {
        gap = (gap < 1) ? 1 : gap / 1.3;
        printf("-> The gap with a value %d.\n", gap);
        check = 0;
        for (int i = beg; i < (end + 1 - gap); i++)
        {
            printf("-> First element %d is comparing with element %d.\n", *(a + i), *(a + i + gap));
            if (*(a + i) > *(a + i + gap))
            {
                printf("-> First element %d is greater than element %d. so, we swaped it.\n", *(a + i), *(a + i + gap));
                int change = *(a + i);
                *(a + i) = *(a + i + gap);
                *(a + i + gap) = change;
                check = 1;
            }
        }
    }
}

void bitonicSort(int *a, int beg, int end, int x)
{
    if (end > 1)
    {
        printf("-> Entering array from %d to %d with value %d.\n", beg, end, x);
        int k = end / 2;
        printf("-> Dividing array into two parts %d to %d and %d to %d.\n", beg, k, k + 1, end);
        bitonicSort(a, beg, k, 1);
        bitonicSort(a, beg + k, k, 0);
        bitonicMerge(a, beg, end, x);
    }
}

void bitonicMerge(int *a, int beg, int end, int x)
{
    if (end > 1)
    {
        printf("-> Swaping array elements from %d to %d with value %d under required condition.\n", beg, end, x);
        int k = end / 2;
        for (int i = beg; i < (beg + k); i++)
            bitonicSwap(a, i, i + k, x);
        bitonicMerge(a, beg, k, x);
        bitonicMerge(a, beg + k, k, x);
    }
}

void bitonicSwap(int *a, int beg, int end, int x)
{
    if ((*(a + beg) > *(a + end) && x == 1) || (*(a + beg) < *(a + end) && x == 0))
    {
        printf("-> Swaping %d and %d.\n", *(a + beg), *(a + end));
        int change = *(a + beg);
        *(a + beg) = *(a + end);
        *(a + end) = change;
    }
    else
        printf("-> Swaping is not possible.\n");
}

void pegionholeSort(int *a, int beg, int end)
{
    int min = *a, max = *a;
    for (int i = beg + 1; i <= end; i++)
    {
        if (*(a + i) > max)
            max = *(a + i);

        if (*(a + i) < min)
            min = *(a + i);
    }

    int range = max - min + 1;
    int *ph = malloc(sizeof(int) * range);
    for (int i = beg; i < range; i++)
        *(ph + i) = 0;

    for (int i = beg; i <= end; i++)
        (*(ph + *(a + i) - min))++;

    int index = beg;
    for (int i = beg; i < range; i++)
        while ((*(ph + i))-- > 0)
            *(a + index++) = (i + min);
}

void quickSort(int *a, int beg, int end)
{
    system("cls");
rev:;
    printf("QUICK SORT\n");
    printf("----------\n");
    printf("It is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.\n\n");
    printf("[1]: Normal Quick Sort with Lomuto Partition Scheme.\n");
    printf("[2]: Normal Quick Sort with Hoare Partition Scheme.\n");
    printf("[3]: Tail Optimization Quick Sort with Lomuto Partition Scheme.\n");
    printf("[4]: Tail Optimization Quick Sort with Hoare Partition Scheme.\n");
    printf("Please choose one: ");
    scanf(" %c", &choose);
    system("cls");
    switch (choose)
    {
    case '1':
        printf("NORMAL QUICK SORT WITH LOMUTO PARTION SCHEME.\n");
        normalQuickSort(a, beg, end, 1);
        break;
    case '2':
        printf("NORMAL QUICK SORT WITH LOMUTO PARTION SCHEME.\n");
        normalQuickSort(a, beg, end, 2);
        break;
    case '3':
        printf("NORMAL QUICK SORT WITH LOMUTO PARTION SCHEME.\n");
        tailOptimizationQuickSort(a, beg, end, 1);
        break;
    case '4':
        printf("NORMAL QUICK SORT WITH LOMUTO PARTION SCHEME.\n");
        tailOptimizationQuickSort(a, beg, end, 2);
        break;
    default:
        system("cls");
        printf("Error! Please press a key carefully.");
        goto rev;
    }
}

// NORMAL PROCESS.
// Time Complexity : O(nlogn).
// Space Complexity : O(logn).
void normalQuickSort(int *a, int beg, int end, int code)
{
    if (beg < end)
    {
        int p = (code == 1) ? lomutoPartitionScheme(a, beg, end) : hoarePartitionScheme(a, beg, end);
        normalQuickSort(a, beg, p - 1, code);
        normalQuickSort(a, p + 1, end, code);
    }
}

void tailOptimizationQuickSort(int *a, int beg, int end, int code)
{
    while (beg < end)
    {
        int p = (code == 1) ? lomutoPartitionScheme(a, beg, end) : hoarePartitionScheme(a, beg, end);
        if ((p - beg) < (end - p))
        {
            tailOptimizationQuickSort(a, beg, p - 1, code);
            beg = p + 1;
        }
        else
        {
            tailOptimizationQuickSort(a, p + 1, end, code);
            end = p - 1;
        }
    }
}

int lomutoPartitionScheme(int *a, int beg, int end)
{
    int pivot = *(a + end);
    int i = beg - 1;
    int j, change;

    for (j = beg; j < end; j++)
    {
        if (*(a + j) < pivot)
        {
            i++;
            change = *(a + i);
            *(a + i) = *(a + j);
            *(a + j) = change;
        }
    }

    change = *(a + i + 1);
    *(a + i + 1) = *(a + end);
    *(a + end) = change;

    return (i + 1);
}

int hoarePartitionScheme(int *a, int beg, int end)
{
    int pivot = *(a + beg);
    int i = beg - 1;
    int j = end + 1;

    while (1)
    {
        do
        {
            i++;
        } while (*(a + i) < pivot);

        do
        {
            j--;
        } while (*(a + j) > pivot);

        if (i >= j)
            return j;
        int change = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = change;
    }
}

// Time Complexity : O(nlogn).
// Space Complexity : O(n).
void mergeSort(int *a, int beg, int end)
{
    if (beg < end)
    {
        int mid = beg + (end - beg) / 2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid + 1, end);
        mergeAll(a, beg, mid, end);
    }
}

void mergeAll(int *a, int beg, int mid, int end)
{
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    int arr1[n1], arr2[n2], i, j, k = beg;

    for (j = 0; j < n1; j++)
        arr1[j] = a[beg + j];

    for (i = 0; i < n2; i++)
        arr2[i] = a[mid + 1 + i];

    i = 0, j = 0;
    while (j < n1 && i < n2)
    {
        if (arr1[j] <= arr2[i])
        {
            a[k] = arr1[j];
            j++;
        }
        else
        {
            a[k] = arr2[i];
            i++;
        }
        k++;
    }

    while (j < n1)
    {
        a[k] = arr1[j];
        j++;
        k++;
    }

    while (i < n2)
    {
        a[k] = arr2[i];
        i++;
        k++;
    }
}

void heapSort(int *a, int beg, int end)
{
    for (int i = end / 2 - 1; i >= beg; i--)
        heapify(a, end, i);

    for (int i = end - 1; i > beg; i--)
    {
        int temp = *a;
        *a = *(a + i);
        *(a + i) = temp;
        heapify(a, i, 0);
    }
}

void heapify(int *a, int end, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l<end &&*(a + l)> * (a + largest))
        largest = l;

    if (r<end &&*(a + r)> * (a + largest))
        largest = r;

    if (largest != i)
    {
        int swap = *(a + i);
        *(a + i) = *(a + largest);
        *(a + largest) = swap;

        heapify(a, end, largest);
    }
}

void array(int *a, int n)
{
    printf("# List:- ");
    for (int i = 0; i <= n; i++)
        printf("%d ", *(a + i));
    printf("\n");
}

// ---------------------------------------------------------------------------- ( 3. Mathematical Terms ) --------------------------------------------------------------------------------
void maths()
{
    system("cls");
    printf("Mathematical Terms\n");
    printf("------------------\n");
    printf("defination.\n\n");
    keys('3');
}

void factorial()
{
    system("cls");
    int n;
    printf("FACTORIAL\n");
    printf("---------\n");
    printf("The product of an integer and all the integers below it.\n");
    printf("Time Complexity: O(n)\n");
    printf("Auxilary Space: O(1)\n\n");
    printf("^> Enter a  number: ");
    scanf("%d", &n);
    printf("\nFactorial of %d is %d ", n, fac(n));
}

int fac(int n)
{
    if (n == 1)
    {
        printf("# List:- 1 ");
        return 1;
    }

    n *= fac(n - 1);
    printf("%d ", n);
    return n;
}

// ---------------------------------------------------------------------------- ( 4. Pattern ) --------------------------------------------------------------------------------
void pattern()
{
    system("cls");
    printf("PATTERN\n");
    printf("-------\n");
    printf("It is a repeated decorative design.\n\n");

    int n;
    printf("^> Enter a odd number: ");
    scanf("%d", &n);
rev:;
    printf("\n");
    printf("Asterisks Pattern\n");
    printf(".................\n");
    printf("[1]: Star\n");
    printf("[2]: Hollow Star\n");
    printf("[3]: Hollow star in rectangle\n");
    printf("[4]: Butterfly Pattern\n\n");

    printf("Number Pattern\n");
    printf("..............\n");
    printf("[5]: Floyed Triangle\n");
    printf("[6]: Pascal Triangle\n");
    printf("[7]: Pattern 1\n");
    printf("[8]: Pattern 2\n\n");
    printf("^> Please choose one (To quit, press \"q/Q\"): ");
    scanf(" %c", &choose);
    switch (choose)
    {
    case '1':
        star(n);
        break;
    case '2':
        hollowStar(n);
        break;
    case '3':
        hollowStarInRect(n);
        break;
    case '4':
        butterfly(n);
        break;
    case '5':
        floyed();
        break;
    case '6':
        pascal();
        break;
    case '7':
        pattern1();
        break;
    case '8':
        pattern2();
        break;
    default:
        printf("Error! Please choose it carefully.\n");
        goto rev;
    }
    keys('4');
}

void star(int n)
{
    system("cls");
    printf("STAR PATTERN\n");
    printf("------------\n\n");

    for (int i = 0; i < n; i++)
    {
        if (i < (n + 1) / 2)
            for (int j = 0; j <= (n + 1) / 2 + i; j++)
                (j >= (n + 1 - 2 * i) / 2) ? printf("*") : printf(" ");
        else
            for (int j = 0; j <= 3 * n / 2 - i; j++)
                (j > i - n / 2) ? printf("*") : printf(" ");
        printf("\n");
    }

    printf("\n");
    keys('4');
}

void hollowStar(int n)
{
    system("cls");
    printf("HOLLOW STAR PATTERN\n");
    printf("-------------------\n\n");

    for (int i = 0; i < n; i++)
    {
        if (i < (n + 1) / 2)
            for (int j = 0; j <= (n + 1) / 2 + i; j++)
                (j == (n + 1 - 2 * i) / 2 || j == (n + 1) / 2 + i) ? printf("*") : printf(" ");
        else
            for (int j = 0; j <= 3 * n / 2 - i; j++)
                (j == i + 1 - n / 2 || j == 3 * n / 2 - i) ? printf("*") : printf(" ");
        printf("\n");
    }

    printf("\n");
    keys('4');
}

void hollowStarInRect(int n)
{
    system("cls");
    printf("HOLLOW STAR IN RECTANGLE PATTERN\n");
    printf("--------------------------------\n\n");

    for (int i = 0; i < n; i++)
    {
        if (i < (n + 1) / 2)
            for (int j = 0; j < n; j++)
                (j >= (n + 1 - 2 * i) / 2 && j < n / 2 + i) ? printf(" ") : printf("*");
        else
            for (int j = 0; j < n; j++)
                (j > i - n / 2 && j < 3 * n / 2 - i - 1) ? printf(" ") : printf("*");
        printf("\n");
    }

    printf("\n");
    keys('4');
}

void butterfly(int n)
{
    system("cls");
    printf("BUTTERFLY PATTERN\n");
    printf("-----------------\n\n");

    for (int i = 0; i < n; i++)
    {
        if (i < (n + 1) / 2)
            for (int j = 0; j < n; j++)
                (j <= i || (n - 1 - i) <= j) ? printf("*") : printf(" ");
        else
            for (int j = 0; j < n; j++)
                (j < n - i || i <= j) ? printf("*") : printf(" ");
        printf("\n");
    }

    printf("\n");
    keys('4');
}

void floyed()
{
}

void pascal()
{
    system("cls");
    printf("PASCAL TRIANGLE\n");
    printf("---------------\n");
    printf("Time Complexity: O(n*2)\n");
    printf("Auxilary Space: O(1)\n\n");
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("\n");

    for (int i = 1; i <= n; i++)
    {
        int line = 1;
        for (int j = 0; j < (n - i); j++)
            printf(" ");

        for (int j = 1; j <= i; j++)
        {
            printf("%d ", line);
            line = line * (i - j) / j;
        }
        printf("\n");
    }
    keys('4');
}

void pattern1()
{
}

void pattern2()
{
}

void fibonacci()
{
    system("cls");
    printf("FIBONACCI NUMBER\n");
    printf("-----------------\n");
    printf("It is a series of numbers in which each number is the sum of the two preceding numbers.\n");
    printf("Time Complexity: O(n)\n");
    printf("Auxilary Space: O(n)\n\n");
    int n, i;
    printf("^> Enter the length: ");
    scanf("%d", &n);

    printf("# Fabonacci numbers:-  ");
    for (i = 0; i < n; i++)
        printf("%d ", fib(i));
    keys('4');
}

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

// ---------------------------------------------------------------------------- ( 5. Matrix ) --------------------------------------------------------------------------------
void matrix()
{
    system("cls");
rev:;
    printf("MATRIX\n");
    printf("------\n");
    printf("A matrix is a collection of numbers, which are organised in rows and columns.\n\n");
    printf("[1]: Sum\n");
    printf("[2]: Difference\n");
    printf("[3]: Multiplication\n\n");
    printf("^> Please choose one: ");
    scanf(" %c", &choose);
    switch (choose)
    {
    case '1':
        sum();
        break;
    case '2':
        difference();
        break;
    case '3':
        multiplication();
        break;
    default:
        system("cls");
        printf("Error! Please choose it carefully.\n\n");
        goto rev;
    }
}

void sum()
{
    system("cls");
    printf("SUM OF MATRIX\n");
    printf("-------------\n");
    printf("Time Complexity: O(n^2)\n");
    printf("Auxilary Space: O(n)\n\n");
    printf("^> Enter the number of Rows and Columns: ");
    int n;
    scanf("%d", &n);

    printf("^> Enter the First list: ");
    int **a = malloc(sizeof(int *) * n);
    input(a, n, n);

    printf("^> Enter the Second list: ");
    int **b = malloc(sizeof(int *) * n);
    input(b, n, n);
    printf("\n");

    int **sum = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        *(sum + i) = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            printf("-> Adding %d of first list and %d of second list.\n", *(*(a + i) + j), *(*(b + i) + j));
            *(*(sum + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
        }
    }

    printf("\n# First List:- \n");
    output(a, n, n);

    printf("\n# Second List:- \n");
    output(b, n, n);

    printf("\n# Sum of the List:- \n");
    output(sum, n, n);
    keys('5');
}

void difference()
{
    system("cls");
    printf("DIFFERENCE OF MATRIX\n");
    printf("--------------------\n");
    printf("Time Complexity: O(n^2)\n");
    printf("Auxilary Space: O(n)\n\n");
    printf("^> Enter the number of Rows and Columns: ");
    int n;
    scanf("%d", &n);

    printf("^> Enter the First list: ");
    int **a = malloc(sizeof(int *) * n);
    input(a, n, n);

    printf("^> Enter the Second list: ");
    int **b = malloc(sizeof(int *) * n);
    input(b, n, n);
    printf("\n");

    int **diff = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        *(diff + i) = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            printf("-> Subtracting %d of second list from %d of first list.\n", *(*(b + i) + j), *(*(a + i) + j));
            *(*(diff + i) + j) = *(*(a + i) + j) - *(*(b + i) + j);
        }
    }

    printf("\n# First List:- \n");
    output(a, n, n);

    printf("\n# Second List:- \n");
    output(b, n, n);

    printf("\n# Difference of the List:- \n");
    output(diff, n, n);
    keys('5');
}

void multiplication()
{
    system("cls");
    printf("MULTIPLICATION OF MATRIX\n");
    printf("------------------------\n");
    printf("Time Complexity: O(n*m)\n");
    printf("Auxilary Space: O(n)\n\n");
    int n, m;
    printf("^> Enter the number of Rows: ");
    scanf("%d", &n);
    printf("^> Enter the number of Columns: ");
    scanf("%d", &m);

    printf("^> Enter the First list: ");
    int **a = malloc(sizeof(int *) * n);
    input(a, n, m);

    printf("^> Enter the Second list: ");
    int **b = malloc(sizeof(int *) * m);
    input(b, m, n);
    printf("\n");

    int **mul = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        *(mul + i) = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++)
        {
            *(*(mul + i) + j) = 0;
            for (int k = 0; k < m; k++)
            {
                printf("-> Multiply %d of first list from %d of second list.\n", *(*(a + i) + k), *(*(b + k) + j));
                *(*(mul + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
            }
        }
    }

    printf("\n# First List:- \n");
    output(a, n, m);

    printf("\n# Second List:- \n");
    output(b, m, n);

    printf("\n# Multiplication of the List:- \n");
    output(mul, n, n);
    keys('5');
}

void input(int **num, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        *(num + i) = malloc(sizeof(int) * y);
        for (int j = 0; j < y; j++)
            scanf("%d", (*(num + i) + j));
    }
}

void output(int **num, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
            printf("%5d\t", *(*(num + i) + j));
        printf("\n");
    }
}

// ---------------------------------------------------------------------------- ( Login Page ) --------------------------------------------------------------------------------
void login(FILE *fp)
{
    system("cls");
    printf("LOGIN\n");
    printf("-----\n");

    char *username = malloc(sizeof(char) * M);
    printf("Enter Username: ");
    scanf("%s", username);

    int i = 0;
    char *password = malloc(sizeof(char) * M), blank = ' ';
    printf("Enter Password: ");
    while (i < M)
    {
        *(password + i) = getch();
        blank = *(password + i);
        if (blank == 13)
            break;
        else
            printf("*");
        i++;
    }
    *(password + i) = '\0';
    i = 0;
    printf("\n\n");
    if (strcmp(username, "PMS") == 0 && strcmp(password, "nolimit") == 0)
    {
        printf("ACCESS GRANTED.\n");
        printf("Press any key to continue...");
        getch();
        details(fp);
    }
    else
    {
        printf("ACCESS DENIED.\n");
        printf("^>Please choose one (To back, press \"b/B\" | To quit, press \"q/Q\"): ");
        scanf(" %c", &choose);
        switch (choose)
        {
        case 'b':
        case 'B':
            main();
            break;
        case 'q':
        case 'Q':
            finish();
            break;
        default:
            finish();
            break;
        }
    }
}

// ---------------------------------------------------------------------------- ( Detail Page ) --------------------------------------------------------------------------------
void details(FILE *fp)
{
    system("cls");
    printf("NAMES\n");
    printf("-----\n");
    while (fgets(registor.name, M - 1, fp) != 0)
    {
        printf("%s ", registor.name);
        fflush(stdin);
    }
    fclose(fp);
    keys('0');
}

// ---------------------------------------------------------------------------- ( Exit Page ) --------------------------------------------------------------------------------
void finish()
{
    system("cls");
    for (int i = 0; i < N; i++)
        printf("-");
    printf("\n");
    for (int i = 0; i < N / 10; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == 0 || j == 1 || j == (N - 2) || j == (N - 1))
                printf("|");
            else if (i == 5 && j == 41)
            {
                printf("Thanks for Visiting.");
                j += 19;
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++)
        printf("-");
    getch();
    exit(1);
}