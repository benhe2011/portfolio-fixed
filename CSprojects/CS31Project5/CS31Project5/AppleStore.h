#ifndef APPLESTORE_H
#define APPLESTORE_H
#include "AppleProduct.h"

namespace cs31 {
	class AppleStore {
	
	public:
		AppleStore();
		AppleProduct buyWatch1(string color);
		AppleProduct buyWatch3(string color);

		AppleProduct buyiPad(string color, int gigabytes);
		AppleProduct buyiPadPro(string color, int gigabytes);

		AppleProduct buyiPhoneX(string color, int gigabytes);
		AppleProduct buyiPhone8(string color, int gigabytes);
		AppleProduct buyiPhone8Plus(string color, int gigabytes);
	};
































};


#endif