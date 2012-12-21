.global maiorContexto
.global numContexto
.global mostraContexto
.global numPrio

#maior Contexto
maiorContexto:
	pushl %ebp
	movl %esp, %ebp

	movl 8(%ebp), %ebx #ptr struct
	movl 12(%ebp), %ecx #tam struct
	movl 16(%ebp), %eax #tamanho ptr
	movl 20(%ebp), %edx #prio a comparar
	

	addl $8, %ebx

	movl $32, %ecx
	movl (%ebx), %esi
	movl $0, %eax
	movl $1, %edi

ciclo:
	
	movl %esi, %edx
	andl $1, %edx
	cmpl $1, %edx
	jne naoIgual
	movl %edi, %eax

naoIgual:
	incl %edi
	rorl %esi
	loop ciclo

	movl %ebp, %esp
	popl %ebp

	ret

#Numero de contextos
numContexto:
	pushl %ebp
	movl %esp, %ebp

	movl $0, %edx
	movl 8(%ebp), %ebx #ptr struct
	movl 12(%ebp), %ecx #tam struct
	movl 16(%ebp), %eax #pos

	imull %ecx #valor a avancar = tam*pos
	addl %eax, %ebx #posicao na struct

	addl $8, %ebx

	movl $32, %ecx
	movl (%ebx), %esi
	movl $0, %eax
	movl $0, %edi

cic:
	
	movl %esi, %edx
	andl $1, %edx
	cmpl $1, %edx
	jne naoIg
	incl %eax

naoIg:
	incl %edi
	rorl %esi
	loop cic

	movl %ebp, %esp
	popl %ebp

	ret

#mostra os contextos
mostraContexto:
	pushl %ebp
	movl %esp, %ebp

	movl $0, %edx
	movl 8(%ebp), %ebx #ptr struct
	movl 12(%ebp), %ecx #tam struct
	movl 16(%ebp), %eax #pos
	movl 20(%ebp), %edi #ptr vect

	imull %ecx #valor a avancar = tam*pos
	addl %eax, %ebx #posicao na struct

	addl $8, %ebx

	movl $32, %ecx
	movl (%ebx), %esi
	movl $0, %eax

cic2:
	incl %eax	
	movl %esi, %edx
	andl $1, %edx
	cmpl $1, %edx
	jne notEq
	movl %eax, (%edi)
	addl $4, %edi

notEq:
	rorl %esi
	loop cic2

	movl %ebp, %esp
	popl %ebp

	ret

#numero de prioridades
numPrio:
	pushl %ebp
	movl %esp, %ebp

	movl $0, %eax
	movl 8(%ebp), %ebx #ptr struct
	movl 12(%ebp), %edi #tamanho struct
	movl 16(%ebp), %ecx #tam array
	movl 20(%ebp), %edx #prioridade

	addl $4, %ebx #percorrer só as prioridades

ciclo2:
	movl (%ebx), %esi
	cmpl %edx, %esi
	jne notEquals
	incl %eax

notEquals:
	addl %edi, %ebx

	loop ciclo2

	movl %ebp, %esp
	popl %ebp

	ret