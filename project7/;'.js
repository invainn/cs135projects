var canvas = document.getElementById("map");
var ctx = canvas.getContext("2d");

function speedy() {
	var img = new Image();
	img.src = "assets/base.png";

	this.x = 320;
	this.y = 430;

	this.changeDirection = function() {
		if(this.x > canvas.width - this.width || this.x < 0) {
			return this.direction = -1;
		}
	}

	this.draw = function() {
		ctx.drawImage(img, this.x, this.y);
	}
}

function drawImage() {
	setInterval(update, 1000/30.0);
}

function update() {
	ctx.clearRect(0, 0, canvas.length, canvas.width);

	speedy.draw();
}