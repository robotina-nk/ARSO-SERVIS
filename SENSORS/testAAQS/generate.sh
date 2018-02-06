# starlet_sel_t_v
starlet_sel_t_v(){
	xmlstarlet sel -t -v $1 4000_config.xml 2> /dev/null #supperss warning, 2> file redirects stderr to file
}
var_zober_name=$(starlet_sel_t_v "/logfile/Station/zober-name/@txt")
var_location_code=$(starlet_sel_t_v "/logfile/Station/location-code/@txt")
var_station_code=$(starlet_sel_t_v "/logfile/Station/station-code/@txt")
var_station_type=$(starlet_sel_t_v "/logfile/Station/MM/Type/@txt")
var_station_Sn=$(starlet_sel_t_v "/logfile/Station/MM/Sn/@txt")
var_Server_IP=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@IP")
var_mask=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@mask")
var_bcast=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@bcast")
var_network=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@network")
var_gw=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@gw")
var_dns=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@dns")
var_vmd8s_IP=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net/process[@proc='jmd']/../@IP")
var_vmd8s_zobervis_IP=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s-zobervis']/Net/@IP")
var_N2_IP=$(starlet_sel_t_v "/logfile/Servers_KAZ-miniKONTEJNER/Server[@Idx='N2']/Net[@mask]/./@IP")
var_N3=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@mask]/./@IP")
var_O3=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='O3']/Net[@mask]/./@IP")
var_NOx=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='NOx']/Net[@mask]/./@IP")
var_SO2=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='SO2']/Net[@mask]/./@IP")
var_CO=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='CO']/Net[@mask]/./@IP")
var_PM=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='PM']/Net[@mask]/./@IP")
var_BC=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='BC']/Net[@mask]/./@IP")
var_N3_P1_tcpPort=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P1']/./@tcpPort")
var_N3_P1_serConfig=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P1']/./serConnection/@serConfig")
var_N3_P2_tcpPort=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P2']/./@tcpPort")
var_N3_P2_serConfig=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P2']/./serConnection/@serConfig")
var_N3_P3_tcpPort=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P3']/./@tcpPort")
var_N3_P3_serConfig=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P3']/./serConnection/@serConfig")
var_N3_P4_tcpPort=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P4']/./@tcpPort")
var_N3_P4_serConfig=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P4']/./serConnection/@serConfig")
var_N3_P5_tcpPort=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P5']/./@tcpPort")
var_N3_P5_serConfig=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P5']/./serConnection/@serConfig")
var_N3_P6_tcpPort=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P6']/./@tcpPort")
var_N3_P6_serConfig=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P6']/./serConnection/@serConfig")
var_N3_P7_tcpPort=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P7']/./@tcpPort")
var_N3_P7_serConfig=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P7']/./serConnection/@serConfig")
var_N3_P8_tcpPort=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P8']/./@tcpPort")
var_N3_P8_serConfig=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@comPort='P8']/./serConnection/@serConfig")

var_64001_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64001']/process/@Desc")
var_64002_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64002']/process/@Desc")
var_64003_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64003']/process/@Desc")
var_64004_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64004']/process/@Desc")
var_64005_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64005']/process/@Desc")
var_64006_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64006']/process/@Desc")
var_64100_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64100']/process/@Desc")
var_64101_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64101']/process/@Desc")
var_64102_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64102']/process/@Desc")
var_64105_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64105']/process/@Desc")
var_64106_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64106']/process/@Desc")
var_64108_Desc=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64108']/process/@Desc")

var_64001_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64001']/./@IPport")
var_64002_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64002']/./@IPport")
var_64003_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64003']/./@IPport")
var_64004_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64004']/./@IPport")
var_64005_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64005']/./@IPport")
var_64006_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64006']/./@IPport")
var_64100_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64100']/./@IPport")
var_64101_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64101']/./@IPport")
var_64102_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64102']/./@IPport")
var_64105_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64105']/./@IPport")
var_64106_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64106']/./@IPport")
var_64108_IPport=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net[@tcpPort='64108']/./@IPport")



rm textile.xml
echo '<?xml version="1.0" encoding="UTF-8"?><wiki_page><title>Wiki</title><text>h1. 4000_E4000_Test_WIKI (Ljubljana_Bezigrad)' >> textile.xml
echo >> textile.xml
echo "*STATUS:* Postaja ni vključena v omrežje ARSO *o.net*, Test!" >> textile.xml
echo >> textile.xml
echo "h2. Osnovna dokumentacija" >> textile.xml
echo >> textile.xml
echo "* *Topologija* [TODO] http://pivka.arso.sigov.si/svn/xober_op_location/..." >> textile.xml
echo "* *Senzorji* [TODO] http://pivka.arso.sigov.si/svn/xober_op_location/..." >> textile.xml
echo "* *Procesiranje* [TODO] http://pivka.arso.sigov.si/svn/xober_op_location/..." >> textile.xml
echo "* *MASTER dokumentacija* [TODO] http://pivka.arso.sigov.si/svn/xober_dv_location/..." >> textile.xml
echo >> textile.xml
echo "h2. Merilni sistem" >> textile.xml
echo >> textile.xml
echo "|_\5=. Glavna merilna plošča - CPU0 |" >> textile.xml
echo "|\2=.IT Merilni sistem||\2=.Merilna plošča|" >> textile.xml
echo "|_&#60;.Ime lokacije|%{background:lightgreen}$var_zober_name%||_&#60;.Tip|%{background:lightgreen}$var_station_type%|" >> textile.xml
echo "|_&#60;.Koda lokacije|%{background:lightgreen}$var_location_code%||_&#60;.Ser. št.|%{background:lightgreen}$var_station_Sn%|" >> textile.xml
echo "|_&#60;.Koda postaje|%{background:lightgreen}$var_station_code%||_&#60;.Inv. št.||" >> textile.xml
echo "|\5=.|" >> textile.xml
echo "|\2=.Komunikacijske nastavitve||\2=.VPN/GPRS|" >> textile.xml
echo "|_&#60;.DNS name|.mpls.arso.sigov.si||_&#60;.DNS name||" >> textile.xml
echo "|_&#60;.Tip VPN/GPRS,HSDPA| DA ||_&#60;.username|  |" >> textile.xml
echo "|_&#60;.Tip ADSL/MPLS| NE ||_&#60;.password|  |" >> textile.xml
echo "|_&#60;.IP1 Qnap-ts251/TS-463U-RP|%{background:lightgreen}$var_Server_IP%||_&#60;.IP radius server||" >> textile.xml
echo "|_&#60;.IP2 VM-d8s|%{background:lightgreen}$var_vmd8s_IP%||\2=.SIM KARTICA|" >> textile.xml
echo "|_&#60;.IP3 VM-d8s_zobervis|%{background:lightgreen}$var_vmd8s_zobervis_IP%||_&#60;.Ser. Št.||" >> textile.xml
echo "|_&#60;.IP4 N2 UC-8410A-T-LX|%{background:lightgreen}$var_N2_IP%||_&#60;.Tel. Številka||" >> textile.xml
echo "|_&#60;.IP5 |/||_&#60;.PIN||" >> textile.xml
echo "|_&#60;.DNS|%{background:lightgreen}$var_dns%||_&#60;.PUK||" >> textile.xml
echo "|_&#60;.netmask|%{background:lightgreen}$var_mask%||||" >> textile.xml
echo "|_&#60;.broadcast|%{background:lightgreen}$var_bcast%||||" >> textile.xml
echo "|_&#60;.network|%{background:lightgreen}$var_network%||||" >> textile.xml
echo "|_&#60;.HostMin (gateway)|%{background:lightgreen}$var_gw%||||" >> textile.xml
echo "|_&#60;.HostMax|?||||" >> textile.xml
echo "|_&#60;.Host/Net|?||||" >> textile.xml
#echo "|\5=.|" >> textile.xml
echo "|\5=.Komunikacijske nastavitve com strežnikov|" >> textile.xml
echo "|_&#60;.ComServer1 Nport-6650|%{background:lightgreen}$var_N3%|%{background:lightgreen}$var_N3_P1_tcpPort:$var_N3_P1_serConfig&#10;$var_N3_P2_tcpPort:$var_N3_P2_serConfig&#10;$var_N3_P5_tcpPort:$var_N3_P5_serConfig&#10;$var_N3_P6_tcpPort:$var_N3_P6_serConfig%|%{background:lightgreen}$var_64101_Desc&#10;$var_64102_Desc&#10;$var_64105_Desc&#10;$var_64106_Desc%|%{background:lightgreen}$var_64101_IPport&#10;$var_64102_IPport&#10;$var_64105_IPport&#10;$var_64106_IPport%|" >> textile.xml
echo "|_&#60;.APOA-370 O3|%{background:lightgreen}$var_O3%||$var_64001_Desc|$var_64001_IPport|" >> textile.xml
echo "|_&#60;.APNA-370 NOx|%{background:lightgreen}$var_NOx%||$var_64002_Desc|$var_64002_IPport|" >> textile.xml
echo "|_&#60;.APSA-370 SO2|%{background:lightgreen}$var_SO2%||$var_64003_Desc|$var_64003_IPport|" >> textile.xml
echo "|_&#60;.APMA-370 CO|%{background:lightgreen}$var_CO%||$var_64004_Desc|$var_64004_IPport|" >> textile.xml
echo "|_&#60;.APDA-372 PM1|%{background:lightgreen}$var_PM%||$var_64005_Desc|$var_64005_IPport|" >> textile.xml
echo "|_&#60;.AE33 BC|%{background:lightgreen}$var_BC%||$var_64006_Desc|$var_64006_IPport|" >> textile.xml

echo "" >> textile.xml
echo "" >> textile.xml
echo "" >> textile.xml
echo "" >> textile.xml
echo "" >> textile.xml
echo "" >> textile.xml
echo "" >> textile.xmlecho "" >> textile.xml



#

#|_<.ComServer1 IP|172.19.xxx.xxx|4001:19200,N,8,1,N; 4002:19200,N,8,1,N|||



#|_<.ComServer1 IP|172.19.xxx.xxx|4001:19200,N,8,1,N;
#4002:19200,N,8,1,N|||
#|_<.ComServer2 IP|172.19.xxx.xxx|4001:19200,N,8,1,N;
#4002:19200,N,8,1,N|||
#|_<.ComServer3 IP|172.19.xxx.xxx|5666:AMS156|||
#|_<.APSA-370 SO2|172.19.xxx.xxx|53700:Horiba SO2|||
#|_<.APNA-370 NOx|172.19.xxx.xxx|53700:Horiba NOx|||
#|_<.APMA-370 CO|172.19.xxx.xxx|53700:Horiba CO|||
#|_<.APOA-370 O3|172.19.xxx.xxx|53700:Horiba O3|||
#|\5=.|



echo '</text></wiki_page>' >> textile.xml
#echo "" >> textile.xml


curl -v -u nkostic:Kosnik00 -H "Content-Type: application/xml" -X PUT http://pivka.arso.sigov.si/redmine/projects/e4000_test_wiki-testna-postaja/wiki/Wiki.xml --data-binary "@textile.xml"
