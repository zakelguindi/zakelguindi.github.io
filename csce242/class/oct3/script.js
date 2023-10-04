const toggleNav = () => {
  document.getElementById("nav-items").classList.toggle("hide-small"); 
}

let toys = ["drum", "ball" , "rope", "balloon", "tire"]; 

const showToys = () => {
  let result = document.getElementById("result"); //assigns input to result variable 

  result.innerHTML = ""; //clears table

  for (let i in toys) {
    result.innerHTML += toys[i] + "<br>"; // adds result to toys 
  }
};

const showToyTable = () => {
  let toysPrice = [];
  toysPrice["barbie"] = 7.54; 
  toysPrice["doll house"] = 86.23; 
  toysPrice["slide"] = 8.57; 
  toysPrice["ken"] = 2.3; 
  toysPrice["bike"] = 5.6; 

  const toysTable = document.getElementById("toy-table");
  //const toysTable = document.querySelector("toys-table");  same as line above

  for(let toy in toysPrice) {
    // const tr = document.createElement("tr"); 
    // toysTable.append(tr); 
    // tr.innerHTML = `<td>${toy}</td>`;    
    // toysTable.innerHTML += `<td><td>${toy}</td></tr>`;


    const tr = document.createElement("tr"); 
    const td = document.createElement("td"); 
    const text = document.createTextNode(toy); 
    toysTable.append(tr); 
    td.append(text); 
    tr.append(td); 


    tr.onclick = () => {
      let p = document.getElementById("toy-description"); //assigns toy description space to p 
      p.innerHTML = `${toy} costs $${toysPrice[toy]}`;//displays price 
      console.log(`you clicked ${toy}`);
      tr.classList.add("special"); //makes it purple 
    }
  }

};

const addToy = () => { 
  const toy = document.getElementById("txt-toy").value;
  toys.push(toy); 
  showToys(); 
}

let timesran = 0; 

const slide = () => {


  // if(timesran < 10) {

    
    const currentImage = document.querySelector("#slideshow :not(.hidden)");
    currentImage.classList.add("slideHide"); //hides current image

    let nextImage = currentImage.nextElementSibling; //moves to next image

    if(nextImage == null) {
      nextImage = document.querySelector("#slideshow :first-child");
    }

    nextImage.classList.remove("slideHide"); //unhides next image
    // timesran = timesran+1; 
    // console.log(timesran); 
  // }

}

window.onload = () => {
  document.getElementById("hamburger").onclick = toggleNav; 
  showToys(); 
  document.getElementById("button-add-toy").onclick = addToy; 
  showToyTable(); 

  setInterval(slide, 1000);
}