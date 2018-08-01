<?php
//微妙
echo microtime(true);
exit;


//毫秒
list($t1, $t2) = explode(' ', microtime());
echo  (float)sprintf('%.0f',(floatval($t1)+floatval($t2))*1000);
