#include "modGRONSFELD.h"
#include <UnitTest++/UnitTest++.h>

TEST(TestConstructorValidKey) {
    modAlphaCipher cipher(L"УХА"); 
}

TEST(TestConstructorInvalidKeyLowerCase) {
    CHECK_THROW(modAlphaCipher(L"уха"), std::invalid_argument); 
}

TEST(TestConstructorEmptyKey) {
    CHECK_THROW(modAlphaCipher(L""), std::invalid_argument);
}

TEST(TestConstructorInvalidKeyWithDigits) {
    CHECK_THROW(modAlphaCipher(L"УХА123"), std::invalid_argument); 
}

TEST(TestConstructorInvalidKeyWithSpecialChars) {
    CHECK_THROW(modAlphaCipher(L"У,ХА"), std::invalid_argument);
}

TEST(TestEncryptEmptyText) {
    modAlphaCipher cipher(L"УХА");
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument);
}

TEST(TestDecryptEmptyText) {
    modAlphaCipher cipher(L"УХА");
    CHECK_THROW(cipher.decrypt(L""), std::invalid_argument); 
}

TEST(TestEncryptTextWithLowerCase) {
    modAlphaCipher cipher(L"УХА");
    CHECK_THROW(cipher.encrypt(L"ёёабжфвёмузод"), std::invalid_argument); 
}

TEST(TestEncryptTextWithForeignCharacters) {
    modAlphaCipher cipher(L"УХА");
    CHECK_THROW(cipher.encrypt(L"Hello"), std::invalid_argument);
}

TEST(TestEncryptValidText) {
    modAlphaCipher cipher(L"УХА");
    std::wstring encrypted = cipher.encrypt(L"ТРАНСФОРМАТОР");
    CHECK(encrypted == L"ЁЁАБЖФВЁМУЗОД"); 
}

TEST(TestDecryptTextWithLowerCase) {
    modAlphaCipher cipher(L"УХА");
    CHECK_THROW(cipher.decrypt(L"ёёабжфвёмузод"), std::invalid_argument);
}

TEST(TestDecryptTextWithForeignCharacters) {
    modAlphaCipher cipher(L"УХА");
    CHECK_THROW(cipher.decrypt(L"Hello"), std::invalid_argument);
}

TEST(TestDecryptionCorrectness) {
    modAlphaCipher cipher(L"УХА");
    std::wstring decrypted = cipher.decrypt(L"ЁЁАБЖФВЁМУЗОД");
    CHECK(decrypted == L"ТРАНСФОРМАТОР");
}

int main() { 
    return UnitTest::RunAllTests();
}