#include <iostream>

using namespace std;

int max(int a, int b){
    int i;
    if(a == b){
        return a;
    }
    if(a > b){
        i = a;
    }
    else{
        i = b;
    }
    return i;
}

int rightsequance(int a,int b, int i){
     for (i; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
            break;
        }
    }
    return 0;
}

int main(){
    int a, b, i;
    cin >> a >> b;
    i = max(a,b);
    cout << rightsequance(a,b,i) << endl;
    return 0;
}