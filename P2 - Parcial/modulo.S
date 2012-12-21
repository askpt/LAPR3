.global maiorContexto
.global numContexto

#maior Contexto
maiorContexto:
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