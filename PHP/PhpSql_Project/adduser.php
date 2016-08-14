<?php
if(!isset($_POST['name'])){
    die('user name not define');
}
if(!isset($_POST['age'])){
    die('user age not define');
}
$name = $_POST['name'];
if(empty($name)){
    die('user name is empty');
}
$age = $_POST['age'];
if(empty($age)){
    die('user age is empty');
}
$age = intval($age);
// 防止 sql 注入攻击:
// 字符串用引号引起来
// 其它类型一定要类型转换

require_once 'function.php';
$mysqli = connectionDB();
$query_ins = "insert into users(name ,age) values ('$name', $age)";
$result = $mysqli -> query($query_ins);
if ($result) {
    header("Location:index.php"); //页面跳转
}else{
    die("insert error");
}
?>

