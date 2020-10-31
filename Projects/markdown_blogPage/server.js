const express = require("express");
const Article = require('./models/article');
const mongoose = require('mongoose');
const articleRouter = require('./routes/articles'); 
const methodOverride = require('method-override');

const app = express();

mongoose.connect('mongodb://localhost/blog', { useNewUrlParser: true, useUnifiedTopology: true, useCreateIndex: true });

app.set('view engine', 'ejs');
app.use(express.urlencoded({ extended: false }));
app.use(methodOverride('_method'));

app.get("/" , async (req, res) => {

    console.log("\nHome Page\n");

    const articles = await Article.find().sort({ date: 'desc'});
    
    res.render('articles/index', { articles: articles });
});

app.use('/articles', articleRouter);

app.listen(5000);



console.log("Hello world");