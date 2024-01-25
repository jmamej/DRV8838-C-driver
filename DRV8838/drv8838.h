/*
 * DRV8838 Driver
 *
 * PHASE  - Rotation direction
 * ENABLE - PWM (250 kHz)
 * SLEEP  - Low power mode (default HIGH)
 *
 */


#ifndef __DRV8838_H__
#define __DRV8838_H__

#include "main.h"
#include "tim.h"

//complete:
#define DRV_TIM			(&htim1)		//Change to appropriate timer.
#define TIM_CHANNEL		TIM_CHANNEL_2	//TIM_CHANNEL_X - change X with chosen channel number

#define DRV_PHASE_PORT	PHASE_GPIO_Port
#define DRV_PHASE_PIN	PHASE_Pin

#define DRV_ENABLE_PORT	ENABLE_GPIO_Port
#define DRV_ENABLE_PIN	ENABLE_Pin

#define DRV_SLEEP_PORT	SLEEP_GPIO_Port
#define DRV_SLEEP_PIN	SLEEP_Pin

void drv8838_init(void);
void drv8838_rot_clkwise(void);
void drv8838_rot_ctrclkwise(void);
void drv8838_set_speed(uint16_t speed);
void drv8838_stop(void);
void drv8838_sleep(void);
void drv8838_sleep_wake(void);

#endif /* __DRV8838_H__ */
