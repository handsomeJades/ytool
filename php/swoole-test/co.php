<?php

print_r(co::getaddrinfo('http://www.baidu.com'));
echo Swoole\Coroutine::getuid();
echo "\n";
go(function () {
		echo Swoole\Coroutine::getuid();
		co::sleep(0.5);
		echo "hello";
		});
