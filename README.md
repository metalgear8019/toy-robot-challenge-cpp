# toy-robot-challenge
C++ Technical Challenge
## Table of Contents  
* [Description and requirements](#description)  
* [Constraints](#constraints) 
* [Approach](#approach)
* [Prerequisite and Instructions](#prerequisite)   
* [Example](#example)  


<a name="description"/>

## Description and Requirements
* The application is a simulation of a toy robot moving on a square table top, of dimensions 5 units x 5 units.
* There are no other obstructions on the table surface.
* The robot is free to roam around the surface of the table, but must be prevented from falling to destruction.
* Any movement that would result in the robot falling from the table must be prevented, however further valid movement commands must still be allowed.

Commands available in this console:

* `PLACE X,Y,F`
* `MOVE`
* `LEFT`
* `RIGHT`
* `REPORT`

## Constraints
* The toy robot must not fall off the table during movement. This also includes the initial placement of the toy robot.
* Any move that would cause the robot to fall must be ignored.

### Visualization
To visualize the robot movement and starting point please see reference below:

**PLACE at 0,0,NORTH**<br/>
As you could see we started at the bottom left corner of the table to mark the 0,0(x,y) coordinate<br/>
![0_place](https://user-images.githubusercontent.com/13585907/171349681-9fbae0f6-2255-47ea-be05-2aa77e53e09c.PNG)

**MOVE**<br/>
When MOVE command is entered, we move the robot(bug) to 1 coordinate where the robot(bug) is facing<br/>
![1_move](https://user-images.githubusercontent.com/13585907/171349691-ab8f1205-0914-4c2d-8701-5db7869ba764.PNG)

**LEFT/RIGHT**<br/>
When LEFT/RIGHT command is entered, we move turn the robot(bug) to the left/right.<br/>
![2_left](https://user-images.githubusercontent.com/13585907/171349723-3d81b11e-2df5-4eff-a636-25142e8d2123.PNG)

**REPORT**<br/>
When REPORT command is entered, we get the position of the robot(bug)<br/>
![3_move_report](https://user-images.githubusercontent.com/13585907/171349731-23da5053-7a16-465f-a975-61aa9cfda006.PNG)

<a name="prerequisite"/>

## Prerequisite
* Create and tested using Visual Studio 2017
* Google Test Adapter (installed via Visual Studio 2017)

## Instructions

### Unit Test
1. Clone this repository.
2. Run `ToyRobot.sln` via Visual Studio _(preferrably Visual Studio 2017 or newer)_
3. Rebuild the solution.
4. Open the "Test Explorer" via
5. Run it via "Local Windows Debugger"

### Application
1. Follow same steps as _Unit Test_.
2. Run it via "Local Windows Debugger".

<a name="example"/>

## Example Input and Output
### Example 1
Input
<pre>
PLACE 0,0,NORTH 
MOVE 
REPORT 
</pre>
Output: 
<pre>
0,1,NORTH 
</pre>
### Example #2
Input
<pre>
PLACE 0,0,NORTH 
LEFT 
REPORT 
</pre>
Output: 
<pre>
0,0,WEST 
</pre>
### Example #3
Input
<pre>
PLACE 1,2,EAST 
MOVE 
MOVE 
LEFT 
MOVE 
REPORT 
</pre>
Output: 
<pre>
3,3,NORTH
