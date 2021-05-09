<?php
$_lastname = $_REQUEST['account'];
$query = "SELECT * FROM actors WHERE last_name = '$_lastname'";

var_dump($_lastname);
var_dump($query);
?>