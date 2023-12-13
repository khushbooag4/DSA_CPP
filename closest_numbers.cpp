#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numbers[] = {6,2, 4, 10};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    sort(numbers, numbers + n);
    int mindiff = numbers[1] - numbers[0];
    for(int i = 1; i <n;i++){
        if(numbers[i] - numbers[i-1] == mindiff){
            cout<<numbers[i-1]<<" "<<numbers[i]<<endl;
        }
    }
    return 0;
}