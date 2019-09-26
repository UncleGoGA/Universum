//Программа по статистическому анализу числа(Какие числа входят и сколько таких чисел)
#include <iostream>

int main(){

    int iN, iNum, iK = 0;
    int *mas = new int[iNum];
    printf("%s","Enter value of Mas");
    scanf("%d", iNum);
    printf("%s","Enter value of your Number");
    scanf("%d", iN);
    for(int i = 0; i<iNum;i++)
    {
        mas[i] = 0;
    }
    for(int i = iNum; i!=0; i--){
        mas[i] = iN%10;
        iN /= 10;
    }
    for(int i = 0; i< iNum - 1; i++)
    {
        for(int j = 1; j < iNum; j++)
        {
            if(mas[i] == mas[j])
            iK++;
            if(j == iNum)
            {
                printf("%s%d", "The number", mas[i], "/t", "is", "/t", iK);
            }
    
        }
        iK = 0;
    }
    system("pause");
    return 0;
}