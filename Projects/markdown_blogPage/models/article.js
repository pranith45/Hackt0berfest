const mongoose = require('mongoose');
const marked = require('marked');   // to compile the markdown text to simple html
const slugify = require('slugify'); // to have simple url rather than having weird id in url
const creatDomPurify = require('dompurify');
const { JSDOM } = require('jsdom');

const dompurify = creatDomPurify(new JSDOM().window);   //this santitizes our html

const articleSchema = new mongoose.Schema({
    title: {
        required: true,
        type: String
    }, 
    
    description: String,

    markdown: {
        type: String,
        required: true
    },
    
    date: {
        type: Date,
        default: Date.now()
    },
    slug: {
        type: String,
        required: true,
        unique: true
    },
    sanitizedHtml: {
        type: String,
        required: true
    }
});

articleSchema.pre('validate', function(next) {
    if(this.title) {
        this.slug = slugify(this.title, { lower: true, strict: true})
    }

    if(this.markdown) {
        const html = marked(this.markdown);
        this.sanitizedHtml = dompurify.sanitize(html);

        console.log("Sanitizing...")
    }

    next()
});


module.exports = mongoose.model('Article', articleSchema);