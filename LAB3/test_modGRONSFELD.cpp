#include "modGRONSFELD.h"

#include <UnitTest++/UnitTest++.h>

// Тест на шифрование пустого текста
TEST(TestEncryptEmptyText)
{
    modAlphaCipher cipher(L"ЗДМ");
    std::wstring encrypted = cipher.encrypt(L"");
    CHECK(encrypted == L""); // пустая строка
}

// Тест на дешифрование пустого текста
TEST(TestDecryptEmptyText)
{
    modAlphaCipher cipher(L"ЗДМ");
    std::wstring decrypted = cipher.decrypt(L"");
    CHECK(decrypted == L""); // пустая строка
}

// Тест на шифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInText)
{
    modAlphaCipher cipher(L"ЗДМ");
    CHECK_THROW(cipher.encrypt(L"зжйв"), std::invalid_argument); // исключение
}

// Тест на дешифрование текста с недопустимыми символами
TEST(TestLowerCaseCharacterInKey)
{
    modAlphaCipher cipher(L"ЗДМ");
    CHECK_THROW(cipher.decrypt(L"зжйв"), std::invalid_argument); // исключение
}

// Тест на шифрование текста с невалидным символом
TEST(TestForeignCharacterInText)
{
    modAlphaCipher cipher(L"ЗДМ");
    CHECK_THROW(cipher.encrypt(L"World"), std::invalid_argument); // исключение
}

// Тест на шифрование минимального ключа
TEST(TestMinimalKey)
{
    modAlphaCipher cipher(L"ЗДМ");
    std::wstring encrypted = cipher.encrypt(L"ГЖСИ"); // валидный текст
    CHECK(encrypted != L"");                          // результат не пустой
}

// Тест на шифрование длинного ключа
TEST(TestLongKey)
{
    modAlphaCipher cipher(L"ЗДМЗДМЗДМЗДМЗДМ");
    std::wstring encrypted = cipher.encrypt(L"ГЖСИ"); // валидный текст
    CHECK(encrypted != L"");                          // результат не пустой
}

// Тест на правильность шифрования
TEST(TestEncryptionCorrectness)
{
    modAlphaCipher cipher(L"ЗДМ");
    std::wstring encrypted = cipher.encrypt(L"ГЖСИ");
    CHECK(encrypted == L"ТЕОР"); // ожидаемый результат
}

// Тест на правильность дешифрования
TEST(TestDecryptionCorrectness)
{
    modAlphaCipher cipher(L"ЗДМ");
    std::wstring decrypted = cipher.decrypt(L"ТЕОР");
    CHECK(decrypted == L"ГЖСИ"); // ожидаемый результат
}


int main() { return UnitTest::RunAllTests(); }
