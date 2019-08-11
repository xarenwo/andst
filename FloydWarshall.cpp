#include <iostream>
#define inf 999999
#define Vertices 4
using namespace std;

int min(int a, int b) {
    if(a<b) {
        return a;
    }
    return b;
}
void FloydWarshall(int A[][Vertices]) {
    int i,j,k;
    for(k=0;k<Vertices;k++) {
        for(i=0;i<Vertices;i++) {
            for(j=0;j<Vertices;j++) {
                A[i][j] = min((A[i][j]),(A[i][k]+A[k][j]));
            }
        }
    }
    cout << "Shortest paths between all pairs of vertices are displayed in the following matrix : \n";
    for(i=0;i<Vertices;i++) {
        for(j=0;j<Vertices;j++) {
            cout <<"|" <<A[i][j] << "| ";
        }
        cout << "\n";
    }
}
int main() {

    int A[Vertices][Vertices] ={
        {0,3,inf,7},
        {8,0,2,inf},
        {5,inf,0,1},
        {2,inf,inf,0}
        };

    FloydWarshall(A);
    return 0;
}
