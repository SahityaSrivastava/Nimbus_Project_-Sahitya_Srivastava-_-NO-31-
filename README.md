# Nimbus_Project_-Sahitya_Srivastava , Vishesh_Kumar , -NO-31-
PPS project creation.

**Question For Project **

Project 31 : Smart Home Automation Controller (Rule-Based) 
Real-world context: Home automation systems control lights, HVAC, and appliances based on schedules, sensors, and user preferences. 
Problem description (detailed):  Build a console application that models a small smart-home controller. Features: 
* Maintain devices as struct (id, name, type, status, power_rating, schedule pointers). 
* Read sensor inputs (simulated: temperature, ambient light, occupancy) and apply rules (if temp > X and occupancy true → turn AC on). 
* Support user schedules (time ranges) and manual override. Schedules stored in dynamically allocated lists. 
* Provide energy usage report (per device & total), and simulated “what-if” scenarios (e.g., change thermostat by 2°C). 
* Implement rule engine: rules are stored as structures that include condition codes and action pointers; evaluate rules each cycle using functions. 
* Use pointers to link schedules and devices, dynamic memory (malloc, realloc) for variable device list, string handling for names, loops for periodic evaluation, and decision constructs for rules. 
* Optional extension: persist configuration to file and load at startup. 
Syllabus topics applied: Problem solving & flowchart, I/O, decision statements, loops, arrays & dynamic arrays, functions, structures, pointers, dynamic memory, file I/O. 
CO mapping: 
* CO1 : design rule flowcharts and algorithms; 
* CO2 : apply C basics for condition checks, I/O, and scheduling logic; 
* CO3 : use arrays/functions for device lists and reporting; 
* CO4 : use pointers for schedule linking and dynamic device lists; 
* CO5 : design a modular system combining all syllabus topics. 

