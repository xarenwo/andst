#include <iostream>
using namespace std;

int main() {
    int stages = 4;
    int min=0;
    int n=8;
    int cost[9];
    int d[9]; // array for storing via which vertex we are getting the shortest path
    int path[9];
    int c[9][9] = {{0,0,0,0,0,0,0,0,0},
                   {0,0,2,1,3,0,0,0,0},
                   {0,0,0,0,0,2,3,0,0},
                   {0,0,0,0,0,6,7,0,0},
                   {0,0,0,0,0,6,8,9,0},
                   {0,0,0,0,0,0,0,0,6},
                   {0,0,0,0,0,0,0,0,4},
                   {0,0,0,0,0,0,0,0,5},
                   {0,0,0,0,0,0,0,0,0}};
    cost[n] = 0; //cost of last vertex is 0 (cost of 8) , this is because 8 is the sink, we do not go anywhere
    for(int i=n-1; i>=1; i--) { // loop from back to front, and calculate cost, loop from 7 to 1, as 8 is already 0 as cost
        min = 32767;
        for(int k=i+1; k<=n; k++) { // i is 4
            if(c[i][k] != 0 && (c[i][k] + cost[k]) < min) { // cost of 4 is cost[4] = min{c[i][k] + cost[k]}
                // i is 4 , so we count distance from i+1 to n, so from 5 to 8
                // k=5 , c[4][5] = 6, cost[k] = cost[5] = 6 => min = 6+6 = 12
                // k=6 , c[4][6] = 8, cost[6] = 4 = > min = 8+4 = 12
                // k=7 , c[4][7] = 9, cost[7] = 5 => 9+5 = 14
                // k=8 , c[4][8] = 0, cost[8] = 0 => 0 , we have condition c[i][k] != , so c[4][8] being 0, is ignored
                min = c[i][k] + cost[k]; // min for k=5 is 12, and for k=6 is also 12, we can take k=5
                d[i] = k; // store that min cost is via vertex k=5 , so for d[4] min cost is via vertex k=5
            }
        }
        cost[i] = min; // cost of 4 is 12
    }
    path[1] = 1;
    path[stages] = n;
    for(int i=2; i<stages;i++) {
        path[i] = d[i-1];
       // cout << "Path of i="<<i<<" is " << path[i] << "\n";
    }

    for(int i=1; i<=8;i++) {
        if(path[i] >1 && path[i] < 1000 ) {
            cout << "Shortest Path from Vertex "<<i-1<<" is to Vertex " << path[i] << "\n";
        }

    }
    return 0;
}
