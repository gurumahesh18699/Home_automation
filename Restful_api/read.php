<?php
 header("Access-Control-Allow-Origin: *");
header("Content-Type: application/json; charset=UTF-8");
 
  $db = mysqli_connect('localhost', 'id7386218_miniproject191', 'miniproject191', 'id7386218_miniproject191');
  $sql = "SELECT * FROM led";
  $result=mysqli_query($db,$sql);

if (isset($_GET["id"])) {
$response = array();
while ($row=$result->fetch_assoc()) {

      $led=array();
      $led["id"]=$row["id"];
      $led["status"]=$row["status"];
     $response["success"]=1;
     $response["led"]=array();
     array_push($response["led"],$led);
     echo $led["status"];


	# code...
}
}
else{
	 $response["success"]=0;
     $response["message"]="parameters are misssing";

     echo json_encode($response);
}
?>