#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generateRandomParagraph(int length) {
    std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ;:'\",.? ";
    std::string randomParagraph;

    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < length; ++i) {
        char randomChar = characters[std::rand() % characters.length()];
        randomParagraph.push_back(randomChar);
        if (i > 0 && i % 10 == 0 || i % 7 == 0) {
            randomParagraph.push_back(' ');
        }

        // Add a newline character after every 80 characters
        if (i > 0 && i % 90 == 0 || i % 80 == 0 ) {
            randomParagraph.push_back('\n');
        }
    }

    return randomParagraph;
}

int main() {
    int paragraphLength = 1500;

    std::string randomParagraph = generateRandomParagraph(paragraphLength);

    std::cout << randomParagraph << std::endl;

    return 0;
}
