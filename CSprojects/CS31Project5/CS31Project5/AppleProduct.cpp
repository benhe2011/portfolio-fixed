#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
using namespace std;
#include "AppleProduct.h"

namespace cs31 {


	AppleProduct::AppleProduct() {
		mKind = NOTSPECIFIED;
		mVersion = "";
		mColor = "";
		mCost = 0.0;
	}

	AppleProduct::AppleProduct(Kind kind, string version, string color, double cost) {
		mVersion = version;
		mColor = color;
		mKind = kind;
		mCost = cost;
	}

	//these functions just return the values of the private member variables
	string AppleProduct::getVersion() {
		return mVersion;
	}

	string AppleProduct::getColor() {
		return mColor;
	}

	AppleProduct::Kind AppleProduct::getKind() {  //had to specify that the Kind enum is part of AppleProduct
		return mKind;
	}

	double AppleProduct::getCost() {
		return mCost;
	}







































}