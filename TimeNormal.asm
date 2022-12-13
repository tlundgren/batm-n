PUBLIC TimeNormal

.DATA
scaleNormal QWORD 3f800000H ; scaleNormal = 1.0

.CODE
TimeNormal PROC
PUSH RBP
MOV RBP, RSP
PUSH RBX
MOV RAX, GS:[60h]
MOV RAX, [RAX+10h] ; RAX = ImageBase
ADD RAX, 0e2e474H ; RAX = &timeScale
MOV RBX, scaleNormal; RBX = scaleNormal
MOV [RAX], RBX ; timeScale = scaleNormal
POP RBX
LEAVE
RET
TimeNormal ENDP

END