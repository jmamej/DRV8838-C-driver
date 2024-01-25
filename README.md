# DRV8838_C_driver



### DRV8838 is an integrated motor driver with an H-bridge built in consisting of N-channel MOSFETs.


![image](https://github.com/jmamej/DRV8838_C_driver/assets/57408600/c3f6cbbe-6402-45bf-9830-1afb7201186b)

### Datasheet [link](https://www.ti.com/lit/ds/symlink/drv8838.pdf).

### PINS

| Pins          | Discription                                           |
|:-------------:| ----------------------------------------------------- |
| ENABLE        | PWM signal                                            |
| PHASE         | Motor spin direction                                  |
| SLEEP         | Switch to low power mode (default state: HIGH)        |
| VIN           | Reverse-protected motor power supply input            |
| VM            | Motor power supply after (reverse-voltage protection) |
| OUT+          | H-bridge output 1                                     |
| OUT-          | H-bridge output 2                                     |

### Setup (STM32CubeIDE)

![image](https://github.com/jmamej/DRV8838_C_driver/assets/57408600/c434c17c-8905-4b94-b655-c63ba359fbb5)


Set SLEEP and PHASE as output.

Set Enable as TIMX_CHX

![image](https://github.com/jmamej/DRV8838_C_driver/assets/57408600/9a51b1c8-bdfc-4a65-a46c-2170e872cc50)

Max externally applied PWM frequency for DRV8838 - 250 kHz

![image](https://github.com/jmamej/DRV8838_C_driver/assets/57408600/49a7eeca-c6ad-4d43-9d99-5f80d5973634)

TIM1 freq / prescaler <= 250 kHz

64 MHz / 256 = 250 kHz -> Set prescaler to 255 (prescaler automatically incremented by 1 to avoid dividing by 0)


![image](https://github.com/jmamej/DRV8838_C_driver/assets/57408600/a56ccdb7-0de4-483d-ada5-c82c18bb52a6)


### Usage

```
#include "drv8838.h"

int main()
{

  drv8838_init();
  drv8838_rot_clkwise();

while(1)
{

  drv8838_set_speed(1000);  // speed 0 - 1000 (counter period - see last picture)

}
}
```






