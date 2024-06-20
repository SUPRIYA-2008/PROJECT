//#include <iostream>
//#include <cstdlib> // Include this for rand() and RAND_MAX
//
//int main() {
//    // Seed the random number generator with the current time
//    srand(static_cast<unsigned int>(time(0)));
//
//    // Generate and print 5 random numbers
//    for (int i = 0; i < 5; ++i) {
//        int randomNumber = rand() % (RAND_MAX + 1);
//        std::cout << "Random number " << i + 1 << ": " << randomNumber << std::endl;
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <cstdlib> // Include this for rand() and RAND_MAX
//#include <ctime>   // Include this for time()
//
//int main() {
//    // Seed the random number generator with the current time
//    srand(static_cast<unsigned int>(time(0)));
//
//    // Generate and print 5 random numbers between 0 and 1
//    for (int i = 0; i < 5; ++i) {
//        // Generate a random integer between 0 and RAND_MAX
//        int randomInt = rand();
//
//        // Normalize the random integer to a floating-point number between 0 and 1
//        double randomNumber = static_cast<double>(randomInt) / RAND_MAX;
//
//        std::cout << "Random number " << i + 1 << ": " << randomNumber << std::endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <iomanip> // Include this for stream manipulators
//#include <cstdlib> // Include this for rand() and RAND_MAX
//#include <ctime>   // Include this for time()
//
//int main() {
//    // Seed the random number generator with the current time
//    srand(static_cast<unsigned int>(time(0)));
//
//    // Define the threshold value
//    const double threshold = 0.5;
//
//    // Generate and print 5 random numbers between 0 and 1, with exactly 3 decimal digits
//    for (int i = 0; i < 5; ++i) {
//        double randomNumber;
//        do {
//            // Generate a random integer between 0 and RAND_MAX
//            int randomInt = rand();
//
//            // Normalize the random integer to a floating-point number between 0 and 1
//            randomNumber = static_cast<double>(randomInt) / RAND_MAX;
//        } while (randomNumber < threshold);
//
//        // Set the precision to 3 decimal digits
//        std::cout << "Random number " << i + 1 << ": " << std::fixed << std::setprecision(3) << randomNumber << std::endl;
//    }
//
//    return 0;
//}

