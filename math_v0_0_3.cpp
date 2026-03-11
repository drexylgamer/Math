#include <iostream>
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
	std::cout << "11. Exit" << std::endl;
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
		std::cout << "Type \"q\" to Quit or press Enter to continue..." << std::endl;
		std::string op;
		std::cin.ignore(); // Ignore the newline character left in the buffer
		std::getline(std::cin, op);
		if (op == "q") {
			running = false;
			std::cout << "Thank you for using the math calculator!" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		}
	}
	return 0;
}