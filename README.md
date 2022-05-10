# SFMLEngine - SFMLGameEngine   
My Game Engine that has been written on C++ with SFML graphics library  
The architecture of this engine is pretty simular to Unreal Engine 4 architecture  
# Base classes   
## SEngine  
The class that is starting up everything  
## SClass  
The class that describe all the basic functionality  
## SObject   
The class used for creating your own objects  
## SRawObject  
As the class but can not be used in run-time   
## AActor  
Just the basic actor  
## AMode  
Basic mode class. The mode class will stated up when the engine is starting    
## AController  
The class for controlling APawn class  
## APawn  
The class that uses as the pawn actor in engine    