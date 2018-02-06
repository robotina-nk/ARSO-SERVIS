#!/bin/sh
#//**! \header 
#*   Copyright bcer 2009 - 2017/09
#*   Project name.: xoberl_4000
#*   File.........: WS700.hxx
#*   Author.......: (c) Bojan Cernac - bcer, Nikola Kostic - nkostic
#*   Target / OS..: Nport8410, uc8410-LX  / Linux Moxa 2.6.10_devixdp42x-arm_xscale_be  Busybox v1.6.0
#*   Compiler.....: GNU 3.4.4 arm_linuc_gcc C Compiler V3.4.4
#*   Description..: TCP Serial server, Embedded Computer
#*   Version......: 3000.5
#*   Machine......: PC AT compatible, OS: WindowsXP & VitrualBox 3.1.2 ( Linux Ubuntu 9.10 )
#*   Created......: 2017-04 (september)
#*   Last update..: 2017-09-22
#**  \endheader */
/* POWER CONSUMPTION: Specified: 160 mA, Measured: 155mA ,INITIAL CURRENT 290 mA, 75mA without FAN, 55mA ECO mode */

/**	UMB ISO-Con module
		- Can be used for initial configuration with UMB Config Tool SW
		- NOT necessary, just for Data logger - SDI12 mode
*/
/** UMB Config Tool
		- Software for configuration of the WS700 sensor
		- Supported Communication  protocols
			- REF 10.2.3 General Settings
				- Communications protocol of the sensor (UMB-Binary, UMB-ASCII, SDI-12, Modbus-RTU, Modbus-ASCII, Terminal-Mode, XDR).
*/
/**	MEASURED PHYSICAL PROPERTIES
		Precipitation Radar
		Wind Direction
		Wind Speed
		Air Temperature
		Relative Humidity
		Air Pressure
		Compass
		Global Radiation	
*/
/**	RS485 Interface
	The equipment has an electrically isolated, half-duplex, 2 wire RS485 interface for configuration, measurement polling and the firmware update.
	See page 46 for technical details.
*/


{# [I.]  frequently used commands WS700

}

{# [II.] UART WS700 / N3_Nport_8410 config / wiring
/*	Sensor WS700 UART settings (DEFAULT)
		Baud rate: 19200
		Data bits: 8
		Parity: none 
		Stop bits: 1 
		Flow ctrol:none
		Interface: RS-485 2-Wire	
*/
/*	Sensor WS700 UART settings (CURRENT)
		Baud rate: 19200
		Data bits: 8
		Parity: none 
		Stop bits: 1 
		Flow ctrol:none
		Interface: RS-485 2-Wire
*/
/*	MOXA NPort 5650-8DT-J settings 
		IP: 172.19.7.137
		Serial port: 8
		Baud rate: 19200
		Data bits: 8
		Stop bits: 1 
		Parity: none 
		FIFO: disable 
		Flow ctrol:none
		Interface: RS-485 2-Wire	
*/	
}



{# [1.0] Read Sensor Config

}

{# [2.0] Setting Uart Config N3-8	
SET TO:
		Baud rate: 19200
		Data bits: 8
		Stop bits: 1 
		Parity: none 
		FIFO: disable 
		Flow ctrol:none
		Interface: RS-485 2-Wire	
}

{# [2.1] Read Uart Config N3-8
telnet 172.19.7.137
Trying 172.19.7.137...
Connected to 172.19.7.137.
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
Interface                      : RS-485 2-Wire	

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
/**	SETTING UP TERMINAL for the communication (data poll)
		Hyper terminal over Aten USB<->232: 
			(COM Port8), 19200 8N1 flowCTRL:none, 
			File | Properties | Settings | Ascii Setup | check Echo typed characters locally, Send line end with line feeds		
*/	
/**	TESTING with HYPERTERMINAL (UMB ICO-Con module connected)
		E0
		E0;Ta+022.7C;Tp+009.7C;Tw+024.8C;Hr+043.8P;Pa+0987.3H;Sa+000.0M;Da+000.0D;Ra+00000.00M;Rt+000N;Ri+000.0M;
*/		
/**	TESTING with FTDI USB-RS485-WE (WITHOUT UMB ISO-Con module & RS232 interface)
		WIRING:
			FTDI (2)[yellow]|DATA-/B| <->  |RS485_B|[yellow](4) WS700
			FTDI (5)[orange]|DATA+/A| <->  |RS485_A|[green](3) WS700
				[img05.jpg] [power supply 24VDC connected sepparately - not on the picture]
		TESTING with HYPERTERMINAL
			E0
			E0;Ta+024.0C;Tp+008.8C;Tw+000.0C;Hr+038.0P;Pa+0985.8H;Sa+000.0M;Da+000.0D;Ra+00000.00M;Rt+000N;Ri+000.0M;
*/			
/**	TESTING OVER MOXA NPORT 5650-8FT-J: 
		SERIAL Settings:
			IP: 172.19.7.137
			Serial port: 8
			Baud rate: 19200
			Data bits: 8
			Stop bits: 1 
			Parity: none 
			FIFO: disable 
			Flow ctrol:none
			Interface: RS-485 2-Wire		
		Wiring:
			White 		Supply voltage ground   <-> (1) GND
			Brown 		Positive supply voltage <-> (7) 24VDC
			Green 		RS485_A (+)             <-> (5) RxD+
			Yellow 		RS485_B (-)         	<->	(6) RxD-
		Listen
			ssh root@172.19.7.135
			cat < /dev/tcp/172.19.7.137/64008
			# img06.jpg
		Commands issuing
			echo -n -e "E0\r\n" | nc -w 2 172.19.7.137 64008	
		E0;Ta+023.3C;Tp+008.8C;Tw+025.5C;Hr+039.5P;Pa+0985.7H;Sa+000.0M;Da+000.0D;Ra+00000.00M;Rt+000N;Ri+000.0M;
*/	
}

{# [4.0] Sensor Initialization
/**	SW700 Pin assignment:
		1 White 	Supply voltage ground and (SDI12_GND for device version > 41)
		2 Brown 	Positive supply voltage (through 2.5A fuse where required)*
		3 Green 	RS485_A (+) or (SDI-12 GND for device version < 42)
		4 Yellow 	RS485_B (-) or SDI-12 Data Line
		5 Grey 		External Sensor a (WS100-UMB only: impulse output Uout)
		6 Pink 		External Sensor b (WS100-UMB only: not connected)
		7 Blue 		Heating voltage ground
		8 Red 		Positive heating voltage (through 2.5A fuse where required)*
	*/
/**	POWER SUPPLY & PROTECTION
		WS100/400/600/700/800-UMB: Supply voltage and heating voltage shall be protected by a fuses 2.5A (fast) each.	
		REF 8.1 Supply Voltage
			The supply voltage for the Smart Weather Sensor is 12 - 24V DC. The power supply unit used must be approved for operation with equipment of protection class III (SELV).
			Starting with device version 037 the Smart Weather Sensor has an extended supply voltage range of 4 … 32V DC. Operation with a supply voltage of 24V is recommended.
*/	
/**	CONNECTING DEVICE: Sensor WS700 <-> UMB ISO-Con <-> Aten_USB_to_232_Adapter <-> PC 
		Sensor WS700 <-> Factory cable
			[img01.jpg]
		Factory cable <-> UMB ISO-Con DATA
			[img02.jpg] 
				Greeen(A), Yellow(B), White(GND2), Brown(+24V) 
		UMB ISO-Con <-> POWER SUPPLY 
			[img03.jpg, img04.jpg]
*/	
/**	Using >>UMB Config Tool SW<< to test the  connection to the sensor 
		HOWTO: https://www.youtube.com/watch?v=FVI7kPLJ_JM
		Setup_UMB_Config_V26.EXE
			Com8
			Edit -> Connection settings -> Use RS232(COM) , Select port 8 ## RESET IF NOT VISIBLE !!!
			Edit -> Sensors -> Autoscan -> Verify -> Save/Exit
			IN THE CONSEQUENT TESTING, THE UMB CONFIG TOOL WAS UNABLE TO DETECT THE SENSOR: =>
				Edit -> Sensors ->
					Type of Sensor: WSx-UMB, ID:1, Add, Configure, select it from the list, "Load profile from sensor"
						WSx-UMB tab
						CHANGE OF SETTINGS IS DONE WITH "Store profile on sensor" button.
*/
/**	Using >>UMB Config Tool SW<< to SET the communication to TERMINAL MODE 
		REF 19.5 Communication in Terminal Mode
			Edit -> Sensors -> Mark the sensor in the sensor list -> Configure -> Load profile from sensor		
					* DEFAULT Protocol is UMB-Binary => change to terminal mode, store profile on sensor
			Note: In the case of communication in the terminal mode, only one single unit may be connected to the interface, as this protocol is NOT network-compatible. It is used for very simple measurement value requests	
			RESET PC
			SENSOR: POWER OFF / POWER ON
*/
}

{# [4.1] Sensor Data Request: polling data from WS700
		Listen
			ssh root@172.19.7.135
			cat < /dev/tcp/172.19.7.137/64008
			# img06.jpg
		Commands issuing
			echo -n -e "E0\r\n" | nc -w 2 172.19.7.137 64008	
		E0;Ta+023.3C;Tp+008.8C;Tw+025.5C;Hr+039.5P;Pa+0985.7H;Sa+000.0M;Da+000.0D;Ra+00000.00M;Rt+000N;Ri+000.0M;
}



{# [5.0] Set Sensor Bus Address  

}

{# [6.0] Setting the Sensor Period Output Report Interval 

}

{# [7.0] Defining Sensor Output Format  
/**REF 19.5.1 Structure
A terminal consists of an ASCII character and a numeric character. The command is
completed with the <CR> sign. There is no echo on entry.
The individual values in the response are separated by a semi-colon (;). The response is
completed with <CR><LF>.
An invalid terminal command is acknowledged with ‘FAILED’. Control commands are
acknowledged with ‘OK’.
The command to which the response relates is given at the beginning of each response.
*/
/**REF 19.5.2 Terminal Commands
The terminal commands transmit the following values or have the following functions:
E0<CR> 	Temperature in °C 					Ta C (Channel 100)
		Dew point temperature in °C 		Tp C (Channel 110)
		Wind chill temperature in °C 		Tw C (Channel 111)
		Relative humidity in % 				Hr P (Channel 200)
		Relative air pressure in hPa 		Pa H (Channel 305)
		Wind speed in m/s 					Sa M (Channel 400)
		Wind dirction in ° 					Da D (Channel 500)
		Precipitation quantity in mm 		Ra M (Channel 620)
		Precipitation type 					Rt N (Channel 700)
		Precipitation intensity in mm/h 	Ri M (Channel 820)
E1<CR> 	Temperature in °F 					Ta F (Channel 105)
		Dew point temperature in °F 		Tp F (Channel 115)
		Wind chill temperature in °F 		Tw F (Channel 116)
		Relative humidity in % 				Hr P (Channel 200)
		Relative air pressure in hPa 		Pa H (Channel 305)
		Wind speed in mph 					Sa S (Channel 410)
		Wind direction in ° 				Da D (Channel 500)
		Precipitation quantity in inches 	Ra I (Channel 640)
		Precipitation type 					Rt N (Channel 700)
		Precipitation intensity in inches/h Ri I (Channel 840)
E2<CR> 	Act. wind speed in m/s 				Sa M (Channel 400)
		Min. wind speed in m/s 				Sn M (Channel 420)
		Max. wind speed in m/s 				Sx M (Channel 440)
		Avg. wind speed in m/s 				Sg M (Channel 460)
		Vct. wind speed in m/s 				Sv M (Channel 480)
		Act. wind direction in °			Da D (Channel 500)
		Min. wind direction in ° 			Dn D (Channel 520)
		Max. wind direction in ° 			Dx D (Channel 540)
		Vct. wind direction in ° 			Dv D (Channel 580)
E3<CR> Act. wind speed in mph 				Sa S (Channel 410)
		Min. wind speed in mph 				Sn S (Channel 430)
		Max. wind speed in mph 				Sx S (Channel 450)
		Avg. wind speed in mph 				Sg S (Channel 470)
		Vct. wind speed in mph 				Sv S (Channel 490)
		Act. wind direction in ° 			Da D (Channel 500)
		Min. wind direction in ° 			Dn D (Channel 520)
		Max. wind direction in ° 			Dx D (Channel 540)
		Vectorial wind direction in ° 		Dv D (Channel 580)
E4<CR> 	Act. Compass heading in ° 			Ca D (Channel 510)
		Act. Global Radiation in W/m2 		Ga W (Channel 900)
		Min. Global Radiation in W/m2 		Gn W (Channel 920)
		Max. Global Radiation in W/m2 		Gx W (Channel 940)
		Avg. Global Radiation in W/m2 		Gg W (Channel 960)
		Act. Specific Enthalpy in KJ/Kg 	Ea J (Channel 215)
		Act. Wet Bulb Temperature in °C 	Ba C (Channel 114)
		Act. Wet Bulb Temperature in °F 	Ba F (Channel 119)
		Act. Air Density in kg/m3 			Ad G (Channel 310)
E5<CR> 	reserved 							La X (Channel 710)
		reserved 							Lb X (Channel 711)
		external temperature (act) °C 		Te C (Channel 101)
		external temperature (act) °F 		Te F (Channel 106)
		lightning events (min) 				Lm E (Channel 617)
		lightning events (interval) 		Li E (Channel 677)

Mx<CR> 	Displays the same values as Ex<CR>, but without additional information such as the measurement variable and unit
I0<CR> 	Serial number; date of manufacture; project number; parts list version; SPLAN version; hardware version; firmware version; E2 version; device version
I1<CR> 	Outputs the device description
R0<CR> 	Executes a device reset
R1<CR> 	Resets the accumulated rain quantity and executes a device reset
X0<CR> 	Temporarily switches to UMB binary protocol
*/
/**REF  Examples:
E0<CR> 	E0;Ta+024.9C;Tp+012.2C;Tw+026.8C;Hr+045.0P;Pa+0980.6H;Sa+005.1M;Da+156.6D;Ra+00042.24M;Rt+060N;Ri+002.6M;
M0<CR> M0;+024.9;+012.2;+026.8;+045.0;+0980.6;+005.1;+156.6;+00042.24;+060;+002.6;
E2<CR> E2;Sa+005.1M;Sn+001.1M;Sx+007.1M;Sg+005.1M;Sv+005.0M;Da+156.6D;Dn+166.6D;Dx+176.6D;Dv+156.6D;
M2<CR> M2;+005.1;+001.1;+007.1;+005.1;+005.0;+156.6;+166.6;+176.6;+156.6;
I0<CR> I0;001;0109;0701;004;005;001;016;011;00002;<CR><LF>
R0<CR> R0;OK;<CR><LF>
*/
}



}




