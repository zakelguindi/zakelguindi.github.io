// const helloP = document.getElementById("date"); 
// helloP.innerHTML= "Hi zak"; 

const changeText = () => {
  //called when the button is clicked and changes text on the button 
  loadFunction(); 
}

const hideImage = () => {
  document.getElementById("sampleimage").classList.add("hide"); 
}

const showImage = () => {
  document.getElementById("sampleimage").classList.remove("hide"); 
}

const loadFunction = () => {
  //load function is equal to the arrow function inside the body
  //this is the better standard 
  const helloP = document.getElementById("date"); 
  helloP.innerHTML = "russell westbrook";
  
  helloP.classList.add("special"); //adds a class to the list of classes in helloP 



}

window.onload = () => {
  //when window is loaded, execute all of these functions 
  // const clickButton = document.getElementById("button-click"); 

  //calling changeText() calls it IMMEDIATELY, doing it without parentheses doesn't 
  // clickButton.onclick = changeText; //when button is clicked, call changeText

  //another way to write lines 18 and 21
  document.getElementById("button-click").onclick = changeText; 
  document.getElementById("button-show").onclick = showImage; 
  document.getElementById("button-hide").onclick = hideImage; 
  // loadFunction(); 
};

