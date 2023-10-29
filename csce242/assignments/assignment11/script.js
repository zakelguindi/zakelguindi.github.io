

const getMovies = async () => {
  const url = "https://portiaportia.github.io/json/movies.json";

  try {
    const link = await fetch(url); 
    console.log(link); 
    return await link.json(); 
  } catch(error) {
    console.log(error); 
  }
};

const showMovies = async () => {
  let movies = await getMovies(); 
  let moviesSection = document.getElementById("movies-section"); 

  movies.forEach((movie) => {
    moviesSection.append(getMoviesItem(movie))
  });
};

const getMoviesItem = (movie) => {
  // add director, actors, year, genres, description, image 
  const moviesSection = document.createElement("section"); 
  moviesSection.classList.add("movie"); 

  const a = document.createElement("a"); 
  // a.href = movie.website_url; 
  moviesSection.append(a); 

  const imgSection = document.createElement("section"); 

  const image = document.createElement("img"); 
  image.src = movie.img; 
  image.classList.add("img-format");
  console.log(image); 
  imgSection.append(image);  

  
  const infoSection = document.createElement("section"); 

  const h3 = document.createElement("h3"); 
  h3.innerText = movie.title; 
  infoSection.append(h3); 

  const director = document.createElement("p"); 
  director.innerHTML = "<b>Director: </b>"+movie.director; 
  infoSection.append(director); 

  const actors = document.createElement("p"); 
  actors.innerHTML = "<b>Actors: </b>"+movie.actors; 
  infoSection.append(actors); 

  const year = document.createElement("p"); 
  year.innerHTML = "<b>Year: </b>"+movie.year; 
  infoSection.append(year); 

  const genres = document.createElement("p"); 
  genres.innerHTML = "<b>Genres: </b>"+movie.genres; 
  infoSection.append(genres); 

  const description = document.createElement("p"); 
  description.innerHTML = movie.description; 
  infoSection.append(description); 

  // const image = document.createElement("img"); 
  // image.src = movie.img; 
  // image.classList.add("img-format");
  // console.log(image); 
  // a.append(image);  
  a.classList.add("div-formatting"); 
  a.append(imgSection); 
  a.append(infoSection); 


  return moviesSection;
};

window.onload = () => showMovies(); 


