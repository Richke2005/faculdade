module.exports = function renderImages(father, images, size = "32vw"){
    father.innerHTML = "";
    images.forEach(image => {
        const imgTag = document.createElement('img');
        imgTag.setAttribute("alt", image.title);
        imgTag.setAttribute("src", image.url);
        imgTag.style.width = size;
        imgTag.style.padding = "5px";
        imgTag.style.borderRadius = "10px";
        father.appendChild(imgTag);
    });
}

