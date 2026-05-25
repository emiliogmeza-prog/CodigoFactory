#ifndef LED_ESTADO_H
#define LED_ESTADO_H

class LedEstado {
  private:
    int pin;

  public:
    LedEstado(int p) { pin = p; }

    void begin() { pinMode(pin, OUTPUT); } // Configura pin como salida
    void encender() { digitalWrite(pin, HIGH); }
    void apagar() { digitalWrite(pin, LOW); }
};

#endif