#/**
# ****************************************************************************
# *//@file	1000_topology_meritve.sh
# *//@brief	 meritve  Linux debian 2.6.35.7-nanosg20 #1 PREEMPT Fri Dec 17 13:51:35 CET 2010 armv5tejl
# *//@author    Bojan Cernac
# *//@version	December 2010	V1.0 Creation (BC)
# *//@update	2018-01-24	V1.1 Creation (BC)
# *//@ingroup 	SETUP
# ****************************************************************************
#*/

[I] MERITVE {#  Poraba 
instrumneti
 \--<  usmernik: Agilent E3634A
 
  A.conf { # ttyS1
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 [ nc ]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120 [ nc ]	
	Us= 12.099 V
	Ic= 31mA - 37mA, Ic_avg= 33mA	
	}
  B.conf { # ttyS1, usb0
  # usmernik: Agilent E3634A
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 [`connected`]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120 [ nc ]	
	Us= 12.099 V
	Ic= 39mA - 42mA, Ic_avg= 40mA	
	}	
  C.conf { # ttyS1, eth0, 
  # usmernik: Agilent E3634A
  ./N2/ 
    |--< eth0 [`connected`]
    |--< usb0 [ nc ]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120 [ nc ]	
	Us= 12.099 V
	Ic= 60mA - 65mA, Ic_avg = 62mA	
	}
  D.conf { # ttyS1, eth0, usb0
  # usmernik: Agilent E3634A
  ./N2/ 
    |--< eth0 [`connected`]
    |--< usb0 [`connected`]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120 [ nc ]	
	Us= 12.099 V
	Ic= 68mA - 71mA, Ic_avg= 70mA	
	}	
  E.conf { # ttyS1, ttyS3, eth0 
  # usmernik: Agilent E3634A
  ./N2/ 
    |--< eth0 [`connected`]
    |--< usb0 [ nc ]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected`]
	Us= 12.099 V
	Ic= 71mA - 75mA, Ic_avg= 72mA	
	}	
  F.conf { # ttyS1, ttyS3, eth0, usb0
  # usmernik: Agilent E3634A
  ./N2/ 
    |--< eth0 [`connected`]
    |--< usb0 [`connected`]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]	
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected`]
	Us= 12.099 V
	Ic= 77mA - 81mA, Ic_avg= 78mA	
	}	
  Ga.conf { # ttyS1, ttyS2, ttyS3,  
  # usmernik: Agilent E3634A
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 [ nc ]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]	
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected`]
	Us= 12.099 V
	Ic= 44mA - 50mA, Ic_avg= 45mA	
	}	
  Gb.conf { # ttyS1, ttyS2, ttyS3, connected & sending data
  # usmernik: Agilent E3634A
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 [ nc ]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]	
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected & sending data`]
	Us= 12.099 V
	Ic= 100mA - 120mA, Ic_avg= 110mA	
	}	
  G1a.conf { # ttyS1, ttyS2, ttyS3, usb0
  # usmernik: Agilent E3634A
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 [`connected`]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [`connected`]
    \--< X13 rs232 - ttyS3 – N3,mbIO120 [`connected`]	
	Us= 12.91 V
	Ic= 62mA - 78mA, Ic_avg= 68mA	
	}	
  G1b.conf { # ttyS1, ttyS2, ttyS3, usb0, connected & sending data
  # usmernik: Agilent E3634A
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 [ `connected` ]
    |--< usb1 [ nc ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected & sending data`]
	Us= 12.8 V
	Ic= 110mA - 174, Ic_avg= 130mA
	}	
  H1a.conf { # ttyS1, ttyS2, ttyS3, usb0, usb1
  # usmernik: Agilent E3634A
  # ttyUSB_RS485_0 SMP3 	[ `connected` ]
  # ttyUSB_RS485_1 WXT536 	[ `connected` ]
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 rs485 - ttyUSB_RS485_0[ `connected` ]
    |--< usb1 rs485 - ttyUSB_RS485_1[ `connected` ]
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected`]
	Us= 12.8 V
	Ic= 60mA - 101mA, Ic_avg= 66mA
	}
  H1b.conf { # ttyS1, ttyS2, ttyS3, usb0
  # usmernik: Agilent E3634A
  # ttyUSB_RS485_0 SMP3 	[ `connected` ]
  # ttyUSB_RS485_1 WXT536 	[ `connected` ]
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 rs485 - ttyUSB_RS485_0[ `connected` ]  
    |--< usb1 rs485 - ttyUSB_RS485_1[ `nc` ]         
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected`]
	Us= 12.8 V
	Ic= 62mA - 95mA, Ic_avg= 55mA
	}
  H1c.conf { # ttyS1, ttyS2, ttyS3, usb0
  # usmernik: Agilent E3634A
  # usmernik: Agilent E3634A
  # ttyUSB_RS485_0 SMP3 	[ `connected` ]
  # ttyUSB_RS485_1 WXT536 	[ `nc` ] 
 ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 rs485 - ttyUSB_RS485_0[ `connected` ] 
    |--< usb1 rs485 - ttyUSB_RS485_1[ `nc` ]        
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected`]
	Us= 12.8 V
	Ic= 57mA - 79mA, Ic_avg= 53mA
	}
  H1d.conf { # ttyS1, ttyS2, ttyS3,
  # usmernik: Agilent E3634A
  # usmernik: Agilent E3634A
  # ttyUSB_RS485_0 SMP3 	[ `connected` ]
  # ttyUSB_RS485_1 WXT536 	[ `nc` ]
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 rs485 - ttyUSB_RS485_0[ `nc` ] 
    |--< usb1 rs485 - ttyUSB_RS485_1[ `nc` ] 
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected`]
	Us= 12.8 V
	Ic= 53mA - 91mA, Ic_avg= 47mA
	}
  H1e.conf { # ttyS1, ttyS2, ttyS3,
  # usmernik: Agilent E3634A
  # usmernik: Agilent E3634A
  # ttyUSB_RS485_0 SMP3 	[ `nc` ]
  # ttyUSB_RS485_1 WXT536 	[ `nc` ]  
  ./N2/ 
    |--< eth0 [ nc ]
    |--< usb0 rs485 - ttyUSB_RS485_0[ `nc` ] /
    |--< usb1 rs485 - ttyUSB_RS485_1[ `nc` ] /
    |--< X6  rs232 - ttyS1 – local      [`connected`]
    |--< X13 rs485 - ttyS2 – N3,mbIO120 [ nc ]
    \--< X13 rs232 - ttyS3 – N3,mbIO120_modem [`connected`]
	Us= 12.8 V
	Ic= 47mA - 107mA, Ic_avg= 43mA
	}
}	 


