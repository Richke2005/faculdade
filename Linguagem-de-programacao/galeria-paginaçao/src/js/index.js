const { getImagesFromTo  } = require("./services");



const prefix = document.getElementById("prefix");

function renderImages(father){
    const images = getImagesByPage({page: 1, limit: 12});
    
    images.forEach(image => {
        const imgTag = document.createElement('img');
        imgTag.setAttribute("alt", image.title);
        imgTag.setAttribute("src", image.url);

        father.appendChild(imgTag);
    });
}

console.log(getImagesFromTo(3, 12));
