

const imageBoxSetup = () => {
  const background =document.getElementById("modal-background"); 
  const dialog = document.querySelector(".dialog"); 

  document.querySelectorAll(".items img").forEach((img) => {
    // img.classList.add("hidden");
    img.onclick = () => {
      const largeImage = img.getAttribute("data-large-src"); 
      document.querySelector(".dialog img").src = largeImage; 
      background.style.display = "block"; 
      dialog.classList.add("slideShow"); 
      // dialog.style.opacity = 1; 
      dialog.addEventListener("animationend", () => {
        dialog.classList.remove("slideShow"); 
        dialog.style.opacity = 1;
      })
    };
  }); 

  document.querySelector(".close").onclick = () => {
    background.style.display = "none"; 
    dialog.style.opacity = 0; 
  }; 

  window.onclick = (event) => {
    //event has a target 
    // console.log(event.target);
    if(event.target == background) {
      // makes it go away when you click the background
      background.style.display = "none"; 
      dialog.style.opacity = 0; 
    }
  };
}

window.onload = () => {

  imageBoxSetup(); 
}