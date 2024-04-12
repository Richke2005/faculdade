const lat1 = document.getElementById('lat1');
const long1 = document.getElementById('long1');
const lat2 = document.getElementById('lat2');
const long2 = document.getElementById('long2');
const lat3 = document.getElementById('lat3');
const long3 = document.getElementById('long3');
const lat4 = document.getElementById('lat4');
const long4 = document.getElementById('long4');
const lat5 = document.getElementById('lat5');
const long5 = document.getElementById('long5');
const ulResult = document.querySelector('ul');
const svgCoord = document.querySelector("#svgcoord");

const coordenadas = [
    {    
        lat: lat1,
        long: long1
    },
    { 
        lat: lat2,
        long: long2    
    },
    {    
        lat: lat3,
        long: long3    
    },
    {    
        lat: lat4,
        long: long4
    },
    {    
        lat: lat5,
        long: long5
    }
]

const arrayCoord = [];

coordenadas.forEach(function(e){
    const {lat, long} = e;
    arrayCoord.push(lat);
    arrayCoord.push(long);
})

arrayCoord.forEach(function(ele){
    ele.addEventListener("change", function(e){
        svgPrint(arrayCoord);
    })
})

function svgPrint(array){
    let string = "";
    for(let i = 0; i < array.length; i++){
        if(i % 2 == 0)
            string += " ";
        
        if(i % 2 !== 0)
            string += ",";
        
        string += `${Number.parseInt(array[i].value)}`
    }
    svgCoord.setAttribute("points", string);
}

async function sendRequest(){
    //readyState: representam o estado atual da requisição 
    /*
    0: Requisição não inicializada
    1: Estabeleceu conexão com o servidor
    2: Pedido recebido
    3: Processando pedido
    4: Solicitação concluída e resposta pronta
    */
    const xmlHttp = new XMLHttpRequest();

    xmlHttp.responseType = "json";
    xmlHttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            //oque acontecerá quando o estado mudar
            ulResult.innerHTML = "";
            const result = this.response;
            
            result.map(ele =>{
                const list = document.createElement("li");
                list.id = ele.localidade;
                list.textContent = `Ponto ${ele.localidade} - ${ele.distancia} Km`;
                ulResult.appendChild(list)
            })

        }else{
            if(this.readyState == 1){
                console.log({message: "connection established", reqState: this.readyState, status: this.status});
            }
            if(this.readyState == 2){
                console.log({message: "request received", reqState: this.readyState, status: this.status});
            }
            if(this.readyState == 3){
                console.log({message: "processing request", reqState: this.readyState, status: this.status});
            }
        }
    }

    //Verbo http | rota | se é assincrona ou não (padrão é assíncrono)
    // xampp
    xmlHttp.open("POST", "http://localhost:80/server/", true);
    xmlHttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");

    const doc = coordenadas.map(function(obj){
        return {
            lat: Number.parseFloat(obj.lat.value),
            long: Number.parseFloat(obj.long.value)
        }
    })
    
    const data = `coordenadas=${JSON.stringify(doc)}`
    xmlHttp.send(data);
}