#include "modGRONSFELD.h"

#include <UnitTest++/UnitTest++.h>

// Тест на шифрование пустого текста
TEST(TestEncryptEmptyText)
{
    modAlphaCipher cipher(L"УХА");
    std::wstring encrypted = cipher.encrypt(L"");
    CHECK(encrypted == L""); // пустая строка
}

// Тест на дешифрование пустого текста
TEST(TestDecryptEmptyText)
{
    modAlphaCipher cipher(L"УХА");
    std::wstring decrypted = cipher.decrypt(L"");
    CHECK(decrypted == L""); // пустая строка
}

// Тест на шифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInText)
{
    modAlphaCipher cipher(L"УХА");
    CHECK_THROW(cipher.encrypt(L"ёёабжфвёмузод"), std::invalid_argument); // исключение
}

// Тест на дешифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInKey)
{
    modAlphaCipher cipher(L"УХА");
    CHECK_THROW(cipher.decrypt(L"ёёабжфвёмузод"), std::invalid_argument); // исключение
}

// Тест на шифрование текста с невалидным символом
TEST(TestForeignCharacterInText)
{
    modAlphaCipher cipher(L"УХА");
    CHECK_THROW(cipher.encrypt(L"World"), std::invalid_argument); // исключение
}

// Тест на шифрование минимального ключа
TEST(TestMinimalKey)
{
    modAlphaCipher cipher(L"УХА");
    std::wstring encrypted = cipher.encrypt(L"ЁЁАБЖФВЁМУЗОД"); // валидный текст
    CHECK(encrypted != L"");                          // результат не пустой
}

// Тест на шифрование длинного ключа
TEST(TestLongKey)
{
    modAlphaCipher cipher(L"УХАУХАУХАУХАУХА");
    std::wstring encrypted = cipher.encrypt(L"ЁЁАБЖФВЁМУЗОД"); // валидный текст
    CHECK(encrypted != L"");                          // результат не пустой
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness)
{
    modAlphaCipher cipher(L"УХА");
    std::wstring encrypted = cipher.encrypt(L"ЁЁАБЖФВЁМУЗОД");
    CHECK(encrypted == L"ТРАНСФОРМАТОР"); // ожидаемый результат
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness)
{
    modAlphaCipher cipher(L"УХА");
    std::wstring decrypted = cipher.decrypt(L"ТРАНСФОРМАТОР");
    CHECK(decrypted == L"ЁЁАБЖФВЁМУЗОД"); // ожидаемый результат
}


int main() { return UnitTest::RunAllTests(); }
