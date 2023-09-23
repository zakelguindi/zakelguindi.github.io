
const toggleNav = () => {
  document.getElementById("nav-items").classList.toggle("hide"); 
};

const displayData = () => {
  const resultDiv = document.getElementById("result"); 
  const firstname = document.getElementById("txt-first-name").value;
  const lastname = document.getElementById("txt-last-name").value;
  const age = parseInt(document.getElementById("txt-age").value);

  // write using backtick and create elements 
  //backtick
  // resultDiv.innerHTML = `<section>${firstname} ${lastname} </section>`;

  //other way
  const section = document.createElement("section"); 
  resultDiv.append(section); 
  const h3 = document.createElement("h3"); 
  h3.textContent = `${firstname} ${lastname}`; 
  section.append(h3); 
  const p = document.createElement("p"); 
  p.textContent = `Age: ${age}`;
  section.append(p);
};


// 9/21 class stuff
const changeMood = () => {
  const mood = document.getElementById("txt-mood").value.toLowerCase().trim(); 
  const root = document.querySelector("root"); 
  if(mood == "angry") {
    root.style.setProperty("--back", "red"); 
    root.style.setProperty("--headback", "orange"); 
  }
}

//color-gradient stuff for hw7 
const colorSquare = () => {
  document.getElementById("square").classList.add("rainbow"); 
}

window.onload = () => {
  document.getElementById("hamburger").onclick = toggleNav; 
  document.getElementById("button-show-data").onclick = displayData; 
  document.getElementById("button-gradient").onclick = colorSquare; 
};

const orderCoffee = () => {
  const numCoffees = parseInt(document.getElementById("txt-num").value);
  const coffeeType = document.getElementById("txt-type").value; 
  const orderDiv = document.getElementById("coffee-order"); 
  const error = document.getElementById("error-num"); 

  error.classList.add("hidden"); 
  orderDiv.classList.add("hidden"); 

  if(isNaN(numCoffees)) {
    error.classList.remove("hidden"); 
    error.innerHTML="* Not a valid number"; 
  } else if(numCoffees < 0) {
    error.classList.remove("hidden"); 
    error.innerHTML = "* Negative number"; 
  } else if(numCoffees == 0) {
    error.classList.remove("hidden"); 
    error.innerHTML = "* Can't order zero coffees"; 
  } else if(numCoffees == 1) {
    orderDiv.innerHTML = `Ordered 1 ${coffeeType}.`;
    orderDiv.classList.remove("hidden"); 
  } else {
    orderDiv.innerHTML= `Ordered ${numCoffees} ${coffeeType}'s.`;
    orderDiv.classList.remove("hidden"); 
  }

}

