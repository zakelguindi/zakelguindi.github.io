

const toggleAssignments = () => {
  document.getElementById("assignmentslist").classList.toggle("hide"); 
}

const toggleProject =  () => {
  document.getElementById("projectslist").classList.toggle("hide"); 
}

window.onload = () => {
  document.getElementById("assignments-id").onclick = toggleAssignments;
  document.getElementById("projects-header").onclick = toggleProject;  
}