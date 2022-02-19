#include <Auxiliar.h>

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


string inString()
{
    string str;
    getline(cin, str);
    return str;
}



void clean()
{
    for (unsigned int i = 0; i<200; i++) {
        cout << endl;
    }
}
