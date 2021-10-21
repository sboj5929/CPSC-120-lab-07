
/* Automatically generated using makeheaders. Do not edit. */
#ifndef __MIND_READER__
#define __MIND_READER__
/// \file
#include <string>

extern const int kNumberOfSuits;
std::string Suit(const std::string& card);
std::string FaceValue(const std::string& card);
std::string NumericValueToFaceValue(int value);
int DeckOrderValue(const std::string& card);
int SuitOffset(const std::string& suit);
int FitchCheneySecretSteps(const std::string& card_one,
                           const std::string& card_two,
                           const std::string& card_three);
int NumericValue(const std::string& face_value);
int FitchCheneySecretCardValue(int base_value, int steps);
#endif
