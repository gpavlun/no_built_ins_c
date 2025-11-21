# makefile for G--
# Version: 1
#
# -Wall turns on all warning messages 
#

G--_Language :  Command_Calls.h Integer_Ops.o Character_Ops.o Input_Output.o G--_Language.o
	gcc  Integer_Ops.o Character_Ops.o Input_Output.o Command_Calls.o G--_Language.o -o  G--_Language

Command_Calls : Command_Calls.c Command_Calls.h
	gcc -c Command_Calls.c

Integer_Ops :  Integer_Ops.c Integer_Ops.h
	gcc -c  Integer_Ops.c

Character_Ops :   Character_Ops.c   Character_Ops.h
	gcc -c   Character_Ops.c

Input_Output :  Input_Output.c Input_Output.h
	gcc -c Input_Output.c

 G--_Language.o :  G--_Language.c Command_Calls.h Integer_Ops.h Character_Ops.h Input_Output.h
	gcc -c  G--_Language.c

clean :
	rm -f *.o  G--_Language
