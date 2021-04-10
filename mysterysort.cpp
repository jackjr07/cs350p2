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

    //Start sort algorithm



    return 0;
}

