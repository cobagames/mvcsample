mvcsample
=========
A short description on the MVC pattern

Controller
Send commands to model to update the model’s state. It can also send commands to it’s associated view to change the views’s presentation of the model.

Model
Notifies it’s associated it’s associated views and controllers when there has been a change in the state. This notification allows the views to produce an updated output and controllers to change the available set of commands.

View
Requests information from the model that it needs for generating an output representation to the user.

This is a simple xcode project to demonstrate the implementation of MVC framework in a cocos2d-x project. 

References:

http://en.wikipedia.org/wiki/Model%E2%80%93view%E2%80%93controller
