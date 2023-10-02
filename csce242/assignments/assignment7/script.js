

const togglenav = () => {
  document.getElementById("exercise-headers").classList.toggle("hide"); //toggles between hidden and show 
}
const toggleExercise1 = () => {
  document.getElementById("whostheoldest").classList.toggle("hide");
  document.getElementById("fundraising").classList.add("hide"); 
}
const toggleExercise2 = () => {
  document.getElementById("fundraising").classList.toggle("hide"); 
  document.getElementById("whostheoldest").classList.add("hide"); 
}

const compareAges = () => {
  const name1 = document.getElementById("name1").value; 
  const name2 = document.getElementById("name2").value; 
  const name3 = document.getElementById("name3").value; 

  console.log(name1+" "+name2+", "+name3); 

  const age1 = parseInt(document.getElementById("age1").value);
  const age2 = parseInt(document.getElementById("age2").value);
  const age3 = parseInt(document.getElementById("age3").value);
  console.log(age1+ " "+age2+" "+age3); 

  const output = document.getElementById("output")

  const error = document.getElementById("error"); 

  //portia- sorry this is ugly. I just don't know syntax to do more efficient ways in JS
  if(isNaN(age1) || isNaN(age2) || isNaN(age3)) {
    error.classList.remove("hide"); 
    error.innerHTML="*Not a valid input"; 
  } else if(age1 < 0 || age2 < 0 || age3 < 0) {
    error.classList.remove("hide"); 
    error.innerHTML="* Error -- Negative Number"; 
  } else {
    output.innerHTML = "In order from oldest to youngest: "; 
    if(age1 > age2 && age1 > age3) {
      //age 1 is largest
      output.innerHTML += name1 +", "; 
      if(age2 > age3) {
        output.innerHTML += name2+", "+name3; 
      } else {
        output.innerHTML += name3+", "+name2; 
      }
    } else if(age2 > age1 && age2 > age3) {
      //age 2 is oldest
      output.innerHTML += name2 + ", "; 
      if(age1 > age3) {
        output.innerHTML += `${name1}, ${name3}`;
      } else {
        output.innerHTML += `${name3}, ${name1}`;
      }
    } else {
      //age 3 is oldest 
      output.innerHTML += name3 + ", "; 
      if(age1 > age2) {
        output.innerHTML += `${name1}, ${name2}`;
      } else {
        output.innerHTML += `${name2}, ${name1}`;
      }
    }
  }
}




var x = 0
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
  document.getElementById("nav-toggle").onclick = togglenav; 
  document.getElementById("exercise1").onclick = toggleExercise1;
  document.getElementById("exercise2").onclick = toggleExercise2;
  document.getElementById("compareagebutton").onclick = compareAges; 
  document.getElementById("displayfunds").onclick = colorBar;
}