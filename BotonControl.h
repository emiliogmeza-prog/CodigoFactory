#ifndef BOTON_CONTROL_H
#define BOTON_CONTROL_H

class BotonControl {
  private:
    int pin;
    bool ultimoEstado = HIGH;
    unsigned long ultimoTiempo = 0;

  public:
    BotonControl(int p) { pin = p; }

    void begin() { pinMode(pin, INPUT_PULLUP); } 

    bool fuePresionado() { //Detecta el clic
      bool lectura = digitalRead(pin);
      if (lectura == LOW && ultimoEstado == HIGH && millis() - ultimoTiempo > 250) {
        ultimoTiempo = millis();
        ultimoEstado = lectura;
        return true;
      }
      ultimoEstado = lectura;
      return false;
    }

    bool presionado() { return digitalRead(pin) == LOW; } //Detecta si está presionado
};

#endif