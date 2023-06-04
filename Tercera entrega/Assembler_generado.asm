include macros2.asm
include number.asm.MODEL LARGE
.STACK 200h
.386
.DATA

|_87878.6            dd		 |87878.6                      
|_99.                dd		 |99.                          
|_asldk              dd		 sjf                           
|a1                  dd		 |                             
|a3                  dd		 |                             
|b1                  dd		 |                             
|b3                  dd		 |                             
|d2                  dd		 |                             
|p1                  dd		 |                             
|p2                  dd		 |                             
|p3                  dd		 |                             
|variable1           dd		 |                             
_______________________________________________________________________________ dd		 |                             

.CODE
MOV EAX,@DATA
MOV DS,EAX
MOV ES,EAX;


mov ax,4c00h
int 21h
End