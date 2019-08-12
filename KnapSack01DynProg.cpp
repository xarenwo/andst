#include <iostream>
#define objects 4
#define capacity 8
using namespace std;

int max(int a, int b) {
    if(a>b) {
        return a;
    }
    return b;
}

int main() {
    int Profit[objects+1] = {0,1,2,5,6};
    int Weight[objects+1] = {0,2,3,4,5};
    int Table[objects+1][capacity+1];
    cout << "Table is : \n";
    for(int i=0; i<=objects; i++) {
        for(int w=0; w<=capacity; w++) {
            if(i==0 || w==0) {
                //  If we are in the first row or column, put 0 in the table as Weight/Profit are always 0
                Table[i][w] = 0;
            } else if(Weight[i] <= w)  {
                //  If the weight of the current object i is <= than w, calculate profit
                // Example for first case, we have i=1 and w=0, write 0, then i=1, w=1, so Weight[1] = 2. 2 is not <=1 , so just copy Table[1-1][1] = 0
                // After we have i=1, w=2, so Weight[1] = 2 <=2, it means we take the max between Profit[1]+Table[0][2-2] and Table[1-1][2], which is  Profit[1] = 1

                Table[i][w] = max(Profit[i]+Table[i-1][w-Weight[i]],Table[i-1][w]);
            } else {
                Table[i][w] = Table[i-1][w];
            }
            cout << Table[i][w] << " ";
        }
        cout << "\n";
    }
    int op = Table[objects][capacity];
    cout << "\n Optimal solution is : " << op << "\n\n";
    int i=objects,j=capacity;
    while(i>0 && j>0) {
        if(Table[i][j] == Table[i-1][j]) {
            cout << "Object " << i << " is not included as exists in " << i-1 << "\n";
            i--;
        } else {
            cout << "Object " << i << " is included \n";
            j=j-Weight[i];
            i--;
        }
    }




    return 0;
}
