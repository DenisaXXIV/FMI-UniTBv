.model small 
.stack 10 
.data    
mesaj db 'Hello, world!$' 
.code 
start:      
; iniializarea registrului DS     
mov ax, @data     
mov ds, ax     
; mut în DX adresa de început a datei mesaj     
mov dx, offset mesaj     
; scrie pe ecran coninutul registrului DX, pân la caracterul $    
 mov ah, 9    
 int 21h    
 ; revenirea în DOS   
  mov ax, 4c00h  
   int 21h 
end start