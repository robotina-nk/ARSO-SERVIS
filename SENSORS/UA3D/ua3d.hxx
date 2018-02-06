#!/bin/sh
#//**! \header 
#*   Copyright Samuel Tscharmanoff 2016
#*   Project name.: moberl_3000
#*   File.........: ThiesCLima3D.sh
#*   Author.......: (c) Samuel Tscharmanoff
#*   Target / OS..: Nport6450 uc7420Plus, uc8410-LX  / Linux Moxa 2.6.10_devixdp42x-arm_xscale_be  Busybox v1.6.0
#*   Compiler.....: GNU 3.4.4 arm_linuc_gcc C Compiler V3.4.4
#*   Description..: TCP Serial server, Embedded Computer
#*   Version......: 3000.5
#*   Machine......: PC AT compatible, OS: WindowsXP & VitrualBox 3.1.2 ( Linux Ubuntu 9.10 )
#*   Created......: 2016-11
#*   Last update..: 2016-12-09
#**  \endheader */


{#  [I.]  frequently used commnads
	$ setinterface /dev/ttyM0 1		
	$ stty 19200 < /dev/ttyM0
	$ stty -a < /dev/ttyM0 | grep speed
	$ mount -o bind /home/local /usr/local
	$ cat /home/local/etc/minirc.dfl
	$ minicom -s -o -c on dfl
	$ echo -n -e "\$0OPEN\r" > /dev/ttyM0	
	$ while [ 1 ]; do echo -n -e "W3" > /dev/ttyM0; sleep 1; done
	bcer@ub910: $ ssh root@172.19.2.226 'echo  -n -e "OPEN\r" > /dev/ttyM0 &'
	$ cat < /dev/ttyM0 | sed "s/*/*echo -n -e '$6RD\r'/g" 
	
	bcer@ub710~$ printf "PA\r"| nc -w 2 172.19.139.20 2003 | tr -d \r >temp.txt
	bcer@ub910:~$ echo -e -n "get pa\r\n" | nc -w 1 172.19.2.226 6000
	bcer@ub910:~$ echo -e -n "get pa\r\n" | nc -q 1 172.19.2.226 6000
	bcer@ub910:~$ for i in 1 2 3 4 5 6 7 8; do echo -e -n "get ta ch00 10\r\n" | nc -q 1 172.19.2.226 6000 && echo; sleep 1; done
}

{#  [II.] N2-x ttyMx_config (rc.local)
#	SerialPort:		/dev/ttyM0
# 	Interface:	RS485 half dulpex	(1)
#	Protocol:	ASCII_RS485
#	addr:		0
#	baud_rate:	19200		 
#	parity:		none	(-parenb -parodd)
# 	data_bits:	8		(cs8)
#	stop_bits:	1		(-cstopb)
# 	echo:		off		(-echo)	
#
# N2-1 uart_WMT703_config (DEFAULT) COM1
#	Interface	RS485_half duplex
#	Protocol:	ASCII_RS485 (mode:WMT700)
#	addr:		A (set by reset comand)
				x (x= set when configurated)
				0 (general adress)
#	baud_rate:	9600
#	parity:		None
# 	data_bits:	8
#	stop_bits:	1
#	echo:		on	
}

{#  [2.0] Setting Uart Config
printf "00KY00001"| nc -w 2 172.19.7.172 64008 #User access
printf "00BR00005"| nc -w 2 172.19.7.172 64008 #Baud rate to 9600
printf "00KY00001"| nc -w 2 172.19.7.172 64008 #Exit user access
}				

{#  [1.0] Read Sensor Config

# Asking all system parameter / System status
printf "00SS\n"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D

!00AA00000 #Functions for Pin1 - disabled.

!00AB00000 #Functions for Pin4 - disabled.

!00AC00000 #Functions for Pin3 - disabled.

!00AG00000 #Group of analogue output values

!00AM00000 #Average mode: 0 - Vectorially avergaed velocity and vectorially averaged angle

!00AN00002 #Analogue mode 

!00AR00060 #Scaling of analogue output mode (0 - 60 m/s)

!00AU00050 #Update of analogue outputs - 50 ms

!00AV00030 #Averaging time = 3 sec

!00AY00000 #Scales minimum value for analogue output

!00AZ00000 #Scales maximum value for analogue output

!00BL00308 #Softvare versionV 3.08

!00BH00000 #Bavaria Hesse sensor address

!00BP00100 #Pretrigger in burst mode 100 miliseconds

!00BR00005 #BaudRate 9600 8N1

!00BS00100 #Buffer size in burst mode 100

!00BT00000 #Bus terminating resistor disabled

!00BX00005 #BaudRate extension; Here 5 = 9600 8N1

!00BY00000 #Minimum value for analogue output PIN 3

!00BZ00000 #Maximum value for analogue output PIN 3

!00CA59876 #Calibration value for analogue current/voltage output - SLOPE (device dependant)

!00CB01000 #Calibration value for analogue current/voltage output - OFFSET (device dependant)

!00CI00000 #Command interpfreter 0 = Standard Thies

!00CO00001 #Calculation of the turbulence variable is switched ON, no coordinate rotation (1)

!00CY00000 #Minimum value for analogue output PIN 3

!00CZ00000 #Maximum value for analogue output PIN 3

!00DE00001 #Standard Deviation 1= ON

!00DM00002 #Full duplex mode is ON (2)

!00DU19884 #Reserved

!00DV19899 #Reserved

!00DW19899 #Reserved

!00EI00000 #Analogue value in case of error 0=maximum

!00FB00000 #Fast Boot 0 = OFF; Facebook also OFF :)

!00GU00000 #Maximum value in the averaging buffer (gust acquisition)

!00HC00010 #Voltage threshold for Arm and Transducer heating

!00HL00275 #Lower temperature threshold for switching the Arm and Transducer heating = 275 K

!00HH00280 #Higher temperature threshold for switching the Arm and Transducer heating = 280 K

!00HT00001 #Heating control 1 = heating software-controlled by virtual temperature

!00ID00000 #Sensor ID / BUS address

!00MA00013 #Automatic adjustment of measured value acguisition 13 = this interval selected during plausibility check

!00MD00005 "Measuring interval/Measurement delay 5 = 5milisec

!00NC00000 #Correction to north

!00OR01000 #Telegram output interval 1000 = 1000 milisecends

!00OS00000 #Scaling of wind velocity output 0 = m/s

!00PC00007 #Plausibility test

!00PR00048 #Periodic receiver time (Receiver time) unit is 100 nanosec

!00PT00048 #Periodic transmitter time (Receiver time) unit is 100 nanosec

!00RC00559 #Correction factor for analog input values

!00RD00005 #Deleyed response 5 = 5 milisec

!00RF00120 #Restart with invalid measuring values (restart at Fail) 120 = 120 seconds

!00SC00000 #Minimum value of analogue outputs (Start current)

!00SH00716 #Serial number (High word)

!00SL00219 #Serial number (Low word)

!00SM00000 #Reserved

!00SV00312 #Software version

!00TA508052 #Reserved

!00TB00012 #Telegram in burst mode

!00TC00001 #Temperature correction 1 = correction activated

!00TF00001 #Transformer for generating acoustic signals (Transformer)

!00TT00006 #Automatic telegram output 6 = Telegram Nr 6

!00UM00000 #Reserved

!00UN00000 #Reserved

!00VC01088 #Constant velocity correction; Do not change.

!00VM00000 #Reserved

!00VN00002 #Reserved

!00VT00001 #Angle dependant velocity correction 1 = ON

!00WM00000

!00WN00001

!00XI00000 #External ID


# Parameters and commands - page 63 and 64 in the manual Operating Instructions 021507/09/13 Ultrasonic Anemometer 3d 4.383x.xx.xxx V3.12


}

{#  [2.0] Setting Uart Config
printf "00KY00001\r"| nc -w 2 172.19.7.172 64008 #User access
printf "00BR00005\r"| nc -w 2 172.19.7.172 64008 #Baud rate to 9600
printf "00DM00002\r"| nc -w 2 172.19.7.172 64008 #Full duplex mode
printf "00KY00001\r"| nc -w 2 172.19.7.172 64008 #Exit user access                                  
}                                                             

{#  [2.1] Read Uart Config
                telnet 172.19.7.172
                Port 8    
                Baud rate                      : 9600
                Data bits                      : 8
                Stop bits                      : 1  
                Parity                         : None
                Flow control                   : None 
                FIFO                           : Enable
                Interface                      : RS-422
}

{#  [3.0] System Sensor Setup (uart, operating modes)
printf "00KY00001\r" | nc -w 2 172.19.7.172 64008 #Access User mode
printf "00AV00030\r" | nc -w 2 172.19.7.172 64008 #Averaging time 3s
printf "00KY00000\r" | nc -w 2 172.19.7.172 64008 #Exit User Access mode 
}

{# [4.0] Sensor Initialization               
printf "00KY00001\r" | nc -w 2 172.19.7.172 64008 #Access User mode
printf "00CO00001\r" | nc -w 2 172.19.7.172 64008 #Calculation of Covariance ON
printf "00KY00000\r" | nc -w 2 172.19.7.172 64008 #Exit User Access mode 
} 

{# [4.1] Sensor Data Request: polling data from ThiesClima3D
#The user is asking for Telegram 1
printf "00TR00001\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
000.1;024;+000.0;+00;0E;79
#STX(02h)Wind velocity azimuth;Wind direction azymuth;Wind velocity elevation;Wind direction elevation;Thies status hex;Checksum hex CR(ETX)

#The user is asking for Telegram 2
printf "00TR00002\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
000.0;000;+000.0;+00;+22.0;0E;70
#STX(02h)Wind velocity azimuth;Wind direction azymuth;Wind velocity elevation;Wind direction elevation;Acoustic virtual temperature;Thies status hex;Checksum hex CR(ETX)


#The user is asking for Telegram 3
printf "00TR00003\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
000.0;000;+000.0;+22.0;0E;60
#STX(02h)Wind velocity azimuth;Wind direction azymuth;Wind velocity elevation;Acoustic wind temperature;Thies status hex;Checksum hex CR(ETX)


#The user is asking for Telegram 4
printf "00TR00004\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
$WIMWV,000.0,R,000.0,M,A*20
#Fixed text "$WIMWv";Wind velocity azimuth,Wind direction azymuth,R,K or N or M or S scaling dependant,V (invalid) or A (valid), Check sum identifier (2Ah) CR LF


#The user is asking for Telegram 5
printf "00TR00005\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
+000.01;-000.02;-000.01;+22.0;0E;4C
#STX(02h)Wind velocity X component;Wind velocity Y component;Wind velocity Z component;Acoustic virtual temperature;Thies status;Checksum hex CR(ETX)


#The user is asking for Telegram 6 (User defined)
printf "00TR00006\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
#Depends on User telegram settings


#The user is asking for Telegram 7
printf "00TR00007\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
+000.01;-000.03;-000.02;+22.06;000.00;000.00;000.01;00.01;0E;48
#Wind velocity X component;Wind velocity Y component;Wind velocity Z component;Standard deviation X component;Standard deviation X component;Standard deviation Y component;Standard deviation Z component;Standard deviation acoustic temperature;Thies status;Checksum hex;CR
                               

#The user is asking for Telegram 8
printf "00TR00008\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
+000.01;-000.03;-000.02;+22.01;+000.00;+000.00;+000.00;+000.00;+000.00;+000.00;0E;7F
#Wind velocity X component;Wind velocity Y component;Wind velocity Z component;Acoustic virtual temperature;Covariance XY;Covariance XZ;Covariance XT;Covariance YZ;Covariance YT;Covariance XY;Covariance ZT;Thies status;Checksum hex CR


#The user is asking for Telegram 9
printf "00TR00009\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
+000.02;-000.04;-000.02;+22.06;000.06;000.05;000.09;0E;53
#Wind velocity X component;Wind velocity Y component;Wind velocity Z component;Acoustic virtual temperature;Turbulence intensitiy X component;Turbulence intensitiy Y component;Turbulence intensitiy Z component;Thies status;Checksum hex CR


#The user is asking for Telegram 12 (Scientific diagnostic telegram)
printf "00TR000012\r"| nc -w 2 172.19.7.172 64008

# Reply from ThiesClima3D
000.06;352.3;-000.03;+00.0;VT:+022.13;000.07;VX:+000.01;-000.06;-000.03;TU:+22.38;+21.92;+22.09;23081;23083;23119;23117;23108;23115;00000;00030;00101;0E;0F00;004928775
#Wind velocity azimuth;Wind direction azymuth;Wind velocity elevation;Wind direction elevation (9..90);Fixet text "VT";Acoustic virtual temperature;Wind velocity (XYZ);Wind velocity X component;Wind velocity Y component;Wind velocity Z component;Fixed text "TU";Acoustic virtual temperature U component;Acoustic virtual temperature V component;Acoustic virtual temperature W component;Delay of distance U top down CUBT;Delay of distance U bottom up CUBT;Delay of distance V top down CUBT;Delay of distance V bottom up CUBT;Delay of distance W top down CUBT;Delay of distance W bottom up CUBT;Internal counter;Time interval in which values are written to main averaging memory;Number of values in main averaging memory;Thies status;Telegram status EXTENDED status information;Internal tickcount in ms of procesor CR LF
                               
}

{# [5.0] Set Sensor Bus Address                                              
printf "00KY00001\r" | nc -w 2 172.19.7.172 64008 #Access User mode
printf "00ID00000\r" | nc -w 2 172.19.7.172 64008 #Set ID / Bus address to 00
printf "00KY00000\r" | nc -w 2 172.19.7.172 64008 #Exit User Access mode 
}

{# [6.0] Setting the Sensor Period Output Report Interval 
# Setting the transmit telegram time to 10 sec  (10 000 milisec)                        
printf "00KY00001\r" | nc -w 2 172.19.7.172 64008 #Access User mode
printf "00OR10000\r" | nc -w 2 172.19.7.172 64008 #Set output telegram to 10 sec
printf "00KY00000\r" | nc -w 2 172.19.7.172 64008 #Exit User Access mode    
}

{# [7.0] Defining Sesnor Output Format  
 - /          
}


