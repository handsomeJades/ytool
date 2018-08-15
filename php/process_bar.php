<?php
/*
* \r 移到行首
*/
$count = 100;
for ($i = 1; $i <= 100; $i++) {
	    usleep(50000);
		    //printf("\r [%-100s] (%2d%%/%2d%%)", str_repeat("=", $i) . ">", ($i / $count) * 100, $count);
		    printf("\n\r [%-100s] (%2d%%/%2d%%)", str_repeat("=", $i) . ">", ($i / $count) * 100, $count);
}
