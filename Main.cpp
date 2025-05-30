#include <iostream>
#include <chrono>
#include "MergeSort.hpp"
#include "ParallelMergeSort.hpp"


int main(int argc, char *argv[]){

    const int SIZE = 100000;  
    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);

    for(int i=0; i<SIZE; i++){
        nums[i] = rand()%100000;
        nums1[i] = rand()%100000;
    }

    MergeSort *mergesort = new MergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();  
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortDuration = end - start;
    std::cout<<"MergeSort Algorithm Time taken :" << mergesortDuration.count() << "Seconds" << std::endl;

    delete mergesort;

    ParallelMergeSort*mergesort1 = new ParallelMergeSort(&nums1);
    auto st = std::chrono::high_resolution_clock::now();
    mergesort1->sort();  
    auto en = std::chrono::high_resolution_clock::now();
    mergesortDuration = en - st;
    std::cout<<"ParallelMergeSort Algorithm Time taken :" << mergesortDuration.count() << "Seconds" << std::endl;

    delete mergesort1;

}