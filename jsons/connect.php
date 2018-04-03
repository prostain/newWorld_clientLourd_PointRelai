<?
session_start();
$host='localhost';
$user='root';
$pass='';
$nomBase="newWorld";
mysql_connect($host,$user,$pass);
mysql_select_db('newWorld');
$base_url="http://172.16.63.116/~rbayeux/newWorld/";
$base=mysqli_connect($host,$user,$pass,$nomBase);
mysqli_query($base,"set collation utf8mb4_unicode_520_ci");
?>
