#!/bin/sh
#/**! \header 
#*   Copyright bcer 2009
#*   Project name.: moberl_3000
#*   File.........: smp11.sh
#*   Author.......: (c) Bojan Cernac - bcer
#*   Target / OS..: Nport6450 uc7420Plus, uc8410-LX  / Linux Moxa 2.6.10_devixdp42x-arm_xscale_be  Busybox v1.6.0
#*   Compiler.....: GNU 3.4.4 arm_linuc_gcc C Compiler V3.4.4
#*   Description..: TCP Serial server, Embedded Computer
#*   Version......: 3000.5
#*   Machine......: PC AT compatible, OS: WindowsXP & VitrualBox 3.1.2 ( Linux Ubuntu 9.10 )
#*   Created......: 2009-25 (avgust)
#*   Last update..: 2012-02-02
#**  \endheader */#!/bin/sh


{#  [I.]  frequently used commnads smp11
}



{#  [II.] P034 uart_Nport6450_config (DEFAULT)
#	SerialPort:	/dev/tcp/172.19.33.131/4005
# 	Interface:	RS485	(0)
#	Protocol:	MB-RTU_RS485
#	addr:		0
#	baud_rate:	19200
#	parity:		even	( parenb -parodd)
# 	data_bits:	8		(cs8)
#	stop_bits:	1		(-cstopb)
# 	echo:		off		(-echo)
#
# P034 uart_smp11_config (DEFAULT)
#	Interface	RS485
#	Protocol:	MB-RTU_RS485
#	addr:		0
#	baud_rate:	19200
#	parity:		even
# 	data_bits:	8
#	stop_bits:	1
#	echo:		off
#
#
# P034 uart_smp11_config (bcer=DEFAULT)
#	Interface	RS485C
#	Protocol:	MB-RTU_RS485
#	addr:		0
#	baud_rate:	19200
#	parity:		even
# 	data_bits:	8
#	stop_bits:	1
#	echo:		off	
#
}



{#  [1.0] Read Sensor Config

}



{#  [2.0] Setting Uart Config

}				



{# [3.0] System Sensor Setup (uart, operating modes) 

}  	

			
  
{#  [4.0] Sensor Initialization
}

{#  [4.0N] Sensor Initialization
	{WIRING:
		(Sensor<->Dose_B3-5): PE-PE, 
					5(yellow/RS485+), 
					  6(gray/RS485-), 
					    1(black/GND), 
					7(white/5-30VDC)	
	}

	{mbclient TOOL - modbus communication testing:
		ssh root@172.19.7.170
		root@Moxa:/var/sda# ./mbclient -h
		mbclient help:
		
		Usage: mbclient [options] MB_PROTOCOL DEV_ADDR MB_FUNCODE [REG_DATA] REG_ADDR REG_NUM DEV_COMM
		
		  MB_PROTOCOL: modbus protocol
		               supported protocols: rtu, ascii, tcp
		
		  DEV_ADDR:    address of device on communication line
		               address formats: decimal (1) & hexadecimal (0x01)
		
		  MB_FUNCODE:  function code
		               code formats: decimal (4) & hexadecimal (0x04)
		               supported codes:
		                 0x01 - read coils
		                 0x02 - read discrete inputs
		                 0x03 - read holding registers
		                 0x04 - read input registers
		                 0x05 - write single coil
		                 0x06 - write single register
		                 0x0F - write multiple coils
		                 0x10 - write multiple registers
		
		 [REG_DATA]:   data to be written to registers
		               Data must be in HEXADECIMAL format! Leading '0x' is optional
		
		  REG_ADDR:    start address of register
		               address formats: decimal (0) & hexadecimal (0x00)
		
		  REG_NUM:     number of register to read
		               formats: decimal (14) & hexadecimal (0x0E)
		
		  DEV_COMM:    communication device to send to
		               Serial: /dev/ttyS0 RS232 [RS232, RS485-2W, RS485-4W, RS422]
		               TCP: /dev/tcp/172.19.0.1/508
		               UDP: /dev/udp/172.19.0.1/508
		
		OPTIONS
		
		  -t  timeout
		               timeout in seconds
		  -h           print this help
		  -v           print version
		
		EXAMPLES
		
		  Read 18 input registers starting at address 0:
		    ./mbclient rtu 1 4 0 18 /dev/tcp/172.19.7.142/64008
		  Expected reply:
		    Read 18 input register(s):
		     0261 0066 0001 0000 0000 FFF5 FFF5 0000 00F9 00F5 01B4 01B4 0000 7474 0000 0000 1116 0005
		
		  Read 22 holding registers starting at address 0:
		    ./mbclient tcp 1 3 0 22 /dev/tcp/172.19.142.100/502
		  Expected reply:
		    Read 22 holding register(s):
		     0000 0000 0000 410C 3EDE 0000 0000 0000 0000 0000 0000 3F80 0000 3F80 0000 4952 3136 3239 3534 3200 0000 0000
		
		  Write '00FF0003000F' to 3 registers starting at address 1000:
		    ./mbclient ascii 0x0B 0x10 00FF0003000F 1000 3 /dev/ttyS2 RS485-2W
		  Expected reply:
		    Successfully written to registers
		
		  Read 3 holding registers starting at address 1000:
		    ./mbclient ascii 0x0B 0x03 1000 3 /dev/ttyS2 RS485-2W
		  Expected reply:
		    Read 3 holding register(s):
		     00FF 0003 000F
	}

	{Sendor reading(checking) with mbclient 
		root@Moxa:/var/sda# ./mbclient rtu 01 04 2 8 /dev/tcp/172.19.7.137/64008
		Read 8 input register(s):
		0001 0008 0000 0000 0000 0000 00E7 00F4
	}

	{Cheching the correct syntax for sending hexadecimal values
		ssh root@172.19.7.165 ########## postaja katera že komunicira po protokolu MODBUS-RTU  ##########
		root@Moxa:/var/sda/amws/smp11d# cat smp11d.log | grep DevicePoll | tail
		2017-10-03;11:47:20.055;(105);DEVICE[0x1];MBSerial_DevicePoll: Tx = '\x01\x04\x00\x00\x00\x12\x70\x07',
		2017-10-03;11:47:20.132;(106);DEVICE[0x1];MBSerial_DevicePoll: Rx = '\x01\x04\x24\x02\x5B\x00\x64\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\xE5\x00\xF2\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x73\x00\x03\x0A\xAE',
		...
	}

	{Listening using cat < dev/tcp, or netcat
		ssh root@172.19.7.135
		#REQUEST: 
		echo -n -e "\x01\x04\x00\x02\x00\x08\x50\x0C" | nc -w 2 172.19.7.137 64008
					01 - modbus address
						04 - function for reading input registers
							00  02 - starting address
									00  08 - number of requested registers
											50  0C - calculated CRC code

		#LISTEN                                                                    LISTEN																
		nc -k 172.19.7.137 64008													cat < /dev/tcp/172.19.7.137/64008 
		#ANSWER																		ANSWER
		▒:																			▒:

		#LISTEN with hexdump														LISTEN with hexdump
		nc -k 172.19.7.137 64008 | hd												cat < /dev/tcp/172.19.7.137/64008 | hd
		ANSWER																		ANSWER
		0000000 0401 0010 0001 0008 0000 0000 0000 0000							0000000 0401 0010 0001 0008 0000 0000 0000 0000
		#LISTEN with hexdump with redirection to file
		cat < /dev/tcp/172.19.7.137/64008 > /tmp/testmodbus.txt
		CTRL+C
		cat /tmp/testmodbus.txt | hd
		0000000 0401 0010 0001 0008 0000 0000 0000 0000
		0000010 00e7 3af4 00d4
		0000015

		#HANDLING ENDIANNESS
		0401 0010 0001 0008 0000 0000 0000 0000 00e7 3af4 00d4
		0104 1000 0100 0800 0000 0000 0000 0000 e700 f43a d400
		01 04 10 00 01 00 08 00 00 00 00 00 00 00 00 00 e7 00 f4 3a d4 00

		01 	- MODBUS address
		04 	- read input registers
		10 	- number of received data bytes [DEC:16]
		00 01 	- IO_OPERATIONAL_MODE			[DEC:1(mode 1)]
		00 08 	- IO_STATUS_FLAGS				[DEC:8(none)]
		00 00 	- IO_SCALE_FACTOR				[DEC:0(1x)]
		00 00 	- IO_SENSOR1_DATA
		00 00 	- IO_RAW_SENSOR1_DATA
		00 00 	- IO_STDEV_SENSOR1
		00 e7 	- IO_BODY_TEMPERATURE			[DEC:231(23.1°C)]
		00 f4 	- IO_EXT_POWER_SENSOR			[DEC:244(24.4°C)]
		3a d4 	- CRC
		00
	}
		
	{ONLINE CRC CALCULATOR
		https://www.lammertbies.nl/comm/info/crc-calculation.html
		HEX:01 04 0002 0008 
			-> CRC-16 (Modbus)	0x0C50
		HEX:0104 1000 0100 0800 0000 0000 0000 0000 e700 f4
			-> CRC-16 (Modbus)	0xD43A
	}
}

{#  [4.1] Sensor Data Request: polling data from smp11

}
{#  [4.2] Sensor Data Request/Response: polling to/from smp11

}

 
 

{# [5.0] Set Sensor Bus Address  			

}



{# [6.0] Setting the Sensor Period Output Report Interval 

} 



{# [7.0] Defining Sensor Output Format  	


}

