/* pfintr.S - pfintr */


    	   .text
pferrcode: .long 0
           .globl  pfintr,pferrcode 
pfintr:
    popl pferrcode
    pushfl
    pushal
    call pfint
    popal
    popfl
    iret

