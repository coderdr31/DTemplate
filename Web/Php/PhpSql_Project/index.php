<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title></title>
</head>
<body>
    <a href="adduser.html">add user</a><br>
<table style='text-align: left; border: solid' border='1'>
    <tr><th>id</th><th>name</th><th>age</th><th>edit</th></tr>
<?php
$mysqli = new mysqli("localhost","root","root","myapp"); //实例化mysql,myapp-database
//select
$query_sel = "select * from users";
$result = $mysqli -> query($query_sel);
if ($result) {
    if ($result -> num_rows > 0) {
        while($row = $result -> fetch_array()){
            //每次得到一个
            // 方法fetch_array()将结果集中的记录放入一个数组中并将其返回;
            echo($row[0]."\n"); //html页面中不换行，空格
            echo($row[1]."\n");
            echo($row[2]."\n");
            //echo("\n");
            $id = $row['id'];
            $name = $row['name'];
            $age = $row['age'];
            echo"<tr><td>$id</td><td>$name</td><td>$age</td><td><a href='edituser.php?id=$id'>edit</a> <a href='deleteuser.php?id=$id'>del</a></td></tr>";
        }
    }
} else {
    echo "查询失败";
}
$result -> free();
?>
</table>

<?php
//delete save
$query_del = "delete from users where id = 1";
$result = $mysqli -> query($query_del);
if ($result) {
    echo "删除操作执行成功";

} else {

    echo "删除操作执行失败";
}
// 再执行一次就能看到结果

// free()方法将结果集中的内存释放，使用close()方法将数据库连接关闭
//$result -> free();  // 这个方法要用在 select 后

$mysqli -> close();
?>

</body>
</html>
