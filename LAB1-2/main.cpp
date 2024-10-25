#include "header/modAlphakey.h"

bool isValid(const std::wstring& s)
{
    for(auto c : s) {
        if(!isalpha(c) || !isupper(c)) {
            return false;
        }
    }
    return true;
}

int main()
{
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
    int key;
    std::wstring text;
    int op;

    std::wcout << L"Cipher ready. Input key: ";
    std::wcin >> key;

    if(!std::wcin.good()) {
        std::wcerr << L"key not valid\n";
        return 0;
    }

    modAlphakey cipher(key);
    do {
        std::wcout << L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        std::wcin >> op;

        if(op > 2) {
            std::wcout << L"Illegal operation\n";
        } else if(op > 0) {
            std::wcout << L"Cipher ready. Input text: ";
            std::wcin >> text;

            if(isValid(text)) {
                if(op == 1) {
                    std::wcout << L"Encrypted text: " << cipher.encrypt(text) << std::endl;
                } else {
                    std::wcout << L"Decrypted text: " << cipher.decrypt(text) << std::endl;
                }
            } else {
                std::wcout << L"Operation aborted: invalid text\n";
            }
        }
    } while(op != 0);

    return 0;
}