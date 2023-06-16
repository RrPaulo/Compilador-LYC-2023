include macros2.asm
include number.asm
.MODEL LARGE
.STACK 200h
.386
.DATA

_.9999                    dd		 .9999                         
_1                        dd		 1                             
_3                        dd		 3                             
_67                       dd		 67                            
_87878.6                  dd		 87878.6                       
_99.                      dd		 99.                           
_asldk  fh sjf            db		 "asldk  fh sjf"               , '$', 14 dup (?)
a1                        dd		 ?                             
a3                        dd		 ?                             
b1                        dd		 ?                             
b3                        dd		 ?                             
d2                        dd		 ?                             
p1                        db		 ?                             , '$', 14 dup (?)
p2                        db		 ?                             , '$', 14 dup (?)
p3                        db		 ?                             , '$', 14 dup (?)
variable1                 dd		 ?                             

.CODE
MOV EAX,@DATA
MOV DS,EAX
MOV ES,EAX;

FLD var16
FLD id
FXCH
FCOM
FSTSW AX
SAHF
FFREE
JAE [28]
FLD d1
FLD c4
FXCH
FCOM
FSTSW AX
SAHF
FFREE
JNE [28]
FLD 3
FLD var2
FXCH
FADD
FSTP var1
JMP [37]
FLD j
FLD id
FXCH
FCOM
FSTSW AX
SAHF
FFREE
JNE [37]
FLD 3
FLD var2
FXCH
FADD
FSTP var1
FSTP 67
FSTP 87878.6
FSTP 99.
FSTP .9999
FSTP "asldk
FSTP a
FLD b
FLD a
FXCH
FCOM
FSTSW AX
SAHF
FFREE
JNA [67]
FLD 1
FLD a
FXCH
FADD
FLD a
FLD WRITE
FXCH
FADD
JMP [54]

mov ax,4c00h
int 21h
End