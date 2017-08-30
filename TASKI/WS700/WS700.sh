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


Protocol je UMB-Binary - change to terminal mode, store profile on sensor

