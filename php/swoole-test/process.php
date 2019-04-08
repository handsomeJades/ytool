<?php

$process=new swoole_process(function (swoole_process $process){
		sleep(100);
	$process->write("hahaha");
}
);
$res=$process->start();
$process->name("kid process");

var_dump($res);
//sleep(100);

echo $process->read();
