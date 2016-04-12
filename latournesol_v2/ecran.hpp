#ifndef LCD_H
#define LCD_H
#include <mraa/i2c.h>
#include <unistd.h>
#include <iostream>
#include <string>

#define LCD_CLEARDISPLAY 0x01
#define LCD_ENTRYMODESET 0x04
#define LCD_FUNCTIONSET 0x20
#define LCD_DATA 0x40
#define LCD_CMD 0x80
#define LCD_DISPLAYCONTROL 0x08
#define LCD_DISPLAYON 0x04

// flags for display entry mode
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_2LINE 0x08

class lcd{
private:
  mraa_result_t i2cData (mraa_i2c_context ctx, uint8_t value);
  mraa_result_t i2Cmd (mraa_i2c_context ctx, uint8_t value);
  mraa_result_t i2cReg (mraa_i2c_context ctx, int deviceAdress, int addr, uint8_t value);
  mraa_i2c_context m_i2c_lcd_control;
  mraa_i2c_context m_i2c_lcd_rgb;
  int m_bus;
  int m_lcd_control_address;
  int m_rgb_control_address;


public :
  //constructeur
  lcd();
  //destructeur
  ~lcd();
  //Affiche msg_l1 sur la premiere ligne
  // et msg_l2 sur la deuxieme
  void print_msg(std::string msg_l1,std::string msg_l2);
  //affiche rien a l'ecran
  void clear_screen();
  //change la couleur de fonc de l'ecran 
  //en utilisant le code RGB 
  //r,g,b entre 0 et 255
  void change_cou(int r, int g, int b);
};

#endif
