

const getProjects = async () => {
  // const url = "https://github.com/zakelguindi/zakelguindi.github.io/blob/main/csce242/zakelguindiprojects/part5/json/projects.json";
  const url = "https://raw.githubusercontent.com/zakelguindi/zakelguindi.github.io/main/csce242/zakelguindiprojects/part5/json/projects.json";

  try {
    const link = await fetch(url); 
    console.log(link); 
    return await link.json(); 
  } catch(error) {
    console.log(error); 
  }
};

const showProjects = async () => {
  let projects = await getProjects(); 
  let projectsSection = document.getElementById("project-main-div");

  projects.forEach((project) => {
    if(project.language == "Java") {
      //seeing if it's a java project 
      projectsSection.append(getProjectItem(project))
    }
  });
};

const getProjectItem = (project) => {
  const projectsSection = document.createElement("section"); 
  projectsSection.classList.add("project"); 

  const a = document.createElement("p"); 
  projectsSection.append(a); 

  const name = document.createElement("h2");
  name.innerText = project.name;
  a.append(name); 

  const language = document.createElement("h4");
  language.innerText = project.language; 
  a.append(language); 

  const date = document.createElement("h4"); 
  date.innerHTML = project.date; 
  a.append(date); 

  const description = document.createElement("p");
  description.innerHTML = "<b><u>Description:</u></b>  "+ project.description; 
  a.append(description); 

  const ghLink = document.createElement("a"); 
  ghLink.href = project.githubLink; 
  ghLink.innerText = `${project.name} Code`;
  a.append(ghLink); 

  if(project.mediaLink != "") {
    const mediaLink = document.createElement("a"); 
    mediaLink.href = project.mediaLink; 
    mediaLink.innerHTML = project.name + " Media Link";
    a.append(mediaLink); 
  }



  const favorite = document.createElement("p"); 
  favorite.innerHTML = project.favorite; 

  return projectsSection;

};

window.onload = () => showProjects(); 