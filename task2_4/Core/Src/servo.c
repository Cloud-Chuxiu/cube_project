#include "servo.h"

void Servo_set(uint8_t dir, float speed, float angle) // speed: r/s ; angle: deg
{
  if(dir == 1)
  {
    HAL_GPIO_WritePin(GPIOA, DIR_Pin, GPIO_PIN_RESET);
  }
  else if (dir == 0)
  {
    HAL_GPIO_WritePin(GPIOA, DIR_Pin, GPIO_PIN_RESET);
  }
  angle = angle / 1.8;
  uint16_t delay_ms = 0;
  delay_ms = 5 / speed;
  for(int i = 0; i < (int)angle; i++)
  {
    HAL_GPIO_WritePin(GPIOA, PUL_Pin, GPIO_PIN_RESET);
    HAL_Delay(delay_ms / 2);
    HAL_GPIO_WritePin(GPIOA, PUL_Pin, GPIO_PIN_SET);
    HAL_Delay(delay_ms / 2);
  }
}

