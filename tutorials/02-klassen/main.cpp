/*
 *  Created on: Oct 30, 2012
 *      Author: scharf
 */

#include <iostream>
#include <vector>


using namespace std;

class Fahrzeug {
public:
    std::string marke;
    std::string farbe;
    int fahrgestellnummer;
    Fahrzeug::Fahrzeug(string m, string f, int fn) : marke(m), farbe(f), fahrgestellnummer(fn){}
};

class Parkplatz {
    private: std::vector<Fahrzeug> fahrzeuge;
};

class MotorisiertesFahrzeug : public Fahrzeug {
public :
    MotorisiertesFahrzeug::MotorisiertesFahrzeug(string m, string f, int fn): Fahrzeug(m,f,fn){}
    void fahren() {
        std::cout << "Fahren!" << std::endl;
    }
};

class NichtMotorisiertesFahrzeug : public Fahrzeug {
public:
    virtual void strampeln();
    NichtMotorisiertesFahrzeug::NichtMotorisiertesFahrzeug(string m, string f, int fn): Fahrzeug(m,f,fn){}
};

class LKW : public MotorisiertesFahrzeug {
public : LKW::LKW(string m, string f, int fn): MotorisiertesFahrzeug(m,f,fn){}
};

class PKW : public MotorisiertesFahrzeug {
public : PKW::PKW(string m, string f, int fn): MotorisiertesFahrzeug(m,f,fn){}
};

class Motorrad : public MotorisiertesFahrzeug {
public : Motorrad::Motorrad(string m, string f, int fn): MotorisiertesFahrzeug(m,f,fn){}
};

class Fahrrad : NichtMotorisiertesFahrzeug {
public : Fahrrad::Fahrrad(string m, string f, int fn): NichtMotorisiertesFahrzeug(m,f,fn){}
    void strampeln() override{
        std::cout << "Strampeln!" << std::endl;
    }
};


int main(void) {
  //create some test objects here

    Fahrrad rad1("Schrotteil","rost", 123);
    rad1.strampeln();
	return 0;
}
