#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

class Customer{
	public:
		void operator=(Customer&);
		
		bool operator==(Customer&);
		bool operator>=(Customer&);
		bool operator<=(Customer&);
		bool operator>(Customer&);
		bool operator<(Customer&);
		
		~Customer();
		Customer(char*,int);
		Customer(const Customer&);
	private:
		char* address;
		int phone;
		
		friend std::ostream& operator<<(std::ostream& os, Customer& r);
		friend std::istream& operator>>(std::istream& os, Customer& r);
};

std::ostream& operator<<(std::ostream& os, Customer& r);
std::istream& operator>>(std::istream& os, Customer& r);

#endif
