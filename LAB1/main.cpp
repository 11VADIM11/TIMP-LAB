#include "header/modAlphaCipher.h"

#include <iostream>
using namespace std;
void check(const wstring& Text, const wstring& key)
{
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout << L"key=" << key << endl;
    wcout << L"Original text: " << Text << endl;
    wcout << L"Encrypted text: " << cipherText << endl;
    wcout << L"Decrypted text: " << decryptedText << endl;
    if(Text == decryptedText)
        wcout << L"Ok\n";
    else
        wcout << L"Err\n";
}
int main(int argc, char** argv)
{
    check(L"БЫСТРОНОГАЯЛИСИЦАПРЫГАЕТНАЛЕНИВОГОПСА", L"ПРОСТОЙ");
    check(L"БЫСТРОНОГАЯЛИСИЦАПРЫГАЕТНАЛЕНИВОГОПСА", L"ПРИМЕР");
    check(L"БЫСТРОНОГАЯЛИСИЦАПРЫГАЕТНАЛЕНИВОГОПСА", L"АБВГ");
    return 0;
}