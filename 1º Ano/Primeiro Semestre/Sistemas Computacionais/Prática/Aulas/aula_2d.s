	.data
	CR: .word32 0x10000
	DR: .word32 0x10008
	
		.text
		ld r1,CR(r0)
		ld r2,DR(r0)

		daddi r3, r0,8
		sd r3, (r1)
		ld r4,(r2)
		
		daddi r3, r0,8
		sd r3, (r1)
		ld r5, (r2)
		
		dadd r6, r4,r5
		
		daddi r10, r0,2
		sd r6, (r2)
		sd r10,(r1)
		
		halt;