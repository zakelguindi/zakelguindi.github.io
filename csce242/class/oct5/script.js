const toggleNav = () => {
  document.getElementById("nav-items").classList.toggle("hide-small");
};

let count = 1;

const slide = () => {
  const currentImage = document.querySelector(
    `#slideshow :nth-child(${count})`
  );
  count++;

  let nextImage = currentImage.nextElementSibling;

  if (nextImage == null) {
    nextImage = document.querySelector("#slideshow :first-child");
    count = 1;
  }
};

window.onload = () => {
  setInterval(slide, 3000);
};