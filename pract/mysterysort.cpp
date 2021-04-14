/*Jack Wanitkun HW2 CS350
 * Mystery sort
 */

#include<iostream>
#include<cstring>
#include<cctype>
#include<vector>

using namespace std;


void printNums(int z[], int count, int i){
    if(i == count) {
        cout << endl;
        return;
    }
    cout << z[i] << " " ;
    return printNums(z, count, ++i);
}

int * copyArr(int arr[], int z[], int i, int j, int max){
    if(i > max) return arr; //Base case
        arr[i] = z[j];
        ++i;
        ++j;
    return copyArr(arr, z, i, j, max);
}

int swap(int * p1, int * p2){
    cout << "P1: " << p1 << "P2: " << p2 << endl;
    int hold = *p1;
    *p1 = *p2;
    *p2 = hold;
    return 1;
}

int lastCheck(int z[]){
    int len = sizeof(z)/sizeof(z[0]);
    for(int i =0; i<len; ++i){
        if(z[i] > z[i+1]) return 0;
    }
    return 1;
}

//Started the the leftest
    //35 97 99 48 12 27 103 14 32
    //curr = 35 | z[low+1] = 97 | z[hi] = 32
int runSort(int z[], int low, int hi, int hold){
    cout << "hold: " << z[hold] << "low: " << z[low] << "hi: " << z[hi] << endl;
    cout << "Index H: " << hi << "Index L: " << low << endl;
    //All numbers all unique
    //base case
    if(z[low] < z[hold]){
        swap(z[low], z[hold]);
        cout << "hold: " << z[hold] << "low: " << z[low] << "hi: " << z[hi] << endl;
        return runSort(z, low, hi, hold);
    }
    if(z[low] > z[hold]){
        if(z[hi] < z[hold]){
            cout << "HIT" << endl;
            swap(z[low], z[hi]);
            cout << "hold: " << z[hold] << "low: " << z[low] << "hi: " << z[hi] << endl;
            return runSort(z, ++low, --hi, hold);
        }
    } 
    if(low == hi){
        cout << "LOW = HI" << endl;
        int check = lastCheck(z);
        cout << check << endl;
        if(check){
            return check;
        }else{
            swap(z[low], z[hold]);
            return runSort(z, 1, 4, ++hold);
        }
    }
    /*
    if(low == hi) {
        //swap(z[low], z[hold]);
        return 1;
    };
    //The left side is greater than z[hold]
    if(z[low] > z[hold]) {
        //If the left side is less than z[hold] | In this case I want to swap with the Z[lo]
        if(z[hi] < z[hold]) {
            cout << "Before: " << " H:" << z[hi] << " L:" << z[low] << endl;
            swap(z[hi], z[low]);
            cout << "After: " << " H:" <<  z[hi] << " L:" << z[low] << endl;
            return runSort(z, ++low, --hi,hold);
        }
        return runSort(z, ++low, --hi,hold);
    }    
    if(z[low] < z[hold]){
        cout << "Before: " << " L:" << z[low] << " H:" << z[hi] << endl;
        swap(z[low], z[hi]);
        cout << "After: " <<" L:" <<  z[low] << " H:" <<  z[hi] << endl;
        return runSort(z, ++low, hi, hold);
    }


    //older
    if(z[hi] < z[hold]){
        swap(z[low], z[hi]);
        ++low; //2 from 1
        --hi; //7 from 8
        return runSort(z,low,hi,hold);
    }
    if(low == hi){
        swap(z[hold], z[low]);
        return hold; // at index 4 and 5 
    }
    ++low;
    --hi;
    return runSort(z,low,hi,hold);
    */
}

int mysterySort(int z[],int low, int hi){
    printNums(z, hi+1, 0);
    runSort(z, low+1, hi, 0);
    printNums(z, hi+1, 0);

    return 1;
}


int main(){
    //STATIC VARIABLES FROM CLASS
    int i = 0, count, z[1000];

    cout << "This is Jack HW2" << endl;
    //Contorl the loop
    cout << "How many elements you're going to enter: ";
    cin >> count;
    cin.ignore(100, '\n');

    //User give the inputs
    cout << "Enter the number: ";
    while(i<count){
        cin >> z[i];
        ++i;
    }
    cout << "Unsorted data: " ;
    printNums(z, count, 0);

    //leftest always is 0 || rightest is count -1 
    mysterySort(z, 0, count-1);
    printNums(z, count, 0);

    return 0;
}

