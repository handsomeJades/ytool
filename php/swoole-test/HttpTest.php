<?php
$http = new swoole_http_server("10.99.1.52", 9501);

$http->on("start", function ($server) {
    echo "Swoole http server is started at 10.99.1.52:9501\n";
});

$http->on("request", function ($request, $response) {
    $response->header("Content-Type", "text/plain");
	//print_r($request);
	print_r($response);
	$response->status(404);
//    $response->end("Hello World\n");
});

$ports=$http->ports;

print_r($ports);
$http->start();

