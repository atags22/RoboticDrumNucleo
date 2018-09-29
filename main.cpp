#include "mbed.h"
#include "rtos.h"

DigitalOut led1(LED1);
PwmOut led2(LED2);
Thread thread;

void led2_thread() {
  led2.period(.020); //50Hz
  while (true) {
    led2.pulsewidth_us(1000);
    Thread::wait(1000);
    led2.pulsewidth_us(2000);
    Thread::wait(1000);
  }
}

int main() {
  thread.start(led2_thread);

  while (true) {
    led1 = false;
    Thread::wait(40);
    led1 = true;
    Thread::wait(500);
  }
}
