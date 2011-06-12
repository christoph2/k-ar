@echo off
call unc Can_Irq.c
call unc CanIf.c
call unc CanTrcv_4711_PCA82C250.c
call unc Crc.c
call unc Det.c
call unc Dio.c
call unc Ea.c
call unc Eep.c
call unc Eep_Irq.c
call unc Icu.c
call unc IoHwAb.c
call unc Mcu.c
call unc Mcu_Irq.c
call unc MemIf.c
call unc Port.c
call unc Port_Irq.c
call unc SchM.c
call unc Spi.c
call unc Spi_Irq.c
cd MCAL
call proc
cd ..

