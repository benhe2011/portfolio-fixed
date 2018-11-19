/*
#include <iostream>
#include <string>
//using namespace std;
*/









































//Concern base class definition
class Concern {
	public:
		Concern(std::string name);
		virtual ~Concern();
		virtual std::string description() const = 0;
		std::string person() const;
		virtual bool possibleFelony() const = 0;
		

	private:
		std::string m_pp;
};

Concern::Concern(std::string name) {
	m_pp = name;
}

Concern::~Concern() {}

std::string Concern::person() const{
	return m_pp;
}

//Ethics Matter derived class definition
class EthicsMatter : public Concern {
	public:
		EthicsMatter(std::string name);
		~EthicsMatter();
		virtual std::string description() const{
			return "An ethics matter";
		}
		
		virtual bool possibleFelony() const{
			return false;
		}
};

//Ethics Matter function implementations
EthicsMatter::~EthicsMatter() {
	std::cout << "Destroying " << person() << "'s ethics matter" << std::endl;
}

EthicsMatter::EthicsMatter(std::string name)
	:Concern(name) {}


//Hush Payment derived class definition
class HushPayment : public Concern {
	public:
		HushPayment(std::string name, int amt);
		~HushPayment();
		virtual std::string description() const{
			std::string amtString = std::to_string(m_amt);
			return ("A $" + amtString + " payment");
		}
		
		virtual bool possibleFelony() const{
			return false;
		}

	private:
		int m_amt;
};

//Hush Payment function implementations
HushPayment::~HushPayment() {
	std::cout << "Destroying " << person() << "'s hush payment"<< std::endl;
}

HushPayment::HushPayment(std::string name, int amt)
	:Concern(name), m_amt(amt) {}


//Investigation derived class definition
class Investigation : public Concern {
	public:
		Investigation(std::string name);
		~Investigation();
		virtual std::string description() const{
			return "An investigation";
		}
		
		virtual bool possibleFelony() const{
			return true;
		}
};

//Investigation function implementations
Investigation::Investigation(std::string name)
	:Concern(name) {}

Investigation::~Investigation() {
	std::cout << "Destroying " << person() << "'s investigation" << std::endl;
}











































/*
void display(const Concern* c)
{
	cout << c->description() << " involving " << c->person();
	if (c->possibleFelony())
		cout << ", possibly felonious";
	cout << endl;
}

int main()
{
	Concern* concerns[4];
	concerns[0] = new EthicsMatter("Pruitt");
	// Hush payments have a person's name and an amount of money (an int).
	concerns[1] = new HushPayment("Clifford", 130000);
	concerns[2] = new HushPayment("McDougal", 150000);
	concerns[3] = new Investigation("Mueller");

	cout << "Here are the concerns:" << endl;
	for (int k = 0; k < 4; k++)
		display(concerns[k]);

	// Clean up the concerns before exiting
	cout << "Cleaning up:" << endl;
	for (int k = 0; k < 4; k++)
		delete concerns[k];
}
*/