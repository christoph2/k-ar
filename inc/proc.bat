@echo off
call unc AAL_HC12.h
call unc AAL_S12.h
call unc AR_ModuleIDs.h
call unc Cal.h
call unc Can.h
call unc Can_Irq.h
call unc CanIf.h
call unc CanTrcv_4711_PCA82C250.h
call unc ComStack_Types.h
call unc Crc.h
call unc Dem.h
call unc Dem_IntErrId.h
call unc Det.h
call unc Dio.h
call unc Dio_Cbk.h
call unc Ea.h
call unc EcuM.h
call unc Eep.h
call unc Eep_Cbk.h
call unc Gpt.h
call unc Icu.h
call unc IoHwAb.h
call unc IoHwAb_Cbk.h
call unc IoHwAb_Types.h
call unc K_Ar.h
call unc Mcu.h
call unc Mcu_Cbk.h
call unc MemIf.h
call unc MemIf_Types.h
call unc MemMap.h
call unc Module_IDs.h
call unc Port.h
call unc Port_Cbk.h
call unc Pwm.h
call unc Rte.h
call unc SchedM_Spi.h
call unc SchM.h
call unc SchM_Dio.h
call unc SchM_Eep.h
call unc SchM_Mcu.h
call unc SchM_Port.h
call unc Spi.h
cd cpu12
call proc
cd ..
