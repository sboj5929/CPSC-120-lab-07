
#include "mind_reader_functions.h"

#include <unistd.h>

#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <string>

using namespace std;

/// \file
/// Function definitions used in this project

/// There are four suits in a deck of cards, Clubs, Diamonds, Hearts, Spades
const int kNumberOfSuits = 4;

/// Given a two to three letter string that represents a \p card, return
/// a single letter string that represents the card's suit
///
/// \param card A two to three letter string representing a card,
/// ex. AS, 4D, 10H, QS
///
/// \returns A single letter string which has the suit of the given card
/// ex. S, D, H, S
std::string Suit(const std::string& card) {
  try {
    return string(1, card.at(card.size() - 1));
  } catch (exception const& problem) {
    cout << "Problem reading card's suit\n";
    cout << problem.what() << "\n";
    exit(1);
  }
}

/// Given a two to three letter string that represents a \p card, return
/// a single letter string that represents the card's face_value
///
/// \param card A two to three letter string representing a card,
/// ex. AS, 4D, 10H, QS
///
/// \returns A single letter string that which has the face_value of the
/// card (A, 2, 3, 4, 5, 6, 7, 8, 9, 1, J, Q, K)
///
/// \remark Although a 10 has two letters, only the first letter is needed
/// since it is the only card that has a value that starts with 1.
std::string FaceValue(const std::string& card) {
  try {
    return string(1, card.at(0));
  } catch (exception const& problem) {
    cout << "Problem reading card's value\n";
    cout << problem.what() << "\n";
    exit(1);
  }
}

/// NumericValue takes the \p face_value of a card as a string
/// and returns the numeric value of the card as an int
///
/// \param face_value A string representing the value of a card
/// (A, 2, ..., Q, K)
///
/// \returns The numeric value of the card as an int (0, 1, ..., 11, 12)
///
/// \remark This is in the inverse of NumericValueToFaceValue()
int NumericValue(const std::string& face_value) {
  int numeric_value = 0;
  // TODO: Implement this function given the explanation given above.
  return numeric_value;
}

/// Given a card, convert the card to the absolute deck ordered value.
///
/// Since it is quite possible that cards of the same value but of different
/// suits are selected, we will have to map all the cards to have unique values.
/// In this fashion, all the cards that have a face value of 6 will have a
/// unique value. For example, _6C_, _6D_, _6H_, and _6S_ all have a face value
/// of 6 and are of different suits. We cannot order these cards as low, middle,
/// and high unless we factor in the suits. Recall that we'll rank the suits in
/// alphabetical order so _6C_ < _6D_ < _6H_ < _6S. Mapping all the cards to
/// values between 1 and 52 is achieved by recognizing that there are 4 of each
/// card and we can assign a value to each suit: clubs are 1, diamonds are 2,
/// hearts are 3, and spades are 4.
///
/// Given a card, separate the card into it's _face value_ and _suit_. Map the
/// _face value_ to a value between 0 and 12, let's call this _numeric value_.
/// Using the suit, lookup the _suit's offset_; clubs are 1, diamonds are 2,
/// hearts are 3, and spades are 4. Finally, calculate the _deck value_ using
/// the formula _numeric value_ * 4 + _suit's offset_.
///
/// Working with a deck that is ordered by value first and suit second, you'll
/// have a deck that is ordered as _AC, AD, AH, AS, 1C, 1D, 1H, 1S,…, QC, QD,
/// QH, QS, KC, KD, KH, KS_. This means _AC_ is 1, _AD_ is 2, _KH_ is 51, and
/// _KS_ is 52. Consider the following examples.
///
/// * _AC_ is _numeric value_ of 0 and a _suit's offset_ of 1 thus 0 * 4 + 1 = 0
/// * _AS_ is _numeric value_ of 0 and a _suit's offset_ of 4 thus 0 * 4 + 4 = 4
/// * _6C_ is _numeric value_ of 5 and a _suit's offset_ of 1 thus 5 * 4 + 1 =
/// 21
/// * _6D_ is _numeric value_ of 5 and a _suit's offset_ of 2 thus 5 * 4 + 2 =
/// 22
/// * _6H_ is _numeric value_ of 5 and a _suit's offset_ of 3 thus 5 * 4 + 3 =
/// 23
/// * _6S_ is _numeric value_ of 5 and a _suit's offset_ of 4 thus 5 * 4 + 4 =
/// 24
/// * _QH_ is _numeric value_ of 11 and a _suit's offset_ of 3 thus 11 * 4 + 3 =
/// 47
/// * _KS_ is _numeric value_ of 12 and a _suit's offset_ of 4 thus 12 * 4 + 4 =
/// 52
int DeckOrderValue(const std::string& card) {
  int deck_order_value = 0;
  // TODO: Implement this function given the explanation given above.
  return deck_order_value;
}

/// NumericValueToFaceValue takes the numeric \p value of a card and returns
/// the face value.
///
/// \param value An int representing the value of a card as an int
/// (0, 1, ..., 11, 12)
///
/// \returns A string representing the value of a card (A, 2, ..., Q, K)
///
/// \remark This is the inverse of NumericValue()
std::string NumericValueToFaceValue(int value) {
  string face_value;
  // TODO: Implement this function given the explanation given above.
  return face_value;
}

/// The offset of each suit; since the cards are ordered value first, suit
/// second, the function returns the rank of a given \p suit. Suits are
/// ranked in alphabetical order (C=1, D, H, S). (Does not follow CHSD order.)
///
/// \param suit A single letter string representing the suit (C, D, H, S)
///
/// \returns An int between [1,4] representing the rank of the given suit
int SuitOffset(const std::string& suit) {
  // This follows *alphabetical order* CDHS
  // not CHSD
  int offset = 0;
  // TODO: Implement this function given the explanation given above.
  return offset;
}

/// FitchCheneySecretCardValue returns the numeric value of the secret card
/// given the \p base_value and the \p steps.
///
/// Since the \p base_value of the base card is an integer between 0
/// and 12, we can add \p steps to the \p base_value to find the
/// numeric value of the secret card. To wrap the count around
/// (from K to A), use modulo 13.
/// \f$\left(base\_value + steps \right) \% 13\f$
///
/// \param base_value The numeric value of the base card, for
/// example 3C -> 2
/// \param steps The number of steps from the base numeric value to the secret
/// card value
///
/// \returns The simple_value of the secret card as an int (0, 1, ..., 11, 12)
int FitchCheneySecretCardValue(int base_value, int steps) {
  int card_value = 0;
  // TODO: Implement this function given the explanation given above.
  return card_value;
}

/// SecretSteps calculates the number of steps that are being signaled given
/// the order of the three cards.
///
/// There are four cards given on the command line. The first card is the base
/// card. The remaining three cards are \p card_one (argv[2]),
/// \p card_two (arg[3]), \p card_three (argv[4]).
///
/// Given the relative order of these cards, determine the steps to return
/// (labeled Value to Add in the table).
///
/// | Order | Value to Add |
/// | :--- | :---: |
/// | low, middle, high | 1 |
/// | low, high, middle | 2 |
/// | middle, low, high | 3 |
/// | middle, high low | 4 |
/// | high, low, middle | 5 |
/// | high, middle, low | 6 |
///
/// \param card_one The first card, expressed as a 2-3 letter string
/// \param card_two The second card, expressed as a 2-3 letter string
/// \param card_three The third card, expressed as a 2-3 letter string
///
/// \returns The number of steps to add (labeled Value Add in the table)
int FitchCheneySecretSteps(const std::string& card_one,
                           const std::string& card_two,
                           const std::string& card_three) {
  int secret_steps = 0;
  // TODO: implement this function. This function was not previously
  // implemented.
  return secret_steps;
}
