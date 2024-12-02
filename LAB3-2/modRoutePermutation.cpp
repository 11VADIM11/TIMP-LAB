#include "modRoutePermutation.h"
#include <locale>
#include <stdexcept>

// Конструктор, инициализирующий ключ
modRoutePermutationCipher::modRoutePermutationCipher(const std::wstring &skey) {
  if (skey.empty()) {
    throw std::invalid_argument(
        "Ошибка: ключ не может быть пустым. Пожалуйста, введите положительное "
        "целое число.");
  }

  // Поддержка русского и английского алфавитов
  alphabet = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯABCDEFGHIJKLMNOPQRSTUVWXYZ";
  validateKey(skey);

  // Заполнение ключа
  for (const auto &ch : skey) {
    key.push_back(
        static_cast<int>(ch - L'0')); // Явное преобразование типа для ясности
  }
}

// Валидация ключа
void modRoutePermutationCipher::validateKey(const std::wstring &skey) {
  for (const auto &ch : skey) {
    if (!iswdigit(ch)) {
      throw std::invalid_argument(
          "Ошибка: ключ должен состоять только из цифр. Пожалуйста, введите "
          "положительное целое число.");
    }
  }

  // Проверка на нулевой или отрицательный ключ
  int keyValue = std::stoi(skey);
  if (keyValue <= 0) {
    throw std::invalid_argument("Ошибка: ключ должен быть положительным целым "
                                "числом. Пожалуйста, введите корректный ключ.");
  }
}

// Валидация текста
void modRoutePermutationCipher::validateText(const std::wstring &text) {
  if (text.empty()) {
    throw std::invalid_argument(
        "Ошибка: текст не может быть пустым. Пожалуйста, введите текст для "
        "шифрования/расшифрования.");
  }

  for (const auto &ch : text) {
    if (alphabet.find(ch) == std::wstring::npos) {
      throw std::invalid_argument(
          "Ошибка: текст должен содержать только буквы из заданного алфавита "
          "(русские и английские буквы).");
    }
  }
}

// Шифрование текста
std::wstring modRoutePermutationCipher::encrypt(const std::wstring &open_text) {
  validateText(open_text);
  std::wstring result;
  size_t keySize = key.size();

  for (size_t i = 0; i < open_text.size(); ++i) {
    int shift = key[i % keySize];
    wchar_t ch = open_text[i];
    size_t index = alphabet.find(ch);
    if (index != std::wstring::npos) {
      // Шифруем символ и добавляем в результат
      result.push_back(alphabet[(index + shift) % alphabet.size()]);
    }
  }
  return result;
}

// Расшифрование текста
std::wstring modRoutePermutationCipher::decrypt(const std::wstring &cipher_text) {
  validateText(cipher_text);
  std::wstring result;
  size_t keySize = key.size();

  for (size_t i = 0; i < cipher_text.size(); ++i) {
    int shift = key[i % keySize];
    wchar_t ch = cipher_text[i];
    size_t index = alphabet.find(ch);
    if (index != std::wstring::npos) {
      // Расшифруем символ и добавляем в результат
      result.push_back(
          alphabet[(index - shift + alphabet.size()) % alphabet.size()]);
    }
  }
  return result;
}