# kaambox-media

## Description

`KaamBox` is a custom *useless box* that triggers a random Kaamelott sound handled by a daemon process on a remote server
(see the [`kaambox-daemon`](https://github.com/KaamBox/kaambox-daemon) project).


## Setup

* Set this `Complementary board URL` in your Arduino IDE settings: `http://arduino.esp8266.com/versions/2.4.0/package_esp8266com_index.json`
* Go to `Tools -> Board Type -> Board Manager` and install the following packages: `esp8266` and `WiFi Manager`

Open a terminal, go to the `~/Arduino/libraries` directory and clone the following repositories:

* `git clone https://github.com/earlephilhower/ESP8266Audio`
* `git clone https://github.com/Gianbacchio/ESP8266_Spiram`

Then, in the `Tools` menu, select the following values:

* Board type: `WeMos D1 R2 & mini`
* Flash size: `4M (3M SPIFFS)`
* IwIP Variant: `v2 Prebuilt (MSS=536)`
* CPU Frequency: `160 MHz`


## Hardware

| Reference | Product | Unit Price | Qty | Total |
| --------- | ------- | ---------- | --- | ----- |
| ESP8266 | Espressif ESP8266 Microcontroller | 2.99€ | 1 | 2.99€ |
| SVO360DCONT | 360-degree continuous rotation servo (38g, 5.5kg/cm, 4.8v-6v) DS04 | 9.00€ | 2 | 18.00€ |
| POWSEDLITCHM | Battery Charging StepUp Power Supply Module lipo / USB (18650) | 3.00€ | 1 | 3.00€ |
| SPKRH2W8OHM | Flanged cone loudspeaker 1W 8ohm 50mm | 6.00€ | 1 | 6.00€ |
| SWITAOKCDR | KCD3-101N Red (SPDT red rocker switch, 15A / 250V) | 1.25€ | 1 | 1.25€ |
| ENEBATLP603450 | Lithium Polymer Battery - 1200mAh 3.7V | 11.00€ | 1 | 11.00€ |
| MODJANAO | LM358 Operational Amplifier Module | 3.40€ | 1 | 3.40€ |
| SWIJANMTS102 | Toggle Switch MTS-102 | 2.17€ | 1 | 2.17€ |
| CABMICUSB01M | Usb to Micro USB Cable (0.1M) | 2.50€ | 1 | 2.50€ |


## Demo (without sound)

![GIF demonstration of the finished product](https://raw.githubusercontent.com/KaamBox/kaambox-media/master/demo.gif)


## Gallery

### Woodcrafting

![KaamBox 1](https://raw.githubusercontent.com/KaamBox/kaambox-media/master/images/box_1.jpg)

![KaamBox 2](https://raw.githubusercontent.com/KaamBox/kaambox-media/master/images/box_2.jpg)

### Components view: 2 servos & 2 switches

![KaamBox 3](https://raw.githubusercontent.com/KaamBox/kaambox-media/master/images/box_3.jpg)

### Wiring & tests

![KaamBox 4](https://raw.githubusercontent.com/KaamBox/kaambox-media/master/images/box_4.jpg)

![KaamBox 5](https://raw.githubusercontent.com/KaamBox/kaambox-media/master/images/box_5.jpg)

### First prototype

![KaamBox 6](https://raw.githubusercontent.com/KaamBox/kaambox-media/master/images/box_6.jpg)

### Final prototype
![KaamBox 7](https://raw.githubusercontent.com/KaamBox/kaambox-media/master/images/box_7.jpg)

### Back shot with power button

![KaamBox 8](https://raw.githubusercontent.com/KaamBox/kaambox-media/master/images/box_8.jpg)