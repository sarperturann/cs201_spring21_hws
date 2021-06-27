#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm> 
#include <stdlib.h>
using namespace std;

//ALGORITHM - 1
int iterativeLinearSearch( int* arr, int N, int value ) {
    for ( int i = 0; i < N; i++ )
        if ( arr[i] == value )
            return i;
    return -1;
}

//ALGORITHM - 2
int recursiveLinearSearch( int* arr, int N, int value ) {
    if ( N < 0 )
        return -1;
    if ( arr[N - 1] == value )
        return N;
    return recursiveLinearSearch( arr, N - 1, value );
}

//ALGORITHM - 3
int binarySearch( int* arr, int N, int value ) {
    int low = 0, high = N - 1;
    while ( low <= high ) {
        int mid = (low + high) / 2;
        if ( arr[mid] < value )
            low = mid + 1;
        else if ( arr[mid] > value )
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

//ALGORITHM - 4
int jumpSearch( int* arr, int N, int value ) {
    int a = 0, b = sqrt(N);
    while ( arr[min(b,N) -1 ] < value ) {
        a = b;
        b = b + sqrt(N);
        
        if ( a >= N )
            return -1;
    }
    while(arr[a] < value)
    {
        a++;
        if(a == min(b , N))
            return -1; 
    }
    if(arr[a] == value)
        return a;
    else
       return -1;
}

int main() {
    //Creating arrays of different sizes and then sorting them
    const int size1 = 10;
    int* arr1 = new int[size1];  

    for( int i = 0; i < size1; i ++ ){
        arr1[i] = rand() %100; //in the range of 0 to 100
    }
    sort(arr1, arr1+size1);

    int loop = 1000000;
    cout << "First, we will test our program while size = " << size1 << endl << endl;

    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    double duration;
    clock_t startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr1, size1, arr1[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr1, size1, arr1[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr1, size1, arr1[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr1, size1, arr1[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr1, size1, arr1[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr1, size1, arr1[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr1, size1, arr1[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr1, size1, arr1[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr1, size1, arr1[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr1, size1, arr1[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr1, size1, arr1[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr1, size1, arr1[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr1, size1, arr1[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr1, size1, arr1[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr1, size1, arr1[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr1, size1, arr1[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    delete[] arr1;
    
    //**************************************************************************************
    const int size2 = 100;
    int* arr2 = new int[size2];  

    for( int i = 0; i < size2; i ++ ){
        arr2[i] = rand() %1000; //in the range of 0 to 1000
    }
    sort(arr2, arr2+size2);

    cout << "Now, we will test our program while size = " << size2 << endl << endl;

    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr2, size2, arr2[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr2, size2, arr2[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr2, size2, arr2[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr2, size2, arr2[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr2, size2, arr2[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr2, size2, arr2[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr2, size2, arr2[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr2, size2, arr2[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr2, size2, arr2[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr2, size2, arr2[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr2, size2, arr2[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr2, size2, arr2[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr2, size2, arr2[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr2, size2, arr2[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr2, size2, arr2[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr2, size2, arr2[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    
    delete[] arr2;
    //**************************************************************************************
    const int size3 = 500;
    int* arr3 = new int[size3];  

    for( int i = 0; i < size3; i ++ ){
        arr3[i] = rand() %5000; //in the range of 0 to 5000
    }
    sort(arr3, arr3+size3);

    cout << "Now, we will test our program while size = " << size3 << endl << endl;

    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr3, size3, arr3[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr3, size3, arr3[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr3, size3, arr3[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr3, size3, arr3[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr3, size3, arr3[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr3, size3, arr3[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr3, size3, arr3[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr3, size3, arr3[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr3, size3, arr3[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr3, size3, arr3[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr3, size3, arr3[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr3, size3, arr3[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr3, size3, arr3[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr3, size3, arr3[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr3, size3, arr3[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr3, size3, arr3[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    
    delete[] arr3;
    //**************************************************************************************
    const int size4 = 1000;
    int* arr4 = new int[size4];  

    for( int i = 0; i < size4; i ++ ){
        arr4[i] = rand() %10000; //in the range of 0 to 10000
    }
    sort(arr4, arr4+size4);

    cout << "Now, we will test our program while size = " << size4 << endl << endl;
    
    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr4, size4, arr4[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr4, size4, arr4[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr4, size4, arr4[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr4, size4, arr4[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr4, size4, arr4[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr4, size4, arr4[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr4, size4, arr4[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr4, size4, arr4[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr4, size4, arr4[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr4, size4, arr4[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr4, size4, arr4[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr4, size4, arr4[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr4, size4, arr4[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr4, size4, arr4[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr4, size4, arr4[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr4, size4, arr4[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;

    delete[] arr4;
    //**************************************************************************************
    const int size5 = 2000;
    int* arr5 = new int[size5];  

    for( int i = 0; i < size5; i ++ ){
        arr5[i] = rand() %20000; //in the range of 0 to 40000
    }
    sort(arr5, arr5+size5);

    cout << "Now, we will test our program while size = " << size5 << endl << endl;

    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr5, size5, arr5[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr5, size5, arr5[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr5, size5, arr5[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr5, size5, arr5[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr5, size5, arr5[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr5, size5, arr5[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr5, size5, arr5[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr5, size5, arr5[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr5, size5, arr5[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr5, size5, arr5[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr5, size5, arr5[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr5, size5, arr5[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr5, size5, arr5[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr5, size5, arr5[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr5, size5, arr5[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr5, size5, arr5[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    
    delete[] arr5;
    //**************************************************************************************
    const int size6 = 3000;
    int* arr6 = new int[size6];  

    for( int i = 0; i < size6; i ++ ){
        arr6[i] = rand() %30000; //in the range of 0 to 30000
    }
    sort(arr6, arr6+size6);

    cout << "Now, we will test our program while size = " << size6 << endl << endl;

    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr6, size6, arr6[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr6, size6, arr6[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr6, size6, arr6[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr6, size6, arr6[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr6, size6, arr6[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr6, size6, arr6[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr6, size6, arr6[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr6, size6, arr6[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr6, size6, arr6[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr6, size6, arr6[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr6, size6, arr6[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr6, size6, arr6[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr6, size6, arr6[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr6, size6, arr6[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr6, size6, arr6[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr6, size6, arr6[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    
    delete[] arr6;
    //**************************************************************************************
    const int size7 = 4000;
    int* arr7 = new int[size7];  

    for( int i = 0; i < size7; i ++ ){
        arr7[i] = rand() %40000; //in the range of 0 to 40000
    }
    sort(arr7, arr7+size7);

    cout << "Now, we will test our program while size = " << size7 << endl << endl;

    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr7, size7, arr7[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr7, size7, arr7[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr7, size7, arr7[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr7, size7, arr7[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr7, size7, arr7[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr7, size7, arr7[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr7, size7, arr7[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr7, size7, arr7[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr7, size7, arr7[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr7, size7, arr7[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr7, size7, arr7[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr7, size7, arr7[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr7, size7, arr7[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr7, size7, arr7[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr7, size7, arr7[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr7, size7, arr7[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    
    delete[] arr7;
    //**************************************************************************************
    const int size8 = 5000;
    int* arr8 = new int[size8];  

    for( int i = 0; i < size8; i ++ ){
        arr8[i] = rand() %50000; //in the range of 0 to 50000
    }
    sort(arr8, arr8+size8);

    cout << "Now, we will test our program while size = " << size8 << endl << endl;

    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr8, size8, arr8[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr8, size8, arr8[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr8, size8, arr8[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr8, size8, arr8[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr8, size8, arr8[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr8, size8, arr8[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr8, size8, arr8[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr8, size8, arr8[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr8, size8, arr8[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr8, size8, arr8[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr8, size8, arr8[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr8, size8, arr8[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr8, size8, arr8[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr8, size8, arr8[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr8, size8, arr8[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr8, size8, arr8[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    
    delete[] arr8;
    //**************************************************************************************
    const int size9 = 6000;
    int* arr9 = new int[size9];  

    for( int i = 0; i < size9; i ++ ){
        arr9[i] = rand() %60000; //in the range of 0 to 60000
    }
    sort(arr9, arr9+size9);

    cout << "Now, we will test our program while size = " << size9 << endl << endl;

    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr9, size9, arr9[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr9, size9, arr9[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr9, size9, arr9[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr9, size9, arr9[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr9, size9, arr9[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr9, size9, arr9[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr9, size9, arr9[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr9, size9, arr9[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr9, size9, arr9[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr9, size9, arr9[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr9, size9, arr9[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr9, size9, arr9[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr9, size9, arr9[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr9, size9, arr9[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr9, size9, arr9[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr9, size9, arr9[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    
    delete[] arr9;
    //**************************************************************************************
    const int size10 = 8000;
    int* arr10 = new int[size10];  

    for( int i = 0; i < size10; i ++ ){
        arr10[i] = rand() %80000; //in the range of 0 to 80000
    }
    sort(arr10, arr10+size10);

    cout << "Now, we will test our program while size = " << size10 << endl << endl;

    cout << "Iterative Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr10, size10, arr10[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr10, size10, arr10[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr10, size10, arr10[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        iterativeLinearSearch( arr10, size10, arr10[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Recursive Linear Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr10, size10, arr10[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr10, size10, arr10[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr10, size10, arr10[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        recursiveLinearSearch( arr10, size10, arr10[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Binary Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr10, size10, arr10[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr10, size10, arr10[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr10, size10, arr10[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        binarySearch( arr10, size10, arr10[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    cout << "Jump Search: " << endl; //******************************************

    cout <<"Case A: " ;
    startTime = clock();

    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr10, size10, arr10[1]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case B: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr10, size10, arr10[5]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case C: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr10, size10, arr10[7]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout <<"Case D: " ;
    startTime = clock();
    for( int i = 0; i < loop; i++)
    {
        jumpSearch( arr10, size10, arr10[9]);
    }
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

    duration = duration / loop;
    cout << "Execution took " << duration  << " Miliseconds "<< endl;

    cout << endl << endl;
    
    delete[] arr10;
    //**************************************************************************************
}