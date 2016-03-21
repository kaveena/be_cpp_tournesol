#ifndef CAPTEUR_HPP
#define CAPTEUR_HPP
#include <iostream>
#include <mraa/aio.h>
#include <mraa/gpio.h>
#include "type.hpp"


class capteur {};
class photodiode: public capteur, public analog {};
class micro: public capteur, public analog {};

#endif
