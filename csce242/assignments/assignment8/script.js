

const manbuttonclick = () => {
  let count = 0;
  document.getElementById("manpic").classList.add("manAnimation");
}

var y = document.querySelector(':root'); 
const colorBar = () => {
  document.getElementById("displayblock").classList.toggle("hide");
  x = (document.getElementById("funds-raised-txt").value)/100;
  // document.getElementById("displayblock").style.setProperty("--x", x*4+"px");
  // y.style.setProperty("--num", x+"%"); 

  let i = 0; 
  const fill = setInterval(() => { 

    //works
    if(i <= x) {
      y.style.setProperty("--num", i+"%");
      i++; 
    }
  }, 20);


  console.log("X: "+x); 
  document.getElementById("displayblock").classList.add("fillgradient");
}



window.onload = () => {
  document.getElementById("manbutton").onclick = manbuttonclick; 
  document.getElementById("displayfunds").onclick = colorBar; 
}