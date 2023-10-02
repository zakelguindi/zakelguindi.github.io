var width = 100; 

const toggleNav = () => {
  document.getElementById("nav-items").classList.toggle("hide-small"); 
}

const makeLoops = () => {
  const resultDiv = document.getElementById("result"); 

  const ul=document.createElement("ul"); //creates element
  resultDiv.append(ul); //you can append anywhere 

  for(let i=1; i<=10; i++) {
    const li = document.createElement("li"); 
    li.textContent = i ; 
    ul.append(li); 

  }

  // for(let i=0; i<10; i++) {
  //   resultDiv.innerHTML += i +" "; 
  // }
}

const growButton = () => {
  width += 10; 
  setSquareWidth();
}

const shrinkButton = () => {
  width -= 10; 
  setSquareWidth();
}

const setSquareWidth = () => {
  document.getElementById("square").style.setProperty("--x", width +"px"); 
}

const eatFruits = () => {
  const lis = document.getElementsByTagName("li");

  for(let i in lis) {
    lis[i].innerHTML = "nononommm " +lis[i].innerHTML; 
  }
}

const countNums = () => {
  let count = 0; 
  let p = document.querySelector("#count"); 

  const updateCount = (() => {
    count++; 
    p.innerHTML = count; 

    if(count >= 10) {
      clearInverval(updateCount); 
    }
  }, 1000) //run every millisecond 
}

window.onload = () => {
  document.getElementById("hamburger").onclick = toggleNav;
  document.getElementById("button-for-loop").onclick = makeLoops;
  document.getElementById("button-grow").onclick = growButton; 
  document.getElementById("button-shrink").onclick = shrinkButton; 
  setSquareWidth(); //updates x variable in square 

  document.getElementById("button-change-list").onclick = eatFruits; 
  document.getElementById("button-count").onclick = countNums; 
}
