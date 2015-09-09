<?php
error_reporting(E_ALL);
set_time_limit(0);

if(!isset($_POST['json']))
	die('1');
$json = $_POST['json'];
if(empty($json))
	die('2');

$port = 1117;
$ip = "127.0.0.1";


$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
if ($socket < 0) {
    echo "socket_create() failed: reason: " . socket_strerror($socket) . "\n";
}

$result = socket_connect($socket, $ip, $port);
if ($result < 0) {
    echo "socket_connect() failed.\nReason: ($result) " . socket_strerror($result) . "\n";
}else 
/*
$json = '{
  "style": [
    "variables.less",
    "mixins.less",
    "base.less"
  ],
  "js": [
    "core.js"
  ],
  "widgets": [
    
  ]
}';*/

$ii = md5(date('YmdHis') . mt_rand(100000,999999));
$in = $ii."|".$json;




$out = '';

if(!socket_write($socket, $in, strlen($in))) {
    echo "socket_write() failed: reason: " . socket_strerror($socket) . "\n";
}
while($out = socket_read($socket, 8192)) {
   
}
$url = "http://hyyyp.com/tmp/".$ii.".zip";
echo '<script>window.location.href="'.$url.'"</script>';
socket_close($socket);
?>