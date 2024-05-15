//função que retorna um objeto com informações da imagem com base na pagina
//params: 
//page - pagina escolhida, se assemelha a um album escolar
//limit - limites de foto por pagina
//skip - quantas fotos serão puladas a partir do contador -> skip 2 = 0, 2, 4, 6, ...
function getImagesByPage({page = 1, limit = 12, skip = 1}){
    const images = [];

    let i = (page * limit) - limit;
    while(i <= (page * limit)){
        images.push({
            id: i,
            title: `Imagem ${i}`,
            url: `../public/images/a001_${i}.jpg`
        })
        i += skip;
    }
    return images;
}


export {
    getImagesByPage
}