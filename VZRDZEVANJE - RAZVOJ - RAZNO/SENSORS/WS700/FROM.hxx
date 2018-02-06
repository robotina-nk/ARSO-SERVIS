WS700-UMB 8380.U01 (Europe, USA, Canada)
 Precipitation Radar
 Wind Direction
 Wind Speed
 Air Temperature
 Relative Humidity
 Air Pressure
 Compass
 Global Radiation

Pin assignment:
1 White 	Supply voltage ground and (SDI12_GND for device version > 41)
2 Brown 	Positive supply voltage (through 2.5A fuse where required)*
3 Green 	RS485_A (+) or (SDI-12 GND for device version < 42)
4 Yellow 	RS485_B (-) or SDI-12 Data Line
5 Grey 		External Sensor a (WS100-UMB only: impulse output Uout)
6 Pink 		External Sensor b (WS100-UMB only: not connected)
7 Blue 		Heating voltage ground
8 Red 		Positive heating voltage (through 2.5A fuse where required)*

*) WS100/400/600/700/800-UMB: Supply voltage and heating voltage shall be protected
by a fuses 2.5A (fast) each.

8.1 Supply Voltage
The supply voltage for the Smart Weather Sensor is 12 - 24V DC. The power supply unit
used must be approved for operation with equipment of protection class III (SELV).
Starting with device version 037 the Smart Weather Sensor has an extended supply voltage
range of 4 … 32V DC. Operation with a supply voltage of 24V is recommended


8.2 RS485 Interface
The equipment has an electrically isolated, half-duplex, 2 wire RS485 interface for
configuration, measurement polling and the firmware update.
See page 46 for technical details.


https://www.youtube.com/watch?v=FVI7kPLJ_JM
Setup_UMB_Config_V26.EXE


SEARCH for 232 straight through cable (na obe strani matica)

UMB ISO-Con
UMB Config Tool
Com8
Edit | Connection settings | Use RS232(COM) , Select port 8 << težave - se ni videl
Edit | Sensors | Autoscan | Verify | Save/Exit
Edit | Sensors | Mark the sensor in the sensor list | Configure | Load profile from sensor

Communication  protocols
10.2.3 General Settings
Communications protocol of the sensor (UMB-Binary, UMB-ASCII, SDI-12,
Modbus-RTU, Modbus-ASCII, Terminal-Mode, XDR).

19.5 Communication in Terminal Mode
Protocol je UMB-Binary - change to terminal mode, store profile on sensor
Note: In the case of communication in the terminal mode, only one single unit may be
connected to the interface, as this protocol is NOT network-compatible. It is used for very
simple measurement value requests
RESET PC AND SENSOR POWER OFF ON


05.19.2017
call Kruscic - isocon module  - not necessary, just for Data logger - SDI12 mode
Connections:
Hyper terminal over Aten USB<->232: Port8, 19200 8N1 flowCTRL:none, File | Properties | Settings | Ascii Setup | check Echo typed characters locally, Send line end with line feeds
Factory connector: DEVICE <-> UMB: Greeen(A), Yellow(B), 
										img01.jpg img02.jpg
									White(GND2), Brown(+24V) 
										img03.jpg, img04.jpg
HyperTerminal:
E0
E0;Ta+022.7C;Tp+009.7C;Tw+024.8C;Hr+043.8P;Pa+0987.3H;Sa+000.0M;Da+000.0D;Ra+000
00.00M;Rt+000N;Ri+000.0M;


Testiranje komunikacije RS485 mimo UMB modula , namesto prek UMB modula in rs232 vmesnika
Testirano prek FTDI USB-RS485-WE:
FTDI (2)[yellow]{DATA-/B} <->  {RS485_B}[yellow](4) WXT700
FTDI (5)[orange]{DATA+/A} <->  {RS485_A}[green](3) WXT700
	img05.jpg (napajanje 24VDC je izvedeno posebaj - ni na sliki)

E0;Ta+024.0C;Tp+008.8C;Tw+000.0C;Hr+038.0P;Pa+0985.8H;Sa+000.0M;Da+000.0D;Ra+000
00.00M;Rt+000N;Ri+000.0M;


Test prek moxe in doze
ssh root@172.19.7.135
cat < /dev/tcp/172.19.7.137/64008
	img06.jpg
echo -n -e "E0\r\n" | nc -w 2 172.19.7.137 64008	
E0;Ta+023.3C;Tp+008.8C;Tw+025.5C;Hr+039.5P;Pa+0985.7H;Sa+000.0M;Da+000.0D;Ra+00000.00M;Rt+000N;Ri+000.0M;


19.5.1 Structure
A terminal consists of an ASCII character and a numeric character. The command is
completed with the <CR> sign. There is no echo on entry.
The individual values in the response are separated by a semi-colon (;). The response is
completed with <CR><LF>.
An invalid terminal command is acknowledged with ‘FAILED’. Control commands are
acknowledged with ‘OK’.
The command to which the response relates is given at the beginning of each response.

19.5.2 Terminal Commands - ################ TODO COPY HERE ################