#pragma once
#include <algorithm>
#include <iostream>
#include <locale>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

class modRoutePermutationCipher
{
private:
    std::wstring alphabet; // алфавит
    std::vector<int> key;  // ключ в виде вектора

public:
    modRoutePermutationCipher(const std::wstring& skey); // конструктор с ключом

    std::wstring encrypt(const std::wstring& open_text);   // шифрование
    std::wstring decrypt(const std::wstring& cipher_text); // расшифрование

    void validateKey(const std::wstring& key);   // валидация ключа
    void validateText(const std::wstring& text); // валидация текста
};