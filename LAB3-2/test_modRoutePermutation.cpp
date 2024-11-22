#include "modRoutePermutation.h"

#include <UnitTest++/UnitTest++.h>

// Тест на шифрование пустого текста с проверкой исключения
TEST(TestEncryptEmptyText)
{
    modRoutePermutationCipher cipher(L"123");                // Пример ключа
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument); // Ожидаем исключение
}

// Тест на дешифрование пустого текста с проверкой исключения
TEST(TestDecryptEmptyText)
{
    modRoutePermutationCipher cipher(L"123");                // Пример ключа
    CHECK_THROW(cipher.decrypt(L""), std::invalid_argument); // Ожидаем исключение
}

// Тест на шифрование текста с невалидным символом
TEST(TestForeignCharacterInText)
{
    modRoutePermutationCipher cipher(L"123");                     // Пример ключа
    CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument); // Ожидаем исключение
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness)
{
    modRoutePermutationCipher cipher(L"123");         // Пример ключа
    std::wstring encrypted = cipher.encrypt(L"БГЕЖ"); // Здесь проверяем ожидаемый результат
    CHECK(encrypted == L"ВЕЗЗ");                      // Ожидаемый результат
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness)
{
    modRoutePermutationCipher cipher(L"123"); // Пример ключа
    std::wstring decrypted = cipher.decrypt(L"ВЕЗЗ"); // Здесь проверим, что возвращается оригинал
    CHECK(decrypted == L"БГЕЖ");                      // Ожидаемый результат
}

// Тест на обработку некорректного ключа (неположительное число)
TEST(TestInvalidKey)
{
    CHECK_THROW(modRoutePermutationCipher cipher(L"-1"), std::invalid_argument);  // Ожидаем исключение
    CHECK_THROW(modRoutePermutationCipher cipher(L"abc"), std::invalid_argument); // Ожидаем исключение
}

// Тест на шифрование с валидным текстом
TEST(TestEncryptionWithValidText)
{
    modRoutePermutationCipher cipher(L"123"); // Пример ключа
    std::wstring encrypted = cipher.encrypt(L"Тест");
    CHECK(encrypted != L"Тест"); // Убеждаемся, что текст действительно зашифрован
}

// Тест на дешифрование с валидным текстом
TEST(TestDecryptionWithValidText)
{
    modRoutePermutationCipher cipher(L"123"); // Пример ключа
    std::wstring encrypted = cipher.encrypt(L"Тест");
    std::wstring decrypted = cipher.decrypt(encrypted);
    CHECK(decrypted == L"Тест"); // Убеждаемся, что мы можем расшифровать обратно
}

int main()
{
    return UnitTest::RunAllTests(); // Запуск всех тестов
}