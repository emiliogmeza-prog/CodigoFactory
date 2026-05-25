#include "ServoCortina.h"
#include "LedEstado.h"
#include "BotonControl.h"
#include "ControladorCortina.h"

ServoCortina cortina(9);
LedEstado ledVerde(6);
LedEstado ledRojo(7);
LedEstado ledManual(5);
BotonControl boton(2);

ControladorCortina sistema(cortina, ledVerde, ledRojo, ledManual, boton);

void setup() {
  Serial.begin(9600);
  cortina.begin();
  ledVerde.begin();
  ledRojo.begin();
  ledManual.begin();
  boton.begin();
}

void loop() {
  sistema.actualizar(); // Ejecuta las funciones
}