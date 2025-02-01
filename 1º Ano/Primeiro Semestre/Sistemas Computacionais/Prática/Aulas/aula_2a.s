	.data
	A:	.word 10
	B:	.word 8

	
		.text
		ld r4, A(r0)
		ld r5, B(r0)
		
		sd r4, B(r0)
		sd r5, A(r0)
		halt;