#include "drv8838.h"
#include "main.h"

static void sleep_low(void)
{
	HAL_GPIO_WritePin(DRV_SLEEP_PORT, DRV_SLEEP_PIN, 0);
}

static void sleep_high(void)
{
	HAL_GPIO_WritePin(DRV_SLEEP_PORT, DRV_SLEEP_PIN, 1);
}

static void phase_low(void)
{
	HAL_GPIO_WritePin(DRV_PHASE_PORT, DRV_PHASE_PIN, 0);
}

static void phase_high(void)
{
	HAL_GPIO_WritePin(DRV_PHASE_PORT, DRV_PHASE_PIN, 1);
}

/*
 * drv8838_init
 * set initial state of output pins
 *
 */

void drv8838_init(void)
{
	HAL_TIM_PWM_Start(DRV_TIM, TIM_CHANNEL);
	__HAL_TIM_SET_COMPARE(DRV_TIM, TIM_CHANNEL, 0);
	phase_low();
	sleep_high();
}

void drv8838_rot_clkwise(void)
{
	phase_high();
}

void drv8838_rot_ctrclkwise(void)
{
	phase_low();
}

/*
 * drv8838_set_speed(uint16_t speed)
 * speed - variable determines motor speed
 * 0 - stop
 * counter period - max speed
 *
 */

void drv8838_set_speed(uint16_t speed)
{
	__HAL_TIM_SET_COMPARE(DRV_TIM, TIM_CHANNEL, speed);
}

void drv8838_stop(void)
{
	__HAL_TIM_SET_COMPARE(DRV_TIM, TIM_CHANNEL, 0);
}

void drv8838_sleep(void)
{
	sleep_low();
}

void drv8838_sleep_wake(void)
{
	sleep_high();
}
