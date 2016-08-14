<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title></title>
</head>
<body>
<?php
require_once 'function.php';
if(!empty($_GET['id'])){
    $mysqli = connectionDB();
    $id = intval($_GET['id']);
    $query_sel ="select * from users where id = $id";
    $result = $mysqli -> query($query_sel);
    if ($result) {
        $row = $result -> fetch_array();
    } else {
        die("select error");
    }
}else{
    die("id not define");
}
?>

<form action="edituser_server.php" method="post">
    <div>
        id:<input type="text" name="id" value="<?php echo $row['id']; ?>">
    </div>
    <div>
        name:<input type="text" name="name" value="<?php echo $row['name']; ?>">
    </div>
    <div>
        age:<input type="text" name="age" value="<?php echo $row['age']; ?>">
    </div>
    <input type="submit" value="submit">
</form>

</body>
</html>
