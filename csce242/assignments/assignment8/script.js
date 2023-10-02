

const manbuttonclick = () => {
  let count = 0;
  const interval = setInterval(() =>  {
    



  }, 500); 
}

var y = document.querySelector(':root'); 
const colorBar = () => {
  document.getElementById("displayblock").classList.toggle("hide");
  x = (document.getElementById("funds-raised-txt").value)/100;
  // document.getElementById("displayblock").style.setProperty("--x", x*4+"px");
  if(x > 0 && x <= 25) {
    //25%
    y.style.setProperty("--num", 25+"%");
  } else if(x > 25 && x <= 50) {
    //50%
    y.style.setProperty("--num", 50+"%");
  } else if(x > 50 && x <= 75) {
    //75%
    y.style.setProperty("--num", 75+"%");
    console.log("here"); 
  } else if(x > 75 && x <= 100) {
    //100%
    y.style.setProperty("--num", 100+"%");
  }
  console.log("X: "+x); 
  document.getElementById("displayblock").classList.add("fillgradient");
}



window.onload = () => {
  document.getElementById("manbutton").onclick = manbuttonclick; 
  document.getElementById("displayfunds").onclick = colorBar; 
}