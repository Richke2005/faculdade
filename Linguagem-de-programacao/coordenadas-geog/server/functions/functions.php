<?php

//levando em consideração a curvatura da terra utilizando a formula de haversine
function calcularDistanciaFromEarth($lat1, $lon1, $lat2, $lon2) {
    $R = 6371; // Raio da Terra em quilômetros
    $dLat = deg2rad($lat2 - $lat1);
    $dLon = deg2rad($lon2 - $lon1);
    $a = sin($dLat / 2) * sin($dLat / 2) +
         cos(deg2rad($lat1)) * cos(deg2rad($lat2)) *
         sin($dLon / 2) * sin($dLon / 2);
    $c = 2 * atan2(sqrt($a), sqrt(1 - $a));
    $distance = $R * $c;
    return $distance;
}

//Calculado distancia entre 2 pontos
function calcularDistancia($lat1, $long1, $lat2, $long2){
    $dLat = $lat2 - $lat1;
    $dLong = $long2 - $long1;

    $distance = sqrt((pow($dLat, 2)) + pow($dLong, 2));
    return $distance;
}
?>