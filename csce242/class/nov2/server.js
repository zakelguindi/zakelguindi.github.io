const express = require("express");
const app = express();
app.use(express.static("public"));

app.get("/", (req, res) => {
    res.sendFile(__dirname + "/index.html");
});


app.get("/api/animals", (req, res) => {
    const animals = [];
    animals[0] = {
        name: "lion",
        color: "yellow",
        state: "fierce",
        img: "images/pitt-bull.jpg"
    };
    animals[1] = {
        name: "bear",
        color: "white",
        state: "timid",
        img: "images/golden-retriever.jpg"
    };
    animals[2] = {
        name: "penguin",
        color: "black and white",
        state: "playful",
        img: "images/yorkie.jpg"
    };

    res.json(animals);
    // res.end(); 
});

app.listen(3000, () => {
    console.log("listening");
});