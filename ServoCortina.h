#ifndef SERVO_CORTINA_H
#define SERVO_CORTINA_H

#include <Servo.h>

class ServoCortina {
  private:
    Servo servo;
    int pin;
    bool abierta = false;

  public:
    ServoCortina(int p) { pin = p; }

    void begin() {
      servo.attach(pin); //Inicia servo
      servo.write(0);
    }

    void abrir() {
      if (abierta) return;
      for (int i = 0; i <= 90; i++) { //Mueve el servo con for para que sea mas lento y no con la velocidad maxima al 90
        servo.write(i);
        delay(10);
      }
      abierta = true;
    }

    void cerrar() {
      if (!abierta) return;
      for (int i = 90; i >= 0; i--) {  //Mueve el servo con for para que sea mas lento y no con la velocidad maxima al 0
        servo.write(i);
        delay(10);
      }
      abierta = false;
    }

    bool estaAbierta() { return abierta; }
};

#endif