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
    CHECK(encrypted == L"ЗУЖФУ");                      
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness)
{
    modRoutePermutationCipher cipher(L"456"); 
    std::wstring decrypted = cipher.decrypt(L"ЗУЖФУ");
    CHECK(decrypted == L"ДОБРО");                     
}

// Тест на обработку некорректного ключа (неположительное число)
TEST(TestInvalidKey)
{
    CHECK_THROW(modRoutePermutationCipher cipher(L"-1"), std::invalid_argument);   // исключение
    CHECK_THROW(modRoutePermutationCipher cipher(L"xyz"), std::invalid_argument); // исключение
}

// Тест на шифрование с валидным текстом
TEST(TestEncryptionWithValidText)
{
    modRoutePermutationCipher cipher(L"456"); 
    std::wstring encrypted = cipher.encrypt(L"ЗУЖФУ");
    CHECK(encrypted != L"ДОБРО"); // Убеждаемся, что текст действительно зашифрован
}

// Тест на дешифрование с валидным текстом
TEST(TestDecryptionWithValidText)
{
    modRoutePermutationCipher cipher(L"456");
    std::wstring encrypted = cipher.encrypt(L"ДОБРО");
    std::wstring decrypted = cipher.decrypt(encrypted);
    CHECK(decrypted == L"ЗУЖФУ"); // Убеждаемся, что мы можем расшифровать обратно
}

int main()
{
    return UnitTest::RunAllTests();
}
