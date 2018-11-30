#include <iostream>
#include <wiringPi.h>
#include <thread>
#include <string>

#define LED 0

using namespace std;

void blinky(){
	for(;;){
		digitalWrite(LED,HIGH);
		delay(500);
		digitalWrite(LED,LOW);
		delay(500);
	}
}

int main(){
	
	cout << "Raspberry Pi blink with thread" << endl;

	wiringPiSetup();
	pinMode(LED,OUTPUT);

	thread t1(blinky);

	for(;;){
		cout << "Execution" << endl;
		delay(600);
	}

	t1.join();
}


