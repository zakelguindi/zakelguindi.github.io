

class Toy {
  constructor(name, price, ageRange, rating, pic) {
    this.name = name;
    this.price = price; 
    this.ageRange = ageRange; 
    this.rating = rating; 
    this.pic = pic; 
  }

  // have section for image and section for the section. 
  // 

  get Item() {
    const section = document.createElement("section"); 
    section.classList.add("toy"); //creates toy div 
    // section.classList.add("opacity"); 

    const picture = this.picture(this.pic); 
    section.append(picture);

    const subsection = document.createElement("section");
    subsection.classList.add("subsection");  
    section.append(subsection); 

    const h3 = document.createElement("h3");
    h3.innerHTML = this.name; 
    subsection.append(h3); 
    subsection.append(this.listItem("Price "+this.price));
    subsection.append(this.listItem("Age Range: "+this.ageRange)); 
    subsection.append(this.listItem("Rating: "+this.rating)); 

    section.onmouseover = () => {
      subsection.classList.add("goodOpacity");
      picture.classList.add("dullOpacity");
    }
    section.onmouseout = () => {
      subsection.classList.remove("goodOpacity"); 
      picture.classList.remove("dullOpacity"); 
    }
    return section; 
  }

  picture(info) {
    const pic = document.createElement("img");
    pic.src = "images/" + info;
    return pic;
}

  listItem(info) {
    const li = document.createElement("p"); 
    li.textContent = info; 
    return li; 
  }


}


const showToys = () => {
  const toysList = document.getElementById("toys");
  const toys = []; 

  toys.push(new Toy("Bike", "$70.00", "7-10", 4, "bike.png"));
  toys.push(new Toy("Buzz Lightyear", "$19.99", "4-10", 3, "buzz.png"));
  toys.push(new Toy("Dinosaur", "$15", "3-7", 4, "dino.png")); 
  toys.push(new Toy("Doll", "$9.99", "4-8", 5, "doll.png")); 
  toys.push(new Toy("Doll House", "$29.99", "5-10", 4, "dollhouse.png")); 
  toys.push(new Toy("Woody", "$8.99", "3-8", 4, "woody.png"));

  toys.forEach(toy => {
    toysList.append(toy.Item); 
  });

}


window.onload = () => {
  showToys(); 
}