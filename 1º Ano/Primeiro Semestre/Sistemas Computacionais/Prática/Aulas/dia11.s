0 -> Aberto (Utilizamos o AND, ANDI)
1 -> Fechado (Utilizamos o OR, ORI)

P -> 7 6 5 4 3 2 1 0
V -> 1 1 0 1 1 1 1 0
M -> 1 1 1 1 1 0 1 1

0xDE

AND -> Porta para 0
Exemplo:
	
	P -> 1 1 0 1 1 1 1 0
	M -> 1 1 1 1 1 0 1 1
	
	  -> 1 1 0 1 1 0 1 0
	
	AND r1,r2,r3
	
	ANDI r1,r2,0xFB
	

M -> 0 1 1 1	1 1 1 1
		7		   F

Fechar a porta 5:
(Vamos utilizar o OR)

	P -> 1 1 0 1 	1 0 1 0
	M -> 0 0 1 0 	0 0 0 0
			2		   0
	
	  -> 1 1 1 1 1 0 1 0
	  
	OR r1,r1,r3
	ORI r1,r1,0x20
	
Porta 0 com valor 1:
	
	P -> 1 1 0 1 	1 0 1 0
	M -> 0 0 0 0 	0 0 0 1
			0          1
			
	  -> 1 1 0 1 1 0 1 1
	  
	ORI r1,r1,0x01
	
Alterar estado porta 1 e 2:
(Vamos utilizar o XOR, XORI)

	P -> 1 1 0 1	1 0 1 0
	M -> 0 0 0 0	0 1 1 0
			0          6
	
	  -> 1 1 0 1    1 x 1 0
	  
	 XORI r1,r1,0x06
	 
Alterar estado porta 7 e 6:
(Vamos utilizar o XOR, XORI)

	P -> 1 1 0 1	1 0 1 0
	M -> 1 1 0 0	0 0 0 0
		   12          0
	
	  -> 1 1 0 1    1 0 1 0
	  
	 XORI r1,r1,0xC0
	 

//////////////////////////////////////////////


0 -> passou
1 -> reprovou

Quero reprovar o aluno 6 e 0.

P -> 1 1 0 1	1 0 1 0
M -> 0 1 0 0    0 0 0 1
        4          1

ORI r6,r6 0x41

;AND -> Passar bits a 0
;OR -> Passar bits a 1
;XOR -> Alterar bits (contrario)
			
