

// for quotes- look at toys example oct 3 
//for rainbow- try oct 5 example 

let quotesList = [
  `"To be or not to be, that is the question" - William Shakespeare`, 
  `"I love web dev" - Zak Elguindi`, 
  `"I still love web dev" - Zak Elguindi`, 
  `"One small step for mankind, one great leap for mankind" - Neil Armstrong`, 
  `"What are you working on?" - My roomate Josh`
]

const showQuotes = () => {
  let quotes = document.getElementById("quotes");
  quotes.innerHTML = quotesList[0]; 

  let i = 1; 
  const interval = setInterval(() => {
    quotes.innerHTML = quotesList[i]; 
    i++

    if(i == 5) {
      i = 0; 
    }
  }, 2000)
}

var y=document.querySelector(":root"); 
const showRainbow = () => {

  console.log("rainbow");
  //create colors array, create paragraph, add box to it,
  //set style background every 1000 ms
  let colors = ["red", "orange", "yellow", "green", "blue", "purple"];
  let i=0; 
  const rainbow = document.querySelector("#rainbowdrawing");
  rainbow.innerHTML = "";
  
    const interval = setInterval(() => {
      const thisLine = document.createElement("p");
      console.log(thisLine); 
      thisLine.classList.add("box"); 
      thisLine.style.setProperty("background", colors[i]);
      i++;
      console.log(i);
      rainbow.append(thisLine); 
      console.log(thisLine);
      // console.log(i); 

      if(i >= colors.length) {
        clearInterval(interval); 
        document.getElementById("goldpot").classList.remove("hidden"); 

      }
      
    }, 1000);
  
  
}

window.onload = () => {
  //works
  showQuotes(); 
  document.getElementById("draw-rainbow-button").onclick = showRainbow; 
}