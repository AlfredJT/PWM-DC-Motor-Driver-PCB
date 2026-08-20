# PWM DC Motor Driver PCB

A high-side MOSFET driver board that switches high-current DC motors from a low-voltage microcontroller PWM signal, using a separate gate-drive supply instead of driving the MOSFET gate directly off logic level.

<img width="962" height="738" alt="Motor driver board" src="https://github.com/user-attachments/assets/75395502-0a53-4655-ba12-bd343cb60826" />

## How It Works

Driving a MOSFET gate directly from an MCU's PWM pin works fine at low currents, but it doesn't scale well once you need to switch a real motor load and you often want the motor running on a completely separate, higher-voltage rail from the logic. This board solves that with a small gate-drive stage:

- The **IRF540N's gate** is pulled up to the power rail through a **1kΩ resistor**.
- A **2N2222A transistor** sits between the gate and ground, acting as the switch that controls the MOSFET.
- When the **MCU's PWM signal goes high**, current flows through a **220Ω** base resistor and turns the 2N2222A on, pulling the gate down to ground — **MOSFET off**.
- When the **PWM signal goes low**, the transistor turns off and the 1kΩ resistor pulls the gate back up to the rail — **MOSFET on**.

The result is that a low-voltage logic signal fully controls a MOSFET switching a completely separate, higher-voltage motor supply.

**Supporting components:**
- A **10kΩ resistor** holds the transistor's base low by default, so the transistor — and therefore the MOSFET — stays off if the PWM pin is ever left floating.
- A **0.1µF capacitor** filters noise on the voltage rail.
- A **1N5822 Schottky diode** is placed across the motor to catch the flyback voltage spike generated each time the MOSFET switches off. Since motors are inductive loads that resist sudden changes in current, this diode is essential for protecting the MOSFET. The 1N5822 was chosen specifically for its fast switching speed and low forward voltage drop, which lets it keep up with the switching frequency.

## PCB Schematic

<img width="569" height="847" alt="PCB schematic" src="https://github.com/user-attachments/assets/92e8cc4f-dfec-4f96-a09e-8c18c729ae83" />

## KFK-180 Motors

<img width="801" height="560" alt="KFK-180 motors" src="https://github.com/user-attachments/assets/3e0542ac-674e-4353-b6cd-ca0409495376" />

A DC motor's spin direction is determined purely by the polarity of current through its windings. That means two KFK-180 motors can be wired with opposite lead polarity and driven off the same PWM signal while spinning in opposite directions.
## Designing the Fan & Enclosure

Designed a fan impeller in Fusion 360, sized specifically for the KFK-180 motor's shaft and 3D printed it.

<img width="1137" height="512" alt="Fusion 360 fan design" src="https://github.com/user-attachments/assets/0cc7fbc5-3640-4b0e-8b3c-5a3c2b34ed17" />

<img width="684" height="469" alt="3D printed fan" src="https://github.com/user-attachments/assets/1299a325-bd57-4edc-bf60-ce2ef6ec0dc6" />

## Final Application

<img width="579" height="431" alt="Final enclosure cooling application" src="https://github.com/user-attachments/assets/6d25474c-d951-4a5e-928a-396cd834f8ca" />

This driver module is used to configure a cooling system for a custom enclosure. By wiring the two fans with opposite polarity off the same PWM signal, one fan spins clockwise and the other counterclockwise at identical speed allowing one one to serve as intake and the other as exhaust. Thereby creating directional airflow through the enclosure without needing independent control channels.
