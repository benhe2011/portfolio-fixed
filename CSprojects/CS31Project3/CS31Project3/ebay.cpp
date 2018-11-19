#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
using namespace std;

bool isValidEbayListingString(string auctionstring);
bool listingSold(string auctionstring);
int howMuch(string auctionstring);
int watchers(string auctionstring);
int convertToNumber(string numstring, size_t& index);

int main()
{
	
	cerr << "1\n";
	assert(isValidEbayListingString("") == false);
	assert(isValidEbayListingString(" ") == false);
	assert(isValidEbayListingString("a") == false);
	assert(isValidEbayListingString("L") == false);
	assert(isValidEbayListingString("z") == false);
	assert(listingSold("0") == false);
	assert(isValidEbayListingString("l50") == true);
	assert(listingSold("l50") == false);
	assert(isValidEbayListingString("L50") == true);
	assert(listingSold("L50") == false);
	assert(isValidEbayListingString("L00050") == false);
	assert(isValidEbayListingString("L-1") == false);
	assert(isValidEbayListingString("Lambasdff ") == false);
	assert(isValidEbayListingString("L50L50L50l50") == false);
	assert(isValidEbayListingString("LLLL") == false);
	assert(isValidEbayListingString("L100 B50 W B+10 U W B+40 W") == false);
	assert(isValidEbayListingString("L100.50B50") == false);
	assert(isValidEbayListingString("L100B50UW") == false);
	assert(isValidEbayListingString("L100BW50") == false);
	assert(isValidEbayListingString("L100B50WBU+50") == false);
	assert(isValidEbayListingString("L100B50UUUUUUUUU") == false);
	assert(isValidEbayListingString("L100B50WWUUUUUUUUU") == false);
	assert(isValidEbayListingString("WUL100") == false);
	assert(isValidEbayListingString("L100L50") == false);
	assert(isValidEbayListingString("L100B+50") == false);
	assert(isValidEbayListingString("L100B50B+50B20") == false);
	assert(isValidEbayListingString("LBWuUWW+") == false);
	assert(isValidEbayListingString("L99B50WB+10UWB+40W") == true);
	assert(watchers("L99B50WB+10UWB+40W") == 2);
	assert(isValidEbayListingString("l99b50wb+10uwb+40w") == true);
	assert(watchers("l50b50wb+15uwb+40w") == 2);
	assert(isValidEbayListingString("L100B99") == true);
	assert(listingSold("L100B99") == false);
	assert(isValidEbayListingString("L100B50WWWWWWW") == true);
	assert(listingSold("L100B50WWWWWWW") == false);
	assert(isValidEbayListingString("L100B50WUWUWUWWWWW") == true);
	assert(listingSold("L100B50WUWUWUWWWWW") == false);
	assert(isValidEbayListingString("L100B50WWUUB+10WWUU") == true);
	assert(listingSold("L100B50WWUUB+10WWUU") == false);
	assert(isValidEbayListingString("L100W") == true);
	assert(listingSold("L100W") == false);
	assert(isValidEbayListingString("L100WU") == true);
	assert(listingSold("L100WU") == false);
	assert(isValidEbayListingString("L100WB50WU") == true);
	assert(watchers("L100WB50WUB+30WUWUB+70") == 1);
	assert(isValidEbayListingString("L") == false);

	cerr << "All tests passed :)\n";

}

bool isValidEbayListingString(string auctionstring)
{
	bool isValid = true;
	

	/*if (auctionstring.empty())                                                          //cannot have empty string
	{
		cerr << "invalid auctionstring--empty\n";
		isValid = false;
	}
	if (auctionstring[0] != 'L' && auctionstring[0] != 'l')                             //string has to start with L or l
	{
		cerr << "invalid auctionstring--first letter is not L.\n";
		isValid = false;
	}
	*/
	if (!auctionstring.empty())                                                       //string at least needs L and some number for the listing price
	{
		int watch = 0;                                                             //variables to track the indexes of the first watch and the first unwatch.
		int unwatch = 0;
		
		bool lExists = false;
		bool firstL = true;
		bool onL = false;
		
		bool firstB = true;
		bool onB = false;
		
		bool onPlus = false;
		
		bool numGo = false;
		
		for (size_t i = 0; i < auctionstring.size(); i++)
		{
			if (isValid == false)                                             //once isValid is false, there's no point in continuing the loop
			{
				break;
				cerr << "isValid became false within the for loop\n";
			}
			
			switch (auctionstring[i])
			{
				case 'L':
				case 'l':
				{
					if (!lExists)                                              //there can only be one L which is at the beginning of the string, otherwise invalid string
					{
						firstL = false;
						onL = true;
						lExists = true;
						break;
					}
					else
					{
						isValid = false;
						cerr << "multiple L's appeared in the string\n";
						break;
					}
				}
				case 'B':
				case 'b':
				{
					if (lExists)                                                     //if there isn't already an L, the string is invalid
					{
						if (onL || onB || onPlus)                                    //if the letter before is still waiting for a number, putting another letter is invalid
						{

							isValid = false;
							cerr << "L, B, or Plus must complete first\n";
							break;
						}
						onB = true;
						break;
					}
					else 
					{ 
						isValid = false;
						cerr << "L did't exist before b\n";
						break;
					}
				}
				case '+':
					if (lExists)                                                             //l must be at the beginning of the string
					{
						if (onB && !firstB)                                          //+ must follow B and only if it is not the first B
						{
							onPlus = true;
							break;
						}
						else
						{
							isValid = false;
							cerr << "plus is not allowed to appear yet\n";
							break;
						}
					}
					else 
					{
						isValid = false;
						cerr << "L did not appear in the beginning\n";
						break;
					}
				case 'W':
				case 'w':
					if (lExists)
					{
						if (onL || onB || onPlus)
						{
							isValid = false;                                              //cannot immediately follow a L, B, or plus
							cerr << "L, B, or Plus still needs to complete\n";
							break;
						}
						watch++;
						break;
					}
					else
					{
						isValid = false;
						cerr << "L needs to appear first\n";
						break;
					}
				case 'U':
				case 'u':
					if (lExists)
					{
						if (onL || onB || onPlus)
						{
							isValid = false;
							cerr << "U cannot immediately follow L, B, or plus\n";
							break;
						}
						if (watch > unwatch)                                           //as long as watch is always larger than unwatch, it means that it appeared before any unwatches have
						{
							unwatch++;
							break;
						}
						else
						{
							isValid = false;
							cerr << "unwatch cannot be greater than watch\n";
							break;
						}
					}
					else
					{
						isValid = false;
						cerr << "L has not appeared yet\n";
						break;
					}
				case '0':
					if (!numGo)
					{
						isValid = false;
						cerr << "cannot start a number with 0\n";
						break;
					}
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9': 
					if (lExists)
					{
						
						if (onL || onB || onPlus)                                           //continue the string but get off the letter after all the numbers are gone through
						{
							if (onB && !onPlus && !firstB && !numGo)                           //after the first B, numbers can only appear if there is a + after the B
							{
								isValid = false;
								cerr << "there must be a plus after the first B\n";
								break;
							}
							numGo = true;
							if (i < (auctionstring.size()-1))
							{
								switch (auctionstring[i + 1])                            //if next character is a number, keep going, otherwise turn off the L, B, and Plus switches
								{
								case '0':
								case '1':
								case '2':
								case '3':
								case '4':
								case '5':
								case '6':
								case '7':
								case '8':
								case '9':
									break;
								default:
									onL = false;
									onB = false;
									onPlus = false;
									numGo = false;
								}
							}                
							if (onB && firstB)                                             //if B is not the first, it must be followed with a + sign
							{
								firstB = false;
							}
							break;
						}
						else
						{
							isValid = false;
							cerr << "number must appear after a letter\n";
							break;
						}
					}
					else
					{
						isValid = false;
						cerr << "there must be an L before any numbers\n";
						break;
					}
				default:
					isValid = false;
			}

		}
		
		switch (auctionstring[auctionstring.size() - 1]) //make sure the last character of the string is allowed
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			onL = false;
			onB = false;
			onPlus = false;
			numGo = false;
		case 'W':
		case 'w':
		case 'U':
		case 'u':
			break;
		default:
			isValid = false;
			cerr << "cannot have the string end in l, b, or +\n";
		}
		
	}
	else
	{
		cerr << "empty input string\n";
		isValid = false;

	}
	return isValid;
}

//function to convert whatever number is in the auctionstring.
int convertToNumber(string numstring, size_t& index)
{
	int value = 0;
	bool shouldcontinue = true;
	for (index; index < numstring.length(); index++)
	{
		switch (numstring[index])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			{
				value = value * 10 + (numstring[index] - '0');
				break;
			}
			default:
				shouldcontinue = false;
		}
		if (!shouldcontinue)
		{
			index--;
			break;
		}
	}
	return value;
}

bool listingSold(string auctionstring)
{
	bool isSold = true;
	if (isValidEbayListingString(auctionstring))
	{
		bool onB = false;
		bool firstB = true;
		bool onL = false;
		bool onPlus = false;
		int listingPrice = 0;
		int bid = 0;

		for (size_t i = 0; i < auctionstring.size(); i++)
		{
			switch (auctionstring[i])
			{
			case 'L':
			case 'l':
				i++;
				listingPrice = convertToNumber(auctionstring, i);
				break;
			case 'B':
			case 'b':
				if (firstB)
				{
					i++;
					bid += convertToNumber(auctionstring, i);
					firstB = false;
				}
				break;
			case '+':
				i++;
				bid += convertToNumber(auctionstring, i);
				break;
			default:
				break;
			}
		}
		cerr << "List: " << listingPrice << endl;
		cerr << "Bid: " << bid << endl;
		if (bid > listingPrice)
		{
			isSold = true;
			cerr << "sold\n";
		}
		else
		{
			isSold = false;
			cerr << "not sold\n";
		}
	}
	else
	{
		isSold = false;
		cerr << "invalid string\n";
	}
	
	return isSold;

}
int howMuch(string auctionstring)
{
	if (!isValidEbayListingString(auctionstring))
	{
		return -1;
	}
	else if (isValidEbayListingString(auctionstring) && !listingSold(auctionstring))
	{
		return 0;
	}
	else
	{
		bool onB = false;
		bool firstB = true;
		bool onPlus = false;
		int bid = 0;

		for (size_t i = 0; i < auctionstring.size(); i++)
		{
			switch (auctionstring[i])
			{
			case 'B':
			case 'b':
				if (firstB)
				{
					i++;
					bid += convertToNumber(auctionstring, i);
					firstB = false;
				}
				break;
			case '+':
				i++;
				bid += convertToNumber(auctionstring, i);
				break;
			default:
				break;
			}
		}
		cerr << "Bid: " << bid << endl;
		return bid;
	}
}
int watchers(string auctionstring)
{
	if (!isValidEbayListingString(auctionstring))
	{
		return -1;
	}
	else
	{
		int watcher = 0;
		for (size_t i = 0; i < auctionstring.size(); i++)
		{
			switch (auctionstring[i])
			{
			case 'W':
			case 'w':
				watcher++;
				break;
			case 'U':
			case 'u':
				watcher--;
				break;
			default:
				break;

			}
		}
		return watcher;
	}
}