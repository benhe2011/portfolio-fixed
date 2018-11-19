#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;
#include "AppleStore.h"
using namespace cs31;

int main() {
	// test code 
	//testing the different class constructors and the class functions to make sure all the values are correct and that the functions perform correctly
	cs31::AppleProduct p;
	assert(p.getCost() == 0.0);
	assert(p.getKind() == cs31::AppleProduct::Kind::NOTSPECIFIED);
	assert(p.getColor() == "");
	assert(p.getVersion() == "");

	cs31::AppleProduct p1(cs31::AppleProduct::Kind::IPHONE, "8", "Space Grey", 699.00);
	assert(std::to_string(p1.getCost()) == "699.000000");
	assert(p1.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(p1.getColor() == "Space Grey");
	assert(p1.getVersion() == "8");

	cs31::AppleProduct p2(cs31::AppleProduct::Kind::IPAD, "8", "Space Grey", 429.00);
	assert(std::to_string(p2.getCost()) == "429.000000");
	assert(p2.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(p2.getColor() == "Space Grey");
	assert(p2.getVersion() == "8");

	cs31::AppleStore store;
	cs31::AppleProduct iphone8_64 = store.buyiPhone8("Space Grey", 64);
	assert(std::to_string(iphone8_64.getCost()) == "699.000000");
	assert(iphone8_64.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8_64.getColor() == "Space Grey");
	assert(iphone8_64.getVersion() == "8");

	cs31::AppleProduct iphone8_256 = store.buyiPhone8("Pink", 256);
	assert(std::to_string(iphone8_256.getCost()) == "849.000000");
	assert(iphone8_256.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8_256.getColor() == "Pink");
	assert(iphone8_256.getVersion() == "8");

	cs31::AppleProduct iphone8plus_64 = store.buyiPhone8Plus("Blue", 64);
	assert(std::to_string(iphone8plus_64.getCost()) == "799.000000");
	assert(iphone8plus_64.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8plus_64.getColor() == "Blue");
	assert(iphone8plus_64.getVersion() == "8Plus");

	cs31::AppleProduct iphone8plus_256 = store.buyiPhone8Plus("Red", 256);
	assert(std::to_string(iphone8plus_256.getCost()) == "949.000000");
	assert(iphone8plus_256.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8plus_256.getColor() == "Red");
	assert(iphone8plus_256.getVersion() == "8Plus");

	cs31::AppleProduct iphoneX_64 = store.buyiPhoneX("White", 64);
	assert(std::to_string(iphoneX_64.getCost()) == "999.000000");
	assert(iphoneX_64.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphoneX_64.getColor() == "White");
	assert(iphoneX_64.getVersion() == "X");

	cs31::AppleProduct iphoneX_256 = store.buyiPhoneX("Black", 256);
	assert(std::to_string(iphoneX_256.getCost()) == "1149.000000");
	assert(iphoneX_256.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphoneX_256.getColor() == "Black");
	assert(iphoneX_256.getVersion() == "X");
	
	cs31::AppleProduct ipad_32 = store.buyiPad("Turqoise", 32);
	assert(std::to_string(ipad_32.getCost()) == "329.000000");
	assert(ipad_32.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipad_32.getColor() == "Turqoise");
	assert(ipad_32.getVersion() == "");

	cs31::AppleProduct ipad_128 = store.buyiPad("Olive", 128);
	assert(std::to_string(ipad_128.getCost()) == "429.000000");
	assert(ipad_128.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipad_128.getColor() == "Olive");
	assert(ipad_128.getVersion() == "");

	cs31::AppleProduct ipadPro_64 = store.buyiPadPro("", 64);
	assert(std::to_string(ipadPro_64.getCost()) == "649.000000");
	assert(ipadPro_64.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipadPro_64.getColor() == "");
	assert(ipadPro_64.getVersion() == "Pro");

	cs31::AppleProduct ipadPro_256 = store.buyiPadPro("Emerald", 256);
	assert(std::to_string(ipadPro_256.getCost()) == "799.000000");
	assert(ipadPro_256.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipadPro_256.getColor() == "Emerald");
	assert(ipadPro_256.getVersion() == "Pro");

	cs31::AppleProduct ipadPro_512 = store.buyiPadPro("Maroon", 512);
	assert(std::to_string(ipadPro_512.getCost()) == "999.000000");
	assert(ipadPro_512.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipadPro_512.getColor() == "Maroon");
	assert(ipadPro_512.getVersion() == "Pro");

	cs31::AppleProduct watch1 = store.buyWatch1("Silver");
	assert(std::to_string(watch1.getCost()) == "249.000000");
	assert(watch1.getKind() == cs31::AppleProduct::Kind::WATCH);
	assert(watch1.getColor() == "Silver");
	assert(watch1.getVersion() == "1");

	cs31::AppleProduct watch3 = store.buyWatch3("Brown");
	assert(std::to_string(watch3.getCost()) == "329.000000");
	assert(watch3.getKind() == cs31::AppleProduct::Kind::WATCH);
	assert(watch3.getColor() == "Brown");
	assert(watch3.getVersion() == "3");

	//testing that the std::logic_error exceptions are thrown correctly
	cs31::AppleStore s;
	try
	{
		cs31::AppleProduct iphone8 = s.buyiPhone8("Space Grey", 9999);
		assert(false);

	}
	catch (std::logic_error) {
		assert(true);
	}

	try
	{
		cs31::AppleProduct iphone8plus = s.buyiPhone8Plus("Grey", 0);
		assert(false);

	}
	catch (std::logic_error) {
		assert(true);
	}

	try
	{
		cs31::AppleProduct iphoneX = s.buyiPhoneX("Purple", 32);
		assert(false);

	}
	catch (std::logic_error) {
		assert(true);
	}

	try
	{
		cs31::AppleProduct ipad = s.buyiPad("Orange", 64);
		assert(false);

	}
	catch (std::logic_error) {
		assert(true);
	}

	try
	{
		cs31::AppleProduct ipadPro = s.buyiPadPro("Yellow", 128);
		assert(false);

	}
	catch (std::logic_error) {
		assert(true);
	}

	cout << "all tests passed!" << endl;

	return 0;


}