/*30 pos - fio, birthday(int), salary(double), date postup na rabotu(01.01.2001)
find sotrudnik, who stazh >= 25 let, print avg salary*/

#include <iostream>
#include <string.h>
#include <time.h>

struct Clerk{
    private:
    char fio[31]; //max 30 elments
    int birthday;
    double salary;
    char postup[11]; //(01.01.2001) - 11 elements
    public:
    Clerk(const Clerk& clerk){
        for(size_t i = 0; i < 31; ++i){
            this->fio[i] = clerk.fio[i];
        }
        this->birthday = clerk.birthday;
        this->salary = clerk.salary;
        for(size_t i = 0; i < 11; ++i){
            this->postup[i] = clerk.postup[i];
        }
    }
    Clerk(char* name = "a", int birthday = 0, double salary = 0, char* postup = "0.0.0000", size_t staz = 0){
        for(size_t i = 0; i < 31; ++i){
            this->fio[i] = name[i];
        }
        this->birthday = birthday;
        this->salary = salary;
        for(size_t i = 0; i < 11; ++i){
            this->postup[i] = postup[i];
        }
        this->staz = staz;
    }
    ~Clerk(){ 
    }
    size_t staz;

    void set_staz(){
        char year[4];
        for(size_t i = 0; i < 4; ++i){
            year[i] = postup[6 + i];
        }
        for(size_t i = 0; i < 4; ++i){
            staz += year[i] - 48;
            staz *= 10;
        }
        staz /= 10;
    }

    void set_staz_via_syscals(){
        time_t now;
        struct tm *curtime;
        time(&now);
        curtime = gmtime(&now);
        staz = -1 * (staz - (curtime->tm_year + 1900));
    }

    void set_fio(char* name){
        for(size_t i = 0; i < 31; ++i){
            this->fio[i] = name[i];
        }
    }

    void set_fio(){
        char name[10];
        memset(name, 0, 10);
        char suname[10];
        memset(suname, 0, 10);
        char last_name[10];
        memset(last_name, 0, 10);
        scanf("%s", &name);
        scanf("%s", &suname);
        scanf("%s", &last_name);
        static size_t i = 0;
        for(; name[i] != '\0'; ++i){
            fio[i] = name[i];
        }
        fio[i] = ' ';
        i++;
        for(size_t j = 0; name[j - 1] != '\0'; ++i, j++){
            fio[i] = suname[j];
        }
        fio[i] = ' ';
        i++;
        for(size_t j = 0; name[j] != '\0'; ++i, ++j){
            fio[i] = last_name[j];
        }
        fio[i] = ' ';
        i++;
        fio[i] = '\0';
    }

    void set_birthday(char* date){
        this->birthday = atol(date);
    }

    void set_birthday(int date){
        this->birthday = date;
    }

    void set_birthday(){
        scanf("%d", &birthday);
    }

    void set_salary(char* salary){
        this->salary = atof(salary);
    }

    void set_salary(double salary){
        this->salary = salary;
    }
    
    void set_salary(){
        scanf("%lf", &salary);
    }

    void set_postup(char* postup){
        for(size_t i = 0; postup[i - 1] != '\0'; ++i){
            this->postup[i] = postup[i];
        }
        /*smth magic with staz*/
    }

    void set_postup(){
        memset(postup, 0, 11);
        scanf("%s", &postup);
    }

    void show(){
        printf("%s\t", this->fio);
        printf("%d\t", this->birthday);
        printf("%f\t", this->salary);
        printf("%s\t", this->postup);
    }

    char* get_fio(){
        return this->fio;
    }

    int get_birthday(){
        return this->birthday;
    }

    double get_salary(){
        return this->salary;
    }

    char* get_postup(){
        return this->postup;
    }
};

class Base{
    size_t size;
    Clerk* clerk;
    inline char* substr(char* str, size_t pos, size_t n){
        char* newstr = new char[n];
        for(size_t i = pos, k = 0; k < n; ++k){
            newstr[k] = str[i];
        }
        return newstr;
    }
public:
    Base(){
        size = 1;
        clerk = new Clerk[size];
    }
    Base(size_t size, size_t current_year){
        this->size = size;
        clerk = new Clerk[size];
    }
    ~Base(){
        delete[] clerk;
    }
    size_t get_size(){
        return this->size;
    }
    void resize(size_t size){
        // this->size = size;
        Clerk* semi_clerk = new Clerk[size];
        for(size_t i = 0; i < this->size; ++i){
            semi_clerk[i] = this->clerk[i];
        }
        this->size = size;
        delete[] this->clerk;
        clerk = semi_clerk;
    }
    void show(){
        for(size_t i = 0; i < this->size; ++i){
            clerk[i].show();
            printf("\n");
        }
    }
    void clear(){
        delete[] this->clerk;
        this->size = 0;
    }
    double semi_salary(){
        double semi = 0;
        for(size_t i = 0; i < this->size; ++i){
            semi += clerk[i].get_salary();
        }
        return semi/this->size;
    }
    char** find_staz(){
        size_t current = 0;
        for(size_t i = 0; i < this->size; ++i){
            if(clerk[i].staz >= 25){
                current++;
            }
        }
        if(current == 0){
            return 0;
        }
        char** arr = new char*[current];
        for(size_t i = 0; i < current; ++i){
            arr[i] = new char[31];
        }
        for(size_t i = 0, j = 0; i < this->size; ++i){
            if(clerk[i].staz >= 25){
                arr[j] = clerk->get_fio();
                ++j;
            }
        }
        return arr;
    }
    Clerk operator[](size_t value){
        return clerk[value];
    }
    void enter_base(){
        for(size_t i = 0; i < this->size; ++i){
            printf("Enter fio *max 30 char*\n");
            clerk[i].set_fio();
            printf("Enter birthday\n");
            clerk[i].set_birthday();
            printf("Enter salary\n");
            clerk[i].set_salary();
            printf("Enter postup\n");
            clerk[i].set_postup();
            // clerk[i].keyboard_set_fio();
            clerk[i].set_staz();
            clerk[i].set_staz_via_syscals();
        }
    }

    void enter_base_via_file(){ //need to finish
        char file_name[] = "test.txt";
        FILE* fp;
        fp = fopen(file_name, "r+");

        size_t size = 0;
        size_t size_base = 0;

        int ch;

        while(!feof(fp)){
            ch = fgetc(fp);
            if(char(ch) == '\n'){
                size_base++;
            }
            size++;
        }
        resize(size_base);
        
        char* whole_file = new char[size];

        fgets(whole_file, size, fp);
        //fio(31, ' ')' 'birthday' 'salary' 'postup(11, '.')' ' 
        for(size_t i = 0, j = 0, k = 0, n = 0; i < size; ++i, ++n, ++j){
            if(whole_file[i] == '\n'){
                j = -1;
            }
            if(whole_file[i] == ' '){
                j++;
            }
            if(j == 3){
                clerk[k].set_fio(substr(whole_file, i - n + 1, n - 1));
                n = -1;
            }
            else if(j == 4){
                clerk[k].set_birthday(substr(whole_file, i - n + 1, n - 1));
                n = -1;
            }
            else if(j == 5){
                clerk[k].set_salary(substr(whole_file, i - n + 1, n - 1));
                n = -1;
            }
            else if(j == 6){
                clerk[k].set_postup(substr(whole_file, i - n + 1, n - 1));
                n = -1;
                k++;
            }
        }
    }

    void enter_base_via_file(char* argv[]){ //need to finish
        FILE* fp;
        fp = fopen(argv[1], "r+");

        size_t size = 0;
        size_t size_base = 0;

        int ch;

        while(!feof(fp)){
            ch = fgetc(fp);
            if(char(ch) == '\n'){
                size_base++;
            }
            size++;
        }
        resize(size_base);
        
        char* whole_file = new char[size];

        fgets(whole_file, size, fp);
        //fio(31, ' ')' 'birthday' 'salary' 'postup(11, '.')' ' 
        for(size_t i = 0, j = 0, k = 0, n = 0; i < size; ++i, ++n, ++j){
            if(whole_file[i] == '\n'){
                j = -1;
            }
            if(whole_file[i] == ' '){
                j++;
            }
            if(j == 3){
                clerk[k].set_fio(substr(whole_file, i - n + 1, n - 1));
                n = -1;
            }
            else if(j == 4){
                clerk[k].set_birthday(substr(whole_file, i - n + 1, n - 1));
                n = -1;
            }
            else if(j == 5){
                clerk[k].set_salary(substr(whole_file, i - n + 1, n - 1));
                n = -1;
            }
            else if(j == 6){
                clerk[k].set_postup(substr(whole_file, i - n + 1, n - 1));
                n = -1;
                k++;
            }
        }
    }
};


int main(int argc, char* argv[]){
    if(argc == 1){
    Base one;
    one.enter_base();
    char** arr = one.find_staz();
    printf(arr[0]);
    }
    else if(argc == 2){ //if we transfer file to prog before start

    }
    else{
        printf("Invalid params\n");
        return 0;
    }
    return 0;
}