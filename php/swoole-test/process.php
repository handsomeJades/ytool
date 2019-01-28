<?php

$process=new swoole_process(function (swoole_process $process){
	$process->write("hahaha");
}
);
$res=$process->start();

var_dump($res);
sleep(100);

echo $process->read();
