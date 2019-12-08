# CabideArduino
  Esse código para Arduino recolhe informações de um módulo com giroscópio e acelerômetro, Mpu-6050, e envia via rede local, através do módulo esp8266, para um programa em [Unity3D](https://github.com/NascimentoLucas/CabideUnity). Esse projeto faz parte do trabalho final para a matéria computação ubíqua. 

# ESP8266
  Como alternativa para a comunicação em rede, foi implementado um webserver. Para implementar foi necessário [configurar](https://blogmasterwalkershop.com.br/embarcados/esp8266/upgrade-de-firmware-do-wifi-esp8266-esp-01-atraves-do-arduino-e-conversor-usb-serial/) a memória flash do módulo. 
  Além disso foi usado um adaptador para facilitar a implementação, porém é possível usar sem.

# Pinagem do Arduino
- Mpu-6050:
  - VCC -> 5V
  - GND -> GROUND
  - SCL -> A5
  - SDA -> A4
  
- Esp8266 com adaptador:  
  - GND -> GROUND
  - VCC -> 5V
  - TX -> 6
  - RX -> 7
  
# Referência
- [Configuração ESP8266](https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-modulo-wifi-esp8266-esp-01)
- [Configuração Mpu-6050](https://www.filipeflop.com/blog/tutorial-acelerometro-mpu6050-arduino/)
