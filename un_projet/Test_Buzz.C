#include	<mraa/aio.h>	
#include	<mraa/gpio.h>	
	

int main(){
mraa_gpio_context m_gpio;
mraa_gpio_context but_gpio, touch_gpio;
mraa_gpio_context buzz_gpio;

// initialisation
mraa_init();
m_gpio = mraa_gpio_init(8);
mraa_gpio_dir(m_gpio, MRAA_GPIO_OUT);
mraa_gpio_write(m_gpio, 1);
sleep(2);

touch_gpio = mraa_gpio_init(4);

but_gpio = mraa_gpio_init(3);
buzz_gpio = mraa_gpio_init(2);

while (1)                            
{                                    
        // alummage et extinction    
        if (mraa_gpio_read(touch_gpio)||mraa_gpio_read(but_gpio))
        {                            
                mraa_gpio_write(m_gpio, 1);
		mraa_gpio_write(buzz_gpio,1);
        }                                  
        else                               
        {                                  
                mraa_gpio_write(m_gpio,0); 
		mraa_gpio_write(buzz_gpio,0);
        }                                  
                                           
}    
return(0);
}
