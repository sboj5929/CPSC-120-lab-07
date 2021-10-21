
# Fitch Cheney's Five Card Trick Part 2

## Introduction

This exercise is part of a two part lab exercise. This is the first part where you shall develop the necessary parts needed to perform a magical mind reading card trick with the assistance of your computer.

The goal of this exercise is to develop and test most of the functions (units) needed in the following part of this lab. There is no main function in this exercise, however there is a small collection of functions that must be defined in `mind_reader_functions.cc`.

The lab has the following files:
* `mind_reader.cc`
* `mind_reader_functions.cc`
* `mind_reader_functions.h` - Do not edit.
* `mind_reader_unittest.cc` - Do not edit.

Previously, you implemented most of the functions needed for this project in the file `mind_reader_functions.cc`. Copy over the functions you completed and complete one additional function. The function is:

```c++
int FitchCheneySecretSteps(const std::string& card_one,
                           const std::string& card_two,
                           const std::string& card_three){

}
```

In `mind_reader.cc`, the main function needs to be written to process the command line arguments and handle the logic behind the mind reading.

Use the project's documentation and the feedback from the unit tests and the system test to develop the mind reader.

## The Card Trick

In this exercise, we shall write a program that will masquerade as a artificial intelligence. Imagine telling a friend or family member that in your introductory computer science class, you have learned how to write programs that can calculate what cards you have selected from a deck of cards. You may go on to explain that with a little more work, your computer program can predict what everyone was dealt in a poker game. For now, your program can predict the fifth card in a poker hand given the first four cards.

William Fitch Cheney, Jr. was a mathematics professor at Tufts University, University of Connecticut, and the University of Hartford in the middle third of the 20th century passing away in 1974. Other than being a professor, he was a published amateur magician. In the book _Math Miracles_ by Wallace Lee, a trick was published that is credited to Fitch Cheney. This trick uses discrete math, which is very important to a computer science student, to create an astounding effect.

The trick is performed with two magicians. In our case, one of the magicians will be our computer program. The trick can be performed with any deck of playing cards. The deck can be a borrowed deck and can be shuffled as many times as one would like. The trick requires no preparation, gimmicks, or gaffs. Five cards are randomly selected from the deck and given to the the human magician. The human magician then shows (inputs) four of the five cards to the computer magician. The computer magician reveals the unseen fifth card.

To get an idea of how a similar trick is performed, watch a performance of [Al Stanger's Miracle Poker Machine](https://youtu.be/Ef0zy6cXvkY) presented by [Andy Martin](https://www.martinsmagic.com/). There are many videos of the Five Card Trick presented by [two amateur magicians](https://youtu.be/8rfuV12dGjA) and [one magician with a computer](https://youtu.be/MRGTA9y72nA).

### Background

Let's first review some basic terminology. A deck of cards has four suits: clubs ♣️, diamonds ♦️, hearts ♥️, and spades ♠️. Each suit has 13 cards: Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King. Let's abbreviate Ace as _A_, Jack as _J_, Queen as _Q_, and King as _K_. Let's assume that Ace is the lowest value card, with a value of 0, and King is the highest value card, with a value of 12. (In computing, we like counting from zero rather than 1.) Let's abbreviate the suits as _C_ for clubs, _D_ for diamonds, _H_ for hearts, and _S_ for spades. Additionally, if there are two cards with the same value, then the suit will break the tie. The suits are valued in alphabetical order.

Here are some examples of abbreviations using the given schema:

* The 5 of diamonds is _5D_
* The Jack of hearts is _JH_
* The 2 of clubs is _2C_
* The 7 of clubs is less than the King of clubs, or _7C_ < _KC_
* The Ace of spades is greater than the Ace of diamonds, or _AS_ > _AD_

Typically, a deck of cards is ordered by suit and then by value. This means that all the clubs are together from Ace to King, all the diamonds are together from Ace to King, all the hearts are together from Ace to King, and all the spades are together from Ace to King. To facilitate the calculations in this trick, the sorting of the deck has to be changed. The trick requires that cards are ordered by value and then by suit. This means that the cards are ordered as _AC, AD, AH, AS, 1C, 1D, 1H, 1S, … , QC, QD, QH, QS, KC, KD, KH, KS_. (This detail should not be shared with the spectator.)

### Explanation

The trick is an _almost_ self working card trick which uses a scheme to encode the hidden fifth card's suit and value in the way the other four other cards are presented.

The foundation of this trick is discrete math and Michael Kleber wrote a wonderful article about this trick in [The Mathematical Intelligencer 24, 9–11 (2002)](https://doi-org.lib-proxy.fullerton.edu/10.1007/BF03025305) which explains the math in great detail. (You can also [find this article](https://www.google.com/search?q=michael+kleber+best+card+trick+mathematical+intelligencer) through your favorite search engine.)

Starting with a deck of playing cards, make sure the jokers are removed. Shuffle the cards as many times as you or your spectator likes then select five cards. Let's imagine the following cards are selected: 3 of clubs, 7 of diamonds, 2 of clubs, 10 of spades, and the 3 of hearts.

The cards are handed to the human magician. The magician will first sort the cards into identical suits. Given the hand described above, the magician mentally organizes the cards into:

* clubs: _2C_, _3C_
* diamonds: _7D_
* hearts: _3H_
* spades: _10S_

We need to use a suit that has at least two cards. In this example, the only suit that has two cards is the clubs. One card must be the _base_ card and the other card will be the _secret_ card.

The rules for the base card are:

* Must be the same suit as the secret card

The rules for the secret card are:

* Must be at most +6 steps less than the secret card; for example a _2C_ is 1 step away from a _3C_ and a _4H_ is 5 steps away from a _QH_. (The steps wrap around.)
* The secret card is not revealed until the end

In our example, let's select the base card as _2C_ and the secret card as _3C_. This means that the secret card is only +1 away from the base.

The magician begins by presenting the base card to the computer. This tells the computer the suit and the base value to start from.

Next the magician must present the remaining three cards in a certain order to signal how much to add to the base card. Let's call this _secret steps_. This requires a little bit of subterfuge. Using the table below, order the cards such that they communicate what you want to add to the base card. In the given example, we wish to add one so the cards will be order low, middle, high which is _3H_, _7D_, _10S_.

| Order | Value to Add |
| :--- | :---: |
| low, middle, high | 1 |
| low, high, middle | 2 |
| middle, low, high | 3 |
| middle, high low | 4 |
| high, low, middle | 5 |
| high, middle, low | 6 |

The computer receiving this input will do the math and print out the secret card, in this case _3C_ because _2C_ + 1 is _3C_.

The computer calculates it a little differently since the cards have values between 0 and 12. The _2C_ maps to 1, our secret step is 1 so the computer calculates a value of 2 which maps back to a card's face value of 3.

To generalize this into a formula, (_base card value_ + _secret steps_) % 13 is how the computer program knows how to predict the secret card.

Let's try another example where the base card is greater than the secret card.

Let's imagine the following cards are selected: Jack of diamonds, 7 of diamonds, Ace of clubs, King of hearts, and the 5 of hearts.

* clubs: _AC_
* diamonds: _7D_, _JD_
* hearts: _KH_, _5H_
* spades: None

Let's select the base card as the King of hearts and the secret card as the 5 of hearts.

This means we need to tell the computer to add 5 to the King and that the secret card's suit is heart.

We tell the computer the first card is _KH_, and then order the cards high, low, middle to tell the computer to add 5 to the King. We enter _JD_, _AC_, _7D_ which means the _secret steps_ is +5. Remember to use the formula (_base card value_ + _secret steps_) % 13 or (12 + 4) % 13 which evaluates to 4. (Remember the values of our cards start from zero and go to 12.) Since the base card is a heart, the computer responds with _5H_.

Since it is quite possible that cards of the same value but of different suits are selected, we will have to map all the cards to have unique values. In this fashion, all the cards that have a face value of 6 will have a unique value. For example, _6C_, _6D_, _6H_, and _6S_ all have a face value of 6 and are of different suits. We cannot order these cards as low, middle, and high unless we factor in the suits. Recall that we'll rank the suits in alphabetical order so _6C_ < _6D_ < _6H_ < _6S_. Mapping all the cards to values between 1 and 52 is achieved by recognizing that there are 4 of each card and we can assign a value to each suit: clubs are 1, diamonds are 2, hearts are 3, and spades are 4.

Given a card, separate the card into it's _face value_ and _suit_. Map the _face value_ to a value between 0 and 12, let's call this _numeric value_. Using the suit, lookup the _suit's offset_; clubs are 1, diamonds are 2, hearts are 3, and spades are 4. Finally, calculate the _deck value_ using the formula _numeric value_ * 4 + _suit's offset_.

Working with a deck that is ordered by value first and suit second, you'll have a deck that is ordered as _AC, AD, AH, AS, 1C, 1D, 1H, 1S,…, QC, QD, QH, QS, KC, KD, KH, KS_. This means _AC_ is 1, _AD_ is 2, _KH_ is 51, and _KS_ is 52. Consider the following examples.

* _AC_ is _simple value_ of 0 and a _suit's offset_ of 1 thus 0 * 4 + 1 = 0
* _AS_ is _simple value_ of 0 and a _suit's offset_ of 4 thus 0 * 4 + 4 = 4
* _6C_ is _simple value_ of 5 and a _suit's offset_ of 1 thus 5 * 4 + 1 = 21
* _6D_ is _simple value_ of 5 and a _suit's offset_ of 2 thus 5 * 4 + 2 = 22
* _6H_ is _simple value_ of 5 and a _suit's offset_ of 3 thus 5 * 4 + 3 = 23
* _6S_ is _simple value_ of 5 and a _suit's offset_ of 4 thus 5 * 4 + 4 = 24
* _QH_ is _simple value_ of 11 and a _suit's offset_ of 3 thus 11 * 4 + 3 = 47
* _KS_ is _simple value_ of 12 and a _suit's offset_ of 4 thus 12 * 4 + 4 = 52

## Tips

When working with if-else-if-else conditions here are some tips to keep in mind:

* Always handle the exceptions first and leave the general case for the else statement
* Try to have one entry point and one exit for conditions and functions; use a variable such as `return_value` to hold on to the value you wish to return and then return the variable at the end of the function.
* Write comments in clear, plain english that explain to you what each case is supposed to do. This will help keep your code organized and help you fix any errors.

## Inline Documentation

Are you curious what the `Doxyfile` is for? Wonder what the difference is between the regular comments (`//`) and the weird comments (`///`)?

The triple slash comment (`///`) is used to create documentation using a documentation generator named [Doxygen](http://www.doxygen.nl). In the C++ community, Doxygen is a commonly used program to generate HTML and PDF documentation from a program's comments.

To try it out, use `make doc`. This will create a folder in the project's directory named `doc`. Inside of that directory are HTML files which you can view with your web browser.

Try the following commands to generate and view the documentation for this project:

```
$ make doc
(cat Doxyfile; echo "PROJECT_NAME = rectangle_area") | doxygen -
Notice: Output directory 'doc' does not exist. I have created it for you.
Searching for include files...
Searching for example files...
  # Many lines out output removed
Patching output file 1/2
Patching output file 2/2
lookup cache used 2/65536 hits=2 misses=2
finished...
$ gio open doc/html/index.html 
```

The last command `gio open doc/html/index.html` will open the main HTML file in your web browser.

Another benefit of documenting your code is that when you use an editor like Visual Studio Code, it can show you the documentation when you point your mouse's cursor at a function name.

## Requirements

Using the inline documentation and any `TODO` comments, implement the functions in `mind_reader_functions.cc`.

Ensure that your code passes all unit tests. You can run the unit tests using the commadn `make unittest`.

Ensure that your code passes all system tests. You can run the system tests using the commadn `make test`.

Use the [`at()` method](https://en.cppreference.com/w/cpp/string/basic_string/at) of the [`std::string` class](https://en.cppreference.com/w/cpp/string/basic_string) to access the value and suit of the inputted card. (Do not use the `[]` operators!)

When using the `at()` method it will return a `char` type. Convert the `char` type to a `string` type. For example:

```
string hello = "Hello World";
// The first letter is at position 0
string letter_H = string(1, hello.at(0));
// The second letter is at position 1
string letter_e = string(1, hello.at(1));
// The letter d
// Get the size of the string, subtract 1 which will give the location of the last letter
string last_letter = string(1, hello.at(hello.size() - 1));
```

When using `at()` you should wrap each usage with a try/catch just like the try/catch pattern learned from the previous lab to catch errors.

```c++
string hello = "Hello World";
string letter_e;

try {
  letter_e = string(1, hello.at(1));
}catch (const exception& problem) {
  // Print a descriptive message about what went wrong or what you think went
  // wrong.
  cout << "Explain what happened.\n";
  // Use the exception to print addtional diagnostic messages.
  cout << problem.what() << "\n";
  // exit will end the program abruptly and return 1 to the operating system.
  exit(1);
}
```

Use the [`exit()`](https://en.cppreference.com/w/cpp/utility/program/exit) function to exit from your program if an error occurs in a function. Remember to `#include <cstdlib>` to take advantage of the `exit()` function.

If you need to, use  [`std::stoi()`](https://en.cppreference.com/w/cpp/string/basic_string/stol) to convert a string to an integer. Use the try/catch pattern learned from the previous lab to catch errors.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section Example Output below.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.
* unittest: run unit tests to verify parts of your program performs according to the instructor supplied unit tests.
* doc: generate the project's documentation from the source files and store it in the directory named `doc`.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make unittest
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 mind_reader_functions.cc \
| sed 's/\(mind_reader_functions\)\.o[ :]*/\1.o mind_reader_functions.d : /g' > mind_reader_functions.d; \
[ -s mind_reader_functions.d ] || rm -f mind_reader_functions.d
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 mind_reader.cc \
| sed 's/\(mind_reader\)\.o[ :]*/\1.o mind_reader.d : /g' > mind_reader.d; \
[ -s mind_reader.d ] || rm -f mind_reader.d
rm: cannot remove 'unittest': No such file or directory
make: [Makefile:133: cleanunittest] Error 1 (ignored)
clang++ -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 -c mind_reader_functions.cc
Running main() from /build/googletest-j5yxiC/googletest-1.10.0/googletest/src/gtest_main.cc
[==========] Running 19 tests from 8 test suites.
[----------] Global test environment set-up.
[----------] 4 tests from SuitTest
[ RUN      ] SuitTest.Clubs
[       OK ] SuitTest.Clubs (0 ms)
[ RUN      ] SuitTest.Diamonds
[       OK ] SuitTest.Diamonds (0 ms)
[ RUN      ] SuitTest.Hearts
[       OK ] SuitTest.Hearts (0 ms)
[ RUN      ] SuitTest.Spades
[       OK ] SuitTest.Spades (0 ms)
[----------] 4 tests from SuitTest (0 ms total)

[----------] 4 tests from FaceValueTest
[ RUN      ] FaceValueTest.Clubs
[       OK ] FaceValueTest.Clubs (0 ms)
[ RUN      ] FaceValueTest.Diamonds
[       OK ] FaceValueTest.Diamonds (0 ms)
[ RUN      ] FaceValueTest.Hearts
[       OK ] FaceValueTest.Hearts (0 ms)
[ RUN      ] FaceValueTest.Spades
[       OK ] FaceValueTest.Spades (0 ms)
[----------] 4 tests from FaceValueTest (0 ms total)

[----------] 1 test from NumericValueToFaceValue
[ RUN      ] NumericValueToFaceValue.Trivial
[       OK ] NumericValueToFaceValue.Trivial (0 ms)
[----------] 1 test from NumericValueToFaceValue (0 ms total)

[----------] 4 tests from DeckOrderValueTest
[ RUN      ] DeckOrderValueTest.Clubs
[       OK ] DeckOrderValueTest.Clubs (0 ms)
[ RUN      ] DeckOrderValueTest.Diamonds
[       OK ] DeckOrderValueTest.Diamonds (0 ms)
[ RUN      ] DeckOrderValueTest.Hearts
[       OK ] DeckOrderValueTest.Hearts (0 ms)
[ RUN      ] DeckOrderValueTest.Spades
[       OK ] DeckOrderValueTest.Spades (0 ms)
[----------] 4 tests from DeckOrderValueTest (1 ms total)

[----------] 1 test from SuitOffsetTest
[ RUN      ] SuitOffsetTest.Trivial
[       OK ] SuitOffsetTest.Trivial (0 ms)
[----------] 1 test from SuitOffsetTest (0 ms total)

[----------] 1 test from NumericValueTest
[ RUN      ] NumericValueTest.Trivial
[       OK ] NumericValueTest.Trivial (0 ms)
[----------] 1 test from NumericValueTest (0 ms total)

[----------] 1 test from FitchCheneySecretCardValueTest
[ RUN      ] FitchCheneySecretCardValueTest.Trivial
[       OK ] FitchCheneySecretCardValueTest.Trivial (0 ms)
[----------] 1 test from FitchCheneySecretCardValueTest (0 ms total)

[----------] 3 tests from FitchCheneySecretStepsTest
[ RUN      ] FitchCheneySecretStepsTest.Trivial
[       OK ] FitchCheneySecretStepsTest.Trivial (0 ms)
[ RUN      ] FitchCheneySecretStepsTest.FaceCards
[       OK ] FitchCheneySecretStepsTest.FaceCards (0 ms)
[ RUN      ] FitchCheneySecretStepsTest.SameFaceValue
[       OK ] FitchCheneySecretStepsTest.SameFaceValue (0 ms)
[----------] 3 tests from FitchCheneySecretStepsTest (0 ms total)

[----------] Global test environment tear-down
[==========] 19 tests from 8 test suites ran. (1 ms total)
[  PASSED  ] 19 tests.
$ make test
2021-10-18 17:41:54,781 - INFO - Start Grading Tuffy Titan tuffy.titan@csu.fullerton.edu tuffytitan
2021-10-18 17:41:54,781 - INFO - All files: ./mind_reader.cc ./mind_reader_unittest.cc ./mind_reader_functions.cc ./mind_reader_functions.h
2021-10-18 17:41:54,782 - DEBUG - Skipping base file comparison.
2021-10-18 17:41:54,831 - INFO - Formatting passed on ./mind_reader.cc
2021-10-18 17:41:54,865 - INFO - Formatting passed on ./mind_reader_unittest.cc
2021-10-18 17:41:54,889 - INFO - Formatting passed on ./mind_reader_functions.cc
2021-10-18 17:41:54,904 - INFO - Formatting passed on ./mind_reader_functions.h
2021-10-18 17:41:54,912 - INFO - Using compile command clang++ -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64
2021-10-18 17:41:54,915 - DEBUG - Writing compile_commands.json
2021-10-18 17:41:56,048 - INFO - Linting passed in ./mind_reader.cc
2021-10-18 17:41:56,056 - INFO - Using compile command clang++ -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64
2021-10-18 17:41:56,056 - DEBUG - Removing compile_commands.json
2021-10-18 17:41:56,056 - DEBUG - Writing compile_commands.json
2021-10-18 17:41:59,107 - WARNING - Linter found improvements in ./mind_reader_unittest.cc.
2021-10-18 17:41:59,115 - INFO - Using compile command clang++ -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64
2021-10-18 17:41:59,116 - DEBUG - Removing compile_commands.json
2021-10-18 17:41:59,116 - DEBUG - Writing compile_commands.json
2021-10-18 17:42:00,839 - INFO - Linting passed in ./mind_reader_functions.cc
2021-10-18 17:42:00,847 - INFO - Using compile command clang++ -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64
2021-10-18 17:42:00,847 - DEBUG - Removing compile_commands.json
2021-10-18 17:42:00,847 - DEBUG - Writing compile_commands.json
2021-10-18 17:42:01,480 - INFO - Linting passed in ./mind_reader_functions.h
2021-10-18 17:42:01,480 - DEBUG - make -C . spotless
2021-10-18 17:42:01,492 - DEBUG - make -C . all
2021-10-18 17:42:02,727 - INFO - Build passed
2021-10-18 17:42:02,727 - INFO - Test 1 - ('3C', '4D', '5D', '6H', '4C')
2021-10-18 17:42:02,732 - INFO - ++++ Pass ++++
2021-10-18 17:42:02,732 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 4C.
2021-10-18 17:42:02,833 - INFO - Test 2 - ('3C', '4D', '6H', '5D', '5C')
2021-10-18 17:42:02,838 - INFO - ++++ Pass ++++
2021-10-18 17:42:02,838 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 5C.
2021-10-18 17:42:02,939 - INFO - Test 3 - ('3C', '5D', '4D', '6H', '6C')
2021-10-18 17:42:02,944 - INFO - ++++ Pass ++++
2021-10-18 17:42:02,944 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 6C.
2021-10-18 17:42:03,045 - INFO - Test 4 - ('3C', '5D', '6H', '4D', '7C')
2021-10-18 17:42:03,050 - INFO - ++++ Pass ++++
2021-10-18 17:42:03,050 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 7C.
2021-10-18 17:42:03,151 - INFO - Test 5 - ('3C', '6H', '4D', '5D', '8C')
2021-10-18 17:42:03,156 - INFO - ++++ Pass ++++
2021-10-18 17:42:03,156 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 8C.
2021-10-18 17:42:03,257 - INFO - Test 6 - ('3C', '6H', '5D', '4D', '9C')
2021-10-18 17:42:03,262 - INFO - ++++ Pass ++++
2021-10-18 17:42:03,262 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 9C.
2021-10-18 17:42:03,363 - INFO - Test 7 - ('KS', '4D', '5D', '6H', 'AS')
2021-10-18 17:42:03,368 - INFO - ++++ Pass ++++
2021-10-18 17:42:03,368 - INFO - Your card is a black card.
I can see a face or is that an ace?
The card is AS.
2021-10-18 17:42:03,469 - INFO - Test 8 - ('KS', '4D', '6H', '5D', '2S')
2021-10-18 17:42:03,474 - INFO - ++++ Pass ++++
2021-10-18 17:42:03,474 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 2S.
2021-10-18 17:42:03,575 - INFO - Test 9 - ('KS', '5D', '4D', '6H', '3S')
2021-10-18 17:42:03,580 - INFO - ++++ Pass ++++
2021-10-18 17:42:03,580 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 3S.
2021-10-18 17:42:03,681 - INFO - Test 10 - ('KS', '5D', '6H', '4D', '4S')
2021-10-18 17:42:03,686 - INFO - ++++ Pass ++++
2021-10-18 17:42:03,686 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 4S.
2021-10-18 17:42:03,787 - INFO - Test 11 - ('KS', '6H', '4D', '5D', '5S')
2021-10-18 17:42:03,792 - INFO - ++++ Pass ++++
2021-10-18 17:42:03,792 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 5S.
2021-10-18 17:42:03,893 - INFO - Test 12 - ('KS', '6H', '5D', '4D', '6S')
2021-10-18 17:42:03,898 - INFO - ++++ Pass ++++
2021-10-18 17:42:03,898 - INFO - Your card is a black card.
It's a number card, isn't it?
The card is 6S.
2021-10-18 17:42:03,999 - INFO - Test 13 - ('QH', '4D', '5D', '6H', 'KH')
2021-10-18 17:42:04,004 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,004 - INFO - Your card is a red card.
I can see a face or is that an ace?
The card is KH.
2021-10-18 17:42:04,104 - INFO - Test 14 - ('QH', '4D', '6H', '5D', 'AH')
2021-10-18 17:42:04,110 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,110 - INFO - Your card is a red card.
I can see a face or is that an ace?
The card is AH.
2021-10-18 17:42:04,210 - INFO - Test 15 - ('QH', '5D', '4D', '6H', '2H')
2021-10-18 17:42:04,216 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,216 - INFO - Your card is a red card.
It's a number card, isn't it?
The card is 2H.
2021-10-18 17:42:04,316 - INFO - Test 16 - ('QH', '5D', '6H', '4D', '3H')
2021-10-18 17:42:04,322 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,322 - INFO - Your card is a red card.
It's a number card, isn't it?
The card is 3H.
2021-10-18 17:42:04,422 - INFO - Test 17 - ('QH', '6H', '4D', '5D', '4H')
2021-10-18 17:42:04,428 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,428 - INFO - Your card is a red card.
It's a number card, isn't it?
The card is 4H.
2021-10-18 17:42:04,528 - INFO - Test 18 - ('QH', '6H', '5D', '4D', '5H')
2021-10-18 17:42:04,533 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,534 - INFO - Your card is a red card.
It's a number card, isn't it?
The card is 5H.
2021-10-18 17:42:04,634 - INFO - Test 19 - ('JD', '4C', '4D', '4H', 'QD')
2021-10-18 17:42:04,639 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,640 - INFO - Your card is a red card.
I can see a face or is that an ace?
The card is QD.
2021-10-18 17:42:04,740 - INFO - Test 20 - ('JD', '4C', '4H', '4D', 'KD')
2021-10-18 17:42:04,745 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,746 - INFO - Your card is a red card.
I can see a face or is that an ace?
The card is KD.
2021-10-18 17:42:04,846 - INFO - Test 21 - ('JD', '4D', '4C', '4H', 'AD')
2021-10-18 17:42:04,851 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,851 - INFO - Your card is a red card.
I can see a face or is that an ace?
The card is AD.
2021-10-18 17:42:04,952 - INFO - Test 22 - ('JD', '4D', '4H', '4C', '2D')
2021-10-18 17:42:04,957 - INFO - ++++ Pass ++++
2021-10-18 17:42:04,957 - INFO - Your card is a red card.
It's a number card, isn't it?
The card is 2D.
2021-10-18 17:42:05,058 - INFO - Test 23 - ('JD', '4H', '4C', '4D', '3D')
2021-10-18 17:42:05,063 - INFO - ++++ Pass ++++
2021-10-18 17:42:05,063 - INFO - Your card is a red card.
It's a number card, isn't it?
The card is 3D.
2021-10-18 17:42:05,164 - INFO - Test 24 - ('JD', '4H', '4D', '4C', '4D')
2021-10-18 17:42:05,169 - INFO - ++++ Pass ++++
2021-10-18 17:42:05,169 - INFO - Your card is a red card.
It's a number card, isn't it?
The card is 4D.
2021-10-18 17:42:05,270 - INFO - Run passed
2021-10-18 17:42:05,270 - INFO - End Grading Tuffy Titan tuffy.titan@csu.fullerton.edu tuffytitan
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 mind_reader_functions.cc \
| sed 's/\(mind_reader_functions\)\.o[ :]*/\1.o mind_reader_functions.d : /g' > mind_reader_functions.d; \
[ -s mind_reader_functions.d ] || rm -f mind_reader_functions.d
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 mind_reader.cc \
| sed 's/\(mind_reader\)\.o[ :]*/\1.o mind_reader.d : /g' > mind_reader.d; \
[ -s mind_reader.d ] || rm -f mind_reader.d
clang++ -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 -c mind_reader.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 -c mind_reader_functions.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o mind_reader mind_reader.o mind_reader_functions.o
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 mind_reader_functions.cc \
| sed 's/\(mind_reader_functions\)\.o[ :]*/\1.o mind_reader_functions.d : /g' > mind_reader_functions.d; \
[ -s mind_reader_functions.d ] || rm -f mind_reader_functions.d
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 mind_reader.cc \
| sed 's/\(mind_reader\)\.o[ :]*/\1.o mind_reader.d : /g' > mind_reader.d; \
[ -s mind_reader.d ] || rm -f mind_reader.d
clang++ -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 -c mind_reader.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -DNOSLEEP -D LINUX -D AMD64 -c mind_reader_functions.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o mind_reader mind_reader.o mind_reader_functions.o 
$ ./mind_reader 
Tell me four of the five cards you have drawn, and I'll predict the last card.
$ ./mind_reader 3C
Tell me four of the five cards you have drawn, and I'll predict the last card.
$ ./mind_reader 3C 6H 4S 5D
Your card is a black card.
It's a number card, isn't it?
The card is 8C.
$
```
