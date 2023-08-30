# simple_fare_dhaka

Simploe fare calcualtor for dhaka is made complex with all OOP concept using c++.

Abstraction and Encapsulation: The FareCalculator class defines an abstract base class. It declares a pure virtual function calculateFare which is used to calculate the fare based on the distance traveled. This enforces a common interface for different types of fare calculators while keeping the implementation details hidden.




Polymorphism and Inheritance: The RegularBusFareCalculator class is derived from FareCalculator. It provides a concrete implementation of the calculateFare function, using a fixed fare rate (2.45 times the distance traveled official price for fare/km in Dhaka metro as of Sept 2023) for regular buses.

Polymorphism and Inheritance: The LuxuryBusFareCalculator class is also derived from FareCalculator. It provides a different implementation of the calculateFare function, using a higher fare rate (3.55 times the distance traveled which is self made) for luxury buses.




Class Definition and Inheritance: The Bus class encapsulates a FareCalculator instance, allowing it to use different fare calculation strategies. The constructor accepts a FareCalculator object through dependency injection, making it possible to switch fare calculation strategies at runtime.




In the main function, two instances of the derived fare calculators (RegularBusFareCalculator and LuxuryBusFareCalculator) are created using dynamic memory allocation (using the new keyword). These objects represent different fare calculation strategies.

Two instances of the Bus class are created, each initialized with a different fare calculator object.

User input is obtained for the distance traveled.

The calculateFare method of both the regular and luxury buses is called. Polymorphism allows the appropriate calculateFare implementation to be invoked based on the type of bus.

The calculated fares are displayed, and memory for the dynamically allocated objects is released using delete.




This code illustrates the five OOP concepts (Encapsulation, Inheritance, Polymorphism, Abstraction, and Class Definition) in the context of a bus fare calculator application.
