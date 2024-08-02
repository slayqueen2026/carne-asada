Engineering materials
====
The materials used for this project are:

1. 2 plastic planks
2. 2 Axle carriers
3. 4 wheels
4. 4 Hex coupler connector
5. Screws
6. Plastic separator
7. L289N DC motor controller
8. Genteric DC motor
9. MG996R Servo motor
10. Arduino MEGA board
11. Wires
12. 3 HC-SR04 Ultrasonic sensors
13. Rubber bands
14. 2 Elixes
15. Vex battery for motor  
16. 9v battery for arduino board
17. Circuit plate
18. Loose pins
19. VL53L0/1XV2 Laser Ranging sensor 



## Introduction
We begin with individual testing of physical elements such as distance sensors, servo motors, DC motors, and switches. This phase resulted in the creation of functional modules to control each component, thereby simplifying the main program.
Once the physical testing phase was completed, we proceeded to integrate this part with the programming element containing:
+ Distance module
+ Turning module
+ Acceleration module
+ Brake module

This model will undergo robust evolution once it includes...

As we delve into understanding the intricate workings of our vehicle's electromechanical systems, it is crucial to uncover the underlying code that governs these components. This exploration focuses on the sophisticated modules within our software architecture, their seamless integration with the vehicle's physical hardware, and the meticulous process of building, compiling, and uploading this code to the vehicle's controllers.
Throughout this session, we will navigate the intersection of software and hardware, revealing how each line of code translates into actions within the vehicle's mechanical and electrical framework. By exploring these connections, we aim to deepen our understanding of the synergistic relationship between programming and engineering, which enhances the performance and functionality of our automotive technologies


## Discussion
_Shape of the Car_: The shape of the car was determined based on practical considerations. The decision was made to design the shape of the two plates in a specific way to accommodate the wheels without exceeding the width limits of the car. This design choice was influenced by observing a car building kit. Additionally, the shape and size of the car were designed to ensure that the VEX battery and Arduino plate could fit comfortably within the car's limits.

_Vehicle Mobility_: To enable the vehicle to detect its direction and make appropriate turns, it utilizes a combination of two laser ranging sensors (one on the left and one on the right) and a servo motor. These sensors provide the necessary input for the vehicle to determine its position and navigate accordingly.

_Power_: Initially, we employed two distinct batteries to power the car: a 9V battery for the Arduino board and a VEX battery for the DC motor. However, we have since transitioned to utilizing the VEX battery for both components. This change is attributable to the VEX battery's numerous advantages, including extended battery life, quicker charging times, and reduced weight in comparison to alternative battery options. Furthermore, this consolidation alleviates concerns regarding the depletion of 9V batteries for the Arduino board. 

_Sensors_:Initially, three ultrasonic sensors were used, but they presented challenges in detecting the surroundings and had slow response times. As a result, a decision was made to switch to laser ranging sensors. Laser ranging sensors offer greater precision and faster response times, making them a more suitable choice for the vehicle's sensing needs.
