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
            renderImages(gallery, getImages(
                this.sessionStorage.getItem("album"), 
                this.sessionStorage.getItem("type"),
            {
                page: Number(this.sessionStorage.getItem("page")),
                limit: Number(this.sessionStorage.getItem("limit"))
            }));
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