section .text
    global compute_distance  



;   xmm0: x1 (first coordinate, x-axis)
;   xmm1: x2 (second coordinate, x-axis)
;   xmm2: y1 (first coordinate, y-axis)
;   xmm3: y2 (second coordinate, y-axis)
; Returns:
;   xmm0: result of sqrt((x1 - x2)^2 + (y1 - y2)^2)

compute_distance:

    subsd xmm0, xmm1         
    mulsd xmm0, xmm0         
    subsd xmm2, xmm3         
    mulsd xmm2, xmm2         
    addsd xmm0, xmm2         
    sqrtsd xmm0, xmm0       

    ret
