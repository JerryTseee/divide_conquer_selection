#include<iostream>
using namespace std;

// It is a divide and conquer algorithm to find the kth smallest element in an array

void select(int array[], int pivot, int length){

    // first create two arrays left and right
    int left[length]; // for numbers that smaller than pivot
    int left_index = 0;
    int right[length]; // for numbers that bigger than pivot
    int right_index = 0;


    // start to divide the array
    for (int i = 0; i < length; i++)
    {
        if (array[i] < pivot)
        {
            left[left_index] = array[i];
            left_index++;
        }
        else{
            right[right_index] = array[i];
            right_index++;
        }
    }


    int new_array[length];
    int new_array_index = 0;

    for (int i = 0; i < left_index; i++)
    {
        new_array[new_array_index] = left[i];
        new_array_index++;
    }

    new_array[new_array_index] = pivot;
    new_array_index++;


    for (int i = 0; i < right_index; i++)
    {
        new_array[new_array_index] = right[i];
        new_array_index++;
    }
    
    cout<<"The new array: "<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<new_array[i]<<" ";
    }
    cout<<endl;



    // then start to check condition one by one
    if (left_index < pivot && pivot < left_index + right_index){
        cout<< pivot <<endl;
    }
    else if (pivot <= left_index){
        select(left, pivot, left_index);
    }
    else if (pivot > left_index + right_index){
        select(right, pivot - left_index - 1, right_index);
    }
    


};

int main(){

    int array[] = {8, 3, 2, 5, 1, 4, 7, 6};

    int length = sizeof(array)/sizeof(array[0]);
    select(array, 4, length); // choose 4 as pivot

    return 0;
}