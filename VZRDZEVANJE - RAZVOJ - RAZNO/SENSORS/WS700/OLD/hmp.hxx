#!/bin/sh
#//**! \header 
#*   Copyright bcer 2009
#*   Project name.: moberl_3000
#*   File.........: hmp155.sh
#*   Author.......: (c) Bojan Cernac - bcer
#*   Target / OS..: Nport6450 uc7420Plus, uc8410-LX  / Linux Moxa 2.6.10_devixdp42x-arm_xscale_be  Busybox v1.6.0
#*   Compiler.....: GNU 3.4.4 arm_linuc_gcc C Compiler V3.4.4
#*   Description..: TCP Serial server, Embedded Computer
#*   Version......: 3000.5
#*   Machine......: PC AT compatible, OS: WindowsXP & VitrualBox 3.1.2 ( Linux Ubuntu 9.10 )
#*   Created......: 2009-25 (avgust)
#*   Last update..: 2011-12-26
#**  \endheader */

###
{#  [I.]  frequently used commnads HMP155
	$ setinterface /dev/ttyM1 1		
	$ stty 19200 < /dev/ttyM1
	$ stty -a < /dev/ttyM1 | grep speed
	$ mount -o bind /home/local /usr/local
	$ cat /home/local/etc/minirc.dfl
	$ minicom -s -o -c on dfl
	$ echo -n -e "OPEN\r" > /dev/ttyM1	
	$ while [ 1 ]; do echo -n -e "W3" > /dev/ttyM1; sleep 1; done
	bcer@ub910: $ ssh root@172.19.33.129 'echo  -n -e "OPEN\r" > /dev/ttyM1 &'
	$ cat < /dev/ttyM1 | sed "s/*/*echo -n -e '$6RD\r'/g" 
	
	bcer@ub710~$ printf "PA\r"| nc -w 2 172.19.139.20 2003 |tr -d \r >temp.txt
	bcer@ub910:~$ echo -e -n "get pa\r\n" | nc -w 1 172.19.2.226 6000
	bcer@ub910:~$ echo -e -n "get pa\r\n" | nc -q 1 172.19.2.226 6000
	bcer@ub910:~$ for i in 1 2 3 4 5 6 7 8; do echo -e -n "get ta ch00 10\r\n" | nc -q 1 172.19.2.226 6000 && echo; sleep 1; done
# read /dev/ttyM2
	$ cat < /dev/ttyM2 | grep "^*"
	$ cat < /dev/ttyM2 | sed "s/*/*echo -n -e '$6RD\r'/g" 
	$ cat  /dev/ttyM2 | sed "s/*/digital value: */g"

	$ while [ 1 ]; do echo -n -e "send 0\r" > /dev/ttyM1; sleep 5; done
					# /dev/ttyMx responce
					$ cat < /dev/ttyMx	# or use minicom
						"RH= 11.6 %RH Ta= -3.9 'C"
						"RH= 11.6 %RH Ta= -3.9 'C" 
						"...."
	$ while [ 1 ]; do echo -n -e "send 0\r" > /dev/tcp/172.19.33.131/4004; sleep 5; done
					# /dev/ttyMx responce
					$ cat < /dev/tcp/172.19.33.131/4004
						"00  93.9  5.8  4.9  4.9  6.5  8.0  0000 h 	E4820017"
						"00  93.9  5.8  4.9  4.9  6.5  8.0  0000 h 	E4820017"
						"00  93.9  5.8  4.9  4.9  6.5  8.0  0000 h 	E4820017"
						"00  93.9  5.8  4.9  4.9  6.5  8.0  0000 h 	E4820017"
						"...."							
}
###

###
{#  [II.] N2-x ttyMx_config (rc.local)
#	SerialPort:	/dev/ttyM1
# 	Interface:	RS485 hd	(1)
#	Protocol:	ASCII
#	addr:		0
#	baud_rate:	19200		 
#	parity:		none		(-parenb -parodd)
# 	data_bits:	7		(cs7)
#	stop_bits:	1		(-cstopb)
# 	echo:		off		(-echo)	

# N2-2 uart_HMP155_config (DEFAULT)
#	Interface	RS485_hd
#	Protocol:	ASCII
#	addr:		0
#	baud_rate:	4800
#	parity:		even	
# 	data_bits:	7	(cs7)
#	stop_bits:	1	(-cstopb)
#	echo:		on	(echo)

# N2-2 uart_HMP155_config (CURRENT)
#	Interface	RS485_hd
#	Protocol:	ASCII
#	addr:		0
#	baud_rate:	19200
#	parity:		none	(-parenb -parodd)  == "none"
# 	data_bits:	7
#	stop_bits:	1
#	echo:		on
}
###

###
{#  [1.0] Read Sensor Config
# Power up
# hmp155 response:
HMP155 1.20

$ echo -n -e "?\r" > /dev/ttyM1			# list system config
# HMP155 1.20
# Serial number  : E4820017
# Batch number   : E4630010
# Module number  : E0650044
# Sensor number  : E1940000
# Sensor model   : Humicap 180R
# Cal. date      : 20091202
# Cal. info      : Helsinki / FIN
# Time           : 00:03:51
# Serial mode    :     STOP    
# Baud P D S     :    19200 N 7 1
# Output interval:        2 S
# Serial delay   :       10
# Address        :        0    
# Pressure       :    1.013 bar
# Filter         :    1.000    
}
###

###
{#  [2.0] Setting Uart Config - /dev/ttyM1
  setinterface /dev/ttyM1 1
  stty 19200 < /dev/ttyM1
  stty cs7 < /dev/ttyM1
  stty -parenb < /dev/ttyM1
  stty -parodd < /dev/ttyM1
  stty -cstopb < /dev/ttyM1
  stty -echo < /dev/ttyM1
					#  RS485-hd
					# baudrate to "19200"	[19200]
					# data lenght to "7bit" [cs7]
					# parity to  "none" 	[-parenb]
					# stop bit to  "1" 	[-cstopb]
					# don't loop back recieved characters [-echo]
					# bug#01 
						# seri 19200 N 7 1 	..ok
						# seri 19200 N 8 1 	..doesn't work	HMP155_uart_config remain on "19200 N 7 1"

  setinterface /dev/ttyM1
  stty -a < /dev/ttyM1 | grep speed
  stty -a < /dev/ttyM1 | grep cs   
  stty -a < /dev/ttyM1 | grep echo
  				# show speed, cs .., echo ...
}				
{#  [2.1] Read Uart Config 	- /dev/ttyM1
printf "uart config \n";  setinterface /dev/ttyM1; stty -a < /dev/ttyM1 | grep speed; stty -a < /dev/ttyM1 | grep cs;  stty -a < /dev/ttyM1 | grep echo;  printf "\n"

`speed 19200 baud`; rows 24; columns 80;
intr = ^C; quit = ^\; erase = ^?; kill = ^U; eof = ^D; eol = <undef>; eol2 = <undef>; start = ^Q; stop = ^S;
susp = ^Z; rprnt = ^R; werase = ^W; lnext = ^V; flush = ^O; min = 1; time = 0;
`-parenb` `-parodd` `cs7` hupcl -cstopb cread clocal -crtscts
-ignbrk -brkint -ignpar -parmrk -inpck -istrip -inlcr -igncr icrnl ixon -ixoff -iuclc -ixany -imaxbel
opost -olcuc -ocrnl onlcr -onocr -onlret -ofill -ofdel nl0 cr0 tab0 bs0 vt0 ff0
isig icanon iexten `-echo` echoe echok -echonl -noflsh -xcase -tostop -echoprt echoctl echoke
}
###

###
{#  [3.0] System Sensor Setup (uart, operating modes)  use minicom to setup  - /dev/ttyM1
  $ echo -n -e "help\r" > /dev/ttyM1
						# list availible commands"
  $ echo -n -e "open 0\r" > /dev/ttyM1
						# -> HMP155_mode: STOP "cli mode (addr=0)"
# read/write sensor sonfiguration						
  $ echo -n -e "?\r" > /dev/ttyM1
  $ echo -n -e "form\r" > /dev/ttyM1
  $ echo -n -e "form 3.1 \042RH=\042 RH \042 \042 U4 3.1 \042Ta=\042 Ta \042 \042 U3 #r#n\r" > /dev/ttyM1						
						# reads config setup from sensor
						# reads output format for "send" cmd
						# set up output format for "send" cmd
# set time						
  $ echo -n -e "time 12 23 45\r" > /dev/ttyM1
						# set time to  12:23:45 hh:mm:ss

# uart_config
  $ echo -n -e "seri 19200 N 7 1\r" > /dev/ttyM1
  $ echo -n -e "reset\r" > /dev/ttyM1
						# HMP155_uart_config: set to 19200 -parenb cs7 -cstop
						

# data request						
  $ echo -n -e "addr 0\r" > /dev/ttyM1						
  $ echo -n -e "close\r" > /dev/ttyM1				
  $ echo -n -e "send 0\r" > /dev/ttyM1
  $ echo -n -e "?\r" > /dev/ttyM1
						# HMP155 set address to 0 for POLL mode
						# close STOP mode & -> HMP155_mode: POLL
						# /dev/ttyMx HMP155_data_request 				
						#  read config setup from sensor in POLL mode
  $ echo -n -e "open 0\r" > /dev/ttyM1
						# -> HMP155_mode: STOP "cli mode (addr=0)"						
  $ echo -n -e "INTV 3 s\r" > /dev/ttyM1						
  $ echo -n -e "r\r" > /dev/ttyM1						
  $ echo -n -e "s\r" > /dev/ttyM1
						# HMP155: set output interval to 3 [sec] 1/3 [Hz]
						# -> HMP155_mode: RUN  "START cont. measuring output every 3 sec"
						# -> HMP155_mode: STOP "STOP cont. measuring output"  					
		
# heating 					
	$ echo -n -e "xheat off\r" > /dev/ttyM1			
	$ echo -n -e "xheat on\r" > /dev/ttyM1			

# purge 
	$ echo -n -e "pur\r" > /dev/ttyM1			
	
						
# check Sensor User manual ...						
}
###

###  
{# [4.0] Sensor Initialization
 $ echo -e -n "STOP \r" > /dev/ttyM1
 $ echo -e -n "SMODE POLL \r" > /dev/ttyM1
 replay: Serial mode:  POLL
 3. izklopi napajanje senzorja 
 4. preveri ali je senzor v  POLL modu
 $ echo -n -e "open 1\r" > /dev/ttyM1

#  IN POLL mode
# $ echo -n -e "??\r" > /dev/ttyM1
 $ echo -n -e "?\r" > /dev/ttyM1
  replay:HMP155 1.22
  Serial number  : G2510038
  Batch number   : G2230070
  Module number  : G1740134
  Sensor number  : F4030000
  Sensor model   : Humicap 180R
  Cal. date      : 20110712
  Cal. info      : Helsinki / FIN
Time           : 00:50:30
Serial mode    :     POLL
Baud P D S     :    19200 N 7 1
Output interval:        2 S
Serial delay   :       10
Address        :        1
Pressure       :    1.013 bar
Filter         :    1.000

  5. echo -n -e "CLOSE 1\r" > /dev/ttyM1
replay: line closed

}
{# [4.1] Sensor Data Request: polling data from HMP155
  $ echo -n -e "send 0\r" > /dev/ttyM1			# pull data from sensor HMP155
  $ while [ 1 ]; do echo -n -e "send 0\r" > /dev/ttyM1; sleep 1; done
						# send 0 .. reading measurement command with \r 
						# 	 . 0 = [0..99] - device address
}
{# [4.2] Sensor Data Request/Response: polling to/from HMP155
# /dev/ttyMx request
	$ while [ 1 ]; do echo -n -e "send 0\r" > /dev/ttyM1; sleep 1; done
						# /dev/ttyMx responce
								$ cat < /dev/ttyMx	# or use minicom
								"RH= 11.6 %RH Ta= -3.9 'C"
								"RH= 11.6 %RH Ta= -3.9 'C" 
								"RH= 11.6 %RH Ta= -3.9 'C" 
								"RH= 11.6 %RH Ta= -3.9 'C" 
								"...."
								
			"RH= 11.6 %RH Ta= -3.9 'C"
			# FORMAT: .... #r #n 		
			# 3.1 "RH=" RH " " U4 3.1 "Ta=" Ta " " U3 \r \n			
			# where are:
			#	3.1 "RH=" RH	[3.1] :.."3.1 formated RH xxx.x"
			# [0]		R	
			# [1]		H	
			# [2]		=
			#	11.6
			# [3]			rel. humidity 	( digit_10^2)	
			# [4]		1 	rel. humidity  	( digit_10^1)	
			# [5]		1	rel. humidity  	( digit_10^0)
			# [6]		"." dot
			# [7]		6	rel. humidity   ( digit_10^-1)
			# 	" " SPACE
			# [8]		space \040
			#	%RH
			# [9]		%
			# [10]		R
			# [11]		H
			# 	U4	unit field & lenght for RH _|
			#
			#	3.1 "Ta=" Ta 	[3.1] :.."3.1 formated Ta xxx.x"
			# [12]		T
			# [13]		a
			# [14]		=
			# 	-3.9
			# [15]		-
			# [16]		  	air temp 	( digit_10^2)	
			# [17]		 	air temp  	( digit_10^1)	
			# [18]		3 	air temp  	( digit_10^0)
			# [19]		"." dot
			# [20]		9 	air temp  	( digit_10^-1)
			# [21]		space \040
			# [22]		'
			# [23]		C
			# [24]		\r
			# [25]		\n
			
			# digit ..ASCII value

}
###

###
{# [5.0] Set Sensor Bus Address  
  $ echo -n -e "addr 0\r" > /dev/ttyM1
  $ echo -n -e "addr\r" > /dev/ttyM1			
						# HMP155 set address to 0 for POLL mode
						# HMP155 read the address (used only in POLL mode)
  $ echo -n -e "close\r" > /dev/ttyM1
  $ echo -n -e "send 0\r" > /dev/ttyM1
  $ echo -n -e "?\r" > /dev/ttyM1
						# close STOP mode & -> HMP155_mode: POLL
						# /dev/ttyMx HMP155_data_request 				
						#  read config setup from sensor in POLL mode  $ echo -n -e "open 0\r" > /dev/ttyM1
						# -> HMP155_mode: STOP "cli mode (addr=0)"	
}
###

###
{# [6.0] Setting the Sensor Period Output Report Interval 
 # Relative Periodic Timer [Ti, Tp]; Ti=Tp; 
 # <S>___<OR>__<OR>__<OR>__<OR>__ ...	
 #     Ti    Tp    Tp 	 Tp    Tp
 # <S> .. start 
 # <OR> .. Output Report
  
  $ echo -n -e "INTV 3 s\r" > /dev/ttyM1
  $ echo -n -e "r\r" > /dev/ttyM1
  $ echo -n -e "s\r" > /dev/ttyM1
						# HMP155: set output interval to 3 [sec] 1/3 [Hz]
						# -> HMP155_mode: RUN  "START cont. measuring output every 3 sec"
						# -> HMP155_mode: STOP "STOP cont. measuring output" 
						
# check Sensor User manual ...						
###
}
###

###
{# [7.0] Defining Sesnor Output Format  
  $ echo -n -e "?\r" > /dev/ttyM1
  $ echo -n -e "form\r" > /dev/ttyM1
  $ echo -n -e "form 3.1 \042RH=\042 RH \042 \042 U4 3.1 \042Ta=\042 Ta \042 \042 U3 #r#n\r" > /dev/ttyM1
						# reads config setup from sensor < ? >
						# reads output format for "send" cmd  < form >
						# set up default output format < form / >
						# set up output format for "send" cmd
						
  $ echo -n -e "form /\r" > /dev/ttyM1	# set to default output send format
  response: 'OK'
  $ echo -n -e "form\r" > /dev/ttyM1 	# read output send format
  response:	'3.1 "RH=" RH " " U4 3.1 "Ta=" Ta " " U3 \r \n'
  $ echo -n -e "form ADDR \t RH \t Ta \t Td \t Tdf \t x \t Tw \t ERR \t STAT \t SNUM \r \n" > /dev/ttyM1
  response: 'OK'
  $ echo -n -e "form\r" > /dev/ttyM1
  response: 'ADDR \t RH \t Ta \t Td \t Tdf \t x \t Tw \t ERR \t STAT \t SNUM \r \n'
  $ echo -n -e "send\r" > /dev/ttyM1
  response: '00  93.2  10.9  9.8  9.8  9.0  12.9  0000h  E4820017'
  
# check Sensor User manual ...
}
###

###
{# [A] HMP155_bug#01 
###
	# seri 19200 N 7 1 	..ok
	# seri 19200 N 8 1 	..doesn't work	HMP155_uart_config remain on "19200 N 7 1"
	# 	7 bit data lenght works
	# 	8 bit data lenght doens't work
}	
###
