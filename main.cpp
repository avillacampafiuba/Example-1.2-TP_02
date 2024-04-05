#include "mbed.h"
#include "arm_book_lib.h"

//Augusto: Contenido del proyecto:
//  Librerías:
//  arm_book_lib.h
//  mbed-os.lib

int main()
{
    //Augusto:
    //Path: DigitalIn.h - mbed -> mbed_gpio.c - mbed -> gpio_api.c - mbed -> pinmap.c - mbed -> cmsis_armclang.h - arm -> stm32f4xx_ll_gpio.h - STM
    //                                                                                       -> pin_device.h - mbed -> cmsis_armclang.h - arm -> stm32f4xx_ll_gpio.h - STM
   DigitalIn gasDetector(D2);
   DigitalIn overTempDetector(D3);
   
    //Augusto:
    //Path: DigitalIn.cpp - mbed -> mbed_critical.c - mbed -> mbed_critical_section_api.c - mbed -> cmsis_armclang.h - arm
    //                           -> gpio_api.c - mbed -> pinmap.c - mbed -> cmsis_armclang.h - arm -> stm32f4xx_ll_gpio.h - STM
    //                                                                   -> pin_device.h - mbed -> cmsis_armclang.h - arm -> stm32f4xx_ll_gpio.h - STM
    //                           -> 
   DigitalOut alarmLed(LED1);
   
   gasDetector.mode(PullDown);   
   overTempDetector.mode(PullDown);

   int i = 0;

   while (true) {
      
      if ( gasDetector || overTempDetector ) {
         alarmLed = ON;
         printf("gasDetector: %d\n", gasDetector.read());
         printf("overTempDetector: %d\n", overTempDetector.read());
         printf("alarmLED: %d\n", alarmLed.read());
      } else {
         alarmLed = OFF;
         printf("gasDetector: %d\n", gasDetector.read());
         printf("overTempDetector: %d\n", overTempDetector.read());
         printf("alarmLED: %d\n", alarmLed.read());
      }
      i++;
   }
}