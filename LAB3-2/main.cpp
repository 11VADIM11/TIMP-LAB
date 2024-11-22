#include "modRoutePermutation.h"

#include <codecvt>
#include <iostream>
#include <limits>
#include <locale>
#include <stdexcept>

// Функция для конвертации std::exception сообщений в std::wstring
std::wstring convertExceptionMessage(const std::exception& e)
{
    std::string errorMessage = e.what(); // Получаем сообщение об ошибке
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
    return converter.from_bytes(errorMessage); // Конвертируем в wstring
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8"); // Устанавливаем локаль для работы с русским языком

    std::wstring key;
    bool validKey = false;

    // Цикл для ввода корректного ключа
    while(!validKey) {
        std::wcout << L"Введите ключ (целое положительное число): ";
        std::getline(std::wcin, key);

        try {
            modRoutePermutationCipher cipher(key);
            validKey = true; // Ключ корректен
        } catch(const std::invalid_argument& e) {
            std::wcerr << L"Ошибка в ключе: " << convertExceptionMessage(e) << std::endl;
        }
    }

    int operation;
    do {
        std::wcout << L"Выберите операцию (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
        std::wcin >> operation;

        // Игнорируем оставшийся ввод (символ новой строки)
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');

        std::wstring text;
        if(operation == 1 || operation == 2) {
            bool validText = false;

            // Цикл для ввода корректного текста
            while(!validText) {
                std::wcout << L"Введите текст: ";
                std::getline(std::wcin, text); // Теперь здесь будет происходить ввод текста

                try {
                    validText = true; // Предполагаем, что текст валиден
                    // Вызываем валидацию текста
                    modRoutePermutationCipher cipher(key); // Ключ должен быть валиден
                    if(operation == 1) {
                        std::wstring encrypted_text = cipher.encrypt(text);
                        std::wcout << L"Зашифрованный текст: " << encrypted_text << std::endl;
                    } else if(operation == 2) {
                        std::wstring decrypted_text = cipher.decrypt(text);
                        std::wcout << L"Расшифрованный текст: " << decrypted_text << std::endl;
                    }
                } catch(const std::invalid_argument& e) {
                    std::wcerr << L"Ошибка в тексте: " << convertExceptionMessage(e) << std::endl;
                    validText = false; // Текст некорректен, пробуем снова
                }
            }
        } else if(operation != 0) {
            std::wcout << L"Некорректная операция. Пожалуйста, выберите 0, 1 или 2." << std::endl;
        }
    } while(operation != 0);

    return 0;
}