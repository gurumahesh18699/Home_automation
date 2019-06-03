<?php
	header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");

	// variable declaration
	$response = array(); 
	

	// connect to database
    if(isset($_GET['id']) && isset($_GET['status'])){
     
     $id=$_GET['id'];
     $status=$_GET['status'];

     $db = mysqli_connect('localhost', 'id7386218_miniproject191', 'miniproject191', 'id7386218_miniproject191');
     $result="UPDATE led SET status='$status' WHERE id='$id'";
     mysqli_query($db,$result);

     


    }
    else{
     $response["success"]=0;
     $response["message"]="parameters are misssing";

     echo json_encode($response);
    }

?>
	
