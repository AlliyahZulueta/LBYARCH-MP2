
# LBYARCH MP2 

by: Justin Aganon, Alliyah Zulueta

Specifications: 

![15b7b633-ac47-4b6f-bb07-1c02f7fea431 (1)](https://github.com/user-attachments/assets/f24a6b48-cf20-4c5c-a56c-0e4834c891b4)


### C and x86-64s Screenshots: 
Photo Captured by Justin Aganon:  


![5c6c646a-750d-4517-aaa1-474a8db71e88](https://github.com/user-attachments/assets/fb11b9ac-7877-4e77-b516-dbb0d73780f5)


![080348f4-efac-4bda-89e1-2ee4b5b58b31](https://github.com/user-attachments/assets/f5931b21-3c13-4f98-bd11-7841ac03fd74)


![901aaef7-edaa-4aac-bd13-405a2004a037](https://github.com/user-attachments/assets/ff2f5f95-e73b-455e-be1a-a9387bb65db1)


Photo Captured by: Alliyah Zulueta: 

![141e0cbe-e781-4d55-b14f-a563bf3e6a37](https://github.com/user-attachments/assets/b832a67d-8251-45b6-9414-28dbcc53fcd5)



![4b47f7fd-3968-4bd1-9b78-69c6f3b8a0e2](https://github.com/user-attachments/assets/1716d47c-8881-4b7e-a1d5-fc8af5214bd5)




![f63e4899-ec01-4757-ac32-3b9bc6be9b69](https://github.com/user-attachments/assets/1f95c282-2b7a-426f-afbe-a7a3f27e4c28)



### Comparative Analysis: 

The ASM kernel outperforms the C kernel in all the tests we conducted. While the C kernel is easier to develop and maintain, it is consistently slower due to the program passing through a compiler, while ASM code is directly translated into CPU instructions. Furthermore, the program crashes at 2^30 due to excessive memory demands that exceed system limits. The results also show that the ASM kernel scales more effectively with larger data sizes, making it a superior choice for performance-critical applications, despite its complexity and it being less flexible 

