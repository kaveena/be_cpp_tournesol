#include	<mraa/aio.h>	
#include	<mraa/gpio.h>	
#include 	<iostream>	
#include <mraa/pwm.h>

using namespace std;

int main(){


mraa_gpio_context m_gpio;
mraa_gpio_context but_gpio, touch_gpio, serv_gpio;

mraa_aio_context pot_gpio;

mraa_pwm_context PWM;


// initialisation
mraa_init();
PWM = mraa_pwm_init(5);
mraa_pwm_enable(PWM, 1);
mraa_pwm_write(PWM, 0.25);


m_gpio = mraa_gpio_init(2);
mraa_gpio_dir(m_gpio, MRAA_GPIO_OUT);
mraa_gpio_write(m_gpio, 1);

touch_gpio = mraa_gpio_init(4);
but_gpio = mraa_gpio_init(3);

pot_gpio = mraa_aio_init(0);
//serv_gpio = mraa_gpio_init(5);

while (1)                            
{       
	if (mraa_gpio_read(but_gpio))
	{
		cout << mraa_aio_read(pot_gpio) << endl; 
		sleep(1);  
		//mraa_aio_write(serv_gpio, mraa_aio_read(pot_gpio));
	}
                                           
}    
return(0);
}
