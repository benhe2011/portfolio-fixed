#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;
#include "AppleStore.h"

namespace cs31 {
	//should be empty as there's nothing really to initialize
	AppleStore::AppleStore() {

	}
	
	AppleProduct AppleStore::buyWatch1(string color) {
		//AppleProduct watch = AppleProduct(AppleProduct::WATCH, "1", color, 249.0);
		AppleProduct watch(AppleProduct::WATCH, "1", color, 249.0);
		return watch;
	}

	AppleProduct AppleStore::buyWatch3(string color) {
		AppleProduct watch(AppleProduct::WATCH, "3", color, 329.0);
		return watch;
	}
	//watches don't throw any exceptions

	AppleProduct AppleStore::buyiPad(string color, int gigabytes) {
		if (gigabytes == 32) {
			AppleProduct ipad(AppleProduct::IPAD, "", color, 329.0);
			return ipad;
		}
		else if (gigabytes == 128) {
			AppleProduct ipad(AppleProduct::IPAD, "", color, 429.0);
			return ipad;
		}
		else {
			throw logic_error ("gigabyte size not available for this ipad");
		}
		
	}

	AppleProduct AppleStore::buyiPadPro(string color, int gigabytes) {
		if (gigabytes == 64) {
			AppleProduct ipad(AppleProduct::IPAD, "Pro", color, 649.0);
			return ipad;
		}
		else if (gigabytes == 256) {
			AppleProduct ipad(AppleProduct::IPAD, "Pro", color, 799.0);
			return ipad;
		}
		else if (gigabytes == 512) {
			AppleProduct ipad(AppleProduct::IPAD, "Pro", color, 999.0);
			return ipad;
		}
		else {
			throw logic_error("gigabyte size not available for this ipad pro");
		}
	}


	AppleProduct AppleStore::buyiPhoneX(string color, int gigabytes) {
		if (gigabytes == 64) {
			AppleProduct iphone(AppleProduct::IPHONE, "X", color, 999.0);
			return iphone;
		}
		else if (gigabytes == 256) {
			AppleProduct iphone(AppleProduct::IPHONE, "X", color, 1149.0);
			return iphone;
		}
		else {
			throw logic_error("gigabyte size not available for this iphone x");
		}
	}

	AppleProduct AppleStore::buyiPhone8(string color, int gigabytes) {
		if (gigabytes == 64) {
			AppleProduct iphone(AppleProduct::IPHONE, "8", color, 699.0);
			return iphone;
		}
		else if (gigabytes == 256) {
			AppleProduct iphone(AppleProduct::IPHONE, "8", color, 849.0);
			return iphone;
		}
		else {
			throw logic_error("gigabyte size not available for this iphone 8");
		}
	}

	AppleProduct AppleStore::buyiPhone8Plus(string color, int gigabytes) {
		if (gigabytes == 64) {
			AppleProduct iphone(AppleProduct::IPHONE, "8Plus", color, 799.0);
			return iphone;
		}
		else if (gigabytes == 256) {
			AppleProduct iphone(AppleProduct::IPHONE, "8Plus", color, 949.0);
			return iphone;
		}
		else {
			throw logic_error("gigabyte size not available for this iphone 8 plus");
		}
	}























}