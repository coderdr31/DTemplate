<?php
if(empty($_GET['id'])){
    die('id is empty');
}
$id = intval($_GET['id']);
require_once 'function.php';
$mysqli = connectionDB();
$query_del = "delete from users where id = $id";
$result = $mysqli -> query($query_del);
if($result) {
    header("Location:index.php");
}else {
    die("del error");
}
?>
