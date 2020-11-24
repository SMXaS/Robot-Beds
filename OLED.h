//#include <U8glib.h>
#ifndef _OLED_H_
#define _OLED_H_
//#include "TemperatureHumidity.h"
//#include "Ultrasonic.h"
//U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI

class OLED {

    int _Serial_Clock;
    int _Serial_Data;

  public:
    OLED(int Serial_Clock, int Serial_Data) {
      _Serial_Clock = Serial_Clock;
      _Serial_Data = Serial_Data;
    }

    void Exit(){
      return;
    }

    
/* Simple text display
 
    void OLED_Text(void) {
      u8g.setFont(u8g_font_unifont);
      u8g.drawStr( 0, 22, "Hello World!");
    }

    void Display(void) {
      // picture loop
      u8g.firstPage();
      do {
        OLED_Text();
      } while ( u8g.nextPage() );
      delay(50);
    }
    */

};

#endif // _OLED_H
