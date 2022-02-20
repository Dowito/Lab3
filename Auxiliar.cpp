#include <Auxiliar.h>
#include <math.h>
unsigned long long lenCad(char *cad)
{
    unsigned int tam = 0;
    for (unsigned int i = 0; cad[i] != 0; i++) tam++;
    return tam;
}

unsigned long long lenCad(string cad)
{
    unsigned int tam = 0;
    for (unsigned int i = 0; cad[i] != 0; i++) tam++;
    return tam;
}

bool ifCadSame(char *cad1, char *cad2)
{
    if(lenCad(cad1) != lenCad(cad2)) return false;
    for (unsigned int i = 0; i < lenCad(cad1); i++) {
        if(cad1[i] != cad2[i]) return false;
    }
    return true;
}

bool ifCadSame(string str1, string str2)
{
    if(str1.size() != str2.size()) return false;
    for (unsigned int i = 0; i < str1.size(); i++) {
        if(str1[i] != str2[i]) return false;
    }
    return true;
}

unsigned long long inUnsignedLongLong()
{
    unsigned long long num;
    cin >> num;
    return num;
}

string inString()
{
    string str;
    getline(cin, str);
    return str;
}

unsigned long long str2Num(string str){ //reciclo del lab1

    unsigned long long num = 0;
    long tam = str.size(); //funcion que returna el tamaño de una cadena de caracteres sin incluir el nulo
    for (long i = 0; str[i] != '\0'; i++) {
        num += (unsigned long long)(str[i]-48)*pow(10, tam-(i+1)); //
    }
    return num;
}

string num2Str(unsigned long long num)
{
    if(num == 0) return "0";
    string strNum;
    unsigned short digit;
    unsigned long long indx = 0;
    char ch;
    char buffer[21];
    while((num/10) != 0 || (num%10) != 0){
        digit = num%10;
        ch = digit+48;
        buffer[indx] = ch;
        num = num/10;
        indx++;
    }
    for (unsigned long long i=0; i<indx; i++) {
        strNum.push_back(buffer[(indx-1)-i]);
    }
    return strNum;
}

void clean()
{
    for (unsigned int i = 0; i<200; i++) {
        cout << endl;
    }
}


