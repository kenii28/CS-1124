/*
Kenneth Huynh
CS1124
hw05

This program creates the classes and runs the main needed for hw05
*/

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Protector{
public:
	Protector(const string& name, int strength) : name(name), strength(strength), hired(false){}
	virtual string getName() const {
		return name;
	};

	virtual void attack() = 0;

	virtual void dies() {
		strength = 0;
	}
	virtual int getStrength() const {
		return strength;
	}
	virtual void gotHired() {
		hired = true;
	}
	virtual bool isHired() const {
		return hired;
	}
	virtual void lowerStrength(const double ratio) {
		double amtChange;

		amtChange = 1 - ratio;
		strength = strength * amtChange;
	}
private:
	string name;
	int strength;
	bool hired;
};

class Wizard : public Protector{
public:
	Wizard(const string& name, int strength) : Protector(name, strength) {}
	virtual string getName() const {
		return Protector::getName();
	};
	virtual int getStrength() const {
		return Protector::getStrength();
	}
	virtual void attack() {
		cout << "POOF!\n";
	}
	virtual void dies() {
		Protector::dies();
	}
private:

};

class Warrior : public Protector{
public:
	Warrior(const string& name, int strength) : Protector(name, strength) {}
	virtual string getName() const {
		return Protector::getName();
	};
	virtual int getStrength() const {
		return Protector::getStrength();
	}
	virtual void attack() {}
	virtual void dies() {
		Protector::dies();
	}
private:

};

class Archer : public Warrior{
public:
	Archer(const string& name, int strength) : Warrior(name, strength) {}
	virtual string getName() const {
		return  Warrior::getName();
	};
	virtual int getStrength() const {
		return Warrior::getStrength();
	}
	virtual void attack() {
		cout << "TWANG!   " << getName() << " says: Take that in the name of my lord, ";
	}
	virtual void dies() {
		Warrior::dies();
	}
private:

};

class Swordsman : public Warrior{
public:
	Swordsman(const string& name, int strength) : Warrior(name, strength) {}
	virtual string getName() const {
		return Warrior::getName();
	};
	virtual int getStrength() const {
		return Warrior::getStrength();
	}
	virtual void attack() {
		cout << "CLANG!   " << getName() << " says: Take that in the name of my lord, ";
	}
	virtual void dies() {
		Warrior::dies();
	}
private:

};

class Noble{
public:
	Noble(const string& name) : name(name) {}
	virtual string getName() const{
		return name;
	};
	virtual void lower(const double ratio) = 0;
	virtual void dies() = 0;
	virtual int getStrength() const = 0;
	virtual void attack() const = 0;

	void battle(Noble& noble){ // battle another noble 
		cout << getName() << " battles " << noble.getName() << endl;

		int strength1 = getStrength();
		int strength2 = noble.getStrength();

		if ((strength1 == 999) && strength2 != 0) {
			cout << noble.getName() << " defeats " << getName() << endl;
			strength1 = 0;
		}
		else if ((strength1 == 0) && (strength2 == 0)) // both dead
		{
			cout << "Oh, NO! They're both dead! Yuck!" << endl;

		}

		else if (strength2 == 0) { // noble2 is dead
			cout << "He's dead " << getName() << endl;
		}
		else if (strength1 == 0) { // noble1 is dead
			cout << "He's dead " << noble.getName() << endl;
		}

		else if (strength1 == strength2) { // equal strength
			cout << "Mutual Annihilation: " << getName() << " and " << noble.getName() << " die at each other's hands" << endl;
			dies();
			noble.dies();
		}

		else if (strength1 > strength2) {
			attack();

			cout << getName() << " defeats " << noble.getName() << endl;
			noble.dies();
			

			double ratio;
			ratio = (strength1 - strength2);
			lower(ratio);

		}
		else { // strength2 > strength1
			attack();

			cout << noble.getName() << " defeats " << getName() << endl;
			dies();

			double ratio;
			ratio = (strength2 - strength1);
			noble.lower(ratio);
		}
}
private:
	string name;
};

class Lord : public Noble{
public:
	Lord(const string& name) : Noble(name) {}
	virtual string getName() const {
		return Noble::getName();
	}

	void attack() const { // calls all protectors attack
		for (Protector* ptr : protectors) {
			ptr->attack();
			cout << getName() << endl;
		}
	}
	virtual int getStrength() const {
		if (protectors.size() > 0) {
			int strength = 0;
			for (size_t i = 0; i < protectors.size(); ++i){
				strength += protectors[i]->getStrength();
			}
			return strength;
		}
		else {
			return 999;
		}
	}

	virtual void dies() {
		for (Protector* ptr : protectors)
		{
			ptr->dies();
		}
	}

	void hires(Protector& protector){
		if (!protector.isHired()){
			Protector* ptr = &protector;
			protectors.push_back(ptr);
			protector.gotHired();
		}
	}

	virtual void lower(const double ratio) {
		for (Protector* ptr : protectors)
		{
			ptr->lowerStrength(ratio);
		}
	}
	
private:
	vector<Protector*> protectors;
};

class PersonWithStrengthToFight : public Noble{
public:
	PersonWithStrengthToFight(const string& name, int strength) : Noble(name), strength(strength) {}
	virtual string getName() const {
		return Noble::getName();
	}
	virtual int getStrength() const {
		return strength;
	}
	virtual void dies() {
		strength = 0;
	}

	virtual void lower(const double ratio) {
		double amtChange;

		amtChange = 1 - ratio;
		strength = strength * amtChange;
	}

	virtual void attack() const {}
private:
	int strength;
};

int main()
{
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);

	system("pause");
}