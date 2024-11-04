#include "header/modGRONSFELD.h"

#include <iostream>
#include <locale>

// Функция проверки заглавных русских букв
bool isValid(const std::wstring& s)
{
    for(auto c : s) {
        // Проверяем, является ли символ заглавной буквой русского алфавита
        if(!iswupper(c) && c != L'Ё') { // Не забываем про букву Ё
            return false;
        }
    }
    return true;
}

int main()
{
    try {
        std::locale loc("ru_RU.UTF-8");
        std::locale::global(loc);

        std::wstring key, text;
        int op;

        // Запрашиваем ключ, пока не будет введен корректный
        do {
            std::wcout << L"Введите ключ для шифра Гронсвельда: ";
            std::wcin >> key;

            // Проверка ключа на валидность
            if(!isValid(key)) {
                std::wcerr << L"Ошибка: ключ должен состоять из заглавных букв русского алфавита." << std::endl;
            }
        } while(!isValid(key)); // Повторяем ввод, пока ключ некорректен

        // Создаем объект шифратора с валидным ключом
        modAlphaCipher cipher(key);

        do {
            std::wcout << L"Выберите операцию (0 - выход, 1 - зашифровать, 2 - расшифровать): ";
            std::wcin >> op;

            if(op > 2) {
                std::wcout << L"Некорректная операция. Пожалуйста, выберите 0, 1 или 2.\n";
            } else if(op > 0) {
                bool validInput = false; // флаг для отслеживания валидности ввода текста

                do {
                    std::wcout << L"Введите текст: ";
                    std::wcin >> text;

                    if(isValid(text)) {
                        validInput = true; // Ввод валиден
                        if(op == 1) {
                            std::wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << std::endl;
                        } else {
                            std::wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << std::endl;
                        }
                    } else {
                        std::wcerr << L"Ошибка: текст должен состоять из заглавных букв русского алфавита."
                                   << std::endl;
                    }
                } while(!validInput); // Повторяем ввод, пока текст некорректен
            }
        } while(op != 0);
    } catch(const std::exception& e) {
        std::wcerr << L"Ошибка: " << e.what() << std::endl;
    }

    return 0;
}