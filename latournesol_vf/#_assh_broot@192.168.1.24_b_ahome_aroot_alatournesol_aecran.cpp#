#include "ecran.hpp"

mraa_result_t lcd::i2cData (mraa_i2c_context ctx, uint8_t value) {
  mraa_result_t error = MRAA_SUCCESS;
  uint8_t data[2] = { LCD_DATA, value };
  error = mraa_i2c_address (ctx, m_lcd_control_address);
  error = mraa_i2c_write (ctx, data, 2);
  return error;
}

mraa_result_t lcd::i2Cmd (mraa_i2c_context ctx, uint8_t value) {
  mraa_result_t error = MRAA_SUCCESS;
  uint8_t data[2] = { LCD_CMD, value };
  error = mraa_i2c_address (ctx, m_lcd_control_address);
  error = mraa_i2c_write (ctx, data, 2);
  return error;
}

mraa_result_t lcd::i2cReg (mraa_i2c_context ctx, int deviceAdress, int addr, uint8_t value) {
    mraa_result_t error = MRAA_SUCCESS;
    uint8_t data[2] = { addr, value };
    error = mraa_i2c_address (ctx, deviceAdress);
    error = mraa_i2c_write (ctx, data, 2);   
    return error;
}

lcd::lcd(int a){
  m_bus=0;
  m_lcd_control_address=0x3E;
  m_rgb_control_address=0x62;
  m_i2c_lcd_control = mraa_i2c_init(m_bus);
  mraa_i2c_address(m_i2c_lcd_control, m_lcd_control_address);
  m_i2c_lcd_rgb = mraa_i2c_init(m_bus);
  mraa_i2c_address(m_i2c_lcd_rgb, m_rgb_control_address);
  usleep(50000);
  i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);
  usleep(4500);
  i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);
  usleep(4500);
  i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);
  usleep(4500);
  i2Cmd (m_i2c_lcd_control, LCD_FUNCTIONSET | LCD_2LINE);
  i2Cmd (m_i2c_lcd_control, LCD_DISPLAYCONTROL | LCD_DISPLAYON);
  i2Cmd (m_i2c_lcd_control, LCD_CLEARDISPLAY);
  usleep(4500);
  i2Cmd (m_i2c_lcd_control, LCD_ENTRYMODESET |
	 LCD_ENTRYLEFT |
	 LCD_ENTRYSHIFTDECREMENT);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0, 0);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 1, 0);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x08, 0xAA);
  
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x04, 255);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x03, 255);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x02, 255);
}

lcd::~lcd(){
  sleep(3);
  mraa_i2c_stop(m_i2c_lcd_control);
}

void lcd::print_msg(std::string msg){
  i2Cmd (m_i2c_lcd_control, LCD_CLEARDISPLAY);
  // positionnement ligne 1 colonne 2
  int row=1, column=2;
  int row_addr[] = { 0x80, 0xc0, 0x14, 0x54};
  uint8_t offset = ((column % 16) + row_addr[row]);
  i2Cmd (m_i2c_lcd_control, offset);
  // écriture d'un texte
  usleep(1000);
  for (std::string::size_type i = 0; i < msg.size(); ++i) {
    i2cData (m_i2c_lcd_control, msg[i]);
  }
}

void lcd::change_cou(int r, int g , int b){
  if (r>255) r = 255;
  if (r<0) r = 0;
  if (g>255) g = 255;
  if (g<0) g = 0;
  if (b>255) b = 255;
  if (b<0) b = 0;

  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x04, r);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x03, g);
  i2cReg (m_i2c_lcd_rgb, m_rgb_control_address, 0x02, b);

}
