const { getImagesFromTo, getImagesByPage } = require("./services");

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
      renderImages(gallery, getImagesByPage("001",{page: 1, limit: 3}));
      // Store a value in localStorage to denote that the splash screen
      // has now been displayed
      sessionStorage.setItem("splash", "true");
    }
 });


playButton.addEventListener("click", (e) => {
    const albumValue = album.value
    const initialValue = Number.parseInt(initialPhoto.value) - 1;
    const qtdValue = Number.parseInt(qtdPhotos.value);

    renderImages(gallery, getImagesFromTo({album: albumValue, initial: initialValue, to: qtdValue}))
})





// const prefix = document.getElementById("prefix");

function renderImages(father, images){
    father.innerHTML = "";
    images.forEach(image => {
        const imgTag = document.createElement('img');
        imgTag.setAttribute("alt", image.title);
        imgTag.setAttribute("src", image.url);
        imgTag.style.width = "32vw";
        imgTag.style.padding = "5px";
        imgTag.style.borderRadius = "10px"
        father.appendChild(imgTag);
    });
}
