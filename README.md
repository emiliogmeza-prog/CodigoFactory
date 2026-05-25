# CodigoFactory
Cotinas automaticas
SISTEMA DE CORTINA AUTOMATICA CON ARDUINO


DESCRIPCION

Este proyecto controla una cortina usando un servo motor.
Tiene dos modos: automatico (la cortina abre y cierra sola cada 10 segundos)
y manual (el usuario la controla con un boton).
Tres LEDs indican el estado actual del sistema.

LENGUAJE
C++ para Arduino 

HARDWARE NECESARIO

- Arduino Uno (o compatible)
- 1 servo motor (tipo SG90)
- 1 boton (push button)
- 3 LEDs: verde, rojo y amarillo
- 3 resistencias de 220 ohms
- Cables y protoboard

CONEXIONES
Ver el archivo Diagrama de arquitectura.png

COMO USARLO

1. Abrir el archivo CodigoFactory en el IDE de Arduino
2. Instalar las librerias "Servo" desde el gestor de librerias de Arduino
3. Cargar el codigo al arduino
4. Alimentar el circuito

INSTRUCCIONES 

- El sistema arranca en modo automatico
- Un clic en el boton activa el modo manual
- En modo manual, cada clic abre o cierra la cortina
- Mantener el boton presionado 2 segundos regresa al modo automatico

LED verde  = cortina abierta (modo automatico)
LED rojo   = cortina cerrada (modo automatico)
LED amarillo = modo manual activo
