<?php
require_once 'config.php';
function connectionDB(){
    $conn = new mysqli(MYSQL_HOST, MYSQL_USER, MYSQL_PW, MYSQL_DB);
    if (!$conn) {
        die("connect fail");
    }
    return $conn;
}
?>
