#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <string>
#include <chrono>
#include <thread>

bool running = true;

void invalid_input() {
	std::cerr << "Invalid input. Please enter numeric values." << std::endl;
}

void compound_interest() {
	double principal;
	double rate;
	double time;

	try {
		std::cout << "Enter the principal amount: ";
		std::cin >> principal;
		std::cout << "Enter the annual interest rate (in percentage): ";
		std::cin >> rate;
		std::cout << "Enter the time the money is invested for (in years): ";
		std::cin >> time;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	double r = rate / 100;
	int n = 1; // Compounded once per year
	double A = principal * pow(1 + r / n, n * time) - principal;
	std::cout << "The amount accumulated after " << time << " (time) is: $" << A << std::endl;
	std::cout << "The total amount accumulated after " << time << " (time) is: $" << A + principal << std::endl;
}

void simple_interest() {
	double principal;
	double rate;
	double time;

	try {
		std::cout << "Enter the principal amount: ";
		std::cin >> principal;
		std::cout << "Enter the annual interest rate (in percentage): ";
		std::cin >> rate;
		std::cout << "Enter the time the money is invested for (in years): ";
		std::cin >> time;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	double r = rate / 100;
	double A = principal * r * time;
	std::cout << "The simple interest accumulated after " << time << " (time) is: $" << A << std::endl;
	std::cout << "The total amount accumulated after " << time << " (time) is: $" << A + principal << std::endl;
}

void add_gst() {
	double price;
	double gst_rate = 15.0;

	try {
		std::cout << "Enter the price of the item: ";
		std::cin >> price;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	double gst_amount = price * (gst_rate / 100);
	double total_price = price + gst_amount;
	std::cout << "The GST amount is: $" << gst_amount << std::endl;
	std::cout << "The total price after adding GST is: $" << total_price << std::endl;
}

void remove_gst() {
	double price_with_gst;
	double gst_rate = 15.0;

	try {
		std::cout << "Enter the price of the item including GST: ";
		std::cin >> price_with_gst;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	double original_price = price_with_gst / (1 + gst_rate / 100);
	std::cout << "The original price before adding GST is: $" << original_price << std::endl;
}

void simple_interest_rate() {
	double interest;
	double principal;
	double time;

	try {
		std::cout << "Enter the simple interest amount: ";
		std::cin >> interest;
		std::cout << "Enter the principal amount: ";
		std::cin >> principal;
		std::cout << "Enter the time the money is invested for (in years): ";
		std::cin >> time;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	double rate = (interest / (principal * time)) * 100;
	std::cout << "The annual interest rate is: " << rate << "%" << std::endl;
}

void percentage_decrease() {
	double original_price;
	double new_price;

	try {
		std::cout << "Enter the original price: ";
		std::cin >> original_price;
		std::cout << "Enter the new price: ";
		std::cin >> new_price;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	double decrease = original_price - new_price;
	double percentage_decrease = (decrease / original_price) * 100;
	std::cout << "The percentage decrease is: " << percentage_decrease << "%" << std::endl;
}

void percentage_increase() {
	double original_price;
	double new_price;

	try {
		std::cout << "Enter the original price: ";
		std::cin >> original_price;
		std::cout << "Enter the new price: ";
		std::cin >> new_price;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	double increase = new_price - original_price;
	double percentage_increase = (increase / original_price) * 100;
	std::cout << "The percentage increase is: " << percentage_increase << "%" << std::endl;
}

void currency_conversion() {
    double nzd_amount;
    double aud_rate;

    try {
        std::cout << "Enter the amount in NZD: ";
        std::cin >> nzd_amount;
        std::cout << "Enter the exchange rate (NZD to AUD): ";
        std::cin >> aud_rate;
    } catch (const std::invalid_argument& e) {
        invalid_input();
        return;
    }
    double aud_amount = nzd_amount * aud_rate;
    std::cout << "The amount in AUD is: $" << aud_amount << std::endl;
}

void reverse_currency_conversion() {
		double aud_amount;
		double aud_rate;

		try {
				std::cout << "Enter the amount in AUD: ";
				std::cin >> aud_amount;
				std::cout << "Enter the exchange rate (NZD to AUD): ";
				std::cin >> aud_rate;
		} catch (const std::invalid_argument& e) {
				invalid_input();
				return;
		}
		double nzd_amount = aud_amount / aud_rate;
		std::cout << "The amount in NZD is: $" << nzd_amount << std::endl;
}

void power() {
	double base;
	double exponent;

	try {
		std::cout << "Enter the base: ";
		std::cin >> base;
		std::cout << "Enter the exponent: ";
		std::cin >> exponent;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	double result = pow(base, exponent);
	std::cout << base << " raised to the power of " << exponent << " is: " << result << std::endl;
}

void speed_calc_with_time() {
	double old_speed;
	double original_time;
	double new_speed;
	std::cout << "Enter the old speed: ";
	std::cin >> old_speed;
	std::cout << "Enter the original time: ";
	std::cin >> original_time;
	std::cout << "Enter the new speed: ";
	std::cin >> new_speed;
	double new_time = (old_speed * original_time) / new_speed;
	std::cout << "The new time is: " << new_time << std::endl;
}

void loan_payment_calculator() {
	double principal;
	double annual_rate;
	int years;
	int compounding_frequency = 12; // Monthly

	try {
		std::cout << "Enter the loan amount (principal): ";
		std::cin >> principal;
		std::cout << "Enter the annual interest rate (in percentage): ";
		std::cin >> annual_rate;
		std::cout << "Enter the loan term in years: ";
		std::cin >> years;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	double r = annual_rate / 100 / compounding_frequency;
	int n = years * compounding_frequency;
	double payment = principal * (r * pow(1 + r, n)) / (pow(1 + r, n) - 1);
	std::cout << "The monthly payment is: $" << payment << std::endl;
}

void quadratic_equation_solver() {
	double a, b, c;
	try {
		std::cout << "Enter coefficient a: ";
		std::cin >> a;
		std::cout << "Enter coefficient b: ";
		std::cin >> b;
		std::cout << "Enter coefficient c: ";
		std::cin >> c;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	if (a == 0) {
		std::cout << "Not a quadratic equation." << std::endl;
		return;
	}
	double discriminant = b * b - 4 * a * c;
	if (discriminant > 0) {
		double root1 = (-b + sqrt(discriminant)) / (2 * a);
		double root2 = (-b - sqrt(discriminant)) / (2 * a);
		std::cout << "Roots are real and different: " << root1 << " and " << root2 << std::endl;
	} else if (discriminant == 0) {
		double root = -b / (2 * a);
		std::cout << "Roots are real and same: " << root << std::endl;
	} else {
		std::cout << "Roots are complex." << std::endl;
	}
}

void area_calculator() {
	int choice;
	std::cout << "Choose a shape:" << std::endl;
	std::cout << "1. Circle" << std::endl;
	std::cout << "2. Rectangle" << std::endl;
	std::cout << "3. Triangle" << std::endl;
	std::cin >> choice;
	switch (choice) {
		case 1: {
			double radius;
			try {
				std::cout << "Enter radius: ";
				std::cin >> radius;
			} catch (const std::invalid_argument& e) {
				invalid_input();
				return;
			}
			double area = M_PI * radius * radius;
			std::cout << "Area of circle: " << area << std::endl;
			break;
		}
		case 2: {
			double length, width;
			try {
				std::cout << "Enter length: ";
				std::cin >> length;
				std::cout << "Enter width: ";
				std::cin >> width;
			} catch (const std::invalid_argument& e) {
				invalid_input();
				return;
			}
			double area = length * width;
			std::cout << "Area of rectangle: " << area << std::endl;
			break;
		}
		case 3: {
			double base, height;
			try {
				std::cout << "Enter base: ";
				std::cin >> base;
				std::cout << "Enter height: ";
				std::cin >> height;
			} catch (const std::invalid_argument& e) {
				invalid_input();
				return;
			}
			double area = 0.5 * base * height;
			std::cout << "Area of triangle: " << area << std::endl;
			break;
		}
		default:
			std::cout << "Invalid choice." << std::endl;
	}
}

void unit_converter() {
	int choice;
	std::cout << "Choose conversion:" << std::endl;
	std::cout << "1. Meters to Feet" << std::endl;
	std::cout << "2. Kilograms to Pounds" << std::endl;
	std::cout << "3. Celsius to Fahrenheit" << std::endl;
	std::cin >> choice;
	switch (choice) {
		case 1: {
			double meters;
			try {
				std::cout << "Enter meters: ";
				std::cin >> meters;
			} catch (const std::invalid_argument& e) {
				invalid_input();
				return;
			}
			double feet = meters * 3.28084;
			std::cout << meters << " meters = " << feet << " feet" << std::endl;
			break;
		}
		case 2: {
			double kg;
			try {
				std::cout << "Enter kilograms: ";
				std::cin >> kg;
			} catch (const std::invalid_argument& e) {
				invalid_input();
				return;
			}
			double lbs = kg * 2.20462;
			std::cout << kg << " kg = " << lbs << " lbs" << std::endl;
			break;
		}
		case 3: {
			double celsius;
			try {
				std::cout << "Enter Celsius: ";
				std::cin >> celsius;
			} catch (const std::invalid_argument& e) {
				invalid_input();
				return;
			}
			double fahrenheit = (celsius * 9 / 5) + 32;
			std::cout << celsius << " C = " << fahrenheit << " F" << std::endl;
			break;
		}
		default:
			std::cout << "Invalid choice." << std::endl;
	}
}

void prime_checker() {
	int num;
	try {
		std::cout << "Enter a positive integer: ";
		std::cin >> num;
	} catch (const std::invalid_argument& e) {
		invalid_input();
		return;
	}
	if (num <= 1) {
		std::cout << num << " is not a prime number." << std::endl;
		return;
	}
	bool is_prime = true;
	for (int i = 2; i <= sqrt(num); ++i) {
		if (num % i == 0) {
			is_prime = false;
			break;
		}
	}
	if (is_prime) {
		std::cout << num << " is a prime number." << std::endl;
	} else {
		std::cout << num << " is not a prime number." << std::endl;
	}
}

void choose_operation() {
	int choice;
	std::cout << "Choose an operation:" << std::endl;
	std::cout << "1. Simple Interest" << std::endl;
	std::cout << "2. Compound Interest" << std::endl;
	std::cout << "3. Add GST" << std::endl;
	std::cout << "4. Remove GST" << std::endl;
	std::cout << "5. Simple Interest Rate" << std::endl;
	std::cout << "6. Percentage Decrease" << std::endl;
	std::cout << "7. Percentage Increase" << std::endl;
	std::cout << "8. Currency Conversion" << std::endl;
	std::cout << "9. Reverse Currency Conversion" << std::endl;
	std::cout << "10. Power" << std::endl;
	std::cout << "11. Speed Calculation with Time" << std::endl;
	std::cout << "12. Loan Payment Calculator" << std::endl;
	std::cout << "13. Quadratic Equation Solver" << std::endl;
	std::cout << "14. Area Calculator" << std::endl;
	std::cout << "15. Unit Converter" << std::endl;
	std::cout << "16. Prime Number Checker" << std::endl;
	std::cout << "17. Exit" << std::endl;
	std::cin >> choice;

	switch (choice) {
		case 1:
			simple_interest();
			break;
		case 2:
			compound_interest();
			break;
		case 3:
			add_gst();
			break;
		case 4:
			remove_gst();
			break;
		case 5:
			simple_interest_rate();
			break;
		case 6:
			percentage_decrease();
			break;
		case 7:
			percentage_increase();
			break;
		case 8:
			currency_conversion();
			break;
		case 9:
			reverse_currency_conversion();
			break;
		case 10:
			power();
			break;
		case 11:
			speed_calc_with_time();
			break;
		case 12:
			loan_payment_calculator();
			break;
		case 13:
			quadratic_equation_solver();
			break;
		case 14:
			area_calculator();
			break;
		case 15:
			unit_converter();
			break;
		case 16:
			prime_checker();
			break;
		case 17:
			std::cout << "Exiting the program." << std::endl;
			running = false;
			break;
		default:
			std::cout << "Invalid choice. Please select a valid option." << std::endl << std::endl;
			choose_operation();
			break;
	}
}

int main() {
	while(running) {
		choose_operation();
		if(running==false) {
			std::cout << "Thank you for using the math calculator!" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1500));
		}
	}
	return 0;
}