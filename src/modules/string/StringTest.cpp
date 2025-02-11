#include "faker-cxx/String.h"

#include <algorithm>

#include "gtest/gtest.h"

#include "data/Characters.h"

using namespace ::testing;
using namespace faker;

class StringTest : public Test
{
public:
};

TEST_F(StringTest, shouldGenerateUuid4)
{
    const auto uuid = String::uuid();

    ASSERT_EQ(uuid[8], '-');
    ASSERT_EQ(uuid[13], '-');
    ASSERT_EQ(uuid[14], '4');
    ASSERT_EQ(uuid[18], '-');
    ASSERT_EQ(uuid[23], '-');
}

TEST_F(StringTest, shouldGenerateDefaultSampleString)
{
    const auto sample = String::sample();

    ASSERT_EQ(sample.size(), 10);
    ASSERT_TRUE(std::ranges::all_of(
        sample, [](char sampleCharacter)
        { return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125; }));
}

TEST_F(StringTest, shouldGenerateSampleString)
{
    const auto sample = String::sample(5);

    ASSERT_EQ(sample.size(), 5);
    ASSERT_TRUE(std::ranges::all_of(
        sample, [](char sampleCharacter)
        { return static_cast<int>(sampleCharacter) >= 33 && static_cast<int>(sampleCharacter) <= 125; }));
}

TEST_F(StringTest, shouldGenerateDefaultStringFromCharaters)
{
    const std::string characters{"abc"};

    const auto fromCharacters = String::fromCharacters(characters);

    ASSERT_EQ(fromCharacters.size(), 1);
    ASSERT_TRUE(std::ranges::all_of(fromCharacters, [&characters](char sampleCharacter)
                                    { return characters.find(sampleCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateStringFromCharaters)
{
    const std::string characters{"iosjdaijqw"};

    const auto fromCharacters = String::fromCharacters(characters, 6);

    ASSERT_EQ(fromCharacters.size(), 6);
    ASSERT_TRUE(std::ranges::all_of(fromCharacters, [&characters](char sampleCharacter)
                                    { return characters.find(sampleCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateDefaultApha)
{
    const auto alpha = String::alpha();

    ASSERT_EQ(alpha.size(), 1);
    ASSERT_TRUE(
        std::ranges::any_of(mixedAlphaCharacters, [alpha](char mixedCharacter) { return alpha[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlpha)
{
    const auto alphaLength = 10;

    const auto alpha = String::alpha(alphaLength);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::ranges::all_of(alpha,
                                    [](char alphaCharacter)
                                    {
                                        return std::ranges::any_of(mixedAlphaCharacters,
                                                                   [alphaCharacter](char mixedCharacter)
                                                                   { return mixedCharacter == alphaCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateUpperAlpha)
{
    const auto alphaLength = 15;

    const auto alpha = String::alpha(alphaLength, StringCasing::Upper);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::ranges::all_of(alpha,
                                    [](char alphaCharacter)
                                    {
                                        return std::ranges::any_of(upperCharacters,
                                                                   [alphaCharacter](char upperCharacter)
                                                                   { return upperCharacter == alphaCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateLowerAlpha)
{
    const auto alphaLength = 7;

    const auto alpha = String::alpha(alphaLength, StringCasing::Lower);

    ASSERT_EQ(alpha.size(), alphaLength);
    ASSERT_TRUE(std::ranges::all_of(alpha,
                                    [](char alphaCharacter)
                                    {
                                        return std::ranges::any_of(lowerCharacters,
                                                                   [alphaCharacter](char lowerCharacter)
                                                                   { return lowerCharacter == alphaCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateDefaultAphanumeric)
{
    const auto alphanumeric = String::alphanumeric();

    ASSERT_EQ(alphanumeric.size(), 1);
    ASSERT_TRUE(std::ranges::any_of(mixedAlphanumericCharacters,
                                    [alphanumeric](char mixedCharacter) { return alphanumeric[0] == mixedCharacter; }));
}

TEST_F(StringTest, shouldGenerateMixedAlphanumeric)
{
    const auto alphanumericLength = 10;

    const auto alphanumeric = String::alphanumeric(alphanumericLength);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::ranges::all_of(alphanumeric,
                                    [](char alphanumericCharacter)
                                    {
                                        return std::ranges::any_of(
                                            mixedAlphanumericCharacters,
                                            [alphanumericCharacter](char mixedAlphanumericCharacter)
                                            { return alphanumericCharacter == mixedAlphanumericCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateUpperAlphanumeric)
{
    const auto alphanumericLength = 15;

    const auto alphanumeric = String::alphanumeric(alphanumericLength, StringCasing::Upper);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::ranges::all_of(alphanumeric,
                                    [](char alphanumericCharacter)
                                    {
                                        return std::ranges::any_of(
                                            upperAlphanumericCharacters,
                                            [alphanumericCharacter](char upperAlphanumericCharacter)
                                            { return upperAlphanumericCharacter == alphanumericCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateLowerAlphanumeric)
{
    const auto alphanumericLength = 7;

    const auto alphanumeric = String::alphanumeric(alphanumericLength, StringCasing::Lower);

    ASSERT_EQ(alphanumeric.size(), alphanumericLength);
    ASSERT_TRUE(std::ranges::all_of(alphanumeric,
                                    [](char alphanumericCharacter)
                                    {
                                        return std::ranges::any_of(
                                            lowerAlphanumericCharacters,
                                            [alphanumericCharacter](char lowerAlphanumericCharacter)
                                            { return lowerAlphanumericCharacter == alphanumericCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateNumeric)
{
    const auto numeric = String::numeric();

    ASSERT_EQ(numeric.size(), 1);
    ASSERT_TRUE(
        std::ranges::any_of(numeric, [numeric](char numericCharacter) { return numeric[0] == numericCharacter; }));
}

TEST_F(StringTest, shouldGenerateNumericWithoutLeadingZeros)
{
    const auto numericLength = 13;

    const auto numeric = String::numeric(numericLength, false);

    const auto nonZeroCharacter = numeric[0];
    const auto numericWithPossibleZeroCharacters = numeric.substr(1);

    ASSERT_EQ(numeric.size(), numericLength);
    ASSERT_TRUE(std::ranges::any_of(numericCharactersWithoutZero, [nonZeroCharacter](char numericCharacter)
                                    { return nonZeroCharacter == numericCharacter; }));
    ASSERT_TRUE(std::ranges::all_of(numericWithPossibleZeroCharacters,
                                    [](char numericCharacterWithPossibleZero)
                                    {
                                        return std::ranges::any_of(
                                            numericCharacters, [numericCharacterWithPossibleZero](char numericCharacter)
                                            { return numericCharacterWithPossibleZero == numericCharacter; });
                                    }));
}

TEST_F(StringTest, shouldGenerateHexadecimal)
{
    const auto hexadecimalLength = 8;

    const auto hexadecimal = String::hexadecimal(hexadecimalLength);

    const auto prefix = hexadecimal.substr(0, 2);
    const auto hexNumber = hexadecimal.substr(2);

    ASSERT_EQ(hexadecimal.size(), hexadecimalLength + 2);
    ASSERT_EQ(prefix, "0x");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [hexNumber](char hexNumberCharacter)
                                    { return hexLowerCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithHashPrefix)
{
    const auto hexadecimalLength = 8;

    const auto hexadecimal = String::hexadecimal(hexadecimalLength, HexCasing::Upper, HexPrefix::Hash);

    const auto prefix = hexadecimal.substr(0, 1);
    const auto hexNumber = hexadecimal.substr(1);

    ASSERT_EQ(hexadecimal.size(), hexadecimalLength + 1);
    ASSERT_EQ(prefix, "#");
    ASSERT_TRUE(std::ranges::any_of(hexNumber, [](char hexNumberCharacter)
                                    { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateHexadecimalWithoutPrefix)
{
    const auto hexadecimalLength = 8;

    const auto hexadecimal = String::hexadecimal(hexadecimalLength, HexCasing::Upper, HexPrefix::None);

    ASSERT_EQ(hexadecimal.size(), hexadecimalLength);
    ASSERT_TRUE(std::ranges::any_of(hexadecimal, [](char hexNumberCharacter)
                                    { return hexUpperCharacters.find(hexNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateBinary)
{
    const auto binaryLength = 8;

    const auto binary = String::binary(binaryLength);

    const auto prefix = binary.substr(0, 2);
    const auto binaryNumber = binary.substr(2);

    ASSERT_EQ(binary.size(), binaryLength + 2);
    ASSERT_EQ(prefix, "0b");
    ASSERT_TRUE(std::ranges::any_of(binary, [](char binaryNumberCharacter)
                                    { return std::string("01").find(binaryNumberCharacter) != std::string::npos; }));
}

TEST_F(StringTest, shouldGenerateOctalWithPrefix)
{
    const auto octalLength = 8;

    const auto octal = String::octal(octalLength);

    const auto prefix = octal.substr(0, 2);
    const auto octalNumber = octal.substr(2);

    ASSERT_EQ(octal.size(), octalLength + 2);
    ASSERT_EQ(prefix, "0o");
    ASSERT_TRUE(
        std::ranges::any_of(octal, [](char octalNumberCharacter)
                            { return std::string("01234567").find(octalNumberCharacter) != std::string::npos; }));
}
