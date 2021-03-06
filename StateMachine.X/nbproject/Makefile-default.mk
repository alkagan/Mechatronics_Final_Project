#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/StateMachine.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/StateMachine.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=C:/CMPE118/src/AD.c C:/CMPE118/src/BOARD.c C:/CMPE118/src/IO_Ports.c C:/CMPE118/src/LED.c C:/CMPE118/src/pwm.c C:/CMPE118/src/serial.c C:/CMPE118/src/timers.c "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/BeaconEventChecker.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/BumpEventChecker.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/CornerTapeEventChecker.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_CheckEvents.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Framework.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_KeyboardInput.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Main.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_PostList.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Queue.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_TattleTale.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Timers.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/RC_Servo.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/RenShipTapeEventChecker.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubEngagingHSM.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubOrientationHSM.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubSearchingHSM.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TapeEventChecker.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TopLevelHSM.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TrackWireEventChecker.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/motor_drivers.c" "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/pin_configuration.c"

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/331920610/AD.o ${OBJECTDIR}/_ext/331920610/BOARD.o ${OBJECTDIR}/_ext/331920610/IO_Ports.o ${OBJECTDIR}/_ext/331920610/LED.o ${OBJECTDIR}/_ext/331920610/pwm.o ${OBJECTDIR}/_ext/331920610/serial.o ${OBJECTDIR}/_ext/331920610/timers.o ${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o ${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o ${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o ${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o ${OBJECTDIR}/_ext/1592784148/ES_Framework.o ${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o ${OBJECTDIR}/_ext/1592784148/ES_Main.o ${OBJECTDIR}/_ext/1592784148/ES_PostList.o ${OBJECTDIR}/_ext/1592784148/ES_Queue.o ${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o ${OBJECTDIR}/_ext/1592784148/ES_Timers.o ${OBJECTDIR}/_ext/1592784148/RC_Servo.o ${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o ${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o ${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o ${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o ${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o ${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o ${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o ${OBJECTDIR}/_ext/1592784148/motor_drivers.o ${OBJECTDIR}/_ext/1592784148/pin_configuration.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/331920610/AD.o.d ${OBJECTDIR}/_ext/331920610/BOARD.o.d ${OBJECTDIR}/_ext/331920610/IO_Ports.o.d ${OBJECTDIR}/_ext/331920610/LED.o.d ${OBJECTDIR}/_ext/331920610/pwm.o.d ${OBJECTDIR}/_ext/331920610/serial.o.d ${OBJECTDIR}/_ext/331920610/timers.o.d ${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o.d ${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o.d ${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o.d ${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o.d ${OBJECTDIR}/_ext/1592784148/ES_Framework.o.d ${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o.d ${OBJECTDIR}/_ext/1592784148/ES_Main.o.d ${OBJECTDIR}/_ext/1592784148/ES_PostList.o.d ${OBJECTDIR}/_ext/1592784148/ES_Queue.o.d ${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o.d ${OBJECTDIR}/_ext/1592784148/ES_Timers.o.d ${OBJECTDIR}/_ext/1592784148/RC_Servo.o.d ${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o.d ${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o.d ${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o.d ${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o.d ${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o.d ${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o.d ${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o.d ${OBJECTDIR}/_ext/1592784148/motor_drivers.o.d ${OBJECTDIR}/_ext/1592784148/pin_configuration.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/331920610/AD.o ${OBJECTDIR}/_ext/331920610/BOARD.o ${OBJECTDIR}/_ext/331920610/IO_Ports.o ${OBJECTDIR}/_ext/331920610/LED.o ${OBJECTDIR}/_ext/331920610/pwm.o ${OBJECTDIR}/_ext/331920610/serial.o ${OBJECTDIR}/_ext/331920610/timers.o ${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o ${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o ${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o ${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o ${OBJECTDIR}/_ext/1592784148/ES_Framework.o ${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o ${OBJECTDIR}/_ext/1592784148/ES_Main.o ${OBJECTDIR}/_ext/1592784148/ES_PostList.o ${OBJECTDIR}/_ext/1592784148/ES_Queue.o ${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o ${OBJECTDIR}/_ext/1592784148/ES_Timers.o ${OBJECTDIR}/_ext/1592784148/RC_Servo.o ${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o ${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o ${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o ${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o ${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o ${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o ${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o ${OBJECTDIR}/_ext/1592784148/motor_drivers.o ${OBJECTDIR}/_ext/1592784148/pin_configuration.o

# Source Files
SOURCEFILES=C:/CMPE118/src/AD.c C:/CMPE118/src/BOARD.c C:/CMPE118/src/IO_Ports.c C:/CMPE118/src/LED.c C:/CMPE118/src/pwm.c C:/CMPE118/src/serial.c C:/CMPE118/src/timers.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/BeaconEventChecker.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/BumpEventChecker.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/CornerTapeEventChecker.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_CheckEvents.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Framework.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_KeyboardInput.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Main.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_PostList.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Queue.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_TattleTale.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Timers.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/RC_Servo.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/RenShipTapeEventChecker.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubEngagingHSM.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubOrientationHSM.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubSearchingHSM.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TapeEventChecker.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TopLevelHSM.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TrackWireEventChecker.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/motor_drivers.c C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/pin_configuration.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/StateMachine.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=,--script="C:\CMPE118\bootloader320.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/331920610/AD.o: C:/CMPE118/src/AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/AD.o.d" -o ${OBJECTDIR}/_ext/331920610/AD.o C:/CMPE118/src/AD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/BOARD.o: C:/CMPE118/src/BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/BOARD.o.d" -o ${OBJECTDIR}/_ext/331920610/BOARD.o C:/CMPE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/IO_Ports.o: C:/CMPE118/src/IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/331920610/IO_Ports.o C:/CMPE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/LED.o: C:/CMPE118/src/LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/LED.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/LED.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/LED.o.d" -o ${OBJECTDIR}/_ext/331920610/LED.o C:/CMPE118/src/LED.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/pwm.o: C:/CMPE118/src/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/pwm.o.d" -o ${OBJECTDIR}/_ext/331920610/pwm.o C:/CMPE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/serial.o: C:/CMPE118/src/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/serial.o.d" -o ${OBJECTDIR}/_ext/331920610/serial.o C:/CMPE118/src/serial.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/timers.o: C:/CMPE118/src/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/timers.o.d" -o ${OBJECTDIR}/_ext/331920610/timers.o C:/CMPE118/src/timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/BeaconEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/BeaconEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/BumpEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/BumpEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/CornerTapeEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/CornerTapeEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_CheckEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_CheckEvents.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_Framework.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_Framework.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Framework.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_KeyboardInput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_KeyboardInput.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_Main.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_Main.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_Main.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Main.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_PostList.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_PostList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_PostList.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_PostList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_PostList.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_PostList.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_Queue.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_Queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_Queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_Queue.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Queue.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_TattleTale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_TattleTale.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_Timers.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_Timers.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Timers.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/RC_Servo.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/1592784148/RC_Servo.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/RC_Servo.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/RenShipTapeEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/RenShipTapeEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/SubEngagingHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o.d" -o ${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubEngagingHSM.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/SubOrientationHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o.d" -o ${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubOrientationHSM.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/SubSearchingHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o.d" -o ${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubSearchingHSM.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/TapeEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TapeEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/TopLevelHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o.d" -o ${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TopLevelHSM.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/TrackWireEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TrackWireEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/motor_drivers.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/motor_drivers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/motor_drivers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/motor_drivers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/motor_drivers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/motor_drivers.o.d" -o ${OBJECTDIR}/_ext/1592784148/motor_drivers.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/motor_drivers.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/pin_configuration.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/pin_configuration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/pin_configuration.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/pin_configuration.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/pin_configuration.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -DPICkit3PlatformTool=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/pin_configuration.o.d" -o ${OBJECTDIR}/_ext/1592784148/pin_configuration.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/pin_configuration.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/331920610/AD.o: C:/CMPE118/src/AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/AD.o.d" -o ${OBJECTDIR}/_ext/331920610/AD.o C:/CMPE118/src/AD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/BOARD.o: C:/CMPE118/src/BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/BOARD.o.d" -o ${OBJECTDIR}/_ext/331920610/BOARD.o C:/CMPE118/src/BOARD.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/IO_Ports.o: C:/CMPE118/src/IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/IO_Ports.o.d" -o ${OBJECTDIR}/_ext/331920610/IO_Ports.o C:/CMPE118/src/IO_Ports.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/LED.o: C:/CMPE118/src/LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/LED.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/LED.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/LED.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/LED.o.d" -o ${OBJECTDIR}/_ext/331920610/LED.o C:/CMPE118/src/LED.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/pwm.o: C:/CMPE118/src/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/pwm.o.d" -o ${OBJECTDIR}/_ext/331920610/pwm.o C:/CMPE118/src/pwm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/serial.o: C:/CMPE118/src/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/serial.o.d" -o ${OBJECTDIR}/_ext/331920610/serial.o C:/CMPE118/src/serial.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/331920610/timers.o: C:/CMPE118/src/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/331920610" 
	@${RM} ${OBJECTDIR}/_ext/331920610/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/331920610/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/331920610/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/331920610/timers.o.d" -o ${OBJECTDIR}/_ext/331920610/timers.o C:/CMPE118/src/timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/BeaconEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/BeaconEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/BeaconEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/BumpEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/BumpEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/BumpEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/CornerTapeEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/CornerTapeEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/CornerTapeEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_CheckEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_CheckEvents.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_CheckEvents.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_Framework.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_Framework.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_Framework.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Framework.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_KeyboardInput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_KeyboardInput.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_KeyboardInput.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_Main.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_Main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_Main.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_Main.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Main.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_PostList.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_PostList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_PostList.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_PostList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_PostList.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_PostList.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_PostList.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_Queue.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_Queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_Queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_Queue.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_Queue.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Queue.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_TattleTale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_TattleTale.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_TattleTale.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/ES_Timers.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/ES_Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/ES_Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/ES_Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/ES_Timers.o.d" -o ${OBJECTDIR}/_ext/1592784148/ES_Timers.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/ES_Timers.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/RC_Servo.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/RC_Servo.o.d" -o ${OBJECTDIR}/_ext/1592784148/RC_Servo.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/RC_Servo.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/RenShipTapeEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/RenShipTapeEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/RenShipTapeEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/SubEngagingHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o.d" -o ${OBJECTDIR}/_ext/1592784148/SubEngagingHSM.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubEngagingHSM.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/SubOrientationHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o.d" -o ${OBJECTDIR}/_ext/1592784148/SubOrientationHSM.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubOrientationHSM.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/SubSearchingHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o.d" -o ${OBJECTDIR}/_ext/1592784148/SubSearchingHSM.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/SubSearchingHSM.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/TapeEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/TapeEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TapeEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/TopLevelHSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o.d" -o ${OBJECTDIR}/_ext/1592784148/TopLevelHSM.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TopLevelHSM.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/TrackWireEventChecker.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o.d" -o ${OBJECTDIR}/_ext/1592784148/TrackWireEventChecker.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/TrackWireEventChecker.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/motor_drivers.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/motor_drivers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/motor_drivers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/motor_drivers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/motor_drivers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/motor_drivers.o.d" -o ${OBJECTDIR}/_ext/1592784148/motor_drivers.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/motor_drivers.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1592784148/pin_configuration.o: C:/Users/Alex/Git\ Repos/Mechatronics_Final_Project/StateMachine.X/pin_configuration.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1592784148" 
	@${RM} ${OBJECTDIR}/_ext/1592784148/pin_configuration.o.d 
	@${RM} ${OBJECTDIR}/_ext/1592784148/pin_configuration.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1592784148/pin_configuration.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"." -I"C:/CMPE118/include" -MMD -MF "${OBJECTDIR}/_ext/1592784148/pin_configuration.o.d" -o ${OBJECTDIR}/_ext/1592784148/pin_configuration.o "C:/Users/Alex/Git Repos/Mechatronics_Final_Project/StateMachine.X/pin_configuration.c"    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/StateMachine.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    C:/CMPE118/bootloader320.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -DPICkit3PlatformTool=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/StateMachine.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=PICkit3PlatformTool=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/StateMachine.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   C:/CMPE118/bootloader320.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/StateMachine.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/StateMachine.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
