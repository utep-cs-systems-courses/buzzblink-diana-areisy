	.arch msp430g2553
  	.p2align 1,0
  	
	.text
sw:	.word case0 ; define switch
	.word case1
	.word case2
	.word case3
    
	.global state_advance; method
	.extern switchSM ; variable
    
state_advance:
	cmp &switchSM, #4 ; if switchSm > 4 jump to end
	jnc end
	mov &switchSM, r12 ; move sw[switchSM] to r12
	add r12, r12
	mov sw(r12), r0
case0:
	call #btn_one
	jmp end
case1:
	call #btn_two
	jmp end
case2:
	call #btn_tree
	jmp end
case3:
	call #btn_four
	jmp end
end:
	pop r0
    
