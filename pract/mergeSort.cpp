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
        //cout << arr[i] << endl;
        ++i;
        ++j;
    return copyArr(arr, z, i, j, max);
}

int * partSort(int arr[], int i, int partMax){
   if(i == partMax) return arr; 
   if(arr[i] > arr[i+1]){
        int hold = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = hold;
   }
   return partSort(arr, ++i, partMax);
}



int sort(int z[], int leftest, int middle, int rightest){
    //#1 split into 2 group || n = 9 | 0 - 4 - 5 - 8
    int n1 = middle + 1; //z[0] to z[4]
    int n2 = rightest - middle; // z[5] to z[8]
    //cout << "N1: " << n1 << "N2: " << n2 << endl;

    int left[n1];
    int right[n2];
    
    copyArr(left, z, 0, 0, n1);
    copyArr(right, z, 0, n1, n2-1);
    
    printNums(left, n1, 0); //First Half
    printNums(right, n2, 0); //Second Half

    //create result array and start sorting 
    int result[rightest];
    //I have n1, n2, left[], rigth[]
    //partSort(left, 0, n1);
    //partSort(right, 0, n2-1);
    int i,j,k;
    i = 0; j = 0; k=0;

    //Sorted arrange
    while (i < n1 && j < n2){
        cout << "case: " << left[i] << right[j] << endl;
        if(left[i] <= right[j]){
            result[k] = left[i];
            ++i;
        }else{
            result[k] = right[j];
            ++j;
        }
        ++k;
    }

    while(i < n1){
        result[k] = left[i];
        ++i; ++k;
    }
    while(j < n2){
    result[k] = right[j];
        ++j; ++k;
    }
    cout << "@1" << endl;
    printNums(result, rightest+1, 0);
    int a = 0;
    while(a < rightest){
        if(result[a] > result[a+1]){
            int temp = result[a];
            result[a] = result[a+1];
            result[a+1] = temp;
        }
        ++a;
    }

    printNums(result, rightest+1, 0);

    return 1;
}

void mergeSort(int z[], int leftest, int rightest){
    //init, divided the whole thing into 2 (m = leftest + (rightest - leftest)/2)
    // i = [0,1,2,3,4,5,6,7,8,9] 
    // m = 0 + (9-0)/2 = 4 || m+1 = 5 to rightest [5,9]
    // First halve will be l, m || 1-5
    // second halve will be m+1, r || 6 - 9 
    if(leftest >= rightest) return ; //meaning there's only one value
    int middle = leftest + (rightest - leftest)/2;
    //cout << leftest << "and" << middle << "and" << middle +1 << "and" << rightest << endl;
    sort(z, leftest, middle, rightest);
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
    mergeSort(z, 0, count-1);


    return 0;
}

