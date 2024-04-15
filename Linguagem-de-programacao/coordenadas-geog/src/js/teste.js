// const organizedCoord = coordenadas.map((coord) => {
//     const selectedCoord = {};
//     coord.lat.addEventListener("change", (e)=>{ 
//         const changedPoint = Number.parseInt(e.target.value);
//         selectedCoord.lat = changedPoint;
//         console.log(organizedCoord)
//     });

//     coord.long.addEventListener("change", (e)=>{ 
//         const changedPoint = e.target.value;
//         selectedCoord.long = changedPoint;
  
       
//     });
//     return selectedCoord;
// });

// for(let i = 0; i < organizedCoord.length; i++){
//     coordinates
//     .setAttribute(
//         "points", `${organizedCoord[i].lat},
//     ${organizedCoord[i].long += ` ${organizedCoord[i+1]},${organizedCoord[i+1].long}`}` );
// }

//-----------------------------------------------------------------
// const arrayCoord = [];

// coordenadas.forEach(function(e){
//     const {lat, long} = e;
//     arrayCoord.push(lat);
//     arrayCoord.push(long);
// })

// arrayCoord.forEach(function(ele){
//     ele.addEventListener("change", function(e){
//         svgPrint(arrayCoord);
//     })
// })

// function svgPrint(array){
//     let string = "";
//     for(let i = 0; i < array.length; i++){
//         if(i % 2 == 0)
//             string += " ";
        
//         if(i % 2 !== 0)
//             string += ",";
        
//         string += `${Number.parseInt(array[i].value)}`
//     }
//     svgCoord.setAttribute("points", string);
// }