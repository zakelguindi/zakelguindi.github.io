

const manbuttonclick = () => {
  document.getElementById("runningmandiv").classList.add("hide");
}

window.onload = () => {
  document.getElementById("manbutton").onclick = manbuttonclick; 
}