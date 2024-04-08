<?php
include "./functions/functions.php";
 // Allow from any origin
 if (isset($_SERVER['HTTP_ORIGIN'])) {
    // Decide if the origin in $_SERVER['HTTP_ORIGIN'] is one
    // you want to allow, and if so:
    header("Access-Control-Allow-Origin:*");
    header("Content-Type: text/html; charset=utf-8");
    header("X-Content-Type-Options: nosniff");
    header('Access-Control-Allow-Credentials: true');
    header('Access-Control-Max-Age: 86400');    // cache for 1 day
}

if($_SERVER['REQUEST_METHOD'] == 'POST'){

    if(isset($_POST['coordenadas'])){
        $document = $_POST['coordenadas'];
        $localidades = json_decode($document, true);

        $pontoInicial = $localidades[0];

        foreach($localidades as $index => $localidade){
           $localidades[$index]['localidade'] = $index + 1;
           $localidades[$index]["distancia"] = calcularDistancia($pontoInicial["lat"], $pontoInicial["long"], $localidade["lat"], $localidade["long"]);
        }

        $response = $localidades;
    }
    echo json_encode($response);
}

?>