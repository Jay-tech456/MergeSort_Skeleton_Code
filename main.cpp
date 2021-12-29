//
//  main.cpp
//  mergeSort
//
//  Created by Manjesh Prasad on 12/28/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeS(vector<int> &num, int start, int end){
    int mid = (start + end)/2;
    int i = start;
    int j = mid+ 1;
    vector<int> temp;
    
    while(i <= mid && j <= end){
        if(num[i] < num[j]){
            temp.push_back(num[i]);
            i++;
        }
        else
        {
            temp.push_back(num[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(num[i]);
        i++;
    }
    
    while(j <= end){
        temp.push_back(num[j]);
        j++;
    }
    
    for(int count = start; count <= end; count++){
        num[count] = temp[count -start];
    }
}


void mergeSort(vector<int> & num, int start, int end) {
    
    if(start < end){
        int mid = (start + end)/ 2;
        mergeSort(num, start, mid );
        mergeSort(num, mid + 1, end);
        mergeS(num, start, end);
    }
}
int main(int argc, const char * argv[]) {
    
    vector<int> numList  = {9, 8, 7, 6, 5};
    
    mergeSort(numList, 0, numList.size() - 1);
    
    vector<int>::iterator it;
    for(it = numList.begin(); it != numList.end(); it++)
        cout << *it << " ";
    
}
