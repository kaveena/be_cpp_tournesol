#include "tournesol.hpp"

        unsigned int nb;
        unsigned int *ports_cap;
        unsigned int  port_servo;
        servomotor servo_tourne;
        servomotor servo_cap;
        photodiode * nos_caps;
        int * position_diode;
        int pos_tourne;

tournesol::tournesol(unsigned int port_s, unsigned int port_s2,unsigned int nombre, int les_ports[]){
	port_servo = port_s;
	nb = nombre;
	ports_cap = new unsigned int [nombre];
	for (int i = 0 ; i<nb ;i++) {
		ports_cap[i]=les_ports[i];
	}
	servomotor servo_tourne(port_servo);
	nos_caps = new photodiode[nb];
	for(int i = 0;i<nb;i++){
		nos_caps[i]=photodiode(ports_cap[i]);
	}
	position_diode = new int [nb];
	for (int i = 0; i<nb; i++){
		position_diode[i]=ANGLE_MIN*i;
	}
	servo_cap.set_pos(0);
		

	
			
		

}
