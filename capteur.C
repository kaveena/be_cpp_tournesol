
#include <iostream>
#include <mraa/aio.h>
#include <mraa/gpio.h>
#include "capteur.hpp"

class capteur {

protected
int pin;

// constructeur 
	capteur () { 
		// initialisation
			mraa_init();
			m_gpio = mraa_gpio_init(pin);  // définir la PIN 
			mraa_gpio_dir (m_gpio, MRAA_GPIO_IN);
	}
};


class photodiode: public capteur, public analog{
};

class micro: public capteur, public analog{
};




