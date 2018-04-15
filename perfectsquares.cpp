#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
#include <queue>
#include<set>

using namespace std;


int numSquares(int n){

    vector<int> perfectSquares;
    for(int i=1;i*i<=n;i++){
        perfectSquares.push_back(i*i);
    }

    if(perfectSquares.back() == n){
        return 1;
    }
    vector<int> counts(n+1);
    for(int i=0;i<=n;i++){
        counts[i] = INT32_MAX;
    }
    counts[0] = 0;


    queue<int> bfsQ;

    bfsQ.push(0);
    while(!bfsQ.empty()){
        int front = bfsQ.front();
        bfsQ.pop();

        for(auto val: perfectSquares){
            if((val) + front <= n){
                bfsQ.push(val+front);
                counts[val+front] = min(counts[val+front], counts[front]+1);
                if(val+front==n){
                    return counts[n];
                }
            }
        }

    }


    return counts[n];

}

int main(){

    cout<<numSquares(50);


}