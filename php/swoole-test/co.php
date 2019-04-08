<?php

echo Swoole\Coroutine::getuid();
echo "\n";
go(function () {
print_r(Swoole\Coroutine::getaddrinfo('http://www.baidu.com'));
		echo Swoole\Coroutine::getuid();
		co::sleep(0.5);
		echo "hello";
		});
var_dump(Swoole\Coroutine::stats());
echo 'main end';
