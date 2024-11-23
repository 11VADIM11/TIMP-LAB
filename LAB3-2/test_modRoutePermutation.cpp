#include "modRoutePermutation.h"

#include <UnitTest++/UnitTest++.h>

// Тест на шифрование пустого текста с проверкой исключения
TEST(TestEncryptEmptyText)
{
    modRoutePermutationCipher cipher(L"456");               
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument); // исключение
}

// Тест на дешифрование пустого текста с проверкой исключения
TEST(TestDecryptEmptyText)
{
    modRoutePermutationCipher cipher(L"456");               
    CHECK_THROW(cipher.decrypt(L""), std::invalid_argument); // исключение
}

// Тест на шифрование текста с невалидным символом
TEST(TestForeignCharacterInText)
{
    modRoutePermutationCipher cipher(L"456");                     
    CHECK_THROW(cipher.encrypt(L"World"), std::invalid_argument); // исключение
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness)
{
    modRoutePermutationCipher cipher(L"456");        
    std::wstring encrypted = cipher.encrypt(L"ДОБРО");
    CHECK(encrypted == L"РОДОБ");                      
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness)
{
    modRoutePermutationCipher cipher(L"456"); // Новый пример ключа
    std::wstring decrypted = cipher.decrypt(L"РОДОБ");
    CHECK(decrypted == L"ДОБРО");                     
}

// Тест на обработку некорректного ключа (неположительное число)
TEST(TestInvalidKey)
{
    CHECK_THROW(modRoutePermutationCipher cipher(L"-1"), std::invalid_argument);   // Ожидаем исключение
    CHECK_THROW(modRoutePermutationCipher cipher(L"xyz"), std::invalid_argument); // исключение
}

// Тест на шифрование с валидным текстом
TEST(TestEncryptionWithValidText)
{
    modRoutePermutationCipher cipher(L"456"); // Новый пример ключа
    std::wstring encrypted = cipher.encrypt(L"Привет");
    CHECK(encrypted != L"Привет"); // Убеждаемся, что текст действительно зашифрован
}

// Тест на дешифрование с валидным текстом
TEST(TestDecryptionWithValidText)
{
    modRoutePermutationCipher cipher(L"456"); // Новый пример ключа
    std::wstring encrypted = cipher.encrypt(L"Привет");
    std::wstring decrypted = cipher.decrypt(encrypted);
    CHECK(decrypted == L"Привет"); // Убеждаемся, что мы можем расшифровать обратно
}

int main()
{
    return UnitTest::RunAllTests();
}
