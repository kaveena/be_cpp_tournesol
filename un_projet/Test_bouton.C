#include	<mraa/aio.h>	
#include	<mraa/gpio.h>	
	


int main(){
mraa_gpio_context m_gpio;
mraa_gpio_context but_gpio;

// initialisation
mraa_init();
m_gpio = mraa_gpio_init(2);
mraa_gpio_dir(m_gpio, MRAA_GPIO_OUT);
mraa_gpio_write(m_gpio, 1);
sleep(2);

but_gpio = mraa_gpio_init(3);


while (1)
{
	// alummage et extinction
	if (mraa_gpio_read(but_gpio))
	{
		mraa_gpio_write(m_gpio, 0);
	}
	else
	{
		mraa_gpio_write(m_gpio,1);
	}

}
return(0);
}
