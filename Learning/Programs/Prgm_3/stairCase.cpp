#include<iostream>
using namespace std;

void staircase(int n) {
    
    for(int i=0; i < n; i++)
    {
        int j=0;
        while(j < n){
            if(j < n-i-2) cout << ' ';
            else cout << '#';
            if(j == n-1) cout << endl;
            j++;
        } 
        
    }
}
int main(){
    staircase(3);
}