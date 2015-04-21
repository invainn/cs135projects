var canvas = document.getElementById("map");
var ctx = canvas.getContext("2d");

var base = new baseImage();

function baseImage() {

	var img = new Image();
	img.src = "assets/base.png";

	this.x = 320;
	this.y = 430;
}

function speedy() {
	this.x = 0;
	this.y = 0;

	this.top = 0;
	this.bottom = 0;
	this.right = 0;
	this.left = 0;

	this.speed = Math.random() * 10;
	this.direction = 1;
}

function drawImage() {
	setInterval(update, 1000/30.0);
}

function update() {
	ctx.clearRect(0, 0, canvas.width, canvas.height);

	ctx.drawImage(base.img, base.x, base.y);
}



document.body.onkeydown = function(e) {
	if(e.keyCode == 39) {
		if(direction < 0) {
			direction = -direction;
			update();
		}
	}
	if(e.keyCode == 37) {
		if(direction > 0) {
			direction = -direction;
			update();
		}
	}
	if(e.keyCode == 32) {
		if(shot1 == 0) {
			bubbleX1 = baseX;
			bubbleSpeed1 = 5;
			shot1++;
		} else if(shot2 == 0) {
			bubbleX2 = baseX;
			bubbleSpeed2 = 5;
			shot2++;
		} else if(shot3 == 0) {
			bubbleX3 = baseX;
			bubbleSpeed3 = 5;
			shot3++;
		} 
		update();
	}
}