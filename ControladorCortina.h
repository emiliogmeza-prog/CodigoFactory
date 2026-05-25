#ifndef CONTROLADOR_CORTINA_H
#define CONTROLADOR_CORTINA_H

#include "ServoCortina.h"
#include "LedEstado.h"
#include "BotonControl.h"

class ControladorCortina {
  private:
    ServoCortina& servo;
    LedEstado& verde;
    LedEstado& rojo;
    LedEstado& manual;
    BotonControl& boton;

    bool modoManual = false;
    unsigned long tiempoPresionado = 0;

  public:
    ControladorCortina(
      ServoCortina& s, LedEstado& v, LedEstado& r, LedEstado& m, BotonControl& b
    ) : servo(s), verde(v), rojo(r), manual(m), boton(b) {}

    void actualizar() {
      if (boton.fuePresionado()) { //Cambia a omdo manual o mueve la cortina manualmente
        if (!modoManual) {
          modoManual = true;
          manual.encender();
        } else {
          if (servo.estaAbierta()) servo.cerrar();
          else servo.abrir();
        }
      }

      if (boton.presionado()) {  //Si se deja presionado 2s quita el manual
        if (tiempoPresionado == 0) tiempoPresionado = millis();
        if (millis() - tiempoPresionado > 2000 && modoManual) {
          modoManual = false;
          manual.apagar();
          tiempoPresionado = 0;
        }
      } else {
        tiempoPresionado = 0;
      }

      if (!modoManual) {      // Control automático por tiempo
        unsigned long t = millis()/1000;
        if ((t % 20) < 10) servo.abrir();
        else servo.cerrar();
      }
                              //Control de LEDs de estado
      if (servo.estaAbierta()) { 
        verde.encender();
        rojo.apagar();
      } else {
        verde.apagar();
        rojo.encender();
      }
    }
};

#endif