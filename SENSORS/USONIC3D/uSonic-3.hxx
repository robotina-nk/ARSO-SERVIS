#!/bin/sh
#//**! \header 
#*   Copyright bcer 2009
#*   Project name.: moberl_3000
#*   File.........: uSonic-3.sh
#*   Author.......: (c) Bojan Cernac - bcer
#*   Target / OS..: Nport6450 uc7420Plus, uc8410-LX  / Linux Moxa 2.6.10_devixdp42x-arm_xscale_be  Busybox v1.6.0
#*   Compiler.....: GNU 3.4.4 arm_linuc_gcc C Compiler V3.4.4
#*   Description..: TCP Serial server, Embedded Computer
#*   Version......: 3000.5
#*   Machine......: PC AT compatible, OS: WindowsXP & VitrualBox 3.1.2 ( Linux Ubuntu 9.10 )
#*   Created......: 2016-12 (feb)
#*   Last update..: 2016-12-02
#**  \endheader */


{#  [I.]  frequently used commnads
/*# Listen on MOXA uc8410*/
	#open terminal:
	ssh root@172.19.7.170
	cat < /dev/tcp/172.19.7.172/64008

/*# Asking for the averaging time*/
	# AT? <ENTER>
	printf "AT?\n" | nc -w 2 172.19.7.172 64008
		# Reply from uSonic-3
		USnc-3/T > AT?
		SNC 160511135452 UTC+0000 result: 10

/*# Setting the averaging time to 5s		*/
	printf "AT=5\n" | nc -w 2 172.19.7.172 64008
		# Reply from uSonic-3
		USnc-3/T > AT=5
		
/*# Echo setting		*/
	#EC=0 No reflection of the commands.(recommended for RS485) 
	printf "EC=0\n"| nc -w 2 172.19.7.172 64008

	#EC=1 All commands will be reflected by the uSonic-3 when the ENTER- key is pushed.
	printf "EC=1\n"| nc -w 2 172.19.7.172 64008		
			
}

{#  [II.1] uart_Nport6450_config (CURRENT)
#	SerialPort:	/dev/tcp/172.19.7.172/64008
# 	Interface:	RS422
#	Protocol:	ASCII_RS422
#	addr:		0
#	baud_rate:	9600
#	parity:		none
# 	data_bits:	8
#	stop_bits:	1
# 	Flow ctrl:	XON/XOFF
}

{#  [II.2a] uart_Sonic3 (DEFAULT)
#	SerialPort:	/dev/tcp/172.19.7.172/64008
# 	Interface:	RS422
#	Protocol:	ASCII_RS422
#	addr:		0
#	baud_rate:	9600
#	parity:		none
# 	data_bits:	8
#	stop_bits:	1
# 	Flow ctrl:	XON/XOFF
}

{#  [II.2b] uart_Sonic3 (CURRENT)
#	SerialPort:	/dev/tcp/172.19.7.172/64008
# 	Interface:	RS422
#	Protocol:	ASCII_RS422
#	addr:		0
#	baud_rate:	9600
#	parity:		none
# 	data_bits:	8
#	stop_bits:	1
# 	Flow ctrl:	XON/XOFF
}

{#  [1.0] Read Sensor Config
/*Asking all system parameter*/{
	printf "?\n"| nc -w 2 172.19.7.172 64008
}
/*# Reply from uSonic-3*/{
	USnc-3/T > ?
	SNC 160511143615 UTC+0000 variables:

		 A1=1853
		 A2=1915
		 A3=1966
		 A4=1909
		 A5=2040
		 A6=2037
		 AD=0
		 AE=0
		 AI=0
		 AO=0
		 AT=5
		 AV=4
		 AZ=0
		 BF=420
		 BR=9600
		 BV=3646
		 DC=1
		 EC=1
		 FR=0
		 HC=0
		 HD=0
		 HE=0
		 HT=0
		 LC=12.01.15 16:03:26
		 LD=0
		 LF=2099
		 LT=2099
		 LU=0
		 MD=20
		 N0=
		 N1=urcal
		 N2=urcal
		 N3=urcal
		 O1=1821
		 O2=1822
		 O3=1755
		 O4=1763
		 O5=1853
		 O6=1857
		 OA=0
		 OD=1
		 OI=0
		 P1=1375
		 P2=1378
		 P3=1372
		 PR=0
		 QT=70
		 SF=20000
		 SN=0107124790
		 SO=0
		 SY=0
		 TC=2003
		 TI=11.05.16 14:36:15
		 TR=4500
		 TV=0
		 TZ=+0000
		 US=0
		 VD=140410135526
		 VN=5.56otp
		 VR=6000
		 ZR=100
}
/*# Parameters and commands / meaning / page in the manual 2013Dec_uSonic3_Omni_V554_RS232_Manual.pdf*/{

	SF Sampling Frequency 35
	AV Total Averaging Number 35
	AT Averaging Time 35
	SY Synchronized Averaging 35 
	SO Synchronized Offset 36
	AZ Device Azimuth 36
	HC Head Correction 37
	SA Scalar Averaging 37
	HT Heating (option) 37
	OD Output Digital 38
	OA Output Analog 38
	AO Analog Offset 38
	AE Analog Errorhandling 38 HE Heater Error 39
	QT Qualitiy Threshold 39
	VR Velocity Range 39
	ZR z-Range 40
	TR Temperature Range 40
	TV Test Values 40
	TC Calibration Temperature 40
	P1 … P3 Path Lengths 1,2,3 41
	O1 … O6 Calibration offsets 41
	LC Last Calibration 41
	BR Baudrate 42
	PR Protocol 42
	NO NMEA Options 42
	FR Frame 43
	AD Device Address 43
	EC Echo 44
	TI Time and Date 44
	MD Maximum Deviation 44
	N0 ... N3 Name Parameters 45
	S1 ... S3 Save Parameters 45
	L1 … L3 Load Parameters 45
	LD Log Data 46
	AA Abort Averaging Interval 46
	RD Redraw Data 46
	RL Read Log 46
	LS Log Status 47 
	VS Version number 47 
	BS Battery Status 47 
	? Output of configuration 48 
	CA Calibration 48 
	RS Reset 48 
	SV Service mode 48
}
}

{#  [2.0] Setting Uart Config
  telnet 172.19.7.172 
					# RS485-hd
					# baudrate to "9600"	[9600]
					# data lenght to "8bit" [cs8]
					# parity to  "none" 	[-parenb]
					# stop bit to  "1" 	[-cstopb]
					# don't loop back recieved characters [-echo]
					# Map CR to NL on input.	
}				

{#  [2.1] Read Uart Config
	telnet 172.19.7.172
	Port 8	
	Baud rate                      : 9600
	Data bits                      : 8
	Stop bits                      : 1  
	Parity                         : None
	Flow control                   : XON/XOFF
	FIFO                           : Enable
	Interface                      : RS-422
}

{#  [3.0] System Sensor Setup (uart, operating modes)
#	SerialPort:	/dev/tcp/172.19.7.172/64008 (DEFAULT / CURRENT)
# 	Interface:	RS422
#	Protocol:	ASCII_RS422
#	addr:		0
#	baud_rate:	9600
#	parity:		none
# 	data_bits:	8
#	stop_bits:	1
# 	Flow ctrl:	XON/XOFF
}

{# [4.0] Sensor Initialization
" nastavitve za operativno delovanje"
	# Povezava -ya RA422
	printf "AT=0\n" | nc -w 2 172.19.7.172 64008 #AVERAGING TIME
	printf "RD\n"| nc -w 2 172.19.7.172 64008 #REDRAW DATA
} 

{# [4.1] Sensor Data Request: polling data from uSonic-3
#The user is asking for the latest dataset.
	printf "RD\n"| nc -w 2 172.19.7.172 64008
	# Reply from uSonic-3
	USnc-3/T > RD
	SNC 160511145624 UTC+0000 AVE      10 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
	x =    0.00     y =    0.06     z =   -0.08     T =   23.02
	xsig =  0.0536  ysig =  0.0599  zsig =  0.0522  Tsig =  0.0671
	xycov = -0.0007 xzcov = -0.0007 xTcov =  0.0002
	yzcov =  0.0013 yTcov = -0.0007 zTcov = -0.0021
	psig =  0.0417  qsig =  0.0533  rsig =  0.0678
	tp =  0.4180    tq =  0.5342    tr =  0.6794
	mgust =    0.09 thsig =    10.0 phsig =    12.6 DiffC =       E
	ustar =  0.0392 Tstar = -0.0533    Cd = 0.00726    CT = 0.61162
	MOs =   0.459    mf =   0.000    hf =  -2.506   nrb =  -5.532
	u =    0.00     v =    0.06     w =   -0.08
	vel =    0.06   dir =   178.8  svel =    0.09  sdir =   185.9
	none =       0  none =       0  none =       0  none =       0
	none =       0  none =       0  none =       0  none =       0		
}

{# [4.2] Values names - legend - additional info from uSonic-3_Manual_Turb.pdf
AVE      	averaging time as set by AT
SMP			sample rate as set by SF
AZI     	azimut setting as set by AZ
SDQ     	sonic data quality
MDE      	maximum deviation as set by MD
HTR      	heater control und heater status as defined by HT
SHC       	Sensor Head Correction as set by HC=0, for the applied flow distortion correction.
UST       	type of ustar derivation as set by ustar (ustar: friction velocity)
NRB     	BF factor of Net Radiation Balance derivation
x 			mean wind component along x-axis of sensor head
y 			mean wind component along y-axis of sensor head
z 			mean wind component along z-axis (vertical) of sensor head
T 			sonic temperature as measured
xsig 		std.dev. of mean wind component along x-axis of sensor head
ysig 		std.dev. of mean wind component along y-axis of sensor head
zsig 		std.dev. of mean wind component along z-axis (vertical)of sensor head
Tsig 		std.dev. of sonic temperature
xycov		covariance of x and y
xzcov		covariance of x and z
xTcov 		covariance of x and T
yzcov 		covariance of y and z
yTcov 		covariance of y and T
zTcov		covariance of z and T
psig 		std.dev. of mean wind component parallel to the mean 3-D wind vectorP
qsig 		std.dev. of horizontal mean wind comp. perpendicular to the mean 3-D wind vector P
rsig 		std.dev. of mean wind comp. perpendicular and vertical to the mean 3-D wind vector P
tp			std.dev. of mean wind comp. parallel to the mean 3-D wind vectorP, divided by wind speed
tq			std.dev. of horizontal m. wind comp. perp. to the vectorP, divided by wind speed
tr 			std.dev. of m. wind comp. perp. and vert. to the vector P, divided by wind speed
mgust 		max. wind gust (derived for a 3 s period) within the averaging interval
thsig		std.dev. of horizontal wind direction
phsig		std.dev. of vertical wind direction
DiffC		diffusion class derived from parameterized net radiation balance nrb
ustar		friction velocity u *
Tstar		characteristic temperature T *
Cd			drag coefficient
CT			structure constant of temperature CT2
Mos			Monin Obukhov stability
mf			vertical momentum flux
hf			vertical heat flux, corrected for cross wind component
nrb			parameterized radiation balance, derived from turbulent heat flux hf
u			mean west-east wind component
v			mean south-north wind component
w			mean vertical wind component
vel			mean horizontal wind speed, vector average
dir			mean horizontal wind direction, vector average
svel		mean horizontal wind speed, scalar average
sdir		mean horizontal wind direction, scalar average
}

{# [5.0] Set Sensor Bus Address  			
 - not implemented
}

{# [6.0] Setting the Sensor Period Output Report Interval 
####  

	# Setting the averaging time to 5s		
	printf "AT=5\n" | nc -w 2 172.19.7.172 64008
		# Reply from uSonic-3
		USnc-3/T > AT=5

}

{# [7.0] Defining Sensor Output Format  
/*Choice of values with the parameter OD (output digital)
The uSonic-3 provides following values:
Value	Scale		Meaning								Measurement range
x		0,01 m/s	x- component of wind				0 … 60 m/s
y		0,01 m/s	y- component of wind				0 … 60 m/s
z		0,01 m/s	z- component of wind				0 … 60 m/s
t		0,01°C		acoustic temperature				-40 … 70°C
v		0,01 m/s	horizontal windspeed				0 … 60 m/s
vs		0,01 m/s	horizontal windspeed				0 … 60 m/s
		(scalar averaged)
d		Grad		wind direction						0 … 359°
dh		Grad		wind direction (with hysteresis)	0 … 539°

Choose the displayed values with the command OD (Output Digital):
Value of OD				data set
0						no data output
1						x,y,z,t
2						v,d,z,t
3						v,dh,z,t	
32						test values (see below)
64						timestamp (time)
128						timestamp (date and time)
2048					Additional display of data quality
The values OD=1,2 und 3 can be combined with the values 64, 128 and/ or 2048.
Examples:
OD=0 No data will be displayed. 
OD=2 The values v, d, z and t will be displayed. 
OD=129 The values x,y,z,t and a time stamp (date and time) will be displayed. (Combination of OD=1 and OD=128 >> OD=129) 
OD=32 Display of test values for functional analysis.
*/

USnc-3/T > OD?
SNC 160512153444 UTC+0000 result: 1


SNC 160512153451 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
    x =   -0.03     y =    0.03     z =   -0.05     T =   23.15
 xsig =  0.0504  ysig =  0.0451  zsig =  0.0314  Tsig =  0.0739
xycov = -0.0005 xzcov =  0.0004 xTcov =  0.0005
yzcov =  0.0001 yTcov = -0.0005 zTcov = -0.0002
 psig =  0.0454  qsig =  0.0420  rsig =  0.0416
   tp =  0.6794    tq =  0.6279    tr =  0.6219
mgust =    0.08 thsig =     7.7 phsig =     7.7 DiffC =       D
ustar =  0.0213 Tstar = -0.0073    Cd =-0.20863    CT = 0.13323
  MOs =   0.213    mf =   0.001    hf =  -0.186   nrb =  -0.424
    u =   -0.03     v =    0.03     w =   -0.05
  vel =    0.04   dir =   133.5  svel =    0.07  sdir =   148.9
 none =       0  none =       0  none =       0  none =       0
 none =       0  none =       0  none =       0  none =       0

 
USnc-3/T > OD=4
SNC 160512153627 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
   e1 = -99.999    e2 = -99.999    e3 = -9.9999    e4 = -9.9999
e1sig =  6.3125 e2sig =  6.3125 e3sig =  0.0000 e4sig =  0.0000
e1zco =  0.0183 e2zco =  0.0183 e3zco =  0.0000 e4zco =  0.0000
SNC 160512153639 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
   e1 = -99.999    e2 = -99.999    e3 = -9.9999    e4 = -9.9999
e1sig =  0.0000 e2sig =  0.0000 e3sig =  0.0000 e4sig =  0.0000
e1zco =  0.0000 e2zco =  0.0000 e3zco =  0.0000 e4zco =  0.0000


USnc-3/T > OD=5
SNC 160512153651 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
    x =   -0.01     y =    0.02     z =   -0.02     T =   23.36
   e1 = -99.999    e2 = -99.999    e3 = -9.9999    e4 = -9.9999
 xsig =  0.0416  ysig =  0.0389  zsig =  0.0307  Tsig =  0.1119
e1sig =  0.0000 e2sig =  0.0000 e3sig =  0.0000 e4sig =  0.0000
xycov =  0.0005 xzcov = -0.0001 xTcov = -0.0007
yzcov =  0.0003 yTcov = -0.0003 zTcov =  0.0010
e1zco =  0.0000 e2zco =  0.0000 e3zco =  0.0000 e4zco =  0.0000
 psig =  0.0274  qsig =  0.0463  rsig =  0.0360
   tp =  1.0005    tq =  1.6938    tr =  1.3145
mgust =    0.06 thsig =     8.7 phsig =     6.6 DiffC =       D
ustar =  0.0170 Tstar =  0.0607    Cd =-0.12355    CT =11.18622
  MOs =  -2.768    mf =   0.000    hf =   1.238   nrb =   2.948
    u =   -0.01     v =    0.02     w =   -0.02
  vel =    0.02   dir =   142.2  svel =    0.05  sdir =   144.3
 none =       0  none =       0  none =       0  none =       0
 none =       0  none =       0  none =       0  none =       0

 
USnc-3/T > OD=8
SNC 160512153715 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
   e5 = -9.9999    e6 = -9.9999    e7 = -9.9999    e8 = -9.9999
e5sig =  0.0000 e6sig =  0.0000 e7sig =  0.0000 e8sig =  0.0000
e5zco =  0.0000 e6zco =  0.0000 e7zco =  0.0000 e8zco =  0.0000


USnc-3/T > OD=9
SNC 160512153727 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
    x =   -0.01     y =    0.01     z =   -0.03     T =   23.29
   e5 = -9.9999    e6 = -9.9999    e7 = -9.9999    e8 = -9.9999
 xsig =  0.0369  ysig =  0.0511  zsig =  0.0283  Tsig =  0.1481
e5sig =  0.0000 e6sig =  0.0000 e7sig =  0.0000 e8sig =  0.0000
xycov = -0.0004 xzcov =  0.0000 xTcov = -0.0013
yzcov =  0.0005 yTcov =  0.0027 zTcov =  0.0008
e5zco =  0.0000 e6zco =  0.0000 e7zco =  0.0000 e8zco =  0.0000
 psig =  0.0293  qsig =  0.0355  rsig =  0.0515
   tp =  0.9577    tq =  1.1633    tr =  1.6848
mgust =    0.07 thsig =     6.6 phsig =     9.6 DiffC =       D
ustar =  0.0233 Tstar =  0.0358    Cd =-0.63488    CT =31.57597
  MOs =  -0.870    mf =   0.001    hf =   0.998   nrb =   2.376
    u =   -0.01     v =    0.01     w =   -0.03
  vel =    0.02   dir =   153.2  svel =    0.06  sdir =   174.1
 none =       0  none =       0  none =       0  none =       0
 none =       0  none =       0  none =       0  none =       0


USnc-3/T > OD=12
SNC 160512153751 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
   e1 = -99.999    e2 = -99.999    e3 = -9.9999    e4 = -9.9999
   e5 = -9.9999    e6 = -9.9999    e7 = -9.9999    e8 = -9.9999
e1sig =  7.9660 e2sig =  7.9660 e3sig =  0.0000 e4sig =  0.0000
e5sig =  0.0000 e6sig =  0.0000 e7sig =  0.0000 e8sig =  0.0000
e1zco = -0.1168 e2zco = -0.1168 e3zco =  0.0000 e4zco =  0.0000
e5zco =  0.0000 e6zco =  0.0000 e7zco =  0.0000 e8zco =  0.0000


USnc-3/T > OD=13
SNC 160512153803 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
    x =   -0.01     y =    0.03     z =   -0.05     T =   23.07
   e1 = -99.999    e2 = -99.999    e3 = -9.9999    e4 = -9.9999
   e5 = -9.9999    e6 = -9.9999    e7 = -9.9999    e8 = -9.9999
 xsig =  0.0559  ysig =  0.0612  zsig =  0.0503  Tsig =  0.1013
e1sig =  0.0000 e2sig =  0.0000 e3sig =  0.0000 e4sig =  0.0000
e5sig =  0.0000 e6sig =  0.0000 e7sig =  0.0000 e8sig =  0.0000
xycov =  0.0006 xzcov =  0.0007 xTcov = -0.0007
yzcov =  0.0008 yTcov =  0.0016 zTcov =  0.0023
e1zco =  0.0000 e2zco =  0.0000 e3zco =  0.0000 e4zco =  0.0000
e5zco =  0.0000 e6zco =  0.0000 e7zco =  0.0000 e8zco =  0.0000
 psig =  0.0489  qsig =  0.0611  rsig =  0.0573
   tp =  0.8619    tq =  1.0770    tr =  1.0101
mgust =    0.08 thsig =    11.5 phsig =    10.7 DiffC =       D
ustar =  0.0325 Tstar =  0.0718    Cd =-0.03955    CT = 1.90313
  MOs =  -0.902    mf =   0.000    hf =   2.792   nrb =   6.647
    u =   -0.01     v =    0.03     w =   -0.05
  vel =    0.03   dir =   153.0  svel =    0.08  sdir =   143.7
 none =       0  none =       0  none =       0  none =       0
 none =       0  none =       0  none =       0  none =       0

 
USnc-3/T > OD=16
SNC 160512153839 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
   c1 =       0    c2 =       0

   
USnc-3/T > OD=17
SNC 160512153903 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
    x =    0.00     y =    0.00     z =    0.01     T =   23.24
 xsig =  0.0456  ysig =  0.0500  zsig =  0.0301  Tsig =  0.0966
xycov =  0.0000 xzcov = -0.0002 xTcov = -0.0001
yzcov =  0.0007 yTcov =  0.0010 zTcov = -0.0002
 psig =  0.0396  qsig =  0.0485  rsig =  0.0395
   tp =  3.0355    tq =  3.7241    tr =  3.0278
mgust =    0.06 thsig =     9.0 phsig =     7.4 DiffC =       D
ustar =  0.0277 Tstar = -0.0072    Cd = 5.40576    CT =14.62502
  MOs =   0.125    mf =  -0.001    hf =  -0.239   nrb =  -0.540
    u =    0.00     v =    0.00     w =    0.01
  vel =    0.01   dir =   131.0  svel =    0.06  sdir =   171.6
 none =       0  none =       0  none =       0  none =       0
 none =       0  none =       0  none =       0  none =       0
   c1 =       0    c2 =       0

   
USnc-3/T > OD=20
SNC 160512153927 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
   e1 = -99.999    e2 = -99.999    e3 = -9.9999    e4 = -9.9999
e1sig =  7.8178 e2sig =  7.8178 e3sig =  0.0000 e4sig =  0.0000
e1zco = -0.0321 e2zco = -0.0321 e3zco =  0.0000 e4zco =  0.0000
   c1 =       0    c2 =       0

   
USnc-3/T > OD=21
SNC 160512153939 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
    x =    0.02     y =    0.04     z =   -0.02     T =   23.43
   e1 = -99.999    e2 = -99.999    e3 = -9.9999    e4 = -9.9999
 xsig =  0.0486  ysig =  0.0562  zsig =  0.0344  Tsig =  0.0850
e1sig =  0.0000 e2sig =  0.0000 e3sig =  0.0000 e4sig =  0.0000
xycov = -0.0002 xzcov =  0.0000 xTcov = -0.0003
yzcov =  0.0002 yTcov =  0.0017 zTcov = -0.0003
e1zco =  0.0000 e2zco =  0.0000 e3zco =  0.0000 e4zco =  0.0000
 psig =  0.0476  qsig =  0.0516  rsig =  0.0420
   tp =  1.0747    tq =  1.1655    tr =  0.9488
mgust =    0.08 thsig =     9.6 phsig =     7.9 DiffC =       D
ustar =  0.0149 Tstar = -0.0219    Cd =-0.41895    CT = 1.86344
  MOs =   1.314    mf =   0.001    hf =  -0.389   nrb =  -0.900
    u =    0.02     v =    0.04     w =   -0.02
  vel =    0.04   dir =   203.6  svel =    0.07  sdir =   190.6
 none =       0  none =       0  none =       0  none =       0
 none =       0  none =       0  none =       0  none =       0
   c1 =       0    c2 =       0
   
   
USnc-3/T > OD=24
SNC 160512154003 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
   e5 = -9.9999    e6 = -9.9999    e7 = -9.9999    e8 = -9.9999
e5sig =  0.0000 e6sig =  0.0000 e7sig =  0.0000 e8sig =  0.0000
e5zco =  0.0000 e6zco =  0.0000 e7zco =  0.0000 e8zco =  0.0000
   c1 =       0    c2 =       0

   
USnc-3/T > OD=25
SNC 160512154015 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
    x =   -0.01     y =   -0.01     z =   -0.06     T =   23.24
   e5 = -9.9999    e6 = -9.9999    e7 = -9.9999    e8 = -9.9999
 xsig =  0.0431  ysig =  0.0441  zsig =  0.0327  Tsig =  0.1390
e5sig =  0.0000 e6sig =  0.0000 e7sig =  0.0000 e8sig =  0.0000
xycov = -0.0001 xzcov = -0.0002 xTcov =  0.0000
yzcov =  0.0002 yTcov =  0.0023 zTcov =  0.0015
e5zco =  0.0000 e6zco =  0.0000 e7zco =  0.0000 e8zco =  0.0000
 psig =  0.0331  qsig =  0.0444  rsig =  0.0425
   tp =  0.5250    tq =  0.7035    tr =  0.6725
mgust =    0.06 thsig =     8.3 phsig =     7.9 DiffC =       D
ustar =  0.0162 Tstar =  0.0917    Cd =-0.03507    CT = 6.47780
  MOs =  -4.637    mf =   0.000    hf =   1.774   nrb =   4.225
    u =   -0.01     v =   -0.01     w =   -0.06
  vel =    0.01   dir =    44.3  svel =    0.05  sdir =    13.4
 none =       0  none =       0  none =       0  none =       0
 none =       0  none =       0  none =       0  none =       0
   c1 =       0    c2 =       0

   
USnc-3/T > OD=28
SNC 160512154039 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
   e1 = -99.999    e2 = -99.999    e3 = -9.9999    e4 = -9.9999
   e5 = -9.9999    e6 = -9.9999    e7 = -9.9999    e8 = -9.9999
e1sig =  7.8173 e2sig =  7.8173 e3sig =  0.0000 e4sig =  0.0000
e5sig =  0.0000 e6sig =  0.0000 e7sig =  0.0000 e8sig =  0.0000
e1zco =  0.2381 e2zco =  0.2381 e3zco =  0.0000 e4zco =  0.0000
e5zco =  0.0000 e6zco =  0.0000 e7zco =  0.0000 e8zco =  0.0000
   c1 =       0    c2 =       0

   
USnc-3/T > OD=29
SNC 160512154051 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
    x =    0.01     y =    0.01     z =   -0.05     T =   23.14
   e1 = -99.999    e2 = -99.999    e3 = -9.9999    e4 = -9.9999
   e5 = -9.9999    e6 = -9.9999    e7 = -9.9999    e8 = -9.9999
 xsig =  0.0584  ysig =  0.0505  zsig =  0.0287  Tsig =  0.1090
e1sig =  0.0000 e2sig =  0.0000 e3sig =  0.0000 e4sig =  0.0000
e5sig =  0.0000 e6sig =  0.0000 e7sig =  0.0000 e8sig =  0.0000
xycov = -0.0004 xzcov =  0.0000 xTcov = -0.0005
yzcov =  0.0002 yTcov =  0.0017 zTcov =  0.0006
e1zco =  0.0000 e2zco =  0.0000 e3zco =  0.0000 e4zco =  0.0000
e5zco =  0.0000 e6zco =  0.0000 e7zco =  0.0000 e8zco =  0.0000
 psig =  0.0297  qsig =  0.0591  rsig =  0.0490
   tp =  0.6171    tq =  1.2269    tr =  1.0174
mgust =    0.07 thsig =    11.1 phsig =     9.3 DiffC =       D
ustar =  0.0142 Tstar =  0.0423    Cd =-0.15044    CT =11.22278
  MOs =  -2.781    mf =   0.000    hf =   0.718   nrb =   1.710
    u =    0.01     v =    0.01     w =   -0.05
  vel =    0.01   dir =   213.2  svel =    0.07  sdir =   187.7
 none =       0  none =       0  none =       0  none =       0
 none =       0  none =       0  none =       0  none =       0
   c1 =       0    c2 =       0

   
USnc-3/T > OD=32
SNC 160512154115 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
  p1u =    455c   p2u =    4535   p3u =    4560
  p1d =    455b   p2d =    453b   p3d =    455f

  
USnc-3/T > OD=256
SNC 160512154215 UTC+0000 AVE      12 SMP   5.000 AZI     0.0 SDQ     100 MDE      20 HTR      00 SHC       0 UST       0 NRB     420 NON       0 NON       0 NON       0
 stat =      60       0       0       0       0       0       0       0       0
}

{# [A] bug#01 
- /
}
