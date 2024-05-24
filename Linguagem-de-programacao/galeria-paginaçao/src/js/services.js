//função que retorna um objeto com informações da imagem com base na pagina
//params: 
//page - pagina escolhida, se assemelha a um album escolar
//limit - limites de foto por pagina
//skip - quantas fotos serão puladas a partir do contador -> skip 2 = 0, 2, 4, 6, ...
function getImages(album = 1, type = ".jpg",  {page, initial, limit = 12, skip = 1}){
    const images = [];
    const stringAlbum = album.toString();
    page = (page && !initial) ? page : definePageByInitial(initial, limit);
    let i = (initial) ? initial : defineIByPage(page, limit);
    if(i < 0)
        i = 0;

    while(i < (page * limit)){
        const stringNumber = i.toString();
        images.push({
            id: i,
            title: `Imagem ${i}`,
            url: `../public/images/a${stringAlbum.padStart(3, '0')}_${stringNumber.padStart(5, '0')}${type}`
        });
        console.log(i);
        i += skip;
    }
    return images;
}

function getImagesFromTo({album = 1, initial = 0, to = 12}){
    const images = [];
    const stringAlbum = album.toString();
    while(initial < to){
        const stringNumber = initial.toString();
        images.push({
            id: initial,
            title: `Imagem ${initial}`,
            url: `../public/images/a${stringAlbum.padStart(3, '0')}_${stringNumber.padStart(5, '0')}.jpg`
        })
        initial++;
    }
    return images;
}

function defineIByPage(page, limit){
    return (page * limit) - limit;
}

function definePageByInitial(initial, limit){
    return (limit + initial) / limit;
}



module.exports = {
    getImages, 
    getImagesFromTo,
    definePageByInitial
}
  