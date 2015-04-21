var canvas = document.getElementById("map");
var ctx = canvas.getContext("2d");

function baseImage() {
	var this.img = new Image();
	this.img.src = "assets/base.png";

	this.x = 320;
	this.y = 430;

	this.direction = 1;

	this.changeDirection = function() {
		if(this.x > canvas.width - this.width || this.x < 0) {
			return this.direction = -1;
		}
	}
}

var base = new baseImage();

function drawImage() {
	setInterval(update, 1000/30.0);
}

function update() {
	ctx.clearRect(0, 0, canvas.length, canvas.width);
	
	ctx.drawImage(base.img, base.x, base.y);
	
}

console.log("all done");