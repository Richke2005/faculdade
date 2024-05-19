//função que retorna um objeto com informações da imagem com base na pagina
//params: 
//page - pagina escolhida, se assemelha a um album escolar
//limit - limites de foto por pagina
//skip - quantas fotos serão puladas a partir do contador -> skip 2 = 0, 2, 4, 6, ...
function getImagesByPage(album = "001", {page = 1, limit = 12, skip = 1}){
    const images = [];

    let i = (page * limit) - limit;
    while(i < (page * limit)){
        images.push({
            id: i,
            title: `Imagem ${i}`,
            url: `../public/images/a${album}_${i}.jpg`
        })
        i += skip;
    }

    return images;
}

function getImagesFromTo({album = "001", initial = 0, to = 12}){
    const images = [];

    while(initial < to){
        images.push({
            id: initial,
            title: `Imagem ${initial}`,
            url: `../public/images/a${album}_${initial}.jpg`
        })
        initial++;
    }

    return images;
}

function renderImages(father, images, size = "32vw"){
    const currentPage = sessionStorage.getItem("page");
    father.innerHTML = "";
    images.forEach(image => {
        const imgTag = document.createElement('img');
        imgTag.setAttribute("alt", image.title);
        imgTag.setAttribute("src", image.url);
        imgTag.style.width = size;
        imgTag.style.padding = "5px";
        imgTag.style.borderRadius = "10px"
        father.appendChild(imgTag);
      
    });
  
}


module.exports = {
    getImagesByPage, 
    getImagesFromTo,
    renderImages
}
  