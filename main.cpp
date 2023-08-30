#include <iostream>
using namespace std;

// Abstraction and Encapsulation: Abstract base class for FareCalculator
class FareCalculator {
public:
    virtual double calculateFare(double distance) = 0; // Pure virtual function for calculating fare
    virtual ~FareCalculator() {} // Virtual destructor
};

// Polymorphism and Inheritance: Derived class for RegularBusFareCalculator
class RegularBusFareCalculator : public FareCalculator {
public:
    double calculateFare(double distance) override {
        return 2.45 * distance; // Fixed fare rate
    }
};

// Polymorphism and Inheritance: Derived class for LuxuryBusFareCalculator
class LuxuryBusFareCalculator : public FareCalculator {
public:
    double calculateFare(double distance) override {
        return 3.55 * distance; // Higher fare rate for luxury buses
    }
};

// Class Definition and Inheritance: Bus class with FareCalculator as a member
class Bus {
private:
    FareCalculator* fareCalculator; // Encapsulated FareCalculator instance

public:
    Bus(FareCalculator* calculator) : fareCalculator(calculator) {} // Constructor with Dependency Injection

    double calculateFare(double distance) {
        return fareCalculator->calculateFare(distance); // Polymorphism: Call appropriate calculateFare method
    }

    ~Bus() {
        delete fareCalculator; // Clean up the FareCalculator instance
    }
};

int main() {
    // Create objects for fare calculators
    FareCalculator* regularFareCalculator = new RegularBusFareCalculator();
    FareCalculator* luxuryFareCalculator = new LuxuryBusFareCalculator();

    // Create bus objects with different fare calculators
    Bus regularBus(regularFareCalculator);
    Bus luxuryBus(luxuryFareCalculator);

    // User input for distance
    double distance;
    cout << "Enter the distance traveled in kilometers: ";
    cin >> distance;

    // Calculate and display fare for regular bus
    double regularFare = regularBus.calculateFare(distance);
    cout << "Regular Bus Fare: bdt " << regularFare << "/=" << endl;

    // Calculate and display fare for luxury bus
    double luxuryFare = luxuryBus.calculateFare(distance);
    cout << "Luxury Bus Fare: bdt " << luxuryFare <<"/=" << endl;

    // Clean up
    delete regularFareCalculator;
    delete luxuryFareCalculator;

    return 0;
}
