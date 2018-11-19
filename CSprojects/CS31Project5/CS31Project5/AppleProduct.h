#ifndef APPLEPRODUCT_H
#define APPLEPRODUCT_H

namespace cs31 {
	class AppleProduct {
	
	public:
		enum Kind {NOTSPECIFIED, IPHONE, IPAD, WATCH};
		AppleProduct();
		AppleProduct(Kind kind, string version, string color, double cost);
		string getVersion();
		string getColor();
		Kind getKind();
		double getCost();
	
	private:
		string mVersion;
		string mColor;
		Kind mKind;
		double mCost;

	};























};


















#endif

