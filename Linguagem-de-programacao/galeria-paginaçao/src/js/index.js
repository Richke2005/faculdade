function getImagesByPage(page, limit = 12, skip = 1){
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

function renderImages(){
    const images = getImagesByPage(2, 100, 1);
    let html = '';
    images.forEach(image => {
        html += `
            <div class="col-md-3">
                <div class="thumbnail">
                    <img src="${image.url}" alt="${image.title}">
                    <div class="caption">
                        <h3>${image.title}</h3>
                    </div>
                </div>
            </div>
        `;
    });
    document.getElementById('images').innerHTML = html;
}

console.log(getImagesByPage(2, 100, 1));