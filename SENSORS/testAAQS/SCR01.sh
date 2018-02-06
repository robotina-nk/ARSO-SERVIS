# starlet_sel_t_v
starlet_sel_t_v(){
	xmlstarlet sel -t -v $1 4000_config.xml 2> /dev/null #supperss warning, 2> file redirects stderr to file
}


var_zober_name=$(starlet_sel_t_v "/logfile/Station/zober-name/@txt")
echo $var_zober_name

var_location_code=$(starlet_sel_t_v "/logfile/Station/location-code/@txt")
echo $var_location_code

var_station_code=$(starlet_sel_t_v "/logfile/Station/station-code/@txt")
echo $var_station_code

var_station_type=$(starlet_sel_t_v "/logfile/Station/MM/Type/@txt")
echo $var_station_type

var_station_Sn=$(starlet_sel_t_v "/logfile/Station/MM/Sn/@txt")
echo $var_station_Sn

var_Server_IP=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@IP")
echo $var_Server_IP

var_mask=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@mask")
echo $var_mask

var_bcast=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@bcast")
echo $var_bcast

var_network=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@network")
echo $var_network

var_gw=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@gw")
echo $var_gw

var_dns=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server/Net/@dns")
echo $var_dns

var_vmd8s_IP=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Net/process[@proc='jmd']/../@IP")
echo $var_vmd8s_IP

var_vmd8s_N3=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/serServ[@Idx='N3']/Net[@mask]/./@IP")
echo $var_vmd8s_N3

var_vmd8s_O3=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='O3']/Net[@mask]/./@IP")
echo $var_vmd8s_O3

var_vmd8s_NOx=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='NOx']/Net[@mask]/./@IP")
echo $var_vmd8s_NOx

var_vmd8s_SO2=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='SO2']/Net[@mask]/./@IP")
echo $var_vmd8s_SO2

var_vmd8s_CO=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='CO']/Net[@mask]/./@IP")
echo $var_vmd8s_CO

var_vmd8s_PM=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='PM']/Net[@mask]/./@IP")
echo $var_vmd8s_PM

var_vmd8s_BC=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s']/Servers_AQ-Devices/serServ[@Idx='BC']/Net[@mask]/./@IP")
echo $var_vmd8s_BC

var_vmd8s_zobervis_IP=$(starlet_sel_t_v "/logfile/Servers_KAZ-KONTEJNER/Server[@Idx='ZK1']/Guest[@vmGuest='d8s-zobervis']/Net/@IP")
echo $var_vmd8s_zobervis_IP

var_N2_IP=$(starlet_sel_t_v "/logfile/Servers_KAZ-miniKONTEJNER/Server[@Idx='N2']/Net[@mask]/./@IP")
echo $var_N2_IP
