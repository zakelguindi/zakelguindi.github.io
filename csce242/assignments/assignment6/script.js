/**
 * Use own color scheme and emoji 
 * have same content (Product name, comment, rating, username )
 * everything in 1 column on mobile layout 
 * hide and show
 * animate
 * input
 * comment functionality on products 
 */


const showbuttonclick = () => {
  document.getElementById("column1-img").classList.remove("hide");
}

const hidebuttonclick = () => {
  document.getElementById("column1-img").classList.add('hide');
}

const danceclick = () => {
  document.getElementById("column2.png").classList.add("thumbsupanimation");
}

//add column 3 buttons/functionality 

const commentbuttonclick = () => {
  
  document.getElementById("comment-layout").classList.add("padding-area");
  const productname = document.getElementById("txt-product-name").value; 
  const commentname = document.getElementById("txt-comment-name").value;
  const ratingname = document.getElementById("txt-rating-name").value;
  const username = document.getElementById("txt-user-name").value;
  document.getElementById("comment-header").innerHTML = productname;
  document.getElementById("comment-section").innerHTML = ratingname+"/5 stars. "+commentname;
  document.getElementById("nametag").innerHTML = "by "+username;
}







window.onload = () => {
  document.getElementById("show-button").onclick = showbuttonclick; 
  document.getElementById("hide-button").onclick = hidebuttonclick; 
  document.getElementById("comment-button").onclick = commentbuttonclick;
  document.getElementById("dance-button").onclick = danceclick; 
}