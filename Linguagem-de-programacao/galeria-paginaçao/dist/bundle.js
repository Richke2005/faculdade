(function(){function p(o,i,f){var a="function"==typeof require&&require;function c(n,r){if(!i[n]){if(!o[n]){var e="function"==typeof require&&require;if(!r&&e)return e(n,!0);if(a)return a(n,!0);var r=new Error("Cannot find module '"+n+"'");throw r.code="MODULE_NOT_FOUND",r}var e=i[n]={exports:{}};o[n][0].call(e.exports,function(r){var e;return c(o[n][1][r]||r)},e,e.exports,p,o,i,f)}return i[n].exports}for(var r=0;r<f.length;r++)c(f[r]);return c}return p})()({1:[function(require,module,exports){
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
  
},{}],2:[function(require,module,exports){
const { getImagesFromTo, getImagesByPage, renderImages } = require("./services");

const gallery = document.querySelector(".gallery");
const prefix = document.getElementById("prefix");
const album = document.getElementById("album-number");
const initialPhoto = document.getElementById("initial-photo");
const qtdPhotos = document.getElementById("photos-quantity");
const playButton = document.getElementById("play-button");
const before = document.getElementById("before-button");
const next = document.getElementById("next-button");


window.addEventListener("load", function(){
    // Check localStorage to see if the splash screen 
    // has NOT already been displayed
    if(!sessionStorage.getItem("splash")){
 
        // Splash has not been displayed, so show it:
        renderImages(gallery, getImagesByPage("001",{page: 1, limit: 12}));
        // Store a value in localStorage to denote that the splash screen
        // has now been displayed
        sessionStorage.setItem("splash", "true");
        sessionStorage.setItem("album", "001")
        sessionStorage.setItem("page", 1)
        sessionStorage.setItem("limit", 12) 
        }else{
            renderImages(gallery, getImagesByPage(
                this.sessionStorage.getItem("album"), 
            {
                page: Number(this.sessionStorage.getItem("page")),
                limit: Number(this.sessionStorage.getItem("limit"))
            }));
        }
    })


playButton.addEventListener("click", (e) => {
    const albumValue = album.value
    const initialValue = Number.parseInt(initialPhoto.value) - 1;
    const qtdValue = Number.parseInt(qtdPhotos.value);

    renderImages(gallery, getImagesFromTo({album: albumValue, initial: initialValue, to: qtdValue}))

    sessionStorage.setItem("album", albumValue)
    sessionStorage.setItem("initial-photo", initialValue)
    sessionStorage.setItem("limit", qtdValue) 
})

//next page functions
next.addEventListener("click", (e) => {
    const currentPage = sessionStorage.getItem("page");
    const currentAlbum = sessionStorage.getItem("album");
    const currentLimit = sessionStorage.getItem("limit");

    sessionStorage.setItem("page", Number(currentPage) + 1);
    renderImages(gallery, getImagesByPage(currentAlbum, {page: Number(currentPage) + 1, limit: Number(currentLimit)}));

})

before.addEventListener("click", (e) => {
    const currentPage = sessionStorage.getItem("page");
    const currentAlbum = sessionStorage.getItem("album");
    const currentLimit = sessionStorage.getItem("limit");

    sessionStorage.setItem("page", Number(currentPage) - 1);
    renderImages(gallery, getImagesByPage(currentAlbum, {page: Number(currentPage) -1 , limit: Number(currentLimit)}));

})
},{"./services":1}]},{},[2]);
