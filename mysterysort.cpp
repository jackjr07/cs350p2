/*Jack Wanitkun HW2 CS350
 * Mystery sort
 */

#include<iostream>
#include<cstring>
#include<cctype>
#include<vector>

using namespace std;

int nMAX;

void printNums(int z[], int count, int i){
    if(i == count) {
        cout << endl;
        return;
    }
    cout << z[i] << " " ;
    return printNums(z, count, ++i);
}
/*
void copyArr(int arr [], int z[], int i, int max){
    if(i > max) return;
        arr[i] = z[i];
        cout << arr[i] << endl;
        ++i;
    return copyArr(arr, z, i, max);
}*/ 

int sort(int z[], int leftest, int middle, int rightest){
    //#1 split into 2 group || n = 9 | 0 - 4 - 5 - 8
    int n1 = middle; //z[0] to z[4]
    int n2 = rightest - middle; // z[5] to z[8]
    if(n1 > n2){
        nMAX = n1;
    }else{
        nMAX = n2;
    }
    int left[n1], right[n1];
    

    //copyArr(left, z, 0, middle);
    //copyArr(right, z, middle + 1, rightest);
    int i = 0;
    while(i <= n1){
        left[i] = z[i];
        cout << "Left: " << left[i] << endl;
        ++i;
    };
    cout << "i val"  <<i << endl;
    int j = 0;
    while(j < n2){
        right[j] = z[i];
        cout << "Right: " << right[i] << endl;
        ++i;
        ++j;
    }

    printNums(left, middle, 0);
    printNums(right, rightest, middle+1);

}

void mergeSort(int z[], int leftest, int rightest){
    //init, divided the whole thing into 2 (m = leftest + (rightest - leftest)/2)
    // i = [0,1,2,3,4,5,6,7,8,9] 
    // m = 0 + (9-0)/2 = 4 || m+1 = 5 to rightest [5,9]
    // First halve will be l, m || 1-5
    // second halve will be m+1, r || 6 - 9 
    if(leftest >= rightest) return ; //meaning there's only one value
    int middle = leftest + (rightest - leftest)/2;
        cout << leftest << "and" << middle << "and" << middle +1 << "and" << rightest << endl;
    sort(z, leftest, middle, rightest);
}

int main(){
    //STATIC VARIABLES FROM CLASS
    int i = 0, count, z[100];
    vector<int> x;

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
    mergeSort(z, 0, count-1);


    return 0;
}

