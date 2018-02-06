#!/bin/sh
#/**! \header 
#*   Copyright bcer 2009
#*   Project name.: moberl_3000
#*   File.........: spn1.sh
#*   Author.......: (c) Bojan Cernac - bcer
#*   Target / OS..: Nport6450 uc7420Plus, uc8410-LX  / Linux Moxa 2.6.10_devixdp42x-arm_xscale_be  Busybox v1.6.0
#*   Compiler.....: GNU 3.4.4 arm_linuc_gcc C Compiler V3.4.4
#*   Description..: TCP Serial server, Embedded Computer
#*   Version......: 3000.5
#*   Machine......: PC AT compatible, OS: WindowsXP & VitrualBox 3.1.2 ( Linux Ubuntu 9.10 )
#*   Created......: 2009-25 (avgust)
#*   Last update..: 2011-12-26
#**  \endheader */#!/bin/sh

###
{#  [I.]  frequently used commnads SPN1
#  port4 = /dev/tcp/172.19.75.53/64004
#  port4 = /dev/tcp/172.19.75.53/4004
	$ echo -n -e "?\r" > /dev/tcp/172.19.75.53/64004	# list system config
	$ mount -o bind /home/local /usr/local
	$ cat /home/local/etc/minirc.dfl
	$ minicom -s -o -c on dfl
	$ cat < /dev/ttyM4 | sed "s/*/*echo -n -e '$6RD\r'/g" 
	
	$ echo -n -e "S\r" > /dev/tcp/172.19.75.53/64004
	$ echo -n -e "I\r" > /dev/tcp/172.19.75.53/64004
	
	$ cat < /dev/tcp/172.19.75.53/64004
	$ echo -e -n "T TEST:\r" > /dev/tcp/172.19.75.53/64004
	$ echo -e -n "H12:00:00\r" > /dev/tcp/172.19.75.53/64004
	$ echo -e -n "R" > /dev/tcp/172.19.75.53/64004	
	$ echo -e -n "T TEST:\r" > /dev/tcp/172.19.75.53/64004
	$ echo -e -n "Y2010:04:01\r" > /dev/tcp/172.19.75.53/64004
	$ echo -e -n "R" > /dev/tcp/172.19.75.53/64004
	$ echo -e -n "T TEST:\r" > /dev/tcp/172.19.75.53/64004
	$ echo -e -n "?\r" > /dev/tcp/172.19.75.53/64004
	$ echo -e -n "R" > /dev/tcp/172.19.75.53/64004
	
	boce@deb506:~$ echo -e -n "?\r" | nc -q 1 172.19.75.53 4004
	boce@deb506:~$ nc 172.19.75.53 4004 | od -t x1az
	
	
	bcer@ub710~$ printf "PA\r"| nc -w 2 172.19.33.129 6000 |tr -d \r >temp.txt
	bcer@ub910:~$ echo -e -n "get pa\r\n" | nc -w 1 172.19.33.129 6000
	bcer@ub910:~$ echo -e -n "get pa\r\n" | nc -q 1 172.19.33.129 6000
	bcer@ub910:~$ for i in 1 2 3 4 5 6 7 8; do echo -e -n "get ta ch00 10\r\n" | nc -q 1 172.19.33.129 6000 && echo; sleep 1; done
}
###

###
{#  [II.] P034 uart_Nport6450_config (DEFAULT)
#	SerialPort:	/dev/tcp/172.19.75.53/64004
# 	Interface:	RS232	(0)
#	Protocol:	ASCII_RS232
#	addr:		0
#	baud_rate:	9600
#	parity:		none	(-parenb -parodd)
# 	data_bits:	8		(cs8)
#	stop_bits:	1		(-cstopb)
# 	echo:		off		(-echo)
#
# P034 uart_SPN1_config (DEFAULT)
#	Interface	RS232
#	Protocol:	ASCII_RS232
#	addr:		0
#	baud_rate:	9600
#	parity:		none
# 	data_bits:	8
#	stop_bits:	1
#	echo:		off
#
#
# P034 uart_SPN1_config (bcer=DEFAULT)
#	Interface	RS232C
#	Protocol:	ASCII_RS232
#	addr:		0
#	baud_rate:	9600
#	parity:		none
# 	data_bits:	8
#	stop_bits:	1
#	echo:		off	
#
}
###

###
{#  [1.0] Read Sensor Config
###
[0]	$ cat < /dev/tcp/172.19.75.53/64004 | strings 			# reading the IP:64004 port

[1]	$ echo -n -e "?\r" > /dev/tcp/172.19.75.53/64004 		# commands list (I;S;T TEST: ; Z Date & Time)
[2]	$ echo -n -e "I\r" > /dev/tcp/172.19.75.53/64004  		# info status, (
				# Status info code version: SPN1 
				# code version: v1.04 Mar 31 2008 
				# output units Units: W.m-2; 
				# battery voltage radio link status: 	1mV radio off; 
				# SN: A374)
}
###

###
{#  [2.0] Setting Uart Config

  $ telnet 172.19.33.75.53
  #  RS232C
  # baudrate to "9600"
  # data lenght to "8bit"
  # parity to  "none" -parenb, -parodd
  # stop bit to  "1"
  # don't loop back recieved characters "-echo"
 { # Overview  	
    Model name                    [NP6450              ]
    Serial no                     [3954                ]
    Firmware version              [1.7 Build 08061815  ]
    Ethernet IP address           [172.19.75.53  ]
                                  [fe80::290:e8ff:fe19:7c6e]
                                  [                                       ]
    Ethernet MAC address          [00:90:E8:19:7C:6E]
    Ethernet LAN speed            [100M/Link]
    LAN module speed              [--------- | ---------]
    Up time                       [79 days 19h:20m:02s   ]
    Module type                   [No module]
    Module AP version             [--------------------]

    Server name  [NP6450_3954                             ]
    Location     [                                        ]
    Time zone    [(GMT+01:00)Belgrade, Bratislava, Budapest, Ljubljana, Prague]
    Local time   [2010/12/10 10:36:14 ] (yy/mm/dd hh:mm:ss)
    Time server  [                                        ]
 }
 { # Basic  	
    Server name  [NP6450_3954                             ]
    Location     [                                        ]
    Time zone    [(GMT+01:00)Belgrade, Bratislava, Budapest, Ljubljana, Prague]
    Local time   [2010/12/10 11:24:46 ] (yy/mm/dd hh:mm:ss)
    Time server  [                                        ]
 }
 { # Network
	 { # Basic 
	    IPv4 configuration            [Static    ]
	    IPv4 address                  [172.19.75.53  ]
	    IPv4 netmask                  [255.255.255.0  ]
	    IPv4 gateway                  [172.19.75.1    ]
	    IPv4 DNS server 1             [               ]
	    IPv4 DNS server 2             [               ]
	    IPv4 PPPoE user account       [                                ]
	    IPv4 PPPoE password           [               ]
	    IPv4 WINS function            [Enable ]
	    IPv4 WINS server              [               ]
	    IPv6 configuration            [Auto   ]
	    IPv6 address                  [        	                          ]
	    IPv6 prefix                   [64 ]
	    IPv6 gateway                  [                                       ]
	    IPv6 DNS server 1             [                                       ]
	    IPv6 DNS server 2             [                                       ]
	    Connection priority           [IPv6 first (RFC 3484)]
	    LAN speed                     [Auto        ]
	 }
 	 { # Advanced
	    Routing protocol              [None ]
	    Gratuitous ARP                [Disable]
	    Gratuitous ARP period         [300 ] second
	}
 } 
 { # Port
	 { # Modes
	 Port  Application        Mode              Description/more settings
	  01   [Socket          ] [TCP Server     ] [TCP Server description           ] [ 4001 ]
	  02   [Socket          ] [TCP Server     ] [TCP Server description           ] [ 4002 ]
	  03   [Socket          ] [TCP Server     ] [TCP Server description           ] [ 4003 ]
	  04   [Socket          ] [TCP Server     ] [TCP Server description           ] [ 4004 ]	
		 { # TCP Server description [ 4001 ]
			 +-------------------------------------------------------------------+
			 | TCP alive check time (min)    : [7 ]                              |
			 | Inactivity time (ms)          : [0    ]                           |
			 | Max connection                : [1]                               |
			 | Ignore jammed IP              : [Disable]                         | 
			 | Allow driver control          : [Disable]                         | 
			 | Command by command operation  : [Disable]                         | 
			 | Secure                        : [Disable]                         | 
			 | TCP port                      : [4001 ]                           |
			 | Command port                  : [966  ]                           |
			 | Connection goes down, RTS     : [always high]                     |
			 | Connection goes down, DTR     : [always high]                     |
			 | Response timeout (ms)         : [0    ]                           |
			 | Non-requested serial data     : [Discard                        ] |
			 | Packing length                : [0   ]                            |
			 | Enable delimiter 1            : [Disable]                         |
			 | Delimiter 1 (Hex)             : [0 ]                              |
			 | Enable delimiter 2            : [Disable]                         |
			 | Delimiter 2 (Hex)             : [0 ]                              |
			 | Delimiter process             : [Do Nothing     ]                 |
			 | Force transmit (ms)           : [0    ]                           |
			 +-------------------------------------------------------------------+
		  }	  
		 { # TCP Server description [ 4002 ]
			 +-------------------------------------------------------------------+
			 | TCP alive check time (min)    : [7 ]                              |
			 | Inactivity time (ms)          : [0    ]                           |
			 | Max connection                : [1]                               |
			 | Ignore jammed IP              : [Disable]                         | 
			 | Allow driver control          : [Disable]                         | 
			 | Command by command operation  : [Disable]                         | 
			 | Secure                        : [Disable]                         | 
			 | TCP port                      : [4002 ]                           |
			 | Command port                  : [967  ]                           |
			 | Connection goes down, RTS     : [always high]                     |
			 | Connection goes down, DTR     : [always high]                     |
			 | Response timeout (ms)         : [0    ]                           |
			 | Non-requested serial data     : [Discard                        ] |
			 | Packing length                : [0   ]                            |
			 | Enable delimiter 1            : [Disable]                         |
			 | Delimiter 1 (Hex)             : [0 ]                              |
			 | Enable delimiter 2            : [Disable]                         |
			 | Delimiter 2 (Hex)             : [0 ]                              |
			 | Delimiter process             : [Do Nothing     ]                 |
			 | Force transmit (ms)           : [0    ]                           |
			 +-------------------------------------------------------------------+
		  }	  
		 { # TCP Server description [ 4003 ]
			 +-------------------------------------------------------------------+
			 | TCP alive check time (min)    : [7 ]                              |
			 | Inactivity time (ms)          : [0    ]                           |
			 | Max connection                : [1]                               |
			 | Ignore jammed IP              : [Disable]                         | 
			 | Allow driver control          : [Disable]                         | 
			 | Command by command operation  : [Disable]                         | 
			 | Secure                        : [Disable]                         | 
			 | TCP port                      : [4003 ]                           |
			 | Command port                  : [968  ]                           |
			 | Connection goes down, RTS     : [always high]                     |
			 | Connection goes down, DTR     : [always high]                     |
			 | Response timeout (ms)         : [0    ]                           |
			 | Non-requested serial data     : [Discard                        ] |
			 | Packing length                : [0   ]                            |
			 | Enable delimiter 1            : [Disable]                         |
			 | Delimiter 1 (Hex)             : [0 ]                              |
			 | Enable delimiter 2            : [Disable]                         |
			 | Delimiter 2 (Hex)             : [0 ]                              |
			 | Delimiter process             : [Do Nothing     ]                 |
			 | Force transmit (ms)           : [0    ]                           |
			 +-------------------------------------------------------------------+
		  }	  
		 { # TCP Server description [ 4004 ]
			 +-------------------------------------------------------------------+
			 | TCP alive check time (min)    : [7 ]                              |
			 | Inactivity time (ms)          : [0    ]                           |
			 | Max connection                : [1]                               |
			 | Ignore jammed IP              : [Disable]                         | 
			 | Allow driver control          : [Disable]                         | 
			 | Command by command operation  : [Disable]                         | 
			 | Secure                        : [Disable]                         | 
			 | TCP port                      : [4004 ]                           |
			 | Command port                  : [969  ]                           |
			 | Connection goes down, RTS     : [always high]                     |
			 | Connection goes down, DTR     : [always high]                     |
			 | Response timeout (ms)         : [0    ]                           |
			 | Non-requested serial data     : [Discard                        ] |
			 | Packing length                : [0   ]                            |
			 | Enable delimiter 1            : [Disable]                         |
			 | Delimiter 1 (Hex)             : [0 ]                              |
			 | Enable delimiter 2            : [Disable]                         |
			 | Delimiter 2 (Hex)             : [0 ]                              |
			 | Delimiter process             : [Do Nothing     ]                 |
			 | Force transmit (ms)           : [0    ]                           |
			 +-------------------------------------------------------------------+
		  }	  
		  
	 }
	 { # Line
	 Port  Baud Rate          Data Stop  Parity  Flow Ctrl  FIFO     Interface
	  01   [38400 ]  [      ] [8]  [1  ] [None ] [None    ] [Enable ][RS-485 2Wire]
	  02   [9600  ]  [      ] [8]  [1  ] [None ] [None    ] [Enable ][RS-422      ]
	  03   [9600  ]  [      ] [8]  [1  ] [None ] [None    ] [Enable ][RS-232      ]
	  04   [19200 ]  [      ] [8]  [1  ] [None ] [None    ] [Enable ][RS-485 2Wire]
	 }
 	 { # pOrt buf
	 Port  Port buffering   Location         SD file size      Serial data log
	  01   [Disable]        [Memory (64K)]   [1   ] (Mbytes)   [Disable]
	  02   [Disable]        [Memory (64K)]   [1   ] (Mbytes)   [Disable]
	  03   [Disable]        [Memory (64K)]   [1   ] (Mbytes)   [Disable]
	  04   [Disable]        [Memory (64K)]   [1   ] (Mbytes)   [Disable]
	 }
 	 { # Cipher
	 Port  SSL cipher         SSH cipher
	01  [SSL cipher sort]  [SSH cipher sort]
	02  [SSL cipher sort]  [SSH cipher sort]
	03  [SSL cipher sort]  [SSH cipher sort]
	04  [SSL cipher sort]  [SSH cipher sort]
 	 }
 }				
}				
###

###
{# [3.0] System Sensor Setup (uart, operating modes) 
###

  $ echo -n -e "T TEST:\r" > /dev/tcp/172.19.75.53/64004
  $ echo -n -e "R" > /dev/tcp/172.19.75.53/64004
						# go to sensor TEST mode
						# analog output is off
						# return to POOLING mode

  $ echo -n -e "?\r" > /dev/tcp/172.19.75.53/64004	
						# command list
							# Yyyyy/mm/dd Date
							# Hhh:mm:ss Time
							# An0, An1 read ADCn Vcc/Vref
							# Bn read PD
							# Cnnnn Calibrate
							# CLEAR Set cal to 1
							# DEFAULT Restore default cal
							# E cal values
							# F Get DCO Freq
							# G Set DCO to 1MHz
							# I Status Info
							# Nc,nnnnn set cal c to nnnnn
							# Onnnn,nnnn set DACs
							# Pn.nx read/set pin x is 01=
							# Q Scan PDs
							# R Reset to normal
							# S Send data
							# Tn.nn Sunshine ratio
							# WRITE user cal to default
							# XncccCR Write ccc to string Xn
  $ echo -n -e "Y2010/04/21\r" > /dev/tcp/172.19.75.53/64004							
  $ echo -n -e "H10:30:20\r" > /dev/tcp/172.19.75.53/64004							
  $ echo -n -e "A10\r" > /dev/tcp/172.19.75.53/64004							
  $ echo -n -e "A11\r" > /dev/tcp/172.19.75.53/64004							
  $ echo -n -e "B1\r" > /dev/tcp/172.19.75.53/64004							
# check Sensor User manual ...
}  	
###
			
###
{# [4.0] Sensor Initialization
}  
{# [4.1] Sensor Data Request: polling data from SPN1
##
  echo -n -e "S\r" > /dev/tcp/172.19.75.53/64004			# pull data from sensor SPN1
  while [ 1 ]; do echo -n -e "S\r" > /dev/tcp/172.19.75.53/64004; sleep 1; done
						# S .. reading measurement command with \r 
}
{# [4.2] Sensor Data Request/Response: polling to/from SPN1
##
# /dev/ttyMx request
	$ while [ 1 ]; do echo -n -e "S\r" > /dev/tcp/172.19.75.53/64004; sleep 1; done
						# /dev/ttyMx responce
								# $ cat < /dev/ttyMx	# or use minicom
								$ cat < /dev/tcp/172.19.75.53/64004 |  strings 
								 S 738.7, 166.4, 1
								 S 738.7, 166.4, 1
								 S 738.7, 164.4, 1
								 S 738.7, 166.4, 1
								 S 738.7, 163.4, 1
								....
								
			S 738.7, 163.4, 1
			# FORMAT:	printf "S %4.1f, %4.1f,%d\r" $total $Diffuse $sunprsence	
			# where are:
			#	  738.7 	[4.1] P :.."4.2 formated average pressure xxxx.xx"
			# [0]		"S"	
			# [1]		\040	SPACE
			# [2]		total 	( digit_10^3 )	
			# [3]		total 	( digit_10^2 )	
			# [4]		total  	( digit_10^1 )	
			# [5]		total  	( digit_10^0 )
			# [6]		"." dot	
			# [7]		total  	( digit_10^-1 )
			# [8]		","	
			# [9]		\040	SPACE
			# [10]		diffuse 	( digit_10^3 )	
			# [11]		diffuse 	( digit_10^2 )	
			# [12]		diffuse  	( digit_10^1 )	
			# [13]		diffuse  	( digit_10^0 )
			# [14]		"." dot	
			# [15]		diffuse  	( digit_10^-1 )
			# [16]		","	
			# [17]		sunsinepresent  	( digit_10^0 )
			# [18]		\r

}
###
 
 
###
{# [5.0] Set Sensor Bus Address  			
# [  root@ttyp0] write: #ssh bcer@172.19.2.226 
}
###

###
{# [6.0] Setting the Sensor Period Output Report Interval 
 # Relative Periodic Timer [Ti, Tp]; Ti=Tp; 
 # <S>___<OR>__<OR>__<OR>__<OR>__ ...	
 #     Ti    Tp    Tp 	 Tp    Tp
 # <S> .. start 
 # <OR> .. Output Report
} 
###

###
{# [7.0] Defining Sensor Output Format  	
###

}
###
