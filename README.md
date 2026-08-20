# PWM DC Motor Driver PCB
<img width="962" height="738" alt="image" src="https://github.com/user-attachments/assets/75395502-0a53-4655-ba12-bd343cb60826" />

This board drives high-current DC motors from a microcontroller by using a separate power supply for gate drive rather than switching the MOSFET directly off the MCU's logic level PWM signal. The IRF540N's gate is pulled up to the power source voltage through a 1KΩ resistor, and a 2N2222A transistor sits between the gate and ground. When the MCU's PWM signal goes high, it flows through a 220Ω resistor and turns the transistor on, pulling the gate down to ground and switching the MOSFET off. When PWM goes low, the transistor turns off and the 1K resistor pulls the gate back up to the full voltage rail, switching the MOSFET on. This lets a low-voltage PWM signal control a motor running on a completely separate, higher voltage line. A 10K resistor holds the transistor's base low by default so the transistor stays off if the PWM pin is ever floating, and a 0.1uF capacitor filters noise on the voltage rail. Since motors are inductive loads that resist sudden current changes, a 1N5822 Schottky diode sits across the motors to catch the flyback voltage spike generated each time the MOSFET switches off. The Schottky diode was chosen specifically for its fast switching speed and low forward drop, which is important for the board to keep up with the switching frequency.

# PCB Schematic
<img width="569" height="847" alt="image" src="https://github.com/user-attachments/assets/92e8cc4f-dfec-4f96-a09e-8c18c729ae83" />


## KFK-180 Motors
<img width="801" height="560" alt="image" src="https://github.com/user-attachments/assets/3e0542ac-674e-4353-b6cd-ca0409495376" />
Since a DC motor's spin direction is purely determined by which way current flows through its windings, flipping the leads at the terminals would allow you to run two separate motors in opposite directions off the same PWM Signal.

## Designing Fan & Enclosure
<img width="1137" height="512" alt="image" src="https://github.com/user-attachments/assets/0cc7fbc5-3640-4b0e-8b3c-5a3c2b34ed17" />

Designed a fan based specifically on the KFK-180's motors in Fusion360 and 3D printed it.

<img width="684" height="469" alt="image" src="https://github.com/user-attachments/assets/1299a325-bd57-4edc-bf60-ce2ef6ec0dc6" />

## Final Application
<img width="579" height="431" alt="image" src="https://github.com/user-attachments/assets/6d25474c-d951-4a5e-928a-396cd834f8ca" />

I'm using this driver module to configure a cooling system for an enclosure im designing. The fans being wired opposite to each other allows for one fan to rotate in one direction and the other in a different one, meaning one will serve as intake and the other as exhaust at the exact same speed. 


