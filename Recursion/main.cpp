#include <iostream>
using namespace std;

int strLengthRecursion(char *s) {
    if (*s == '\0') return 0;
    return 1+strLengthRecursion(s+1);
}
int countChar(char *s, char ch) {
    if (*s == '\0') return 0;
    if (*s == ch) return 1 + countChar(s+1, ch);
    return 0+countChar(s+1, ch);
}
bool isLengthEqual(char *s1, char *s2) {
    if (*s1 == '\0' && *s2 =='\0') return true;
    if (*s1 == '\0') return false;
    if (*s2 == '\0') return false;
    return isLengthEqual(s1+1, s2+1);
}
int charFirstPosition(char *s, char ch) {
    if (*s == '\0') return -1;
    if (*s == ch) return 0;
    int idx = charFirstPosition(s+1, ch);
    if (idx == -1) return -1;
    return 1+idx;
}
int charLastPosition(char *s, char ch) {
    if (*s == '\0') return -1;
    int idx = charLastPosition(s+1, ch);
    if (idx != -1) return 1+idx;
    if (*s == ch) return 0;
    return -1;
}
char maxChar(char *s) {
    if (*s == '\0') return 0;
    char maxCharElement = maxChar(s+1);
    if (*s > maxCharElement) return *s;
    return maxCharElement;
}
int main() {
    char str[] = "Benim adim Oğuz Kağan Bilici";
    char str2[] = "Ben Cankaya üniversitesinde yüksek lisans yapıyorum";
    char str3[] = "Benim adim Oğuz Kağan Bilici";

    cout<<"length of str: "<<strLengthRecursion(str)<<endl;
    cout<<"Count of i: "<<countChar(str, 'i')<<endl;
    cout<<"Lengt of strings are equal?: "<<isLengthEqual(str, str2)<<endl;
    cout<<"Lengt of strings are equal?: "<<isLengthEqual(str, str3)<<endl;
    cout<<"The first position of 'O': "<<charFirstPosition(str, 'O')<<endl;
    cout<<"The first position of 'i': "<<charFirstPosition(str, 'i')<<endl;
    cout<<"The last position of 'i': "<<charLastPosition(str, 'i')<<endl;
    cout<<"The biggest char in str: "<<maxChar(str);
    return 0;
}
