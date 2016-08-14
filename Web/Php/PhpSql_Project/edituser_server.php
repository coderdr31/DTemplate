<?php
require_once 'function.php';
if(empty($_POST['id'])){
    die("id is empty");

}
if(empty($_POST['name']))
    die("name is empty");
if(empty($_POST['age']))
    die("age is empty");

$id = intval($_POST['id']);
$name = $_POST['name'];
$age = intval($_POST['age']);

$mysqli = connectionDB();
$query_upd = "update users set name='$name',age=$age where id=$id";
$result = $mysqli -> query($query_upd);
if ($result) {
    header("Location:index.php");
} else {
    die("update error");
}

?>
