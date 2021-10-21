
/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include <gtest/gtest.h>

#include <cstdio>
#include <string>

#include "mind_reader_functions.h"

namespace {

// std::string Suit(const std::string& card);
TEST(SuitTest, Clubs) {
  EXPECT_EQ("C", Suit("AC"));
  EXPECT_EQ("C", Suit("2C"));
  EXPECT_EQ("C", Suit("3C"));
  EXPECT_EQ("C", Suit("4C"));
  EXPECT_EQ("C", Suit("5C"));
  EXPECT_EQ("C", Suit("6C"));
  EXPECT_EQ("C", Suit("7C"));
  EXPECT_EQ("C", Suit("8C"));
  EXPECT_EQ("C", Suit("9C"));
  EXPECT_EQ("C", Suit("10C"));
  EXPECT_EQ("C", Suit("JC"));
  EXPECT_EQ("C", Suit("QC"));
  EXPECT_EQ("C", Suit("KC"));
}

TEST(SuitTest, Diamonds) {
  EXPECT_EQ("D", Suit("AD"));
  EXPECT_EQ("D", Suit("2D"));
  EXPECT_EQ("D", Suit("3D"));
  EXPECT_EQ("D", Suit("4D"));
  EXPECT_EQ("D", Suit("5D"));
  EXPECT_EQ("D", Suit("6D"));
  EXPECT_EQ("D", Suit("7D"));
  EXPECT_EQ("D", Suit("8D"));
  EXPECT_EQ("D", Suit("9D"));
  EXPECT_EQ("D", Suit("10D"));
  EXPECT_EQ("D", Suit("JD"));
  EXPECT_EQ("D", Suit("QD"));
  EXPECT_EQ("D", Suit("KD"));
}

TEST(SuitTest, Hearts) {
  EXPECT_EQ("H", Suit("AH"));
  EXPECT_EQ("H", Suit("2H"));
  EXPECT_EQ("H", Suit("3H"));
  EXPECT_EQ("H", Suit("4H"));
  EXPECT_EQ("H", Suit("5H"));
  EXPECT_EQ("H", Suit("6H"));
  EXPECT_EQ("H", Suit("7H"));
  EXPECT_EQ("H", Suit("8H"));
  EXPECT_EQ("H", Suit("9H"));
  EXPECT_EQ("H", Suit("10H"));
  EXPECT_EQ("H", Suit("JH"));
  EXPECT_EQ("H", Suit("QH"));
  EXPECT_EQ("H", Suit("KH"));
}

TEST(SuitTest, Spades) {
  EXPECT_EQ("S", Suit("AS"));
  EXPECT_EQ("S", Suit("2S"));
  EXPECT_EQ("S", Suit("3S"));
  EXPECT_EQ("S", Suit("4S"));
  EXPECT_EQ("S", Suit("5S"));
  EXPECT_EQ("S", Suit("6S"));
  EXPECT_EQ("S", Suit("7S"));
  EXPECT_EQ("S", Suit("8S"));
  EXPECT_EQ("S", Suit("9S"));
  EXPECT_EQ("S", Suit("10S"));
  EXPECT_EQ("S", Suit("JS"));
  EXPECT_EQ("S", Suit("QS"));
  EXPECT_EQ("S", Suit("KS"));
}

// std::string FaceValue(const std::string& card);
TEST(FaceValueTest, Clubs) {
  EXPECT_EQ("A", FaceValue("AC"));
  EXPECT_EQ("2", FaceValue("2C"));
  EXPECT_EQ("3", FaceValue("3C"));
  EXPECT_EQ("4", FaceValue("4C"));
  EXPECT_EQ("5", FaceValue("5C"));
  EXPECT_EQ("6", FaceValue("6C"));
  EXPECT_EQ("7", FaceValue("7C"));
  EXPECT_EQ("8", FaceValue("8C"));
  EXPECT_EQ("9", FaceValue("9C"));
  EXPECT_EQ("1", FaceValue("10C"));
  EXPECT_EQ("J", FaceValue("JC"));
  EXPECT_EQ("Q", FaceValue("QC"));
  EXPECT_EQ("K", FaceValue("KC"));
}

TEST(FaceValueTest, Diamonds) {
  EXPECT_EQ("A", FaceValue("AD"));
  EXPECT_EQ("2", FaceValue("2D"));
  EXPECT_EQ("3", FaceValue("3D"));
  EXPECT_EQ("4", FaceValue("4D"));
  EXPECT_EQ("5", FaceValue("5D"));
  EXPECT_EQ("6", FaceValue("6D"));
  EXPECT_EQ("7", FaceValue("7D"));
  EXPECT_EQ("8", FaceValue("8D"));
  EXPECT_EQ("9", FaceValue("9D"));
  EXPECT_EQ("1", FaceValue("10D"));
  EXPECT_EQ("J", FaceValue("JD"));
  EXPECT_EQ("Q", FaceValue("QD"));
  EXPECT_EQ("K", FaceValue("KD"));
}

TEST(FaceValueTest, Hearts) {
  EXPECT_EQ("A", FaceValue("AH"));
  EXPECT_EQ("2", FaceValue("2H"));
  EXPECT_EQ("3", FaceValue("3H"));
  EXPECT_EQ("4", FaceValue("4H"));
  EXPECT_EQ("5", FaceValue("5H"));
  EXPECT_EQ("6", FaceValue("6H"));
  EXPECT_EQ("7", FaceValue("7H"));
  EXPECT_EQ("8", FaceValue("8H"));
  EXPECT_EQ("9", FaceValue("9H"));
  EXPECT_EQ("1", FaceValue("10H"));
  EXPECT_EQ("J", FaceValue("JH"));
  EXPECT_EQ("Q", FaceValue("QH"));
  EXPECT_EQ("K", FaceValue("KH"));
}

TEST(FaceValueTest, Spades) {
  EXPECT_EQ("A", FaceValue("AS"));
  EXPECT_EQ("2", FaceValue("2S"));
  EXPECT_EQ("3", FaceValue("3S"));
  EXPECT_EQ("4", FaceValue("4S"));
  EXPECT_EQ("5", FaceValue("5S"));
  EXPECT_EQ("6", FaceValue("6S"));
  EXPECT_EQ("7", FaceValue("7S"));
  EXPECT_EQ("8", FaceValue("8S"));
  EXPECT_EQ("9", FaceValue("9S"));
  EXPECT_EQ("1", FaceValue("10S"));
  EXPECT_EQ("J", FaceValue("JS"));
  EXPECT_EQ("Q", FaceValue("QS"));
  EXPECT_EQ("K", FaceValue("KS"));
}

// std::string NumericValueToFaceValue(int value);
TEST(NumericValueToFaceValue, Trivial) {
  EXPECT_EQ("A", NumericValueToFaceValue(0));
  EXPECT_EQ("2", NumericValueToFaceValue(1));
  EXPECT_EQ("3", NumericValueToFaceValue(2));
  EXPECT_EQ("4", NumericValueToFaceValue(3));
  EXPECT_EQ("5", NumericValueToFaceValue(4));
  EXPECT_EQ("6", NumericValueToFaceValue(5));
  EXPECT_EQ("7", NumericValueToFaceValue(6));
  EXPECT_EQ("8", NumericValueToFaceValue(7));
  EXPECT_EQ("9", NumericValueToFaceValue(8));
  EXPECT_EQ("10", NumericValueToFaceValue(9));
  EXPECT_EQ("J", NumericValueToFaceValue(10));
  EXPECT_EQ("Q", NumericValueToFaceValue(11));
  EXPECT_EQ("K", NumericValueToFaceValue(12));
}

// int DeckOrderValue(const std::string& card);
TEST(DeckOrderValueTest, Clubs) {
  EXPECT_EQ(1, DeckOrderValue("AC"));
  EXPECT_EQ(5, DeckOrderValue("2C"));
  EXPECT_EQ(9, DeckOrderValue("3C"));
  EXPECT_EQ(13, DeckOrderValue("4C"));
  EXPECT_EQ(17, DeckOrderValue("5C"));
  EXPECT_EQ(21, DeckOrderValue("6C"));
  EXPECT_EQ(25, DeckOrderValue("7C"));
  EXPECT_EQ(29, DeckOrderValue("8C"));
  EXPECT_EQ(33, DeckOrderValue("9C"));
  EXPECT_EQ(37, DeckOrderValue("10C"));
  EXPECT_EQ(41, DeckOrderValue("JC"));
  EXPECT_EQ(45, DeckOrderValue("QC"));
  EXPECT_EQ(49, DeckOrderValue("KC"));
}

TEST(DeckOrderValueTest, Diamonds) {
  EXPECT_EQ(2, DeckOrderValue("AD"));
  EXPECT_EQ(6, DeckOrderValue("2D"));
  EXPECT_EQ(10, DeckOrderValue("3D"));
  EXPECT_EQ(14, DeckOrderValue("4D"));
  EXPECT_EQ(18, DeckOrderValue("5D"));
  EXPECT_EQ(22, DeckOrderValue("6D"));
  EXPECT_EQ(26, DeckOrderValue("7D"));
  EXPECT_EQ(30, DeckOrderValue("8D"));
  EXPECT_EQ(34, DeckOrderValue("9D"));
  EXPECT_EQ(38, DeckOrderValue("10D"));
  EXPECT_EQ(42, DeckOrderValue("JD"));
  EXPECT_EQ(46, DeckOrderValue("QD"));
  EXPECT_EQ(50, DeckOrderValue("KD"));
}

TEST(DeckOrderValueTest, Hearts) {
  EXPECT_EQ(3, DeckOrderValue("AH"));
  EXPECT_EQ(7, DeckOrderValue("2H"));
  EXPECT_EQ(11, DeckOrderValue("3H"));
  EXPECT_EQ(15, DeckOrderValue("4H"));
  EXPECT_EQ(19, DeckOrderValue("5H"));
  EXPECT_EQ(23, DeckOrderValue("6H"));
  EXPECT_EQ(27, DeckOrderValue("7H"));
  EXPECT_EQ(31, DeckOrderValue("8H"));
  EXPECT_EQ(35, DeckOrderValue("9H"));
  EXPECT_EQ(39, DeckOrderValue("10H"));
  EXPECT_EQ(43, DeckOrderValue("JH"));
  EXPECT_EQ(47, DeckOrderValue("QH"));
  EXPECT_EQ(51, DeckOrderValue("KH"));
}

TEST(DeckOrderValueTest, Spades) {
  EXPECT_EQ(4, DeckOrderValue("AS"));
  EXPECT_EQ(8, DeckOrderValue("2S"));
  EXPECT_EQ(12, DeckOrderValue("3S"));
  EXPECT_EQ(16, DeckOrderValue("4S"));
  EXPECT_EQ(20, DeckOrderValue("5S"));
  EXPECT_EQ(24, DeckOrderValue("6S"));
  EXPECT_EQ(28, DeckOrderValue("7S"));
  EXPECT_EQ(32, DeckOrderValue("8S"));
  EXPECT_EQ(36, DeckOrderValue("9S"));
  EXPECT_EQ(40, DeckOrderValue("10S"));
  EXPECT_EQ(44, DeckOrderValue("JS"));
  EXPECT_EQ(48, DeckOrderValue("QS"));
  EXPECT_EQ(52, DeckOrderValue("KS"));
}

// int SuitOffset(const std::string& suit);
TEST(SuitOffsetTest, Trivial) {
  EXPECT_EQ(1, SuitOffset("C"));
  EXPECT_EQ(2, SuitOffset("D"));
  EXPECT_EQ(3, SuitOffset("H"));
  EXPECT_EQ(4, SuitOffset("S"));
}

// int NumericValue(const std::string& string_value);
TEST(NumericValueTest, Trivial) {
  EXPECT_EQ(0, NumericValue("A"));
  EXPECT_EQ(1, NumericValue("2"));
  EXPECT_EQ(2, NumericValue("3"));
  EXPECT_EQ(3, NumericValue("4"));
  EXPECT_EQ(4, NumericValue("5"));
  EXPECT_EQ(5, NumericValue("6"));
  EXPECT_EQ(6, NumericValue("7"));
  EXPECT_EQ(7, NumericValue("8"));
  EXPECT_EQ(8, NumericValue("9"));
  EXPECT_EQ(9, NumericValue("1"));
  EXPECT_EQ(10, NumericValue("J"));
  EXPECT_EQ(11, NumericValue("Q"));
  EXPECT_EQ(12, NumericValue("K"));
}

// int FitchCheneySecretCardValue(int base_value, int steps);
TEST(FitchCheneySecretCardValueTest, Trivial) {
  EXPECT_EQ(1, FitchCheneySecretCardValue(0, 1));
  EXPECT_EQ(2, FitchCheneySecretCardValue(0, 2));
  EXPECT_EQ(3, FitchCheneySecretCardValue(0, 3));
  EXPECT_EQ(4, FitchCheneySecretCardValue(0, 4));
  EXPECT_EQ(5, FitchCheneySecretCardValue(0, 5));
  EXPECT_EQ(6, FitchCheneySecretCardValue(0, 6));
  EXPECT_EQ(2, FitchCheneySecretCardValue(1, 1));
  EXPECT_EQ(3, FitchCheneySecretCardValue(1, 2));
  EXPECT_EQ(4, FitchCheneySecretCardValue(1, 3));
  EXPECT_EQ(5, FitchCheneySecretCardValue(1, 4));
  EXPECT_EQ(6, FitchCheneySecretCardValue(1, 5));
  EXPECT_EQ(7, FitchCheneySecretCardValue(1, 6));
  EXPECT_EQ(3, FitchCheneySecretCardValue(2, 1));
  EXPECT_EQ(4, FitchCheneySecretCardValue(2, 2));
  EXPECT_EQ(5, FitchCheneySecretCardValue(2, 3));
  EXPECT_EQ(6, FitchCheneySecretCardValue(2, 4));
  EXPECT_EQ(7, FitchCheneySecretCardValue(2, 5));
  EXPECT_EQ(8, FitchCheneySecretCardValue(2, 6));
  EXPECT_EQ(4, FitchCheneySecretCardValue(3, 1));
  EXPECT_EQ(5, FitchCheneySecretCardValue(3, 2));
  EXPECT_EQ(6, FitchCheneySecretCardValue(3, 3));
  EXPECT_EQ(7, FitchCheneySecretCardValue(3, 4));
  EXPECT_EQ(8, FitchCheneySecretCardValue(3, 5));
  EXPECT_EQ(9, FitchCheneySecretCardValue(3, 6));
  EXPECT_EQ(5, FitchCheneySecretCardValue(4, 1));
  EXPECT_EQ(6, FitchCheneySecretCardValue(4, 2));
  EXPECT_EQ(7, FitchCheneySecretCardValue(4, 3));
  EXPECT_EQ(8, FitchCheneySecretCardValue(4, 4));
  EXPECT_EQ(9, FitchCheneySecretCardValue(4, 5));
  EXPECT_EQ(10, FitchCheneySecretCardValue(4, 6));
  EXPECT_EQ(6, FitchCheneySecretCardValue(5, 1));
  EXPECT_EQ(7, FitchCheneySecretCardValue(5, 2));
  EXPECT_EQ(8, FitchCheneySecretCardValue(5, 3));
  EXPECT_EQ(9, FitchCheneySecretCardValue(5, 4));
  EXPECT_EQ(10, FitchCheneySecretCardValue(5, 5));
  EXPECT_EQ(11, FitchCheneySecretCardValue(5, 6));
  EXPECT_EQ(7, FitchCheneySecretCardValue(6, 1));
  EXPECT_EQ(8, FitchCheneySecretCardValue(6, 2));
  EXPECT_EQ(9, FitchCheneySecretCardValue(6, 3));
  EXPECT_EQ(10, FitchCheneySecretCardValue(6, 4));
  EXPECT_EQ(11, FitchCheneySecretCardValue(6, 5));
  EXPECT_EQ(12, FitchCheneySecretCardValue(6, 6));
  EXPECT_EQ(8, FitchCheneySecretCardValue(7, 1));
  EXPECT_EQ(9, FitchCheneySecretCardValue(7, 2));
  EXPECT_EQ(10, FitchCheneySecretCardValue(7, 3));
  EXPECT_EQ(11, FitchCheneySecretCardValue(7, 4));
  EXPECT_EQ(12, FitchCheneySecretCardValue(7, 5));
  EXPECT_EQ(0, FitchCheneySecretCardValue(7, 6));
  EXPECT_EQ(9, FitchCheneySecretCardValue(8, 1));
  EXPECT_EQ(10, FitchCheneySecretCardValue(8, 2));
  EXPECT_EQ(11, FitchCheneySecretCardValue(8, 3));
  EXPECT_EQ(12, FitchCheneySecretCardValue(8, 4));
  EXPECT_EQ(0, FitchCheneySecretCardValue(8, 5));
  EXPECT_EQ(1, FitchCheneySecretCardValue(8, 6));
  EXPECT_EQ(10, FitchCheneySecretCardValue(9, 1));
  EXPECT_EQ(11, FitchCheneySecretCardValue(9, 2));
  EXPECT_EQ(12, FitchCheneySecretCardValue(9, 3));
  EXPECT_EQ(0, FitchCheneySecretCardValue(9, 4));
  EXPECT_EQ(1, FitchCheneySecretCardValue(9, 5));
  EXPECT_EQ(2, FitchCheneySecretCardValue(9, 6));
  EXPECT_EQ(11, FitchCheneySecretCardValue(10, 1));
  EXPECT_EQ(12, FitchCheneySecretCardValue(10, 2));
  EXPECT_EQ(0, FitchCheneySecretCardValue(10, 3));
  EXPECT_EQ(1, FitchCheneySecretCardValue(10, 4));
  EXPECT_EQ(2, FitchCheneySecretCardValue(10, 5));
  EXPECT_EQ(3, FitchCheneySecretCardValue(10, 6));
  EXPECT_EQ(12, FitchCheneySecretCardValue(11, 1));
  EXPECT_EQ(0, FitchCheneySecretCardValue(11, 2));
  EXPECT_EQ(1, FitchCheneySecretCardValue(11, 3));
  EXPECT_EQ(2, FitchCheneySecretCardValue(11, 4));
  EXPECT_EQ(3, FitchCheneySecretCardValue(11, 5));
  EXPECT_EQ(4, FitchCheneySecretCardValue(11, 6));
  EXPECT_EQ(0, FitchCheneySecretCardValue(12, 1));
  EXPECT_EQ(1, FitchCheneySecretCardValue(12, 2));
  EXPECT_EQ(2, FitchCheneySecretCardValue(12, 3));
  EXPECT_EQ(3, FitchCheneySecretCardValue(12, 4));
  EXPECT_EQ(4, FitchCheneySecretCardValue(12, 5));
  EXPECT_EQ(5, FitchCheneySecretCardValue(12, 6));
}

// int FitchCheneySecretSteps(const std::string& card_one,
//                           const std::string& card_two,
//                           const std::string& card_three);

TEST(FitchCheneySecretStepsTest, Trivial) {
  EXPECT_EQ(1, FitchCheneySecretSteps("4D", "5D", "6H"));
  EXPECT_EQ(2, FitchCheneySecretSteps("4D", "6H", "5D"));
  EXPECT_EQ(3, FitchCheneySecretSteps("5D", "4D", "6H"));
  EXPECT_EQ(4, FitchCheneySecretSteps("5D", "6H", "4D"));
  EXPECT_EQ(5, FitchCheneySecretSteps("6H", "4D", "5D"));
  EXPECT_EQ(6, FitchCheneySecretSteps("6H", "5D", "4D"));
  EXPECT_EQ(1, FitchCheneySecretSteps("4D", "5D", "6H"));
  EXPECT_EQ(2, FitchCheneySecretSteps("4D", "6H", "5D"));
  EXPECT_EQ(3, FitchCheneySecretSteps("5D", "4D", "6H"));
  EXPECT_EQ(4, FitchCheneySecretSteps("5D", "6H", "4D"));
  EXPECT_EQ(5, FitchCheneySecretSteps("6H", "4D", "5D"));
  EXPECT_EQ(6, FitchCheneySecretSteps("6H", "5D", "4D"));
  EXPECT_EQ(1, FitchCheneySecretSteps("4D", "5D", "6H"));
  EXPECT_EQ(2, FitchCheneySecretSteps("4D", "6H", "5D"));
  EXPECT_EQ(3, FitchCheneySecretSteps("5D", "4D", "6H"));
  EXPECT_EQ(4, FitchCheneySecretSteps("5D", "6H", "4D"));
  EXPECT_EQ(5, FitchCheneySecretSteps("6H", "4D", "5D"));
  EXPECT_EQ(6, FitchCheneySecretSteps("6H", "5D", "4D"));
}

TEST(FitchCheneySecretStepsTest, FaceCards) {
  EXPECT_EQ(1, FitchCheneySecretSteps("10D", "JD", "QH"));
  EXPECT_EQ(2, FitchCheneySecretSteps("10D", "QH", "JD"));
  EXPECT_EQ(3, FitchCheneySecretSteps("JD", "AD", "KH"));
  EXPECT_EQ(4, FitchCheneySecretSteps("JD", "QH", "AD"));
  EXPECT_EQ(5, FitchCheneySecretSteps("KH", "AD", "QD"));
  EXPECT_EQ(6, FitchCheneySecretSteps("KH", "JD", "AD"));
}

TEST(FitchCheneySecretStepsTest, SameFaceValue) {
  EXPECT_EQ(1, FitchCheneySecretSteps("4C", "4D", "4H"));
  EXPECT_EQ(2, FitchCheneySecretSteps("4C", "4H", "4D"));
  EXPECT_EQ(3, FitchCheneySecretSteps("4D", "4C", "4H"));
  EXPECT_EQ(4, FitchCheneySecretSteps("4D", "4H", "4C"));
  EXPECT_EQ(5, FitchCheneySecretSteps("4H", "4C", "4D"));
  EXPECT_EQ(6, FitchCheneySecretSteps("4H", "4D", "4C"));
  EXPECT_EQ(1, FitchCheneySecretSteps("JC", "JD", "JH"));
  EXPECT_EQ(2, FitchCheneySecretSteps("JC", "JH", "JD"));
  EXPECT_EQ(3, FitchCheneySecretSteps("JD", "JC", "JH"));
  EXPECT_EQ(4, FitchCheneySecretSteps("JD", "JH", "JC"));
  EXPECT_EQ(5, FitchCheneySecretSteps("JH", "JC", "JD"));
  EXPECT_EQ(6, FitchCheneySecretSteps("JH", "JD", "JC"));
  EXPECT_EQ(1, FitchCheneySecretSteps("QC", "QD", "QH"));
  EXPECT_EQ(2, FitchCheneySecretSteps("QC", "QH", "QD"));
  EXPECT_EQ(3, FitchCheneySecretSteps("QD", "QC", "QH"));
  EXPECT_EQ(4, FitchCheneySecretSteps("QD", "QH", "QC"));
  EXPECT_EQ(5, FitchCheneySecretSteps("QH", "QC", "QD"));
  EXPECT_EQ(6, FitchCheneySecretSteps("QH", "QD", "QC"));
  EXPECT_EQ(1, FitchCheneySecretSteps("KC", "KD", "KH"));
  EXPECT_EQ(2, FitchCheneySecretSteps("KC", "KH", "KD"));
  EXPECT_EQ(3, FitchCheneySecretSteps("KD", "KC", "KH"));
  EXPECT_EQ(4, FitchCheneySecretSteps("KD", "KH", "KC"));
  EXPECT_EQ(5, FitchCheneySecretSteps("KH", "KC", "KD"));
  EXPECT_EQ(6, FitchCheneySecretSteps("KH", "KD", "KC"));
  EXPECT_EQ(1, FitchCheneySecretSteps("AC", "AD", "AH"));
  EXPECT_EQ(2, FitchCheneySecretSteps("AC", "AH", "AD"));
  EXPECT_EQ(3, FitchCheneySecretSteps("AD", "AC", "AH"));
  EXPECT_EQ(4, FitchCheneySecretSteps("AD", "AH", "AC"));
  EXPECT_EQ(5, FitchCheneySecretSteps("AH", "AC", "AD"));
  EXPECT_EQ(6, FitchCheneySecretSteps("AH", "AD", "AC"));
  EXPECT_EQ(1, FitchCheneySecretSteps("10C", "10D", "10H"));
  EXPECT_EQ(2, FitchCheneySecretSteps("10C", "10H", "10D"));
  EXPECT_EQ(3, FitchCheneySecretSteps("10D", "10C", "10H"));
  EXPECT_EQ(4, FitchCheneySecretSteps("10D", "10H", "10C"));
  EXPECT_EQ(5, FitchCheneySecretSteps("10H", "10C", "10D"));
  EXPECT_EQ(6, FitchCheneySecretSteps("10H", "10D", "10C"));
}

}  // namespace
