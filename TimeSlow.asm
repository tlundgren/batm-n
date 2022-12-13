PUBLIC TimeSlow

.DATA
scaleSlow QWORD 3c23d70aH ; scaleSlow = 0.01

.CODE
TimeSlow PROC
PUSH RBP
MOV RBP, RSP
PUSH RBX
MOV RAX, GS:[60h]
MOV RAX, [RAX+10h] ; RAX = ImageBase
ADD RAX, 0e2e474H ; RAX = &timeScale
MOV RBX, scaleSlow ; RBX = scaleSlow
MOV [RAX], RBX ; timeScale = scaleSlow
POP RBX
LEAVE
RET
TimeSlow ENDP

END