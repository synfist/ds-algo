#include<cstdio>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

/* inefficient as fuck. who cares */
int medianOf3IsFirst(int a, int b, int c) {
    if ((a >= b  && a <= c ) || (a >=c && a<=b))
        return true;
    return false;
}

int midlIndex(int from, int to) {
    return from + (to-from)/2;
}
int swap(vector<int> &v, int i, int j) {
    int swap = v.at(i);
    v.at(i) = v.at(j);
    v.at(j) = swap;
}

void printIntVector(vector<int> &v, int from, int to) {
    cout << endl;
    while(from<=to) {
        cout << v.at(from) << "\t";
        from++;
    }
}

int setandgetPivotIndex(vector<int>&v, int from, int to, int pivotStyle) {
    switch(pivotStyle) {
        case 1: break;

        case 2: swap(v,from,to);
                break;

        case 3:
            /* inefficient as fuck. who cares */
            if( (to - from) >= 2 ) {
                int midl = from + (to-from)/2;
                //if(medianOf3IsFirst(v.at(from),v.at(midll),v.at(to)))
                if(medianOf3IsFirst(v.at(midl),v.at(to),v.at(from))) {
                    swap(v,from,midl);
                }
                else if(medianOf3IsFirst(v.at(to),v.at(midl),v.at(from))){
                    swap(v,from,to);
                }
            }//else swap(v,from,to);

    }
    return from;
}

int partition_v2(vector<int> &v, int from, int to, int pivotStyle) {
    int pivotIndex = setandgetPivotIndex(v,from,to,pivotStyle);
    int pivot = v.at(pivotIndex);
    int i = from+1;
    int j = from+1;
    while( j<=to ) {
        if(v.at(j) < pivot) {
            swap(v,i,j);
            i++;
        }
        j++;
    }
    swap(v,from,i-1);
    //printIntVector(v,from,to);
    return i-1;
}

int partition_v1(vector<int> &v, int from, int to, int pivotStyle) {
    int pivot  = setandgetPivotIndex(v,from,to,pivotStyle);
    while(from < to) {
        while ((from < to) && (v.at(from) < v.at(pivot))) {
            from++;
        }
        while ((from < to) && (v.at(to) > v.at(pivot))) {
            to--;
        }
        if(from < to) {
            int swapper = v.at(from);
            v.at(from) = v.at(to);
            v.at(to) = swapper;
        }
    }
    return from;
}


unsigned long long int quickSort(vector<int> &v, int from, int to, int pivotStyle=1, int partitionVersion=2,unsigned long long int *c=0){
    unsigned long long int comparisons = 0;
    if ( from < to ) {
        int partitionedAt = 0;
        //cout << "from=" << from << " to=" << to;
        //printIntVector(v, from, to);
        switch(partitionVersion) {
            case 1: partitionedAt = partition_v1(v,from,to,pivotStyle);
                    break;


            case 2: //cout << "calling v2";
                    partitionedAt = partition_v2(v,from,to,pivotStyle);
                    break;
        }
        comparisons += to - from;
        *c += to - from;
        //cout << "from=" << from << " pivot-1=" << partitionedAt-1;
        //printIntVector(v, from, partitionedAt-1);
        //cout << " pivot+1=" << partitionedAt+1<<  "to=" << to ;
        //printIntVector(v, partitionedAt+1, to);
        comparisons += quickSort(v,from,partitionedAt-1,pivotStyle,partitionVersion,c);
        comparisons += quickSort(v,partitionedAt+1,to,pivotStyle,partitionVersion,c);
    }
    return comparisons;
}

unsigned long long int quickSort(vector<int> &v, int pivotStyle=1, int partitionVersion=2) {
    int from = 0;
    int to = v.size()-1;
    unsigned long long int c = 0;
    return quickSort(v, from, to, pivotStyle, partitionVersion, &c);
    //quickSort(v, from, to, pivotStyle, partitionVersion, &c);
    //return c;
}

int main (void) {
    int number;
    unsigned long long int comparisons =0;
    vector<int> iv;
    ifstream in("quicksort.txt");
    while(in>>number){
        iv.push_back(number);
    }

    //iv.clear();
    /*
    int a[] = { 6 , 3 , 7 ,4};
    vector<int> swapcheck(a,a+sizeof(a)/sizeof(int));
    printIntVector(swapcheck,0,3);
    swap(swapcheck,0,1);
    printIntVector(swapcheck,0,3);
    for (int i=0; i<=100; i++) {
        //iv.push_back(i);
    }
    */

    int a[] = { 6 , 3 , 7 ,4};
    int ix = medianOf3IsFirst(5,4,6);
    cout << ix;



    vector<int> v1(iv.begin(),iv.end());
    comparisons = quickSort(v1,1);
    cout << comparisons <<endl;

    vector<int> v2(iv.begin(),iv.end());
    comparisons = quickSort(v2,2);
    cout << comparisons <<endl;

    vector<int> v3(iv.begin(),iv.end());
    comparisons = quickSort(v3,3);
    cout << comparisons <<endl;

    cout << midlIndex(0,3) << "==5" << endl ;
    cout << midlIndex(0,9)  << "==4" << endl ;

    cout << midlIndex(1,9)  << "==5" << endl ;
    cout << midlIndex(2,9)  << "==5" << endl ;

    cout << midlIndex(1,10) << "==5" << endl ;
    cout << midlIndex(2,10) << "==6" << endl ;

    cout << midlIndex(11,20)<< "==15" << endl ;
    cout << midlIndex(11,21)<< "==16" << endl ;

    /*
    ofstream out("sorted.txt");
    for(int i=0; i<v2.size(); i++) {
        out << v2.at(i) << endl;
    }
    */
    return 0;
}
