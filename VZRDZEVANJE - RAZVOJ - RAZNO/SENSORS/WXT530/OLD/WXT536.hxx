#!/bin/sh
#//**! \header 
#*   Copyright bcer 2009 - 2017/09
#*   Project name.: xoberl_4000
#*   File.........: WXT536.hxx
#*   Author.......: (c) Bojan Cernac - bcer, Nikola Kostic - nkostic
#*   Target / OS..: Nport8410, uc8410-LX  / Linux Moxa 2.6.10_devixdp42x-arm_xscale_be  Busybox v1.6.0
#*   Compiler.....: GNU 3.4.4 arm_linuc_gcc C Compiler V3.4.4
#*   Description..: TCP Serial server, Embedded Computer
#*   Version......: 3000.5
#*   Machine......: PC AT compatible, OS: WindowsXP & VitrualBox 3.1.2 ( Linux Ubuntu 9.10 )
#*   Created......: 2017-29 (avgust)
#*   Last update..: 2017-09-22
#**  \endheader */
 /* POWER CONSUMPTION: Specified: 3.5 mA, Measured: 5.4mA */

{# [I.]  frequently used commands WXT536

}

{# [II.] UART Sensor_WXT536 / N3_Nport_8410 config / wiring
/*	Sensor WXT536 UART settings (DEFAULT)
		Baud rate: 19200
		Data bits: 8
		Parity: none 
		Stop bits: 1 
		Flow ctrol:none
		Interface: rs-232
*/
/*	Sensor WXT536 UART settings (CURRENT)
		Baud rate: 19200
		Data bits: 8
		Parity: none 
		Stop bits: 1 
		Flow ctrol:none
		Interface: rs-232
*/
/*	MOXA NPort 5650-8DT-J settings 
		IP: 172.19.6.84
		Serial port: 8
		Baud rate: 19200
		Data bits: 8
		Stop bits: 1 
		Parity: none 
		FIFO: disable 
		Flow ctrol:none
		Interface: rs-232
*/	
/*	SENSOR WIRING: (over M12 (8pin) factory made cable)
		[M12] white(RxD)   <-> 4(RxD) [A3-4] !!!
		[M12] blue (TxD)   <-> 5(TxD) [A3-4] !!!
		[M12] green(GND)   <-> 3(GND) [A3-4]
		[M12] red V-12DC   <->   0VDC [A3-4]
		[M12] brown V+12DC <-> +12VDC [A3-4]	
*/	
}

{# [1.0] Read Sensor Config
REF 6.4.1 Checking Current Communication Settings (aXU) {	
	#| Command format in ASCII and NMEA 0183:
	aXU<cr><lf>
/**		LEGEND
		| a	 - Device address, which can consist of the following characters: 0 (default) ... 9, A ... Z, a ... z.
		| XU	 - Device settings command in ASCII and NMEA 0183
		| <cr><lf> - Command terminator in ASCII and NMEA 0183
*/		
	#| Example response in ASCII and NMEA 0183:
	aXU,A=a,M=[M],T=[T],C=[C],I=[I],B=[B],D=[D],P=[P],S=[S],L=[L],N=[N],V=[V]<cr><lf>

	####| TEST: ###################################################################################################################
	cmd> echo -n -e "0XU\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0XU,A=0,M=P,T=0,C=2,I=0,B=19200,D=8,P=N,S=1,L=25,N=WXT530,V=3.59,H=0
/**		LEGEND
		  0XU - Device address (Device settings command in ASCII)
		      A=0 - Device address = 0
			      M=P - Communication protocol = ASCII, polled
					      C=2 - Serial interface = RS-232
						      I=0 -  Automatic repeat interval for Composite data message = no automatic repeat
							      B=19200 - Baud rate = 19200 bps
								          D=8 - Data bits = 8
										      P=N - Parity = None
											      S=1 - Stop bits = 1
												      L=25 - RS-485 line delay = 25 ms
													       N=WXT530 - Name of the device =  WXT530
														            V=3.59 -  Software version = 3.59
																	       H=0 - Parameter locking: Parameters can be changed
*/
	}
REF 6.4.2 Settings Fields{
/**	LEGEND
	| a Device address
	| XU Device settings command in ASCII and NMEA 0183
	| [A] Address: 0 (default) … 9, A … Z, a … z
	| [M] Communication protocol:
	| 	A = ASCII, automatic
	| 	a = ASCII, automatic with CRC
	| 	P = ASCII, polled
	| 	p = ASCII, polled, with CRC
	| 	N = NMEA 0183 v3.0, automatic
	| 	Q = NMEA 0183 v3.0, query (= polled)
	| 	S = SDI-12 v1.3
	| 	R = SDI-12 v1.3 continuous measurement
	| [T] Test parameter (for testing use only)
	| [C] Serial interface:
	| 	1 = SDI-12
	| 	2 = RS-232
	| 	3 = RS-485
	| 	4 = RS-422
	| [I] Automatic repeat interval for Composite data message: 1 … 3600 s, 0 = no automatic repeat
	| [B] Baud rate: 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200
	| [D] Data bits: 7/8
	| [P] Parity:
	| 	O = Odd
	| 	E = Even
	| 	N = None
	| [S] Stop bits: 1/2
	| [L] RS-485 line delay: 0 … 10000 ms. Defines the delay between the last character of the query and the first character of the response message from the transmitter. During the delay, the transmitter is disabled. Effective in ASCII, polled and NMEA 0183 query protocols. Effective when RS-485 is selected (C = 3).
	| [N] Name of the device: WXT536 (read-only)
	| [V] Software version: for example, 1.00 (read-only)
	| [H] Parameter locking
	| 	0 = Parameters can be changed
	| 	1 = Parameters locked. Vaisala recommends that you set this parameter to 1 after you have configuration. This prevents accidental changes, for instance, in RS- 485 use when there is interference.
	| <cr><lf> Response terminator 
	}
*/
}}

{# [2.0] Setting Uart Config N3-8
SET TO:
		Baud rate: 19200
		Data bits: 8
		Stop bits: 1 
		Parity: none 
		FIFO: disable 
		Flow ctrol:none
		Interface: rs-232
}

{# [2.1] Read Uart Config N3-8
telnet 172.19.6.84
Trying 172.19.6.84...
Connected to 172.19.6.84.
Escape character is '^]'.



-----------------------------------------------------------------------------
Model name       : NPort 5650-8-DT-J
MAC address      : 00:90:E8:38:0A:28
Serial No.       : 7137
Firmware version : 2.2 Build 11090613
System uptime    : 0 days, 12h:41m:04s
-----------------------------------------------------------------------------
<< Main Menu >>
  (1) Basic settings
  (2) Network settings
  (3) Serial settings
  (4) Operating settings
  (5) Accessible IP settings
  (6) Auto warning settings
  (7) Monitor
  (8) Ping
  (9) Change password
  (a) Load factory default
  (v) View settings
  (s) Save/Restart
  (q) Quit

Key in your selection: v

-----------------------------------------------------------------------------
Server name                    : NP5650-8-DT-J_7131
Time zone                      : (GMT+01:00)Belgrade, Bratislava, Budapest, Ljub                                                     ljana, Prague
Local time                     : 2001/07/30 13:36:03
Time server                    :
Web console                    : Enable
Telnet console                 : Enable
LCM password protect           : No
Reset button protect           : No

Press any key to continue...
...
Port 8
Baud rate                      : 19200
Data bits                      : 8
Stop bits                      : 1
Parity                         : None
Flow control                   : None
FIFO                           : Disable
Interface                      : rs-232

Press any key to continue...

-----------------------------------------------------------------------------
...
Port 8                         : TCP Server Mode
TCP alive check time (0-99min) : 7
Inactivity time                : 0
Max connection                 : 4
Ignore jammed IP               : No
Allow driver control           : No
Packing length                 : 0
Delimiter 1                    : (Disable) 0
Delimiter 2                    : (Disable) 0
Delimiter process              : Do Nothing
Force transmit                 : 0
Local TCP port                 : 64008
Command port                   : 973

Press any key to continue...


}

{# [3.0] System Sensor Setup (Testing with terminal) 
	#Listen
		ssh root@172.19.6.83
		cat < /dev/tcp/172.19.6.84/64008
	#Commands issuing
		echo -n -e "COMMAND\r\n" | nc -w 2   64008					
}

{# [4.0] Sensor Initialization
	REF	6.4.3 Changing the Communication Settings (aXU){
	#| Command format in ASCII and NMEA 0183:
	aXU,A=x,M=x,C=x,I=x,B=x,D=x,P=x,S=x,L=x<cr><lf>
/**		LEGEND - SEE REF 6.4.2 (Settings Fields)
		| A, M, C, I, B, D, P, S,L - The communication setting fields.
		| x 			   - Input value for the setting
		| <cr><lf> 		   - Command terminator in ASCII and NMEA 0183
*/
	#| Example (ASCII and NMEA 0183, device address 0):
	#| Changing the device address from 0 to 1:
	0XU,A=1<cr><lf>
	#| Checking the changed settings:
	1XU<cr><lf>
	1XU,A=1,M=P,T=1,C=2,I=0,B=19200,D=8,P=N,S=1,L=25, N=WXT530V=1.00<cr><lf>

	#| TEST - Change address from 0 to 1: ####################################################################################################
	cmd> echo -n -e "0XU,A=1\r\n" | nc -w 2 172.19.6.84 64008
	answ> 1XU,A=1
	cmd> echo -n -e "1XU\r\n" | nc -w 2 172.19.6.84 64008
	answ> 1XU,A=1,M=P,T=0,C=2,I=0,B=19200,D=8,P=N,S=1,L=25,N=WXT530,V=3.59,H=0

	#| TEST - Change communication to ASCII automatic (push mode):  ##########################################################################
	cmd> echo -n -e "0XU,M=A\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0XU,M=A
	answ> 0R4,Tr=8.2C,Ra=0.0M,Sl=0.001262V,Rt=1032.0R,Sr=-0.566715V
	answ> 0R5,Th=24.0C,Vh=0.0N,Vs=12.2V,Vr=3.681V
	answ> 0R1,Dn=000#,Dm=000#,Dx=000#,Sn=0.0#,Sm=99.9#,Sx=0.0#
	answ> 0R2,Ta=23.3C,Ua=56.0P,Pa=985.3H
	answ> 0R1,Dn=000#,Dm=000#,Dx=000#,Sn=0.0#,Sm=99.9#,Sx=0.0#
	answ> 0R1,Dn=000#,Dm=000#,Dx=000#,Sn=0.0#,Sm=99.9#,Sx=0.0#
	answ> 0R5,Th=24.0C,Vh=0.0N,Vs=12.2V,Vr=3.696V

	#| TEST - Change communication to ASCII poll mode:  ##########################################################################
	echo -n -e "0XU,M=P\r\n" | nc -w 2 172.19.6.84 64008
	0XU,M=P
	
	#| Changing several settings with one command:  ##########################################################################################
	0XU,M=A,C=3,B=9600<cr><lf>
	0XU,M=A,C=3,B=9600<cr><lf>
	#| Checking the changed settings:
	0XU<cr><lf>
	0XU,A=0,M=A,T=1,C=3,I=0,B=9600,D=8,P=N,S=1,L=25, N=WXT530,V=1.00<cr><lf>
	}
}

{# [4.1] Sensor Data Request: polling data from WXT536
	#| TEST - Change communication to ASCII automatic (poll mode): ##################################################
	echo -n -e "0XU,M=P\r\n" | nc -w 2 172.19.6.84 64008
	0XU,M=P
}

{# [4.2] Sensor Data Request/Response: polling to/from WXT536
	REF	7.2.4 Wind Data Message (aR1) {
	#| This command requests the wind data message.
	aR1<cr><lf>
	#| Example of the response (the parameter set is configurable):
	0R1,Dn=236D,Dm=283D,Dx=031D,Sn=0.0M,Sm=1.0M, Sx=2.2M<cr><lf>
/**		LEGEND
		|a 		Device address
		|R1 		Wind message query command
		|Dn 		Wind direction minimum (D = degrees)
		|Dm 		Wind direction average (D = degrees)
		|Dx 		Wind direction maximum (D = degrees)
		|Sn 		Wind speed minimum (M = m/s)
		|Sm 		Wind speed average (M = m/s)
		|Sx 		Wind speed maximum (M = m/s)
		|<cr><lf> 	Response terminator
*/		
	####| TEST: ###################################################################################################################
	cmd> echo -n -e "0R1\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0R1,Dn=028D,Dm=137D,Dx=328D,Sn=0.2M,Sm=0.4M,Sx=0.6M
	}
	REF 7.2.5 Pressure, Temperature and Humidity Data Message (aR2){
	#| This command requests a pressure, temperature, and humidity data message.
	aR2<cr><lf>
	#| Example of the response (the parameter set is configurable):
	0R2,Ta=23.6C,Ua=14.2P,Pa=1026.6H<cr><lf>
/**		LEGEND
		|a 		Device address
		|R2 		Pressure, temperature and humidity message query command
		|Ta 		Air temperature (C = °C)
		|Ua 		Relative humidity (P = % RH)
		|Pa 		Air pressure (H = hPa)
		|<cr><lf> 	Response terminator
*/		
	####| TEST: ###################################################################################################################
	cmd> echo -n -e "0R2\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0R2,Ta=23.4C,Ua=54.2P,Pa=984.8H
	}
	REF	7.2.6 Precipitation Data Message (aR3){
	#| This command requests the precipitation data message.
	aR3<cr><lf>
	#| Example of the response (the parameter set is configurable):
	0R3,Rc=0.0M,Rd=0s,Ri=0.0M,Hc=0.0M,Hd=0s,Hi=0.0M,Rp=0.0M,Hp=0.0M<cr><lf>
/**		LEGEND
		|a Device address
		|R3 Precipitation message query command
		|Rc Rain accumulation (M = mm)
		|Rd Rain duration (s = s)
		|Ri Rain intensity (M = mm/h)
		|Hc Hail accumulation (M = hits/cm2)
		|Hd Hail duration (s = s)
		|Hi Hail intensity (M = hits/cm2h)
		|Rp Rain peak intensity (M = mm/h)
		|Hp Hail peak intensity (M = hits/cm2h)
		|<cr><lf> Response terminator
*/		
	####| TEST: ###################################################################################################################
	cmd> echo -n -e "0R3\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0R3,Rc=0.00M,Rd=0s,Ri=0.0M,Hc=0.0M,Hd=0s,Hi=0.0M
	}
	REF	7.2.7 Supervisor Data Message (aR5){
	#| This command requests a supervisor data message containing self-check parameters of the heating system and power supply voltage.
	aR5<cr><lf>
	#| Example of the response (the parameter set is configurable):
	0R5,Th=25.9C,Vh=12.0N,Vs=15.2V,Vr=3.475V,Id=HEL___<cr><lf>
/**		LEGEND
		|a Device address
		|R5 Supervisor message query command
		|Th Heating temperature (C = °C)
		|Vh Heating voltage (N = heating is off)
		|Vs Supply voltage (V = V)
		|Vr 3.5 V reference voltage (V = V)
		|<cr><lf> Response terminator
		|Id Information field
*/		
	####| TEST: ###################################################################################################################
	cmd> echo -n -e "0R5\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0R5,Th=24.2C,Vh=0.0N,Vs=12.1V,Vr=3.672V
	}
}

{# [5.0] Set Sensor Bus Address  
	REF 7.2.2 Device Address (?) {
	#| This command queries the address of the device on the bus.
	?<cr><lf>
	#| TEST ##########################################################################
	cmd> echo -n -e "?\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0
	}
	REF part 6.4.3{
	#| TEST - Change address from 0 to 1: ####################################################################################################
	cmd> echo -n -e "0XU,A=1\r\n" | nc -w 2 172.19.6.84 64008
	answ> 1XU,A=1
	cmd> echo -n -e "1XU\r\n" | nc -w 2 172.19.6.84 64008
	answ> 1XU,A=1,M=P,T=0,C=2,I=0,B=19200,D=8,P=N,S=1,L=25,N=WXT530,V=3.59,H=0
	}
}

{# [6.0] Setting the Sensor Period Output Report Interval 
/**	REF 7.2.11 Automatic Mode 
	When the automatic ASCII protocol is selected, the transmitter sends data messages at user-configurable update intervals.
	The message structure is the same as with data query commands aR1, aR2,aR3 , and aR5. You can choose an individual update interval for each sensor (parameter [I] REF 8.1.1, 8.1.2, 8.1.3, 8.1.4 )
	See REF 6.4.3 (Change communication to ASCII automatic (push mode))
	*/
}

{# [7.0] Defining Sensor Output Format  
	REF 8.1   Sensor Configuration and Data Message Formatting
	REF 8.1.1 Wind Sensor{
		REF 8.1.1.1 Checking the Settings (aWU){
		aWU<cr><lf>
		#| The response in ASCII and NMEA 0183:
		aWU,R=[R],I=[I],A=[A],G=[G],U=[U],D=[D],N=[N],F=[F]<cr><lf>
		#| Example (ASCII and NMEA 0183, device address 0):
		0WU<cr><lf>
		0WU,R=01001000&00100100,I=60,A=10,G=1,U=N,D= -90,N=W,F=4<cr><lf>
		#| TEST
		cmd> echo -n -e "0WU\r\n" | nc -w 2 172.19.6.84 64008
		answ> 0WU,R=11111100&01001000,I=5,A=3,G=1,U=M,D=0,N=W,F=4
		}		
		REF 8.1.1.2  Setting Fields{
		#| Parameter Description
/**			LEGEND
			|[R] Parameter selection. This field consists of 16 bits defining the wind parameters included in the data messages. The bit value 0 disables and the bit value 1 enables the parameter.
			|Bits 1-8 determine the parameters in the data message obtained with the following commands:
			|• ASCII: aR1 and ar1
			|	1st bit (most left) Dn Direction minimum
			|	2nd bit Dm Direction average
			|	3rd bit Dx Direction maximum
			|	4th bit Sn Speed minimum
			|	5th bit Sm Speed average
			|	6th bit Sx Speed maximum
			|	7th bit output mode
			|	8th bit spare
			|	& delimiter
			|Bits 9-16 determine the parameters in the data message obtained with the following commands:
			|• ASCII: aR0, ar0
			|	9th bit Dn Wind direction minimum
			|	10th bit Dm Wind direction average
			|	11th bit Dx Wind direction maximum
			|	12th bit Sn Speed minimum
			|	13th bit Sm Speed average
			|	14th bit Sx Speed maximum
			|	15th bit spare
			|	16th bit (most right) 0
			|[I] Update interval: 1 ... 3600 seconds
			|[A] Averaging time: 1 ... 3600 seconds
			|	Defines the period over which the wind speed and direction averaging is
			|	calculated. Same period is also used for maximum and minimum calculation. See
			|	Appendix D Wind Measurement Averaging Method on page 201 for difference in
			|	averaging practices when A<I and A>I.
			|[G] Wind speed max/min calculation mode: 1 or 3 seconds G =1: Traditional max/min
			|	calculation is performed both for speed and direction. G =3: Gust & lull are
			|	calculated for wind speed, while direction calculation is as it is with G =1. In the
			|	output messages, gust & lull replace the wind speed max/min values (Sx, Sn), respectively.
			|[U] Speed unit: M = m/s, K = km/h, S = mph, N = knots
			|[D] Direction offset: -180 ... 180°, see Wind Direction Offset on page 51.
			|[N] NMEA wind formatter: T = XDR (transducer syntax), W = MWV (wind speed and
			|	angle) Defines whether the wind message is sent in XDR or MWV format.
			|[F] Sampling rate: 1, 2, or 4 Hz Defines how frequently the wind is measured. Lower
			|	sampling rate reduces the power consumption, but it also weakens the measurement representativeness.
			|<cr><lf> Response terminator
*/			
		}		
		REF 8.1.1.3 Changing the Settings (aWU){
		#| Command format in ASCII and NMEA 0183:
		aWU,R=x,I=x,A=x,G=x,U=x,D=x,N=x,F=x<cr><lf>
		#| If averaging time [A] is greater than update interval [I], it is a multiple of the update interval and at maximum 12 times greater. Example: If I = 5 s, Amax = 60 s.
		Examples (ASCII and NMEA 0183, device address 0):
		#| Changing the measurement interval to 60 seconds:
		0WU,I=60<cr><lf>
		0WU,I=60<cr><lf>
		#| Changing the averaging time to 20 seconds, the wind speed unit to knots, and direction offset to +10°:
		0WU,A=20,U=N,D=10<cr><lf>
		0WU,A=20,U=N,D=10<cr><lf>
		#| Changing the wind parameter selection:
		0WU,R=0100100001001000<cr><lf>
		0WU,R=01001000&00100100<cr><lf>
		#| TEST
		cmd> echo -n -e "0WU,I=60\r\n" | nc -w 2 172.19.6.84 64008
		answ> 0WU,I=60
		}
	}
	REF	8.1.2 Pressure, Temperature, and Humidity Sensors{
			REF 8.1.2.1 Checking the Settings (aTU){
			#| Command format in ASCII and NMEA 0183:
			aTU<cr><lf>
			#| The response in ASCII and NMEA 0183:
			aTU,R=[R],I=[I],P=[P],T=[T]<cr><lf>
			}
			REF 8.1.2.2 Setting Fields{
/**			LEGEND
			|[R] Parameter selection: This field consists of 16 bits defining the PTU parameters included in the data messages. The bit value 0 disables and the bit value 1 enables the parameter.
			|Bits 1-8 determine the parameters included in the message obtained with the following commands:
			|• ASCII: aR2 and ar2
			|	1st bit (most left) Pa Air pressure
			|	2nd bit Ta Air temperature
			|	3rd bit Tp Internal temperature 1)
			|	4th bit Ua Air humidity
			|	5th bit spare
			|	6th bit spare
			|	7th bit spare
			|	8th bit spare
			|	& delimiter
			|Bits 9-16 determine the PTU parameters included in the composite data message obtained with the following commands:
			|• ASCII: aR0 and ar0
			|	9th bit Pa Air pressure
			|	10th bit Ta Air temperature
			|	11th bit Tp Internal temperature1
			|	12th bit Ua Air humidity
			|	13th bit spare
			|	14th bit spare
			|	15th bit spare
			|	16th bit spare
			|[I] Update interval: 1 … 3600 seconds
			|[P] Pressure unit: H = hPa, P = Pascal, B = bar, M = mmHg, I = inHg
			|[T] Temperature unit: C = Celsius, F = Fahrenheit
			|[N] NMEA formatter:
			|	T = XDR (transducer syntax)
			|	D = MDA Defines whether the wind message is sent in XDR or MDA format.
*/			
			#| TEST
			cmd> echo -n -e "0TU\r\n" | nc -w 2 172.19.6.84 64008
			answ> 0TU,R=11010000&11010000,I=60,P=H,T=C,N=T
			}
			REF 8.1.2.3 Changing the Settings (aTU){
			#| Command format in ASCII and NMEA 0183:
			aTU,R=x,I=x,P=x,T=x<cr><lf>
				|R, I, P, T The pressure, temperature and humidity sensor setting fields.
				|x Value for the setting
			}
	}
	REF 8.1.3 Precipitation Sensor{
		REF 8.1.3.1 Checking the Settings (aRU){
		#| Command format in ASCII and NMEA 0183:
		aRU<cr><lf>
		#| The response in ASCII and NMEA 0183:
		aRU,R=[R],I=[I],U=[U],S=[S],M=[M],Z=[Z],X=[X],Y=[Y]<cr> <lf>
		}
		REF 8.1.3.2 Setting Fields{
/**			LEGEND
			|[R] Parameter selection: This field consists of 16 bits defining the precipitation parameters included in the data messages. The bit value 0 disables and the bit value 1 enables the parameter.
			|Bits 1-8 determine the parameters included in the messages obtained with the following commands:
			|• ASCII: aR3 and ar3 left)
			|	1st bit (most left)Rc Rain amount
			|	2nd bit Rd Rain duration
			|	3rd bit Ri Rain intensity
			|	4th bit Hc Hail amount
			|	5th bit Hd Hail duration
			|	6th bit Hi Hail intensity
			|	7th bit Rp Rain peak
			|	8th bit Hp Hail peak
			|	& delimiter
			|Bits 9-16 determine the precipitation parameters included in the composite data messages obtained with the following commands:
			|• ASCII:
			|• NMEA 0183: aR0, ar0
			|	9th bit Rc Rain amount
			|	10th bit Rd Rain duration
			|	11th bit Ri Rain intensity
			|	12th bit Hc Hail amount
			|	13th bit Hd Hail duration
			|	14th bit Hi Hail intensity
			|	15th bit Rp Rain peak
			|	16th bit (most right) Hp Hail peak
			|[I] Update interval: 1 … 3600 seconds. This interval is valid only if the [M] field is = T
			|[U] Precipitation units:
			|	M= metric (accumulated rainfall in mm, Rain duration in s, Rain intensity in mm/h)
			|	I= imperial (the corresponding parameters in units in, s, in/h)
			|[S] Hail units:
			|	M = metric (accumulated hailfall in hits/cm2, Hail event duration in s, Hail intensity in hits/ cm2h)
			|	I = imperial (the corresponding parameters in units hits/in2, s, hits/in2h), H = hits (hits, s, hits/h) Changing the unit resets the precipitation counter.
			|[M] Auto-send mode: R = precipitation on/off, C = tipping bucket, T = time based
			|	R = precipitation on/off: The transmitter sends a precipitation message 10 seconds after the first recognition of precipitation. Rain duration Rd increases in 10 s steps. Precipitation has ended when Ri = 0. This mode is used for indication of the start and the end of the precipitation.
			|	C= tipping bucket: The transmitter sends a precipitation message at each unit increment (0.1 mm/0.01 in). This simulates conventional tipping bucket method.
			|	T= time based: Transmitter sends a precipitation message in the intervals defined in the [I] field. Do not use the auto-send mode tipping bucket in polled protocols as it decreases the resolution of the output (quantized to tipping bucket tips).
			|[Z] Counter reset: M = manual, A = automatic, L= limit Y = immediate
			|	M = manual reset mode: The counter is reset with aXZRU command. See 7.1.2 Precipitation Counter Reset (aXZRU) (page 78).
			|	A = automatic reset mode: The counts are reset after each precipitation message whether in automatic mode or when polled.
			|	L = overflow reset mode. The rain counter or hail counter is reset, when it reaches the predefined limit. The overflow limits (x, y) are defined with the commands aRU,X=x for rain counter and aRU,Y=y for hail counter.
			|	Y = immediate reset: The counts are reset immediately after receiving the command.
			|	[X] Rain accumulation limit : 100...65535. Sets the rain accumulation counter resetting limit. When the value exceeds the limit, the counter is reset to zero. If the precipitation unit aRU,U=x is metric, the limit corresponds the range between 1.00 … 655.35 mm. If the precipitation unit is imperial, the equivalent range varies between 0.100 … 65.535 in. To enable this feature, set the counter reset to aRU,Z=L (overflow reset mode).
			|[Y] Hail accumulation limit: 100 … 65535. Sets the hail accumulation counter resetting limit. When the value exceeds the limit, the counter is reset to zero. If the hail unit aRU,S=x is metric, the limit corresponds the range between 10.0 … 6553.5 hits/ cm2. If the unit is imperial, the equivalent range varies between 100 … 65535 hits/in2. If the unit is hits, the limit matches directly to the amount of hits: 100 … 65535 hits. To enable this feature, set the counter reset to aRU,Z=L (overflow reset mode).
*/			
		}
		REF 8.1.3.3 Changing the Settings (aRU){
		#| Command format in ASCII and NMEA 0183:
		aRU,R=x,I=x, U=x,S=x,M=x,Z=x, X=x, Y=x<cr><lf>
		}
	}
	REF 8.1.4 Supervisor Message{
		REF 8.1.4.1 Checking the Settings (aSU){
		Use this command to check the current supervisor settings.
		#| Command format in ASCII and NMEA 0183:
		aSU<cr><lf>
		#| The response in ASCII and NMEA 0183:
		aSU,R=[R],I=[I],S=[S],H=[Y]<cr><lf>
		}
		REF 8.1.4.2 Setting Fields{
/**		LEGEND
		|[R] Parameter selection: This field consists of 16 bits defining the supervisor parameters included in the data messages. The bit value 0 disables and the bit value 1 enables the parameter.
		|Bits 1-8 determine the parameters included in the message obtained with the following commands:
		|• ASCII: aR5 and ar5
		|	1st bit (most left) Th Heating temperature
		|	2nd bit Vh Heating voltage
		|	3rd bit Vs Supply voltage
		|	4th bit Vr 3.5 V reference voltage
		|	5th bit Id Information field
		|	6th bit spare
		|	7th bit spare
		|	8th bit spare
		|	& delimiter
		|Bits 9-16 determine the supervisor parameters included in the composite data message obtained with the following commands:
		|• ASCII: aR0 and ar0
		|	9th bit Th Heating temperature
		|	10th bit Vh Heating voltage
		|	11th bit Vs Supply voltage
		|	12th bit Vr 3.5 V reference voltage
		|	13th bit Id Information field
		|	14th bit spare
		|	15th bit spare
		|	16th bit (most right) spare
		|[I] Update interval: 1 … 3600 seconds. When the heating is enabled the update interval is forced to 15 seconds.
		|[S] Error messaging: Y = enabled, N = disabled
		|[H] Heating control enable: Y = enabled, N = disabled Heating enabled: The control between full and half heating power is on as described in Heating on page 34. Heating disabled: Heating is off in all conditions.
*/		
		}
		REF 8.1.4.3 Changing the Settings (aSU){
/**		You can change the following settings:
			-Parameters included in the supervisor data message
			-Update interval
			-Error messaging on/off
			-Heating control
*/			
		#Command format in ASCII and NMEA 0183:
		aSU,R=x,I=x,S=x,H=x<cr><lf>
		#Example (ASCII and NMEA 0183, device address 0):
		#Disabling the heating and error messaging:
		0SU,S=N,H=N<cr><lf>
		}
	}
}

{# [8.0] General Settings
	REF 7.1.1 Reset (aXZ){
	#This command performs software reset on the device.
	#Command format in ASCII and NMEA 0183:
	#| TEST ##########################################################################
	aXZ<cr><lf>
	cmd> echo -n -e "0XZ\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0TX,Start-up
	}
	REF 7.1.2 Precipitation Counter Reset (aXZRU){
	#| This command resets the rain and hail accumulation and duration parameters Rc, Rd, Hc, and Hd.
	#| Command format in ASCII and NMEA 0183:
	aXZRU<cr><lf>
	#| TEST ##########################################################################
	cmd> echo -n -e "0XZRU\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0TX,Rain reset
	}
	REF 7.1.3 Precipitation Intensity Reset (aXZRI) {
	#| This command resets the rain and hail intensity parameters Ri, Rp, Hi, and Hp.
	#| Command format in ASCII and NMEA 0183:
	aXZRI<cr><lf>
	#| TEST ##########################################################################
	cmd> echo -n -e "0XZRI\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0TX,Inty reset
	}
	REF 7.1.4 Measurement Reset (aXZM){
	#| This command interrupts all ongoing measurements except rain measurement and restarts them.
	#| Command format in ASCII and NMEA 0183:
	aXZM<cr><lf>
	#| TEST ##########################################################################
	cmd> echo -n -e "0XZM\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0TX,Measurement reset
	}

	REF 7.2.1 Abbreviations and Units {
	#| Table 18 Abbreviations and Units
/**	Abbrev. Name 					Unit 							Status   1)
	Sn 	Wind speed minimum 			m/s, km/h, mph, knots 			#, M, K, S, N
	Sm 	Wind speed average 			m/s, km/h, mph, knots			#, M, K, S, N
	Sx 	Wind speed maximum 			m/s, km/h, mph, knots 			#, M, K, S, N
	Dn 	Wind direction minimum 		deg 							#, D
	Dm 	Wind direction average 		deg 							#, D
	Dx 	Wind direction maximum 		deg 							#, D
	Pa 	Air pressure 				hPa, Pa, bar, mmHg, inHg 		#, H, P, B, M, I
	Ta 	Air temperature 			°C, °F 							#, C, F
	Tp 	Internal temperature 		°C, °F 							#, C, F
	Ua 	Relative humidity 			%RH 							#, P
	Rc 	Rain accumulation 			mm, in 							#, M, I
	Rd 	Rain duration 				s 								#, S
	Ri 	Rain intensity 				mm/h, in/h 						#, M, I
	Rp 	Rain peak intensity 		mm/h, in/h 						#, M, I
	Hc 	Hail accumulation 			hits/cm2, hits/in2, hits 		#, M, I, H
	Hd 	Hail duration 				s 								#, S
	Hi 	Hail intensity 				hits/cm2h, hits/in2h, hits/h	#, M, I, H
	Hp 	Hail peak intensity 		hits/cm2h, hits/in2h, hits/h	#, M, I, H
	Th 	Heating temperature 		°C, °F 							#, C, F
	Vh 	Heating voltage 			V 								#, N, V, W, F   2)
	Vs 	Supply voltage 				V 								V
	Vr 	3.5 V ref. voltage 			V 								V
	Id 	Information field 			alphanumeric
	1) The letters in the status field indicate the Unit, the # character indicates invalid data.
	2) For heating # = heating option is not available (has not been ordered).
		N = heating option is available but have been disabled by user or the heating temperature is over the high control limit.
		V = heating is on at 50% duty cycle and the heating temperature is between the high and middle control limits.
		W = heating is on at 100% duty cycle and the heating temperature is between the low and middle control limits.
		F = heating is on at 50% duty cycle and the heating temperature is below the low control limit.
	}
*/	
	REF 7.2.2 Device Address (?) {
	#| This command queries the address of the device on the bus.
	?<cr><lf>
	#| TEST ##########################################################################
	cmd> echo -n -e "?\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0
	}
	REF 7.2.3 Acknowledge Active Command (a){
	#| This command checks that a device responds to a data recorder or another device. It asks a sensor to acknowledge its presence on the bus.
	a<cr><lf>
	#| TEST
	cmd> echo -n -e "0\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0
	cmd> echo -n -e "0\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0TX,Sync/address error
	}

	REF 7.2.8 Combined Data Message (aR){
	#| This command requests all individual messages aR1, aR2, aR3, and aR5 with one command.
	aR<cr><lf>
	#| Example of the response:
	0R1,Dm=027D,Sm=0.1M<cr><lf>
	0R2,Ta=74.6F,Ua=14.7P,Pa=1012.9H<cr><lf>
	0R3,Rc=0.10M,Rd=2380s,Ri=0.0M,Hc=0.0M,Hd=0s, Hi=0.0M<cr><lf>
	0R5,Th=76.1F,Vh=11.5N,Vs=11.5V,Vr=3.510V,Id=HEL___<cr><lf>
	#| TEST ##########################################################################
	cmd> echo -n -e "0R\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0R1,Dn=090D,Dm=124D,Dx=174D,Sn=0.1M,Sm=0.1M,Sx=0.2M
	answ> 0R2,Ta=23.5C,Ua=53.8P,Pa=984.7H
	answ> 0R3,Rc=0.00M,Rd=0s,Ri=0.0M,Hc=0.0M,Hd=0s,Hi=0.0M
	answ> 0R4,Tr=-301.3#,Ra=0.0M,Sl=0.001153V,Rt=-2038.6R,Sr=-0.566715V
	answ> 0R5,Th=24.2C,Vh=0.0N,Vs=12.2V,Vr=3.656V
	}
	REF 7.2.9 Composite Data Message Query (aR0){
	#| This command requests a combined data message with user-configurable set of wind, pressure, temperature, humidity, precipitation, and supervisor data.
	aR0<cr><lf>
	#| Example of the response (you can select the parameters included from the full parameter set of the commands aR1, aR2, aR3, and aR5):
	0R0,Dx=005D,Sx=2.8M,Ta=23.0C,Ua=30.0P,Pa=1028.2H, Rc=0.00M,Rd=10s,Th=23.6C<cr><lf>
	#| TEST ##########################################################################
	cmd> echo -n -e "0R0\r\n" | nc -w 2 172.19.6.84 64008
	answ> 0R0,Dm=204D,Sm=0.1M,Ta=23.4C,Ua=53.7P,Pa=984.6H,Rc=0.00M,Tr=128.4C,Ra=0.0M,Sl=0.001262V,Sr=-0.463549V,Rt=1505.6R,Th=24.2C,Vh=0.0N
	}
}

{# [A] WXT536_bug#01 

}

