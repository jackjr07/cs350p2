/*Jack Wanitkun HW2 CS350
 * Mystery sort
 */

#include<iostream>
#include<cstring>

using namespace std;


void printNums(int z[], int count, int i){
    if(i == count) {
        cout << endl;
        return;
    }
    cout << z[i] << " " ;
    return printNums(z, count, ++i);
}

int swap(int * p1, int * p2){
    int hold = *p1;
    *p1 = *p2;
    *p2 = hold;
    return 1;
}

//  5   3   4   9   7
int runSort(int * z, int low, int high, int * leftP){
    if(z[low] > z[high]){
        swap(z[low], z[high]);
    }

    int j = low + 1;

    //Index L -- H
    //      p1  p2
    int g = high-1;
    int k = low + 1;

    //  z[l]   X   X   X   z[h]
    int p = z[low];
    int q = z[high];

    
    while (k <= g) {
        //If the L more than pivot
        if (z[k] < p) 
        { 
            swap(z[k], z[j]); 
            j++; 
        } 
        //if the H is smaller than pivot | Swap
        else if (q <= z[k]) {
            while (z[g] > q && k < g) {
                g--; 
            }

                swap(&z[k], &z[g]);
                g--; 

            if (z[k] < p) {
                swap(&z[k], &z[j]); 
                j++; 
            } 
        } 
        k++; 
    } 
    j--; g++; //Increase and reduces [ ->   <-]
    swap(z[low], z[j]); 
    swap(z[high], z[g]); 
    *leftP = j;
    return g; 
}


void mysterySort(int* z,int low, int high){
    if(low < high){
        int leftP, rightP;
        rightP = runSort(z, low, high, &leftP);
        mysterySort(z, low, leftP-1);
        mysterySort(z, leftP+1, rightP-1);
        mysterySort(z, rightP + 1, high);
    }
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

