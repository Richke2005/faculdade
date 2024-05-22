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
        renderImages(gallery, getImagesByPage(1 ,{page: 1, limit: 12}));
        // Store a value in localStorage to denote that the splash screen
        // has now been displayed
        sessionStorage.setItem("splash", "true");
        sessionStorage.setItem("album", 1)
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
    const albumValue = Number.parseInt(album.value);
    const initialValue = Number.parseInt(initialPhoto.value) - 1;
    const qtdValue = Number.parseInt(qtdPhotos.value);
    //render the images in the screen and up the info to storage
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
    //pass the current page to sessionStorage and render the image
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