#include <iostream>

using namespace std;

int random(int a, int b, int c, int m){
    a = (b * a + c)%m;
    return a;
}

int main(){
    const int b = 1366;
    const int c = 1283;
    const int m = 6075;
    int a, safe, i;
    cin >> a;
    safe = a;
    i = 0;
    do{
        i++;
        cout << (a = random(a,b,c,m)) << endl;
    }
    while(a != safe);
    cout << "Counter of the cycle = " << i << endl;
    system("pause");
    return 0;
}