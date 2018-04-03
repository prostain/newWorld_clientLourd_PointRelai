<?php
include("connect.php");
if(isset($_POST['username'])&&isset($_POST['password']))
{
	$req="select idUser, nom, prenom from User where username='".$_POST['username']."' and password='".$_POST['password']."')";
	$res=mysqli_query($base,$req);
	$tabInfo=mysqli_fetch_array($res);
	if(mysqli_num_rows($res)==1)
	{
		$_SESSION['idUser']=$tabInfo[0];
		echo json_encode($tabInfo);
	}
}
else
print_r($_POST);
?