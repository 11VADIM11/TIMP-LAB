#include "header/modRoutePermutation.h"
#include <locale>
#include <stdexcept>

// Конструктор, инициализирующий ключ
modRoutePermutationCipher::modRoutePermutationCipher(const std::wstring& skey)
{
    if(skey.empty()) {
        throw std::invalid_argument(
            "ключ не может быть пустым. Пожалуйста, введите положительное целое число.");
    }
    alphabet =
        L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯABCDEFGHIKLNOPQRSTUVWXYZ"; // Поддержка русского и английского алфавитов
    validateKey(skey);
    for(const auto& ch : skey) {
        key.push_back(wchar_t(ch) - L'0');
    }
}

// Валидация ключа
void modRoutePermutationCipher::validateKey(const std::wstring& skey)
{
    for(const auto& ch : skey) {
        if(!iswdigit(ch)) {
            throw std::invalid_argument(
                "ключ должен состоять только из цифр. Пожалуйста, введите положительное целое число.");
        }
    }

    // Проверка на нулевой или отрицательный ключ
    int keyValue = std::stoi(skey);
    if(keyValue <= 0) {
        throw std::invalid_argument(
            "ключ должен быть положительным целым числом, не равным 0. Пожалуйста, введите корректный ключ.");
    }
}

// Валидация текста
void modRoutePermutationCipher::validateText(const std::wstring& text)
{
    if(text.empty()) {
        throw std::invalid_argument(
            "текст не может быть пустым. Пожалуйста, введите текст для шифрования/расшифрования.");
    }
    for(const auto& ch : text) {
        if(alphabet.find(ch) == std::wstring::npos) {
            throw std::invalid_argument(
                "текст должен содержать только буквы из заданного алфавита (заглавные русские и английские буквы).");
        }
    }
}

// Шифрование текста
std::wstring modRoutePermutationCipher::encrypt(const std::wstring& open_text)
{
    validateText(open_text);
    std::wstring result;
    int keySize = key.size();

    for(size_t i = 0; i < open_text.size(); ++i) {
        int shift = key[i % keySize];
        wchar_t ch = open_text[i];
        int index = alphabet.find(ch);
        if(index != std::wstring::npos) {
            result.push_back(alphabet[(index + shift) % alphabet.size()]);
        }
    }
    return result;
}

// Расшифрование текста
std::wstring modRoutePermutationCipher::decrypt(const std::wstring& cipher_text)
{
    validateText(cipher_text);
    std::wstring result;
    int keySize = key.size();

    for(size_t i = 0; i < cipher_text.size(); ++i) {
        int shift = key[i % keySize];
        wchar_t ch = cipher_text[i];
        int index = alphabet.find(ch);
        if(index != std::wstring::npos) {
            result.push_back(alphabet[(index - shift + alphabet.size()) % alphabet.size()]);
        }
    }
    return result;
}