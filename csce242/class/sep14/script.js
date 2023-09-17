/**
 * 
 * both of these work: 
 * const funcname = () => 6+7; 
 * const funcname = param => { ... return ... }
 */

console.log("Zico"); 
const add = (a,b) => a+b; //don't even need curly braces/return if it's one line. just do expression 
const add_alt = (a,b) => { return a+b; }

console.log(add(5,6)); //adds to console 
console.log(add_alt(5,7));//adds to console

const square = a => a*a; 
console.log(square(5)); //adds to console 

const hello = () => console.log("Zicooooo"); 
hello(); 

const helloSpecific = userName => console.log("Wagwan "+userName+"!");
helloSpecific("Zeeb");

const helloFullName = (firstname, lastname) => {
  console.log("Hello "+firstname+" "+lastname);
  console.log("You are awesome"); 
};
helloFullName("zak","elguindi")

const displayName = () => {
  const firstname = document.getElementById("txt-first-name").value; 
  console.log("Hello " +firstname+"!")
  document.getElementById("sampletext").innerHTML = "Hello "+firstname+"!";
}

const buttonclick = () => {
  document.getElementById("square-setup").classList.add("square");

}

window.onload = () => {
  document.getElementById("button").onclick = buttonclick; /*you only get one function for the onclick */ 
  document.getElementById("button-show-name").onclick = displayName; 
}

//why they need to be constant
/**
 * const myName = "Zak"; 
 * myName = "not zak"; 
 * shows error bc myName can't be renamed once it's declared const
 */




//window onload interacts with HTML 