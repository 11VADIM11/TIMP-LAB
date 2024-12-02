#include "modRoutePermutation.h"
#include <UnitTest++/UnitTest++.h>

TEST(TestEncryptEmptyText)
{
    modRoutePermutationCipher cipher(L"456");               
    CHECK_THROW(cipher.encrypt(L""), std::invalid_argument); 
}

TEST(TestDecryptEmptyText)
{
    modRoutePermutationCipher cipher(L"456");               
    CHECK_THROW(cipher.decrypt(L""), std::invalid_argument); 
}

TEST(TestForeignCharacterInText)
{
    modRoutePermutationCipher cipher(L"456");                     
    CHECK_THROW(cipher.encrypt(L"World"), std::invalid_argument); 
}

TEST(TestEncryptionCorrectness)
{
    modRoutePermutationCipher cipher(L"456");        
    std::wstring encrypted = cipher.encrypt(L"ДОБРО");
    CHECK(encrypted == L"ЗУЖФУ");                      
}

TEST(TestDecryptionCorrectness)
{
    modRoutePermutationCipher cipher(L"456"); 
    std::wstring decrypted = cipher.decrypt(L"ЗУЖФУ");
    CHECK(decrypted == L"ДОБРО");                     
}

TEST(TestInvalidKey)
{
    CHECK_THROW(modRoutePermutationCipher cipher(L"-1"), std::invalid_argument);   
    CHECK_THROW(modRoutePermutationCipher cipher(L"xyz"), std::invalid_argument); 
}

TEST(TestEncryptionWithValidText)
{
    modRoutePermutationCipher cipher(L"456"); 
    std::wstring encrypted = cipher.encrypt(L"ЗУЖФУ");
    CHECK(encrypted != L"ДОБРО"); 
}

int main()
{
    return UnitTest::RunAllTests();
}
