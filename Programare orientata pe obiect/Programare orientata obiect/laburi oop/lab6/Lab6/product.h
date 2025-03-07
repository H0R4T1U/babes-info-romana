#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product{
	public:
		void operator=(Product&);
		
		bool operator==(Product&);
		bool operator>=(Product&);
		bool operator<=(Product&);
		bool operator>(Product&);
		bool operator<(Product&);
		
		~Product();
		Product();
		Product(char*,int);
		Product(const Product&);
		
		char* getName();
	private:
		char* name;
		int price;
		
		friend std::ostream& operator<<(std::ostream& os, Product& r);
		friend std::istream& operator>>(std::istream& os, Product& r);
};

std::ostream& operator<<(std::ostream& os, Product& r);
std::istream& operator>>(std::istream& os, Product& r);

#endif
