<?php
include "./functions/functions.php";
// Decide se a origem $_SERVER['HTTP_ORIGIN'] é uma que
// você deseja permitir, sim ent:
 if (isset($_SERVER['HTTP_ORIGIN'])) {
        //permite de qualquer origem
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
           $localidades[$index]["distancia"] = calcularDistanciaFromEarth($pontoInicial["lat"], $pontoInicial["long"], $localidade["lat"], $localidade["long"]);
        }
        //reordena ascoordenadas com base na distancia do ponto inicial
        usort($localidades, function($a, $b){
            return $a["distancia"] - $b["distancia"];
        });

        $response = $localidades;
    }
    echo json_encode($response);
}
//  Neste sistema optei por distribuir esse processamento com os cálculos do lado do servidor 
//por se tratar de um exemplo didático, como meio de acompanhar oque foi feito em aula.
//  Acredito que seja mais adequado distribuir oque foi feito aqui para o lado do cliente
//possibilitando com que o processamento aqui fique livre para atender um maior numero de usuários a um menor custo.
//Assim balanceando os recursos entre servidor e cliente.
?>
