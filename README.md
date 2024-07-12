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
17. Breadboard


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
_Shape of the car_ : we decided to make the shape of the two plates like that, because we were looking at a car building kit and the shape let us put the wheels in a way where we wouldn’t surpass the width limits of the car.

_Vehicle mobility_ :  The car uses a combination of three ultrasonic sensors to tell distance, a servo motor to be able to make turns and a dc motor that moves the back wheels.

_Power_:we used a VEX edr because it’s a lifepo4 battery that has a longer battery life, faster charging time  and has a more reduced weight.

_Sensors_ : only uses ultrasonic sensors (for now).
