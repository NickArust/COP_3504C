#include <iostream>
#include "StringData.h"
using namespace std;
int linearSearch(vector<string> dataset, string element);
int binarySearch(vector<string> dataset, string element);
vector<long long> timerSearch (vector<string> dataset, string element);
int main() {
    vector<string> dataset = getStringData(); // gets data
    vector<long long> times = timerSearch(dataset, "aaaaa"); // does the timing for each value and prints result
    cout<<"aaaaa"<<endl;
    cout<< times[0] <<endl;
    cout<< times[1] <<endl;
    times = timerSearch(dataset, "mzzzz");
    cout<<"mzzzz"<<endl;
    cout<< times[0] <<endl;
    cout<< times[1] <<endl;
    times = timerSearch(dataset, "not_here");
    cout<<"not_here"<<endl;
    cout<< times[0] <<endl;
    cout<< times[1] <<endl;
    return 0;
}

int linearSearch(vector<string> dataset, string element) {

    for(int i = 0;i<dataset.capacity();i++){ // does linear search
        if(dataset[i]==element){return i;}
    }

    return -1;
}

int binarySearch(vector<string> dataset, string element){

    int minIndex = 0;
    int maxIndex = dataset.capacity()-1;
    int midIndex = minIndex + (maxIndex - minIndex) / 2; // sets the max, min, mid indexs
    while (minIndex <= maxIndex){

        if(dataset[midIndex] == element){ // returns if we have a match
            return midIndex;
        }
        else if (element.compare(dataset[midIndex]) >0){ // changes indexs based on where we are reletive to element
            minIndex = midIndex+1;

        }
        else if (element.compare(dataset[midIndex]) < 0) {
            maxIndex = midIndex - 1;

        }
        midIndex = minIndex + (maxIndex - minIndex) / 2;
    }
    return -1;
}
vector<long long> timerSearch (vector<string> dataset, string element){
    long long slTime = systemTimeNanoseconds();
    linearSearch(dataset, element);
    long long elTime = systemTimeNanoseconds();
    long long sbTime = systemTimeNanoseconds();
    binarySearch(dataset, element); // does the timing and returns array for binary and linear time
    long long ebTime = systemTimeNanoseconds();
    long long ltime = elTime-slTime;
    long long btime = ebTime- sbTime;

    vector<long long> timeArray{ltime,btime};
    return timeArray;
}

