function Article() {
	this.title = "N/A";
	this.author = "N/A";
	this.publishTime = "N/A";
	this.content = "";
}

Article.propotype.getTitle = function() {
	return this.title;
};

Article.propotype.setTitle = function(title) {
	this.title = title;
};

Article.propotype.getAuthor = function() {
	return this.author;
};

Article.propotype.setAuthor = function(author) {
	this.author = author;
};

Article.propotype.getPublishTime = function() {
	return this.publishTime;
};

Article.propotype.setPublishTime = function(publishTime) {
	this.publishTime = publishTime;
};

Article.propotype.addContent = function(content) {
	this.content += content;
};

Article.propotype.getContent = function() {
	return this.content;
};

(function() {
	var art = new Article();
	art.setTitle = "Hello";
	art.addContent("Good Day!");
})();