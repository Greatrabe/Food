#!/usr/bin/env php-cgi

<!DOCTYPE html>
<html>
<body>

<?php
$file = fopen("data.txt","a");
fwrite($file, $_GET['email']);
fwrite($file, ',');
fwrite($file, $_GET['Vegetarian']);
fwrite($file, ',');
fwrite($file, $_GET['Beef']);
fwrite($file, ',');
fwrite($file, $_GET['Chicken']);
fwrite($file, ',');
fwrite($file, $_GET['Pasta']);
fwrite($file, ',');
fwrite($file, $_GET['Mexican']);
fwrite($file, ',');
fwrite($file, $_GET['Asian']);
fwrite($file, ',');
fwrite($file, $_GET['Indian']);
fwrite($file, ',');
fwrite($file, $_GET['Cheese']);
fwrite($file, ',');
fwrite($file, $_GET['Seafood']);
fwrite($file, "\n");
fclose($file);
?>
</body>
</html>
