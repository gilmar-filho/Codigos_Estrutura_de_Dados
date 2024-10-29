#include <iostream>
using namespace std;

int main(){
    int x[3], y[3], c[3];
    for (int i = 0; i < 3; i++){
        int j = 4;
        int g = 1;
        x[i] = j;
        y[i] = g;
        g++;
        j--;
        c[i] = x[i] + y[i];
    }

    for (int r: c){
        cout << r << " ";
    }

    cout << endl << "Hello World!!!" << endl;
}