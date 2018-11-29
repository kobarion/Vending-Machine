// Choose which system to use
// #define sysPC // if using in PC (Linux)
 #define sysRPi // if using in RaspberryPi (ARM based system)

#include <iostream>
#include "../src/advertisement.cpp"

using namespace std;

int main(){
	
    Advertisement ad_controller;

    string msg;

    ad_controller.addAD();
    ad_controller.addAD();
    ad_controller.addAD();
    ad_controller.addAD();
    ad_controller.insertIntoQueue1();
    // msg = ad_controller.removeAD();
    // cout << msg << endl;

    while(1){
		ad_controller.showAD();
    }

    return 0;
}
