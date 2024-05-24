(function(){function p(o,i,f){var a="function"==typeof require&&require;function c(n,r){if(!i[n]){if(!o[n]){var e="function"==typeof require&&require;if(!r&&e)return e(n,!0);if(a)return a(n,!0);var r=new Error("Cannot find module '"+n+"'");throw r.code="MODULE_NOT_FOUND",r}var e=i[n]={exports:{}};o[n][0].call(e.exports,function(r){var e;return c(o[n][1][r]||r)},e,e.exports,p,o,i,f)}return i[n].exports}for(var r=0;r<f.length;r++)c(f[r]);return c}return p})()({1:[function(require,module,exports){
module.exports = function renderImages(father, images, size = "32vw"){
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


},{}],2:[function(require,module,exports){
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
  
},{}],3:[function(require,module,exports){
const renderImages = require("./render.js");
const { getImages, definePageByInitial } = require("./services");

const gallery = document.querySelector(".gallery");
const prefix = document.getElementById("prefix");
const album = document.getElementById("album-number");
const initialPhoto = document.getElementById("initial-photo");
const photosLimit = document.getElementById("photos-quantity");
const size = document.getElementById("photos-size");
const type = document.getElementById("photos-type");
const playButton = document.getElementById("play-button");
const before = document.getElementById("before-button");
const next = document.getElementById("next-button");


window.addEventListener("load", function(){
    // Check localStorage to see if the splash screen 
    // has NOT already been displayed
    if(!sessionStorage.getItem("splash")){
 
        // Splash has not been displayed, so show it:
        renderImages(gallery, getImages(1 , ".jpg", {page: 1, limit: 12}));
        // Store a value in localStorage to denote that the splash screen
        // has now been displayed
        
        sessionStorage.setItem("splash", "true");
        sessionStorage.setItem("album", 1);
        sessionStorage.setItem("type", ".jpg")
        sessionStorage.setItem("page", 1);
        sessionStorage.setItem("limit", 12); 
        }else{
            renderImages(gallery, 
                getImages(
                this.sessionStorage.getItem("album"), 
                this.sessionStorage.getItem("type"),
                {
                    page: Number(this.sessionStorage.getItem("page")),
                    limit: Number(this.sessionStorage.getItem("limit"))
                }), 
            this.sessionStorage.getItem("size")
            );
        }
    });


playButton.addEventListener("click", (e) => {
    const albumValue = Number.parseInt(album.value);
    const sizeValue = size.value;
    const typeValue = type.value;
    const initialValue = Number.parseInt(initialPhoto.value) - 1; //corrigir este erro;
    const limit = Number.parseInt(photosLimit.value);
    const page = definePageByInitial(initialValue, limit);
    //render the images in the screen and up the info to storage
    renderImages(gallery, getImages(albumValue,
        typeValue,
        {
            initial: initialValue,
            limit: limit
        }), sizeValue);
    
    sessionStorage.setItem("size", sizeValue);
    sessionStorage.setItem("type", typeValue);
    sessionStorage.setItem("album", albumValue);
    sessionStorage.setItem("page", page);
    sessionStorage.setItem("initial-photo", initialValue);
    sessionStorage.setItem("limit", limit);
});

//next page functions
next.addEventListener("click", (e) => {
    const currentPage = sessionStorage.getItem("page");
    const currentType = sessionStorage.getItem("type");
    const currentSize = sessionStorage.getItem("size");
    const currentAlbum = sessionStorage.getItem("album");
    const currentLimit = sessionStorage.getItem("limit");
    //pass the current page to sessionStorage and render the image
    sessionStorage.setItem("page", Number(currentPage) + 1);
    renderImages(gallery, 
        getImages(
        currentAlbum,
        currentType,
            {
            page: Number(currentPage) + 1,
            limit: Number(currentLimit)
            }
        ),
        currentSize
    );

});

before.addEventListener("click", (e) => {
    const currentPage = sessionStorage.getItem("page");
    const currentType = sessionStorage.getItem("type");
    const currentSize = sessionStorage.getItem("size");
    const currentAlbum = sessionStorage.getItem("album");
    const currentLimit = sessionStorage.getItem("limit");

    sessionStorage.setItem("page", Number(currentPage) - 1);
    renderImages(gallery, 
        getImages(
        currentAlbum,
        currentType,
            {
            page: Number(currentPage) - 1,
            limit: Number(currentLimit)
            }
        ),
        currentSize
    );
});
},{"./render.js":1,"./services":2}]},{},[3]);
