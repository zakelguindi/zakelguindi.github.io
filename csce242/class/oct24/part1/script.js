

const getShoes = async() => {
  const url = "https://portiaportia.github.io/json/shoes.json"; 

  try {
    const response = await fetch(url); 
    return await response.json(); //know it will be in JSON format, waiting to get it 
    //same flow every time we access json 

  } catch(error) {
    console.log(error); 
  }
}

const showShoes = async() => {
  const shoes = await getShoes(); 
  console.log(shoes); 
  const shoeList = document.getElementById("shoes-section");

  shoes.forEach(shoe => {
    shoeList.append(getShoeSection(shoe));
  });  
};

const getShoeSection = (shoe) => {
  const section = document.createElement("section"); 
  const h3 = document.createElement("h3"); 
  section.append(h3); //shows it in section 
  h3.innerHTML = shoe.name; //calls JSON 


  //printing the shoe brand 
  const brandP = document.createElement("p"); 
  section.append(brandP); 
  brandP.innerHTML = shoe.brand; 

  const ul = document.createElement("ul"); 
  section.append(ul); 
  
  for(let i in shoe.reviews) {
    const li = document.createElement("li"); 
    ul.append(li); 
    li.innerHTML = shoe.reviews[i]; //gets every review in JSON 
  }

  return section; 
};

window.onload = () => showShoes(); 